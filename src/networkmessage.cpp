#include "pch.h"
#include "networkmessage.h"

#define FLOAT_COMPRESSION 1

int find_array_elem(const char** arr, int arrsize, char* name) {
    int id = -1;
    for (int i = 0; i < arrsize; i++) {
        if (!strcasecmp(arr[i], name)) {
            id = i;
            break;
        }
    }

    return id;
}

void NetworkMessageRaw::Put(bool value, NetworkCompressionType compression)
{
    switch (compression)
    {
    case NCTNone: case NCTDefault:
        Write(&value, sizeof(bool));
        break;
    default:
        //ErrF("Unsupported compression method %d", compression);
        break;
    }
}

void NetworkMessageRaw::Put(char value, NetworkCompressionType compression)
{
    switch (compression)
    {
    case NCTNone: case NCTDefault:
        Write(&value, sizeof(char));
        break;
    default:
        //ErrF("Unsupported compression method %d", compression);
        break;
    }
}

template <class IntType>
void NetworkMessageRaw::PutSmallUnsigned(IntType value)
{
    typename std::make_unsigned<IntType>::type val = value;
    for (;;)
    {
        unsigned char c = val & 0x7f;
        val >>= 7;
        if (val)
        {
            c |= 0x80;
            Write(&c, sizeof(unsigned char));
        }
        else
        {
            // no more bits left
            Write(&c, sizeof(unsigned char));
            break;
        }
    }
}

void NetworkMessageRaw::Put(int value, NetworkCompressionType compression)
{
    switch (compression)
    {
    case NCTNone:
        Write(&value, sizeof(int));
        break;
    case NCTSmallUnsigned:
        PutSmallUnsigned<int>(value);
        break;
    case NCTSmallSigned:
    {
        unsigned int val;
        if (value >= 0)
            val = value << 1;
        else
            val = (-value << 1) | 1;
        PutSmallUnsigned<int>(val);
    }
    break;
    default:
        //ErrF("Unsupported compression method %d", compression);
        break;
    }
}

void NetworkMessageRaw::Put(int64_t &value, NetworkCompressionType compression)
{
    switch (compression)
    {
    case NCTNone:
        Write(&value, sizeof(value));
        break;
    case NCTSmallUnsigned:
        PutSmallUnsigned<int64_t>(value);
        break;
    default:
        //ErrF("Unsupported compression method %d", compression);
        break;
    }
}

void NetworkMessageRaw::Put(float value, NetworkCompressionType compression)
{
    switch (compression)
    {
        float min, max, invRange;
#define RANGE(a,b) min = (a), max = (b), invRange = 1.0f/((b)-(a))
    case NCTFloat0To1:
        RANGE(0, 1);
        goto Compression;
    case NCTFloat0To2:
        RANGE(0, 2);
        goto Compression;
    case NCTFloatM1ToP1:
        RANGE(-1, +1);
        goto Compression;
    case NCTFloatMPIToPPI:
        RANGE(-H_PI, +H_PI);
        goto Compression;
    case NCTFloatAngle:
        RANGE(-H_PI, +H_PI);
        goto CompressionUnlimited;
    case NCTFloatMostly0To1:
        RANGE(0, 1);
        goto CompressionUnlimited;
#undef RANGE
        Compression :
                    //DoAssert(value>=min);
                    //DoAssert(value<=max);
        {
            // map min to 0, max to 254
            // note: 254 is used instead of 255, so that 0 with min = max
            // can be represented exactly
            float compressed = (value - min)*invRange;
            int iValue = toInt(compressed * 254);
            saturate(iValue, 0, 254);
            unsigned char cValue = iValue;
            Write(&cValue, sizeof(cValue));
        }
        break;
    CompressionUnlimited:
        {
            // map min to -128, max to 127
            float compressed = (value - min)*invRange;
            int iValue = toInt(compressed * 254 - 127);
            Put(iValue, NCTSmallSigned);
        }
        break;
    case NCTVectorPosition:
    {
        int pos = m_pos;
        int next_pos = pos + 2;
        if (m_buf_size < next_pos)
            break;
        
        uint16_t compressed;
        int flt_to_int = (*(int*)&value);
        int v3 = (uint8_t)(flt_to_int >> 23) - 0x70;
        if (v3 > 0)
        {
            int v5 = (flt_to_int & 0x80000000) >> 16;
            if (v3 < 32)
            {
                compressed = ((uint16_t)v3 << 10) | v5 | (flt_to_int >> 13) & 0x3FF;
            }
            else
            {
                compressed = v5 | 0x7FFF;
            }
        }
        else
            compressed = 0;

        *(uint16_t*)(m_buf + m_pos) = compressed;
        m_pos += 2;
    }
    break;
    case NCTNone: case NCTDefault:
        Write(&value, sizeof(value));
        break;
    default:
        //ErrF("Unsupported compression method %d", compression);
        break;
    }
}


