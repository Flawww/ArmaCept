#pragma once
#include "armastring.h"
#include "vec3.h"
#include "netstrings.h"
#include "netmessages.h"

#define SAFETY_PAD_BYTES    0x30
#define MSG_HEADER_LEN      0x18

#define MSG_VIM_FLAG        0x8000
#define MSG_URGENT_FLAG     0x4000
#define MSG_ORDERED_FLAG    0x2000
#define MSG_FROM_BCAST_FLAG 0x1000
#define MSG_TO_BCAST_FLAG   0x0800
#define MSG_DELAY_FLAG      0x0400
#define MSG_INSTANT_FLAG    0x0200
#define MSG_BANDWIDTH_FLAG  0x0100
#define MSG_BUNCH_FLAG      0x0080
#define MSG_DUMMY_FLAG      0x0040
#define MSG_PART_FLAG       0x0020
#define MSG_CLOSING_FLAG    0x0010
#define MSG_VOICE_FLAG      0x0008
#define MSG_USER_FLAGS      0x0007
#define MSG_ALL_FLAGS       0xffff
#define MSG_MAX_LENGTH      0xffff
#define SHORT_ACK(flags)    (((flags)&(MSG_ORDERED_FLAG|MSG_DELAY_FLAG|MSG_BANDWIDTH_FLAG))!=0)

#define MSG_MAGIC_FLAG      0x0001
#define MAGIC_ACK_PLAYER        0xaaa51a7e
#define MAGIC_TERMINATE_SESSION 0x777814a1

struct ArmaMessageHeader {
    uint16_t length;
    uint16_t flags;
    uint32_t crc;
    uint32_t serial;
    uint32_t ack_origin;

    union {
        uint64_t ack_bitmask;

        struct {
            uint32_t control1;
            uint32_t control2;
        } c;
    };
};

struct CreatorId {
    int creatorId;
};

struct NetworkId {
    NetworkId(int c, int64_t i) { creator = c; id = i; }
    NetworkId() { creator = id = 0; }

    bool operator==(const NetworkId& other) const { return other.creator == creator && other.id == id; }

    int creator;
    int64_t id;
};

class LocalizedString {
public:
    enum Type {
        PlainText,
        Stringtable,
    };

    std::string m_id;
    Type m_type;
};


struct Time {
    Time() { m_time = 0; };
    Time(int t) { m_time = t; };

    int m_time;
};

struct XOnlineStat {
    char m_stat[16];
};

struct XNADDR {
    char m_addr[36];
};

struct Sentence {
    Sentence(std::string str, float p) { m_string = str; m_pause = p; }

    std::string m_string;
    float m_pause;
};

inline float floatMax(float a, float b) { return (a > b ? a : b); }
inline float floatMin(float a, float b) { return (a < b ? a : b); }
inline float floatMax(float a, float b, float c) { return floatMax(a, floatMax(b, c)); }
inline float floatMin(float a, float b, float c) { return floatMin(a, floatMin(b, c)); }

static const char* NetworkCompressionTypeNames[ ] = {
    "NCTNone",
    "NCTSmallUnsigned",
    "NCTDefault",
    "NCTStringMove",
    "NCTFloat0To1",
    "NCTFloat0To2",
    "NCTFloatM1ToP1",
    "NCTFloatMPIToPPI",
    "NCTFloatMostly0To1",
    "NCTFloatAngle",
    "NCTVectorPositionCamera",
    "NCTVectorPosition",
    "NCTMatrixOrientation",

};

//! Types of items compression
enum NetworkCompressionType : int32_t
{
    NCTNone,
    NCTSmallUnsigned, //!< special compression for unsigned int
    NCTSmallSigned, //!< special compression for signed int
    NCTDefault = NCTSmallSigned, //!< default compression for each data type
    NCTStringGeneric = NCTDefault, //!< generic string table
    NCTStringMove, //!< string table for moves
    NCTFloat0To1, //!< float 0 to 1 (8b), vector with size 1 or less (32b)
    NCTFloat0To2, //!< float 0 to 2 (8b)
    NCTFloatM1ToP1, //!< float -1 to 1 (8b)
    NCTFloatMPIToPPI, //!< float -pi to pi (8b)
    NCTFloatMostly0To1, //!< float, mostly 0 to 1 (8b-40b)
    NCTFloatAngle, //!< float, mostly -pi to pi (8b-40b)
    /** camera position - used to control error calculation (1m..10m precision)
    10 m precision required across range:
    x,z from 0..12800, y from 0..1500
    */
    NCTVectorPositionCamera,
    /** generic position - 1 cm precision required across range:
    x,z from 0..12800, y from 0..1500
    */
    NCTVectorPosition,
    //! matrix orientation - matrix is assumed orthogonal
    NCTMatrixOrientation,
};

