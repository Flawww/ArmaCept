#pragma once
#include "pch.h"

class c_armastring
{
public:
    static c_armastring* create_string(const char* str);
    inline uint32_t& get_refs() { return m_refs; }
    inline uint64_t& get_len() { return m_len; }
    inline char* get_str() { return m_str; }

private:
    uint32_t m_refs;    // 0x0000
    char pad_0004[4];   // 0x0004
    uint64_t m_len;     // 0x0008
    char m_str[1];  // 0x0010
};