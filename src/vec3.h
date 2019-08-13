#pragma once
#include "pch.h"

#define H_2PI ( 6.28318530717958647692f )
#define H_PI  ( 3.14159265358979323846f )
#define H_PI2 ( 1.57079632679489661923f ) 
#define H_PI4 ( 0.78539816339744830961f ) 
#define H_SQRT2 ( 1.4142135624f )
#define H_INVSQRT2 ( 0.70710678119f )

#ifndef DEG2RAD
#define DEG2RAD( x  )  ( (float)(x) * (float)(H_PI / 180.f) )
#endif


inline int toInt(float fval) { return _mm_cvtss_si32(_mm_set_ss(fval)); }
inline int toLargeInt(float fval) { return _mm_cvtss_si32(_mm_set_ss(fval)); }

#define BAD_THIS(x, retn) 

void inline sin_cos(float radians, float* sine, float* cosine)
{
    *sine = sin(radians);
    *cosine = cos(radians);
}




/* 3D vector */
class vec3
{
public:
    // dimensions
    union {
        struct {
            float x, y, z;
        };

        float v[3];
    };


    vec3()
    {
        x = y = z = 0;
    }

    vec3(float X, float Y, float Z)
    {
        x = X; y = Y; z = Z;
    }

    inline void zero(float X = 0.f, float Y = 0.f, float Z = 0.f);

    bool operator==(const vec3& v) const;
    bool operator!=(const vec3& v) const;

    inline vec3& operator+=(const vec3& v);
    inline vec3& operator-=(const vec3& v);
    inline vec3& operator*=(const vec3& v);
    inline vec3& operator/=(const vec3& v);
    inline vec3& operator+=(float f);
    inline vec3& operator-=(float f);
    inline vec3& operator*=(float f);
    inline vec3& operator/=(float f);

    vec3& operator=(const vec3& v);
    vec3 operator+(const vec3& v) const;
    vec3 operator-(const vec3& v) const;
    vec3 operator*(const vec3& v) const;
    vec3 operator/(const vec3& v) const;
    vec3 operator*(float f) const;
    vec3 operator/(float f) const;

    inline float length() const;
    inline float length_sqr() const;
    inline float length2D() const;
    inline vec3 normalize();
    inline float normalize_in_place();
    inline float dist_to(const vec3& v) const;
    inline float dot(const vec3& v) const;
    inline vec3 cross_product(const vec3& v) const;
};

/* 3x3 Vector */
class matrix3x3
{
public:
    matrix3x3() { m_aside = m_up = m_dir = vec3(); }
    matrix3x3(vec3 init) { m_aside = m_up = m_dir = init; }

    inline matrix3x3& operator=(const matrix3x3& v) {
        m_aside = v.m_aside;
        m_up = v.m_up;
        m_dir = v.m_dir;
        return *this;
    }

    // dimensions
    union {
        struct {
            vec3 m_aside, m_up, m_dir;
        };

        float	m[3][3];
        struct
        {
            float _11, _12, _13;
            float	_21, _22, _23;
            float	_31, _32, _33;
        };
    };


    inline void set_yaw(float yaw);
    void set_direction_and_up(vec3 dir, vec3 up);
    void set_direction_and_aside(vec3 dir, vec3 aside);
    void set_up_and_aside(vec3 up, vec3 aside);
    void set_up_and_direction(vec3 up, vec3 dir);
};

/* 3x4 vector */
class matrix3x4
{
public:
    matrix3x4() { m_orientation.m_aside = m_orientation.m_dir = m_orientation.m_up = vec3(); m_position = vec3(); }

    vec3& get_position() { BAD_THIS(matrix3x4, vec3()); return m_position; }
    matrix3x3& get_orientation() { BAD_THIS(matrix3x4, matrix3x3()); return m_orientation; }

    inline vec3 rotate(vec3 op);
private:
    matrix3x3 m_orientation;
    vec3 m_position;
};

/* vec3 functions */
inline void vec3::zero(float X, float Y, float Z)
{
    x = X; y = Y; z = Z;
}

inline bool vec3::operator==(const vec3& v) const
{
    return (v.x == x) && (v.y == y) && (v.z == z);
}