void NetworkMessageRaw::Put(char* value, NetworkCompressionType compression)
{
    switch (compression)
    {
    case NCTStringGeneric: //NCTDefault:
    {
        int id = find_array_elem(NetIdStrings, NetIdStringsSize, value);
        if (id >= 0)
        {
            Put(id, NCTSmallUnsigned);
        }
        else
        {
            Put(0, NCTSmallUnsigned);
            Write((const char *)value, strlen(value) + 1);
        }
        break;
    }
    case NCTStringMove:
    {
        int id = find_array_elem(NetIdMoves, NetIdMovesSize, value);
        if (id >= 0)
        {
            Put(id, NCTSmallUnsigned);
        }
        else
        {
            Put(0, NCTSmallUnsigned);
            Write((const char *)value, strlen(value) + 1);
        }
        break;
    }
    case NCTNone:
        Write((const char *)value, strlen(value) + 1);
        break;
    default:
        //ErrF("Unsupported compression method %d", compression);
        break;
    }
}

void NetworkMessageRaw::Put(const LocalizedString &value, NetworkCompressionType compression)
{
    Put(value.m_type, NCTSmallUnsigned);
    Put(value.m_id.c_str(), compression);
}

void NetworkMessageRaw::Put(Time value, NetworkCompressionType compression)
{
    switch (compression)
    {
    case NCTNone: case NCTDefault:
        Put(value, NCTNone);
        break;
    default:
        break;
    }
}

void* NetworkMessageRaw::PutRaw(int size)
{
    int minSize = m_pos + size;

    while (m_buf_size < minSize)
        ExpandBuffer();

    void* retp = m_buf + m_pos;
    m_pos += size;
    m_size += size;
    return retp;
}

void* NetworkMessageRaw::GetRaw(int size)
{
    int minSize = m_pos + size;
    if (m_buf_size < minSize) 
        return nullptr;
    void* retp = m_buf + m_pos;
    m_pos += size;
    return retp;
}

//NCTVectorPositionCamera
//NCTVectorPositionCamera
//NCTFloat0To1

/// similar to Xbox engine version
static inline unsigned IntRange(float x, int mask)
{
    int halfMask = mask / 2;
    int i = toInt(x*-halfMask);
    if (i < -halfMask) i = -halfMask;
    else if (i > +halfMask) i = +halfMask;
    return i & mask;
}
static inline float DecodeRange(unsigned x, int mask, int log)
{
    int halfMask = mask / 2;
    int val = (x >> log)&mask;
    // sign extension needed
    // -halfMask is represented as (-halfMask&mask), which is mask+1-halfMask
    if (val > halfMask) val = val - (mask + 1);
    return val * (-1.0f / halfMask);
}
static inline int VectorTo32B(vec3& src)
{
    return (
        (IntRange(src.z, 0x3ff) << 22) |
        (IntRange(src.y, 0x7ff) << 11) |
        (IntRange(src.x, 0x7ff) << 0)
        );
}

static inline void GetVectorFrom32B(vec3 &n, unsigned int c)
{
    n = vec3(
        DecodeRange(c, 0x3ff, 22),
        DecodeRange(c, 0x7ff, 11),
        DecodeRange(c, 0x7ff, 0)
    );
}

// origin value selected so that typical values are small in absolute value
const float PosMaxXZ = 12800.0f;
const float PosMaxY = 1000.0f;

static const vec3 PosScale(PosMaxXZ*0.5f, PosMaxY*0.5f, PosMaxXZ*0.5f);
static const vec3 PosInvScale(2 / PosMaxXZ, 2 / PosMaxY, 2 / PosMaxXZ);
static const vec3 PosOrigin(PosMaxXZ / 2, PosMaxY / 2, PosMaxXZ / 2);
/**
 Range encoding:
 0: no enlarging necessary
 1: enlarge 2x
 2: enlarge 8x (max. range 102km * 102km * 12 km)
 3: enlarge 64x (max possible range: 1600km*96km*1600km)
*/
static const float PosEnlargeExp[4] = { 1,2,8,64 };
static const float PosEnlargeExpInv[4] = { 1.0f / 1,1.0f / 2,1.0f / 8,1.0f / 64 };