template <class Type>
struct GetNDType
{
    //enum {value=-1};
};

#define REGISTER_NDT(type,name) \
  template <> struct GetNDType< type > {enum {value=name};};

static const char* NetworkDataTypeNames[ ] = {
    "NDTBool",
    "NDTInteger",
    "NDTInt64",
    "NDTFloat",
    "NDTString",
    "NDTRawData",
    "NDTTime",
    "NDTVector",
    "NDTMatrix",
    "NDTBoolArray", // 9
    "NDTIntArray",
    "NDTFloatArray",
    "NDTStringArray",
    "NDTStringBArray",
    "NDTSentence",
    "NDTObject", // 15
    "NDTObjectArray",
    "NDTObjectSRef",
    "NDTRef",
    "NDTRefArray",
    "NDTData", // 20
    "NDTXUIDArray",
    "NDTXNADDR",
    "NDTXOnlineStatArray",
    "NDTLocalizedString",
    "NDTLocalizedStringArray", // 25
};

#define NETWORK_DATA_TYPES(XX) \
      XX(bool,Bool,"Boolean value. Transferred as single byte.") \
      XX(int,Integer,"4 bytes long integer value.") \
      XX(int64_t,Int64,"8 bytes long integer value.") \
      XX(float,Float,"4 bytes long real value.") \
      XX(RString,String,"Null terminated string of bytes, including the trailing zero.") \
      XX(AutoArray<char>,RawData,"Array of bytes. Integer for size, then size bytes of content.") \
      XX(Time,Time,"4 bytes long integer value (time in ms).") \
      XX(vec3,Vector,"Vector of 3 floats.") \
      XX(matrix3x3,Matrix,"Matrix of 3 x 3 floats") \
      XX(AutoArray<bool>,BoolArray,"Array of booleans. Integer for size, then size booleans of content.") \
      XX(AutoArray<int>,IntArray,"Array of integers. Integer for size, then size integers of content.") \
      XX(AutoArray<float>,FloatArray,"Array of floats. Integer for size, then size floats of content.") \
      XX(AutoArray<RString>,StringArray,"Array of strings. Integer for size, then size strings of content.") \
      XX(AutoArray<RStringB>,StringBArray,"Array of strings. Integer for size, then size strings of content.") \
      XX(RadioSentence,Sentence,"Radio message. Integer for number of words, then pairs: string id of word, float pause after word.") \
      XX(NetworkMessage,Object,"Nested message (encoded as whole new message)") \
      XX(AutoArray<NetworkMessage>,ObjectArray,"Array of nested messages. Integer for size, then size of messages.") \
      XX(NoType<3>,ObjectSRef,"Nested message reference (encoded as whole new message)") \
      XX(NetworkId,Ref,"Reference to object. Pair of integer values: id of client where object was created, id of object unique on this client.") \
      XX(AutoArray<NetworkId>,RefArray,"Array of references. Integer for size, then size of references.") \
      XX(NoType<2>,Data,"<notused/> Generic data used for dynamic definition of formats.") \
      XX(AutoArray<XUID>,XUIDArray,"Array of Xbox user ids. Integer for size, then size of ids.") \
      XX(XNADDR,XNADDR,"Xbox network address.") \
      XX(AutoArray<XONLINE_STAT>,XOnlineStatArray,"List of Xbox Live statistics entries.") \
      XX(LocalizedString,LocalizedString,"Client-side localized string.") \
      XX(AutoArray<LocalizedString>,LocalizedStringArray,"Array of client-side localized strings.") \



#define NDT_DEFINE_ENUM(type,name,description) NDT##name,
#define NDT_REGISTER_TYPE(type,name,description) REGISTER_NDT(type,NDT##name)

//! Types of message items
enum NetworkDataType : int32_t
{
    NETWORK_DATA_TYPES(NDT_DEFINE_ENUM)
};


struct NetworkFormatSpecs {
    NetworkDataType m_type;
    NetworkCompressionType m_compression;
    void* m_def_value;
};

struct NetworkMessageFormatItem {
    NetworkMessageFormatItem() { m_name = nullptr; m_specs.m_def_value = nullptr; };
    void init(const char* name, NetworkDataType type, NetworkCompressionType compression, void* def_val, int def_val_size, int offset) {
        // make a copy of the string because I'm afraid the strings I made for the ctor are allocated on the stack, i dont remember
        memcpy(m_name, name, strlen(name) + 1);

        m_offset = offset;
        m_specs.m_type = type;
        m_specs.m_compression = compression;

        // default value
        if (def_val_size && m_specs.m_def_value) {
            memcpy(m_specs.m_def_value, def_val, def_val_size);
        }
    }