inline bool vec3::operator!=(const vec3& v) const
{
    return (v.x != x) || (v.y != y) || (v.z != z);
}

inline vec3& vec3::operator+=(const vec3& v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

inline vec3& vec3::operator-=(const vec3& v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

inline  vec3& vec3::operator*=(const vec3& v)
{
    x *= v.x;
    y *= v.y;
    z *= v.z;
    return *this;
}

inline vec3& vec3::operator/=(const vec3& v)
{
    x /= v.x;
    y /= v.y;
    z /= v.z;
    return *this;
}

inline vec3& vec3::operator+=(float f)
{
    x += f;
    y += f;
    z += f;
    return *this;
}

inline vec3& vec3::operator-=(float f)
{
    x -= f;
    y -= f;
    z -= f;
    return *this;
}

inline vec3& vec3::operator*=(float f)
{
    x *= f;
    y *= f;
    z *= f;
    return *this;
}

inline vec3& vec3::operator/=(float f)
{
    x /= f;
    y /= f;
    z /= f;
    return *this;
}

inline vec3 vec3::operator+(const vec3& v) const
{
    vec3 res;
    res.x = x + v.x;
    res.y = y + v.y;
    res.z = z + v.z;
    return res;
}

inline vec3& vec3::operator=(const vec3& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
}

inline vec3 vec3::operator-(const vec3& v) const
{
    vec3 res;
    res.x = x - v.x;
    res.y = y - v.y;
    res.z = z - v.z;
    return res;
}

inline vec3 vec3::operator*(const vec3& v) const
{
    vec3 res;
    res.x = x * v.x;
    res.y = y * v.y;
    res.z = z * v.z;
    return res;
}

inline vec3 vec3::operator/(const vec3& v) const
{
    vec3 res;
    res.x = x / v.x;
    res.y = y / v.y;
    res.z = z / v.z;
    return res;
}

inline vec3 vec3::operator*(float f) const
{
    vec3 res;
    res.x = x * f;
    res.y = y * f;
    res.z = z * f;
    return res;
}

inline vec3 vec3::operator/(float f) const
{
    vec3 res;
    res.x = x / f;
    res.y = y / f;
    res.z = z / f;
    return res;
}

inline float vec3::length() const
{
    float sqsr = x * x + y * y + z * z;
    return sqrt(sqsr);
}

inline float vec3::length_sqr() const
{
    float sqsr = x * x + y * y + z * z;
    return sqsr;
}

inline float vec3::length2D() const
{
    float sqst = x * x + y * y;
    return sqrt(sqst);
}

inline vec3 vec3::normalize()
{
    vec3 vec;
    float len = this->length();

    if (len != 0)
    {
        vec.x = x / len;
        vec.y = y / len;
        vec.z = z / len;
    }
    else
    {
        vec.x = vec.y = 0.f;
        vec.z = 1.f;
    }

    return vec;
}

inline float vec3::normalize_in_place()
{
    float r = sqrt(x * x + y * y + z * z);

    float ir = 1.f / r;

    x *= ir;
    y *= ir;
    z *= ir;

    return r;
}

float vec3::dist_to(const vec3& v) const
{
    vec3 d;

    d.x = x - v.x;
    d.y = y - v.y;
    d.z = z - v.z;

    return d.length();
}

inline float vec3::dot(const vec3& v) const
{
    const vec3& a = *this;

    return (a.x * v.x + a.y * v.y + a.z * v.z);
}

inline vec3 vec3::cross_product(const vec3& b) const
{
    const vec3& a = *this;

    return vec3(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
}
void inline angle_vectors(const vec3& angles, vec3* forward, vec3* right, vec3* up)
{
    float sr, sp, sy, cr, cp, cy;

    sin_cos(DEG2RAD(angles.y), &sy, &cy);
    sin_cos(DEG2RAD(angles.x), &sp, &cp);
    sin_cos(DEG2RAD(angles.z), &sr, &cr);

    if (forward)
    {
        forward->x = cp * cy;
        forward->y = -sp; 
        forward->z = cp * sy;
    }

    if (right)
    {
        right->x = (-1 * sr * sp * cy + -1 * cr * -sy);
        right->y = -1 * sr * cp; 
        right->z = (-1 * sr * sp * sy + -1 * cr * cy);
    }

    if (up)
    {
        up->x = (cr * sp * cy + -sr * -sy);
        up->y = cr * cp; 
        up->z = (cr * sp * sy + -sr * cy);
    }
}


/* matrix3x3 functions */
inline void matrix3x3::set_yaw(float yaw)
{
    float s = sin(yaw);
    float c = cos(yaw);
    m_dir.x = c;
    m_dir.z = s;
}

inline void matrix3x3::set_direction_and_up(vec3 dir, vec3 up)
{
    m_dir = dir.normalize();

    float t = m_dir.dot(up);
    m_up = ((up - m_dir * t).normalize());
    m_aside = m_up.cross_product(m_dir);
}

inline void matrix3x3::set_direction_and_aside(vec3 dir, vec3 aside)
{
    m_dir = dir.normalize();

    float t = m_dir.dot(aside);
    m_aside = ((aside - m_dir * t).normalize());
    m_up = m_dir.cross_product(m_aside);
}

inline void matrix3x3::set_up_and_aside(vec3 up, vec3 aside)
{
    m_up = up.normalize();

    float t = m_up.dot(aside);
    m_aside = ((aside - m_up * t).normalize());
    m_dir = m_aside.cross_product(m_up);
}

inline void matrix3x3::set_up_and_direction(vec3 up, vec3 dir)
{
    m_up = up.normalize();

    float t = m_up.dot(dir);
    m_dir = ((dir - m_dir * t).normalize());
    m_aside = m_up.cross_product(m_dir);
}

/* matrix3x4 functions */

inline vec3 matrix3x4::rotate(vec3 op)
{
    vec3 out;
    auto a = this->m_orientation;

    out.x = a.m_aside.x * op.x + a.m_aside.y * op.y + a.m_aside.z * op.z;
    out.y = a.m_up.x * op.x + a.m_up.y * op.y + a.m_up.z * op.z;
    out.z = a.m_dir.x * op.x + a.m_dir.y * op.y + a.m_dir.z * op.z;


    return out;
}

struct EncodedMatrix3
{
    // single values encoded as -1 to +1 in 16b representation
    // encoded col 1 (direction up)
    short _01c, _11c;
    // encoded col 2 (direction)
    short _02c, _12c;
    char _21sign;
    char _22sign;

    //! encode 3x3 matrix
    inline void Encode(const matrix3x3 &m);
    //! decode 3x3 matrix
    inline void Decode(matrix3x3 &m) const;
    //! decode 3x3 part of 3x4 matrix
    inline void Decode(matrix3x4 &m) const;
    //@{ decode columns of 3x3 matrix - may be slightly inaccurate
    inline vec3 DirectionUp() const;
    inline vec3 Direction() const;
    //@}
};

static inline void saturate(int &a, int min, int max)
{
    if (a < min) a = min;
    if (a > max) a = max;
}

const int MaxAbsInt16 = 0x4000;
// we want to have 0.5 represented exactly
// we also want to keep some reserve range in case small overflow will occur

static inline int EncodeFloat16(float x)
{
    if (x < -1 || x > +1)
        return 0;

    int r = toInt(MaxAbsInt16*x);
    saturate(r, -MaxAbsInt16, +MaxAbsInt16);
    return r;
}

static inline float DecodeFloat16(short x)
{
    const float coef = 1.0 / MaxAbsInt16;
    return x * coef;
}


inline void EncodedMatrix3::Encode(const matrix3x3 &m)
{
    // the input is assumed to be an orthonormal matrix (no skew, no scale)
    // detect a special case - zero matrix
    if (m.m_dir.length_sqr() < 0.5f * 0.5f)
    {
        if (m.m_dir.length_sqr() > 1e-3f * 1e-3f || m.m_up.length_sqr() > 1e-3f * 1e-3f || m.m_aside.length_sqr() > 1e-3f * 1e-3f)
            return;

        _01c = 0;
        _11c = 0;
        _02c = 0;
        _12c = 0;
        _21sign = 0;
        _22sign = 0;
        return;
    }
     
    // encoding is quite simple
    _01c = EncodeFloat16(m.m[1][0]);
    _11c = EncodeFloat16(m.m[1][1]);
    // note: abs. value can be deduced from previous value, sign not
    _21sign = m.m[1][2] >= 0 ? 1 : -1;
    _02c = EncodeFloat16(m.m[2][0]);
    _12c = EncodeFloat16(m.m[2][1]);
    _22sign = m.m[2][2] >= 0 ? 1 : -1;
}

inline void EncodedMatrix3::Decode(matrix3x3 &m) const
{
    if (_21sign == 0)
    {
        if (_22sign || _01c || _11c || _02c || _12c)
            return;

        m.m_aside = m.m_dir = m.m_up = vec3();
        return;
    }
    // decoding is a little bit more tricky
    // decode col. 1 (up)
    vec3 up = vec3();

    up.v[0] = DecodeFloat16(_01c);
    up.v[1] = DecodeFloat16(_11c);
    float m21_sq = 1 - up.v[0] * up.v[0] - up.v[1] * up.v[1];
    up.v[2] = (m21_sq >= 0 ? sqrt(m21_sq) : 0)*_21sign;

    // decode col. 0 (direction)
    vec3 dir = vec3();
    dir.v[0] = DecodeFloat16(_02c);
    dir.v[1] = DecodeFloat16(_12c);
    float m22_sq = 1 - dir.v[0] * dir.v[0] - dir.v[1] * dir.v[1];
    dir.v[2] = (m22_sq >= 0 ? sqrt(m22_sq) : 0)*_22sign;

    m.m_dir = dir.normalize();
    vec3 t = up * m.m_dir;
    m.m_up = (up - m.m_dir*t).normalize();
    m.m_aside = m.m_up.cross_product(m.m_dir);
}

void EncodedMatrix3::Decode(matrix3x4 &m) const
{
    if (_21sign == 0)
    {
        if (_22sign || _01c || _11c || _02c || _12c)
            return;

        m.get_orientation().m_aside = m.get_orientation().m_up = m.get_orientation().m_dir = m.get_position() = vec3();
        return;
    }
    // decoding is a little bit more tricky
    // decode col. 1 (up)
    vec3 up = vec3();

    up.v[0] = DecodeFloat16(_01c);
    up.v[1] = DecodeFloat16(_11c);
    float m21_sq = 1 - up.v[0] * up.v[0] - up.v[1] * up.v[1];
    up.v[2] = (m21_sq >= 0 ? sqrt(m21_sq) : 0)*_21sign;

    // decode col. 0 (direction)
    vec3 dir = vec3();
    dir.v[0] = DecodeFloat16(_02c);
    dir.v[1] = DecodeFloat16(_12c);
    float m22_sq = 1 - dir.v[0] * dir.v[0] - dir.v[1] * dir.v[1];
    dir.v[2] = (m22_sq >= 0 ? sqrt(m22_sq) : 0)*_22sign;

    m.get_orientation().m_dir = dir.normalize();
    vec3 t = up * m.get_orientation().m_dir;
    m.get_orientation().m_up = (up - m.get_orientation().m_dir*t).normalize();
    m.get_orientation().m_aside = m.get_orientation().m_up.cross_product(m.get_orientation().m_dir);
}

/**
this function should be used for error calculation only.
To get real values whole matrix needs to be decodes
*/
inline vec3 EncodedMatrix3::DirectionUp() const
{
    float m01 = DecodeFloat16(_01c);
    float m11 = DecodeFloat16(_11c);

    float m21_sq = 1 - m01 * m01 - m11 * m11;
    float m21 = (m21_sq >= 0 ? sqrt(m21_sq) : 0)*_21sign;
    return vec3(m01, m11, m21);
}

/**
this function should be used for error calculation only.
To get real values whole matrix needs to be decodes
*/
inline vec3 EncodedMatrix3::Direction() const
{
    float m02 = DecodeFloat16(_02c);
    float m12 = DecodeFloat16(_12c);
    float m22_sq = 1 - m02 * m02 - m12 * m12;
    float m22 = (m22_sq >= 0 ? sqrt(m22_sq) : 0)*_22sign;
    return vec3(m02, m12, m22);
}