static int CameraPosTo32B(vec3& pos)
{
    // note: following encoding is tuned for landscapes 12800x12800 m
    // for NCTVectorPositionCamera range following encoding would work fine:
    // 11b for X/Z, 8b for Y: error ~ 3 in each component
    // we need to encode values outside of this range as well, 2b used as exponent
    vec3 relPos = (pos - PosOrigin) * PosInvScale;
    // check if we are in -1..1 range
    // if not, enlarge the range as necessary
    float maxSize = floatMax(fabs(relPos.x), fabs(relPos.y), fabs(relPos.z));
    unsigned exp = 0;
    while (maxSize > PosEnlargeExp[exp] && exp < 3) exp++;
    relPos *= PosEnlargeExpInv[exp];
    // encode position in 11/8/11 b

    if (pos.v[0] == -FLT_MAX)
    {
        // handle special case - InvalidCamPos
        return ~0;
    }
    return (
        (exp << 30) |
        (IntRange(relPos.z, 0x7ff) << 19) |
        (IntRange(relPos.y, 0xff) << 11) |
        (IntRange(relPos.x, 0x7ff) << 0)
        );
}

static void GetCameraPosFrom32B(vec3 &n, unsigned int c)
{
    if (c == ~0)
    {
        // special case - InvalidCamPos
        n = vec3();
        return;
    }
    unsigned exp = (c >> 30) & 3;
    float range = PosEnlargeExp[exp];
    n = vec3(
        DecodeRange(c, 0x7ff, 0)*range*PosScale.v[0] + PosOrigin.v[0],
        DecodeRange(c, 0xff, 11)*range*PosScale.v[1] + PosOrigin.v[1],
        DecodeRange(c, 0x7ff, 19)*range*PosScale.v[2] + PosOrigin.v[2]
    );
}

void NetworkMessageRaw::Put(vec3& value, NetworkCompressionType compression)
{
    switch (compression)
    {
    case NCTNone: case NCTDefault:
        Put(value.v[0], NCTNone);
        Put(value.v[1], NCTNone);
        Put(value.v[2], NCTNone);
        break;
    case NCTFloat0To1: // compress unit vector
        Put(VectorTo32B(value), NCTNone);
        break;
    case NCTVectorPositionCamera:
        Put(CameraPosTo32B(value), NCTNone);
        break;
    case NCTVectorPosition:
        Put(value.v[0], NCTVectorPosition);
        Put(value.v[1], NCTVectorPosition);
        Put(value.v[2], NCTVectorPosition);
        break;
    default:
        //ErrF("Unsupported compression method %d", compression);
        break;
    }
}

void NetworkMessageRaw::Put(matrix3x3& value, NetworkCompressionType compression)
{
    switch (compression)
    {
    case NCTNone: case NCTDefault:
        for (int i = 0; i < 3; i++)
        {
            Put(value.m[i][0], NCTNone);
            Put(value.m[i][1], NCTNone);
            Put(value.m[i][2], NCTNone);
        }
        break;
    case NCTMatrixOrientation:
    {
        EncodedMatrix3 encoded;
        encoded.Encode(value);
        Write(&encoded, sizeof(encoded));
        break;
    }
    default:
        //ErrF("Unsupported compression method %d", compression);
        break;
    }
}

void NetworkMessageRaw::Put(NetworkId &value, NetworkCompressionType compression)
{
    switch (compression)
    {
    case NCTNone: case NCTDefault:
        Put(value.creator, NCTSmallUnsigned);
        Put(value.id, NCTSmallUnsigned);
        break;
    default:
        //ErrF("Unsupported compression method %d", compression);
        break;
    }
}

void NetworkMessageRaw::Put(CreatorId &value, NetworkCompressionType compression)
{
    switch (compression)
    {
    case NCTSmallUnsigned: case NCTDefault:
        Put(value.creatorId, NCTSmallUnsigned);
        break;
    default:
        //ErrF("Unsupported compression method %d", compression);
        break;
    }
}