    ~NetworkMessageFormatItem() { };

    char* m_name;
    NetworkFormatSpecs m_specs;
    int32_t m_offset;
    char pad_001C[4];
};

class NetworkMessageFormat {
public:
    NetworkMessageFormat() { m_items.clear(); };

    std::vector<NetworkMessageFormatItem> m_items;
    int m_struct_size;
};

class NetMessage {
public:
    NetMessage(unsigned char* buf, int size, ArmaMessageHeader* h) {
        m_data = new unsigned char[size];
        memcpy(m_data, buf, size);
        m_pos = 0;
        m_size = size;
        hdr = *h;
    }

    ~NetMessage() {
        delete[ ] m_data;
    }

    int m_size;
    ArmaMessageHeader hdr;
    unsigned char* m_data;
    int m_pos;
};

class NetworkMessageRaw {
public:

    NetworkMessageRaw(unsigned char* buf, int size) { 
        m_buf = new unsigned char[2048 + SAFETY_PAD_BYTES];
        memcpy(m_buf, buf, size + MSG_HEADER_LEN);
        m_buf += MSG_HEADER_LEN;
        m_pos = 0;  m_buf_size = 2048; m_size = size; m_message_count = 0; m_write_to_packet = false; m_saved_pos = 0; 
    };
    ~NetworkMessageRaw() { delete[ ] (m_buf - MSG_HEADER_LEN); }

    void ExpandBuffer() {
        m_buf_size += 2048;
        auto tmp = new unsigned char[m_buf_size + SAFETY_PAD_BYTES];
        memcpy(tmp, m_buf - MSG_HEADER_LEN, m_size + MSG_HEADER_LEN);
        delete[ ] (m_buf - MSG_HEADER_LEN);
        m_buf = tmp;
        m_buf += MSG_HEADER_LEN;
    }

    template <class IntType>
    void PutSmallUnsigned(IntType value);

    void Put(bool value, NetworkCompressionType compression);
    void Put(char value, NetworkCompressionType compression);
    void Put(int value, NetworkCompressionType compression);
    void Put(int64_t &value, NetworkCompressionType compression);
    void Put(float value, NetworkCompressionType compression);
    void Put(char* value, NetworkCompressionType compression);
    void Put(const LocalizedString &value, NetworkCompressionType compression);
    void Put(Time value, NetworkCompressionType compression);
    void Put(vec3& value, NetworkCompressionType compression);
    void Put(matrix3x3& value, NetworkCompressionType compression);
    void Put(NetworkId &value, NetworkCompressionType compression);
    void Put(CreatorId &value, NetworkCompressionType compression);
    void* PutRaw(int size);

    //@}

    //@{
    //! Read single value from buffer
    /*!
    \param value reference to variable read into
    \param compression compression algorithm
    \return true if value was read, otherwise false
    */
    bool GetNoCompression(char*& value);

    template <class IntType>
    bool GetSmallUnsigned(IntType &value);

    bool Get(bool &value, NetworkCompressionType compression);
    bool Get(char &value, NetworkCompressionType compression);
    bool Get(int &value, NetworkCompressionType compression);
    bool Get(int64_t &value, NetworkCompressionType compression);
    bool Get(float &value, NetworkCompressionType compression);
    bool Get(char*& value, NetworkCompressionType compression);
    bool Get(LocalizedString &value, NetworkCompressionType compression);
    bool Get(Time &value, NetworkCompressionType compression);
    bool Get(vec3 &value, NetworkCompressionType compression);
    bool Get(matrix3x3 &value, NetworkCompressionType compression);
    bool Get(NetworkId &value, NetworkCompressionType compression);
    bool Get(CreatorId &value, NetworkCompressionType compression);
    void* GetRaw(int size);
    //@}

    unsigned char* m_buf;
    int m_buf_size;
    int m_size;
    int m_pos;
    int m_message_count;
    int m_saved_pos;
    bool m_write_to_packet;


protected:
    //! Write raw data to buffer
    /*!
    \param buffer raw data
    \param size raw data size
    */
    void Write(const void *buffer, int size)
    {
        int minSize = m_pos + size;

        while (m_buf_size < minSize) // resize the buffer
            ExpandBuffer();

        memcpy(m_buf + m_pos, buffer, size);
        m_pos += size;
        m_size += size;
    }
    //! Read raw data from buffer
    /*!
    \param buffer where read raw data
    \param size size of data to read
    \return true if data available in buffer, otherwise false
    */
    bool Read(void *buffer, int size)
    {
        int minSize = m_pos + size;

        if (m_buf_size < minSize) 
            return false;
        memcpy(buffer, m_buf + m_pos, size);
        
        m_pos += size;
        return true;
    }
};