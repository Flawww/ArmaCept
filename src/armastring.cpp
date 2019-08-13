#include "pch.h"
#include "armastring.h"

c_armastring* c_armastring::create_string(const char* str)
{
    auto len = strlen(str) + 1; // include null terminator
    auto obj = (c_armastring*)new char[len + sizeof(c_armastring)];

    obj->m_refs = 1;
    obj->m_len = len;
    memcpy((char*)obj + 0x10, str, len);

    return obj;
}