bool NetworkMessageRaw::Get(bool &value, NetworkCompressionType compression)
{
    switch (compression)
    {
    case NCTNone: case NCTDefault:
    {
        // check if the value is correct
        unsigned char val;
        bool ok = Read(&val, sizeof(bool));
        if (val > 1)
        {
            //RptF("Received %d, expected bool", (unsigned int)val);
            ok = false;
        }
        value = val != 0;
        return ok;
    }
    default:
        //ErrF("Unsupported compression method %d", compression);
        return false;
    }
}

bool NetworkMessageRaw::Get(char &value, NetworkCompressionType compression)
{
    switch (compression)
    {
    case NCTNone: case NCTDefault:
        return Read(&value, sizeof(value));
    default:
        //ErrF("Unsupported compression method %d", compression);
        return false;
    }
}

template <class IntType>
bool NetworkMessageRaw::GetSmallUnsigned(IntType &value)
{
    typedef typename std::make_unsigned<IntType>::type UnsignedIntType;
    UnsignedIntType val = 0;
    int offset = 0;
    while (true)
    {
        unsigned char c;
        if (!Read(&c, sizeof(unsigned char))) return false;
        // transfer 7 bits per byte
        val |= UnsignedIntType(c & 0x7f) << offset;
        // check terminator
        if ((c & 0x80) == 0) break;
        offset += 7;
    }
    value = val;
    return true;
}

bool NetworkMessageRaw::Get(int &value, NetworkCompressionType compression)
{
    switch (compression)
    {
    case NCTNone:
        return Read(&value, sizeof(value));
    case NCTSmallUnsigned:
        return GetSmallUnsigned<int>(value);
    case NCTSmallSigned:
    {
        unsigned int val = 0;
        if (!GetSmallUnsigned<unsigned int>(val)) return false;
        if (val & 1)
            value = -(int)(val >> 1);
        else
            value = val >> 1;
    }
    return true;
    default:
        //ErrF("Unsupported compression method %d", compression);
        return false;
    }
}

bool NetworkMessageRaw::Get(int64_t &value, NetworkCompressionType compression)
{
    switch (compression)
    {
    case NCTNone:
        return Read(&value, sizeof(value));
    case NCTSmallUnsigned:
        return GetSmallUnsigned<int64_t>(value);
    default:
        //ErrF("Unsupported compression method %d", compression);
        return false;
    }
}

bool NetworkMessageRaw::Get(float &value, NetworkCompressionType compression)
{
    switch (compression)
    {
        float min, coef;
#define RANGE(a,b) min = (a), coef = float((b)-(a))/254
    case NCTFloat0To1:
        RANGE(0, 1);
        goto Compression;
    case NCTFloat0To2:
        RANGE(0, 2);
        goto Compression;
    case NCTFloatM1ToP1:
        RANGE(-1, +1);
        goto Compression;
    case NCTFloatMPIToPPI:
        RANGE(-H_PI, +H_PI);
        goto Compression;
    case NCTFloatAngle:
        RANGE(-H_PI, +H_PI);
        goto CompressionUnlimited;
    case NCTFloatMostly0To1:
        RANGE(0, 1);
        goto CompressionUnlimited;
#undef RANGE
        Compression :
        {
            unsigned char cValue;
            if (!Read(&cValue, sizeof(cValue))) return false;
            value = cValue * coef + min;
        }
        return true;
    CompressionUnlimited:
        {
            int iValue;
            if (!Get(iValue, NCTSmallSigned)) return false;
            value = (iValue + 127)*coef + min;
        }
        return true;
    case NCTVectorPosition:
    {
        int pos = m_pos;
        int next_pos = pos + 2;
        if (m_buf_size < next_pos)
            return false;

        uint16_t c = *(uint16_t*)&m_buf[pos];
        m_pos = next_pos;
        if (c) {
            int flt = (((c & 0x7C00) + 0x1C000) << 13) | ((c & 0x3FF | 8 * (c & 0x8000)) << 13);
            value = *(float*)&flt;
        }
        else
            value = 0.f;
    }
        return true;
    case NCTNone: case NCTDefault:
        return Read(&value, sizeof(float));
    default:
        //ErrF("Unsupported compression method %d", compression);
        return false;
    }
}

bool NetworkMessageRaw::GetNoCompression(char*& value)
{
    int lastPos = m_pos;

    while (lastPos < m_buf_size && m_buf[lastPos])
        lastPos++;

    if (lastPos >= m_buf_size) 
        return false;

    value = (char*)(m_buf + m_pos);

    m_pos = lastPos + 1;
    return true;
}


