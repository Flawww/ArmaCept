#pragma once
#include "pch.h"

#define __PAIR__(high, low) (((uint32_t)(high)<<sizeof(high)*8) | low)

static void scramble_header_part2(uint8_t* encryption_table, uint32_t encryption_table_size, uint8_t* decrypt_table_out, uint32_t* dword_out1, uint32_t* dword_out2, uint32_t loop_count2) {
    uint8_t v33[1024];

    int v10 = 2;
    uint8_t* v11 = decrypt_table_out + 8;
    int64_t v12 = 256;

    int c = 0;
    do {
        v11 += 16;
        int v14 = encryption_table[(v10 - 2) % encryption_table_size];
        *((uint32_t*)v11 - 6) = v10 - 2;
        *(uint32_t*)&v33[c * 16] = v14;

        int v15 = encryption_table[(v10 - 1) % encryption_table_size];
        *((uint32_t*)v11 - 5) = v10 - 1;
        int v16 = v10 + 1;
        *(uint32_t*)&v33[4 + (c * 16)] = v15;

        int v17 = encryption_table[v10 % encryption_table_size];
        *((uint32_t*)v11 - 4) = v10;
        int v18 = v10 + 1;
        int v19 = (v10 + 1) >> 31;
        v10 += 4;
        *(uint32_t*)&v33[8 + (c * 16)] = v17;

        int v20 = encryption_table[__PAIR__(v19, v18) % encryption_table_size];
        *((uint32_t*)v11 - 3) = v16;
        *(uint32_t*)&v33[12 + (c * 16)] = v20;

        c++;
    } while (v10 - 2 < 256);

    c = 0;
    uint8_t v22 = 0;
    uint8_t* decrypt_table_copy = decrypt_table_out;
    do {
        int v23 = *(uint32_t*)decrypt_table_copy;
        int v24 = *(uint32_t*)&v33[c * 4];

        decrypt_table_copy += 4;
        v22 = (uint8_t)(v22 + v23 + v24);
        *((uint32_t*)decrypt_table_copy - 1) = *(uint32_t*)&decrypt_table_out[4 * v22];
        *(uint32_t*)&decrypt_table_out[4 * v22] = v23;

        --v12;
        c++;
    } while (v12);

    *dword_out1 = 0;
    *dword_out2 = 0;
    if (loop_count2 > 0) {
        do {
            uint8_t v27 = (uint8_t)(*dword_out1 + 1);
            *dword_out1 = v27;
            uint8_t v28 = (uint8_t)(*(uint8_t*)dword_out2 + *(uint32_t*)&decrypt_table_out[4 * v27]);
            *dword_out2 = v28;

            uint8_t* v29 = &decrypt_table_out[4 * v28];
            int v30 = *dword_out1;
            uint32_t v31 = *(uint32_t*)&decrypt_table_out[4 * v30];

            uint8_t* v32 = &decrypt_table_out[4 * v30];
            uint32_t v35 = *(uint32_t*)v29;

            *(uint32_t*)v32 = v35;
            *(uint32_t*)v29 = v31;

            --loop_count2;
        } while (loop_count2);
    }
}


static void scramble_header_part1(uint8_t* buf, int loop_count, uint8_t* encryption_table, uint32_t encryption_table_size, uint32_t loop_count2) {
    uint32_t dword_out1 = 0;
    uint8_t decrypt_table_out[1032];
    uint32_t dword_out2 = 0;

    scramble_header_part2(encryption_table, encryption_table_size, decrypt_table_out, &dword_out1, &dword_out2, loop_count2);

    if (loop_count > 0) {
        dword_out1 = LOBYTE(dword_out1);
        dword_out2 = LOBYTE(dword_out2);

        do {
            dword_out1 = (uint8_t)(dword_out1 + 1);
            ++buf;
            uint32_t v11 = *(uint32_t*)&decrypt_table_out[4 * dword_out1];
            uint8_t v12 = dword_out2 + v11;
            uint8_t* v13 = &decrypt_table_out[4 * dword_out1];
            dword_out2 = v12;
            *(uint32_t*)v13 = *(uint32_t*)&decrypt_table_out[4 * v12];
            *(uint32_t*)&decrypt_table_out[4 * v12] = v11;
            uint8_t v14 = (uint8_t)(v11 + *(uint32_t*)v13);
            *(buf - 1) ^= decrypt_table_out[4 * v14];

            --loop_count;
        } while (loop_count);
    }
}

static void scramble_message_contents(uint8_t* buf, unsigned char* key_table) {
    int v5 = 24;
    int v6 = *((uint32_t*)buf + 2) ^ ((*((uint32_t*)buf + 2) ^ 0x3D0000) >> 16);
    int16_t v7 = (0xEB2D * (9 * v6 ^ (9 * v6 >> 4)) ^ (0x27D4EB2D * (9 * v6 ^ (9 * v6 >> 4)) >> 15)) & 0x7FFF;

    if (*(uint16_t*)buf >= 0x18u && *(uint16_t*)buf <= 2048) {
        uint8_t* v8 = buf + 24;
        do {
            *(++v8 - 1) ^= key_table[(uint16_t)v5++ + v7 & 0x7FF];
        } while (v5 <= *(uint16_t*)buf);
    }
}