bool NetworkMessageRaw::Get(char*& value, NetworkCompressionType compression)
{
    switch (compression)
    {
    case NCTNone:
        return GetNoCompression(value);
    case NCTStringGeneric: //NCTDefault:
    {
        int id;
        bool ok = Get(id, NCTSmallUnsigned);
        if (!ok) return false;
        if (id > 0 && id - 1 < NetIdStringsSize)
        {
            value = (char*)NetIdStrings[id - 1];
            return true;
        }
        else
        {
            ok = GetNoCompression(value);
            return ok;
        }
    }
    case NCTStringMove:
    {
        int id;
        bool ok = Get(id, NCTSmallUnsigned);
        if (!ok) return false;
        if (id > 0 && id - 1 < NetIdMovesSize)
        {
            value = (char*)NetIdMoves[id - 1];
            return true;
        }
        else
        {
            ok = GetNoCompression(value);
            return ok;
        }
    }
    default:
        return false;
    }
}

bool NetworkMessageRaw::Get(LocalizedString &value, NetworkCompressionType compression)
{
    int type;
    if (!Get(type, NCTSmallUnsigned)) return false;
    value.m_type = (LocalizedString::Type)type;

    char* val;
    if (!Get(val, compression)) return false;

    if (val)
        value.m_id = std::string(val);
    else
        value.m_id = std::string("");

    return true;
}

bool NetworkMessageRaw::Get(Time &value, NetworkCompressionType compression)
{
    switch (compression)
    {
    case NCTNone: case NCTDefault:
    {
        int intVal;
        if (!Get(intVal, NCTNone)) return false;
        value = Time(intVal);
        return true;
    }
    default:
        return false;
    }
}

bool NetworkMessageRaw::Get(vec3 &value, NetworkCompressionType compression)
{
    switch (compression)
    {
    case NCTNone: case NCTDefault:
        if (!Get(value.v[0], NCTNone)) return false;
        if (!Get(value.v[1], NCTNone)) return false;
        if (!Get(value.v[2], NCTNone)) return false;
        return true;
    case NCTFloat0To1:
    {
        int c;
        if (!Get(c, NCTNone)) return false;
        GetVectorFrom32B(value, c);
        return true;
    }
    case NCTVectorPositionCamera:
    {
        int c;
        if (!Get(c, NCTNone)) return false;
        GetCameraPosFrom32B(value, c);
        return true;
    }
    case NCTVectorPosition:
    {
        if (!Get(value.v[0], NCTVectorPosition)) return false;
        if (!Get(value.v[1], NCTVectorPosition)) return false;
        if (!Get(value.v[2], NCTVectorPosition)) return false;
        return true;
    }
    default:
        //ErrF("Unsupported compression method %d", compression);
        return false;
    }
}

bool NetworkMessageRaw::Get(matrix3x3 &value, NetworkCompressionType compression)
{
    switch (compression)
    {
    case NCTNone: case NCTDefault:
    {
        for (int i = 0; i < 3; i++)
        {
            if (!Get(value.m[i][0], NCTNone)) return false;
            if (!Get(value.m[i][1], NCTNone)) return false;
            if (!Get(value.m[i][2], NCTNone)) return false;
        }
        return true;
    }
    case NCTMatrixOrientation:
    {
        EncodedMatrix3 encoded;
        Read(&encoded, sizeof(encoded));
        encoded.Decode(value);
        return true;
    }
    default:
        //ErrF("Unsupported compression method %d", compression);
        return false;
    }
}

bool NetworkMessageRaw::Get(NetworkId &value, NetworkCompressionType compression)
{
    switch (compression)
    {
    case NCTNone: case NCTDefault:
        if (!Get(value.creator, NCTSmallUnsigned)) return false;
        if (!Get(value.id, NCTSmallUnsigned)) return false;
        return true;
    default:
        //ErrF("Unsupported compression method %d", compression);
        return false;
    }
}

bool NetworkMessageRaw::Get(CreatorId &value, NetworkCompressionType compression)
{
    switch (compression)
    {
    case NCTSmallUnsigned: case NCTDefault:
    {
        int creator;
        if (!Get(creator, NCTSmallUnsigned)) return false;
        value.creatorId = creator;
    }
    return true;
    default:
        //ErrF("Unsupported compression method %d", compression);
        return false;
    }
}