#pragma once

static unsigned char server_iv[ ] = { 0x69, 0xe2, 0x4b, 0x84,
0x2d, 0x86, 0xcf, 0x48,
0x91, 0x8a, 0x13, 0xcc,
0x95, 0x0e, 0x97, 0xb0, };
static unsigned char server_xorkey[ ] = { 0x7d, 0x44, 0x0b, 0xd2,
0x99, 0x60, 0x27, 0xee,
0xb5, 0x7c, 0x43, 0x0a,
0xd1, 0x98, 0x5f, 0x26 };
static unsigned char server_xorhash[ ] = { 0x00, 0x32, 0x5c, 0x7a, 0x30, 0xca, 0x3c, 0x22, 0xc0, 0x02, 0x7c, 0x6a, 0xb0, 0xda, 0x1c, 0x52, };

static unsigned char client_iv[ ] = { 0x9b, 0x24, 0xad, 0x36,
0xbf, 0x48, 0xd1, 0x5a,
0xe3, 0x6c, 0xf5, 0x7e,
0x07, 0x90, 0x19, 0xa2, };
static unsigned char client_xorkey[ ] = { 0x75, 0x3c, 0x03, 0xca,
0x91, 0x58, 0x1f, 0xe6,
0xad, 0x74, 0x3b, 0x02,
0xc9, 0x90, 0x57, 0x1e, };
static unsigned char client_xorhash[ ] = { 0x00, 0x32, 0x5c, 0x7a, 0x30, 0xca, 0x3c, 0x22, 0xc0, 0x02, 0x7c, 0x6a, 0xb0, 0xda, 0x1c, 0x52 };

static unsigned char key_table_1[ ] = {
0x4c, 0xa6, 0xd3, 0xe9,
0xf4, 0xfa, 0xfd, 0x7e,
0xbf, 0x5f, 0x2f, 0x97,
0xcb, 0x65, 0x32, 0x19,
0x8c, 0x46, 0xa3, 0x51,
0x28, 0x14, 0x8a, 0xc5,
0x62, 0x31, 0x98, 0x4c,
0xa6, 0x53, 0xa9, 0xd4,
0x6a, 0xb5, 0x5a, 0xad,
0x56, 0x2b, 0x95, 0xca,
0xe5, 0x72, 0xb9, 0xdc,
0x6e, 0xb7, 0xdb, 0x6d,
0xb6, 0xdb, 0xed, 0xf6,
0x7b, 0xbd, 0xde, 0x6f,
0x37, 0x1b, 0x0d, 0x06,
0x03, 0x81, 0x40, 0x20,
0x10, 0x88, 0x44, 0xa2,
0xd1, 0xe8, 0xf4, 0x7a,
0xbd, 0x5e, 0xaf, 0xd7,
0xeb, 0xf5, 0x7a, 0x3d,
0x1e, 0x0f, 0x07, 0x03,
0x01, 0x80, 0xc0, 0x60,
0x30, 0x18, 0x8c, 0x46,
0xa3, 0xd1, 0x68, 0x34,
0x9a, 0xcd, 0xe6, 0x73,
0xb9, 0x5c, 0xae, 0x57,
0x2b, 0x95, 0xca, 0x65,
0x32, 0x99, 0x4c, 0xa6,
0x53, 0xa9, 0x54, 0xaa,
0xd5, 0xea, 0x75, 0x3a,
0x1d, 0x8e, 0xc7, 0xe3,
0x71, 0x38, 0x1c, 0x8e,
0x47, 0xa3, 0x51, 0x28,
0x14, 0x0a, 0x05, 0x02,
0x01, 0x00, 0x00, 0x80,
0x40, 0xa0, 0xd0, 0x68,
0x34, 0x9a, 0x4d, 0x26,
0x13, 0x09, 0x84, 0x42,
0x21, 0x10, 0x88, 0xc4,
0x62, 0xb1, 0x58, 0xac,
0x56, 0x2b, 0x15, 0x8a,
0xc5, 0xe2, 0x71, 0xb8,
0xdc, 0xee, 0xf7, 0x7b,
0xbd, 0x5e, 0xaf, 0x57,
0x2b, 0x15, 0x8a, 0xc5,
0xe2, 0x71, 0x38, 0x1c,
0x0e, 0x87, 0x43, 0xa1,
0x50, 0xa8, 0x54, 0x2a,
0x15, 0x0a, 0x05, 0x82,
0x41, 0x20, 0x10, 0x88,
0x44, 0x22, 0x91, 0x48,
0x24, 0x92, 0xc9, 0x64,
0xb2, 0xd9, 0xec, 0xf6,
0xfb, 0x7d, 0x3e, 0x1f,
0x0f, 0x87, 0x43, 0xa1,
0x50, 0xa8, 0x54, 0xaa,
0xd5, 0xea, 0x75, 0xba,
0x5d, 0x2e, 0x17, 0x8b,
0x45, 0x22, 0x11, 0x88,
0x44, 0xa2, 0xd1, 0x68,
0x34, 0x1a, 0x8d, 0xc6,
0xe3, 0xf1, 0xf8, 0xfc,
0x7e, 0x3f, 0x9f, 0xcf,
0xe7, 0x73, 0x39, 0x1c,
0x8e, 0xc7, 0x63, 0xb1,
0xd8, 0xec, 0x76, 0xbb,
0x5d, 0x2e, 0x17, 0x0b,
0x05, 0x82, 0xc1, 0x60,
0xb0, 0xd8, 0xec, 0x76,
0x3b, 0x1d, 0x0e, 0x87,
0xc3, 0xe1, 0xf0, 0xf8,
0x7c, 0xbe, 0xdf, 0x6f,
0x37, 0x9b, 0x4d, 0xa6,
0x53, 0xa9, 0xd4, 0xea,
0x75, 0xba, 0x5d, 0xae,
0x57, 0xab, 0xd5, 0xea,
0x75, 0xba, 0x5d, 0xae,
0xd7, 0x6b, 0xb5, 0x5a,
0x2d, 0x96, 0x4b, 0xa5,
0xd2, 0x69, 0xb4, 0xda,
0xed, 0x76, 0xbb, 0x5d,
0xae, 0x57, 0xab, 0x55,
0xaa, 0x55, 0x2a, 0x95,
0xca, 0xe5, 0x72, 0xb9,
0x5c, 0x2e, 0x17, 0x0b,
0x05, 0x82, 0xc1, 0xe0,
0xf0, 0x78, 0xbc, 0x5e,
0x2f, 0x17, 0x0b, 0x85,
0xc2, 0xe1, 0x70, 0xb8,
0x5c, 0x2e, 0x17, 0x0b,
0x05, 0x02, 0x01, 0x80,
0x40, 0x20, 0x90, 0x48,
0x24, 0x12, 0x09, 0x84,
0x42, 0x21, 0x90, 0x48,
0xa4, 0x52, 0x29, 0x14,
0x8a, 0x45, 0x22, 0x11,
0x88, 0x44, 0x22, 0x91,
0xc8, 0xe4, 0x72, 0xb9,
0xdc, 0xee, 0xf7, 0xfb,
0xfd, 0xfe, 0x7f, 0xbf,
0xdf, 0x6f, 0xb7, 0xdb,
0xed, 0x76, 0xbb, 0x5d,
0x2e, 0x97, 0x4b, 0xa5,
0x52, 0x29, 0x14, 0x8a,
0xc5, 0xe2, 0x71, 0x38,
0x9c, 0x4e, 0xa7, 0xd3,
0xe9, 0x74, 0xba, 0x5d,
0x2e, 0x17, 0x0b, 0x85,
0xc2, 0xe1, 0x70, 0x38,
0x9c, 0xce, 0x67, 0x33,
0x19, 0x0c, 0x06, 0x83,
0x41, 0x20, 0x10, 0x88,
0x44, 0x22, 0x11, 0x88,
0xc4, 0xe2, 0xf1, 0x78,
0xbc, 0xde, 0xef, 0xf7,
0xfb, 0xfd, 0xfe, 0x7f,
0x3f, 0x9f, 0x4f, 0x27,
0x93, 0xc9, 0x64, 0xb2,
0x59, 0x2c, 0x96, 0xcb,
0xe5, 0xf2, 0x79, 0x3c,
0x9e, 0x4f, 0xa7, 0xd3,
0x69, 0xb4, 0xda, 0xed,
0xf6, 0x7b, 0xbd, 0xde,
0xef, 0xf7, 0x7b, 0xbd,
0x5e, 0x2f, 0x97, 0x4b,
0x25, 0x12, 0x89, 0xc4,
0x62, 0x31, 0x18, 0x0c,
0x06, 0x83, 0x41, 0x20,
0x90, 0xc8, 0x64, 0xb2,
0x59, 0xac, 0xd6, 0xeb,
0xf5, 0x7a, 0xbd, 0x5e,
0xaf, 0x57, 0xab, 0xd5,
0xea, 0xf5, 0x7a, 0x3d,
0x1e, 0x0f, 0x07, 0x83,
0x41, 0x20, 0x90, 0x48,
0x24, 0x12, 0x89, 0x44,
0xa2, 0xd1, 0xe8, 0x74,
0xba, 0x5d, 0x2e, 0x17,
0x8b, 0xc5, 0xe2, 0x71,
0x38, 0x1c, 0x8e, 0xc7,
0x63, 0x31, 0x18, 0x8c,
0x46, 0x23, 0x11, 0x08,
0x04, 0x02, 0x01, 0x80,
0x40, 0xa0, 0x50, 0xa8,
0xd4, 0xea, 0x75, 0xba,
0x5d, 0x2e, 0x97, 0x4b,
0x25, 0x92, 0x49, 0xa4,
0x52, 0xa9, 0xd4, 0x6a,
0x35, 0x9a, 0x4d, 0x26,
0x13, 0x09, 0x84, 0xc2,
0x61, 0xb0, 0xd8, 0xec,
0x76, 0xbb, 0x5d, 0xae,
0x57, 0x2b, 0x95, 0xca,
0xe5, 0x72, 0xb9, 0xdc,
0xee, 0x77, 0xbb, 0x5d,
0xae, 0xd7, 0xeb, 0xf5,
0x7a, 0xbd, 0xde, 0xef,
0xf7, 0xfb, 0x7d, 0xbe,
0xdf, 0x6f, 0x37, 0x1b,
0x0d, 0x86, 0xc3, 0x61,
0xb0, 0xd8, 0x6c, 0xb6,
0x5b, 0xad, 0xd6, 0xeb,
0x75, 0xba, 0xdd, 0xee,
0x77, 0x3b, 0x1d, 0x8e,
0xc7, 0xe3, 0x71, 0xb8,
0xdc, 0xee, 0xf7, 0xfb,
0x7d, 0x3e, 0x1f, 0x0f,
0x07, 0x03, 0x81, 0xc0,
0xe0, 0x70, 0xb8, 0xdc,
0xee, 0x77, 0xbb, 0xdd,
0x6e, 0xb7, 0xdb, 0x6d,
0x36, 0x9b, 0xcd, 0xe6,
0xf3, 0xf9, 0xfc, 0x7e,
0x3f, 0x1f, 0x0f, 0x87,
0x43, 0x21, 0x90, 0xc8,
0xe4, 0x72, 0xb9, 0xdc,
0x6e, 0xb7, 0x5b, 0x2d,
0x96, 0x4b, 0xa5, 0xd2,
0x69, 0xb4, 0xda, 0x6d,
0x36, 0x9b, 0x4d, 0xa6,
0x53, 0xa9, 0x54, 0xaa,
0x55, 0x2a, 0x15, 0x8a,
0x45, 0xa2, 0xd1, 0xe8,
0x74, 0x3a, 0x1d, 0x0e,
0x87, 0x43, 0xa1, 0xd0,
0x68, 0x34, 0x1a, 0x8d,
0x46, 0x23, 0x91, 0x48,
0x24, 0x12, 0x09, 0x84,
0xc2, 0xe1, 0x70, 0xb8,
0xdc, 0x6e, 0x37, 0x1b,
0x8d, 0x46, 0x23, 0x91,
0x48, 0x24, 0x92, 0xc9,
0x64, 0xb2, 0xd9, 0x6c,
0xb6, 0xdb, 0x6d, 0x36,
0x1b, 0x0d, 0x86, 0x43,
0xa1, 0x50, 0x28, 0x14,
0x0a, 0x05, 0x82, 0xc1,
0xe0, 0x70, 0x38, 0x1c,
0x8e, 0xc7, 0x63, 0x31,
0x98, 0xcc, 0xe6, 0x73,
0x39, 0x1c, 0x0e, 0x07,
0x03, 0x81, 0x40, 0x20,
0x10, 0x88, 0x44, 0x22,
0x11, 0x88, 0xc4, 0x62,
0xb1, 0x58, 0xac, 0xd6,
0xeb, 0xf5, 0xfa, 0xfd,
0xfe, 0x7f, 0xbf, 0xdf,
0xef, 0xf7, 0xfb, 0x7d,
0x3e, 0x9f, 0x4f, 0x27,
0x93, 0x49, 0xa4, 0xd2,
0x69, 0xb4, 0xda, 0xed,
0xf6, 0xfb, 0x7d, 0x3e,
0x1f, 0x8f, 0x47, 0xa3,
0x51, 0x28, 0x94, 0x4a,
0xa5, 0xd2, 0xe9, 0x74,
0x3a, 0x9d, 0x4e, 0xa7,
0xd3, 0xe9, 0x74, 0xba,
0x5d, 0x2e, 0x97, 0x4b,
0xa5, 0xd2, 0xe9, 0x74,
0x3a, 0x9d, 0xce, 0x67,
0x33, 0x99, 0x4c, 0xa6,
0x53, 0x29, 0x94, 0x4a,
0xa5, 0x52, 0x29, 0x14,
0x0a, 0x85, 0xc2, 0xe1,
0xf0, 0xf8, 0x7c, 0xbe,
0xdf, 0xef, 0x77, 0x3b,
0x1d, 0x8e, 0x47, 0xa3,
0xd1, 0xe8, 0x74, 0xba,
0xdd, 0xee, 0x77, 0x3b,
0x1d, 0x8e, 0x47, 0x23,
0x11, 0x88, 0xc4, 0xe2,
0xf1, 0xf8, 0x7c, 0x3e,
0x1f, 0x8f, 0xc7, 0xe3,
0xf1, 0x78, 0x3c, 0x9e,
0xcf, 0xe7, 0xf3, 0x79,
0x3c, 0x1e, 0x0f, 0x87,
0x43, 0xa1, 0xd0, 0x68,
0xb4, 0xda, 0x6d, 0xb6,
0x5b, 0xad, 0x56, 0x2b,
0x15, 0x0a, 0x85, 0x42,
0x21, 0x10, 0x08, 0x84,
0xc2, 0x61, 0xb0, 0x58,
0x2c, 0x16, 0x0b, 0x85,
0xc2, 0x61, 0x30, 0x98,
0xcc, 0xe6, 0xf3, 0x79,
0x3c, 0x1e, 0x0f, 0x87,
0xc3, 0x61, 0x30, 0x18,
0x8c, 0xc6, 0x63, 0xb1,
0x58, 0xac, 0x56, 0xab,
0xd5, 0x6a, 0xb5, 0x5a,
0x2d, 0x96, 0xcb, 0xe5,
0xf2, 0x79, 0x3c, 0x9e,
0xcf, 0x67, 0xb3, 0x59,
0xac, 0xd6, 0xeb, 0xf5,
0x7a, 0xbd, 0xde, 0x6f,
0x37, 0x9b, 0xcd, 0xe6,
0xf3, 0x79, 0x3c, 0x1e,
0x0f, 0x87, 0x43, 0xa1,
0x50, 0x28, 0x94, 0xca,
0x65, 0xb2, 0x59, 0xac,
0x56, 0x2b, 0x15, 0x8a,
0xc5, 0xe2, 0xf1, 0x78,
0xbc, 0xde, 0xef, 0x77,
0xbb, 0x5d, 0xae, 0x57,
0x2b, 0x95, 0x4a, 0x25,
0x92, 0xc9, 0xe4, 0xf2,
0x79, 0xbc, 0x5e, 0xaf,
0xd7, 0x6b, 0x35, 0x1a,
0x8d, 0xc6, 0xe3, 0x71,
0x38, 0x1c, 0x8e, 0xc7,
0xe3, 0xf1, 0xf8, 0x7c,
0x3e, 0x1f, 0x0f, 0x07,
0x03, 0x01, 0x00, 0x00,
0x80, 0xc0, 0xe0, 0xf0,
0x78, 0xbc, 0xde, 0x6f,
0x37, 0x1b, 0x0d, 0x86,
0xc3, 0x61, 0xb0, 0x58,
0x2c, 0x96, 0x4b, 0xa5,
0xd2, 0xe9, 0x74, 0xba,
0xdd, 0xee, 0xf7, 0x7b,
0xbd, 0x5e, 0xaf, 0x57,
0x2b, 0x95, 0xca, 0xe5,
0xf2, 0x79, 0x3c, 0x1e,
0x0f, 0x87, 0x43, 0xa1,
0xd0, 0xe8, 0xf4, 0xfa,
0x7d, 0xbe, 0x5f, 0xaf,
0x57, 0x2b, 0x15, 0x0a,
0x05, 0x02, 0x81, 0xc0,
0x60, 0x30, 0x98, 0x4c,
0xa6, 0x53, 0x29, 0x94,
0x4a, 0xa5, 0xd2, 0xe9,
0x74, 0x3a, 0x9d, 0xce,
0xe7, 0xf3, 0xf9, 0x7c,
0xbe, 0x5f, 0x2f, 0x97,
0x4b, 0xa5, 0x52, 0xa9,
0xd4, 0xea, 0xf5, 0x7a,
0x3d, 0x1e, 0x8f, 0x47,
0xa3, 0xd1, 0x68, 0xb4,
0x5a, 0x2d, 0x16, 0x8b,
0x45, 0x22, 0x91, 0x48,
0x24, 0x92, 0x49, 0xa4,
0x52, 0x29, 0x94, 0xca,
0xe5, 0x72, 0x39, 0x1c,
0x0e, 0x07, 0x83, 0xc1,
0xe0, 0xf0, 0xf8, 0xfc,
0x7e, 0x3f, 0x1f, 0x8f,
0xc7, 0xe3, 0xf1, 0x78,
0xbc, 0xde, 0x6f, 0xb7,
0xdb, 0x6d, 0x36, 0x1b,
0x0d, 0x86, 0x43, 0x21,
0x90, 0x48, 0x24, 0x12,
0x09, 0x84, 0xc2, 0xe1,
0x70, 0x38, 0x9c, 0x4e,
0x27, 0x13, 0x89, 0x44,
0x22, 0x91, 0x48, 0x24,
0x12, 0x89, 0xc4, 0x62,
0xb1, 0xd8, 0xec, 0xf6,
0x7b, 0x3d, 0x1e, 0x8f,
0xc7, 0x63, 0xb1, 0xd8,
0x6c, 0xb6, 0x5b, 0x2d,
0x96, 0x4b, 0x25, 0x12,
0x89, 0xc4, 0x62, 0x31,
0x18, 0x8c, 0x46, 0xa3,
0x51, 0x28, 0x94, 0xca,
0x65, 0xb2, 0x59, 0xac,
0x56, 0xab, 0x55, 0xaa,
0xd5, 0xea, 0xf5, 0x7a,
0xbd, 0xde, 0xef, 0x77,
0x3b, 0x1d, 0x0e, 0x87,
0x43, 0x21, 0x10, 0x08,
0x84, 0xc2, 0xe1, 0x70,
0x38, 0x9c, 0x4e, 0x27,
0x93, 0xc9, 0x64, 0x32,
0x99, 0x4c, 0x26, 0x13,
0x89, 0xc4, 0x62, 0x31,
0x98, 0x4c, 0x26, 0x13,
0x89, 0x44, 0xa2, 0xd1,
0x68, 0xb4, 0x5a, 0x2d,
0x96, 0x4b, 0xa5, 0xd2,
0xe9, 0x74, 0x3a, 0x9d,
0x4e, 0xa7, 0x53, 0xa9,
0x54, 0xaa, 0x55, 0x2a,
0x95, 0x4a, 0xa5, 0xd2,
0xe9, 0xf4, 0x7a, 0x3d,
0x1e, 0x0f, 0x87, 0xc3,
0x61, 0xb0, 0x58, 0x2c,
0x16, 0x0b, 0x85, 0x42,
0xa1, 0x50, 0xa8, 0xd4,
0xea, 0xf5, 0x7a, 0x3d,
0x1e, 0x0f, 0x07, 0x03,
0x81, 0x40, 0xa0, 0x50,
0x28, 0x14, 0x8a, 0x45,
0xa2, 0xd1, 0x68, 0xb4,
0x5a, 0x2d, 0x96, 0xcb,
0x65, 0xb2, 0xd9, 0x6c,
0x36, 0x9b, 0x4d, 0xa6,
0x53, 0xa9, 0xd4, 0x6a,
0xb5, 0x5a, 0x2d, 0x96,
0x4b, 0xa5, 0xd2, 0xe9,
0x74, 0xba, 0xdd, 0x6e,
0xb7, 0x5b, 0xad, 0x56,
0xab, 0x55, 0x2a, 0x95,
0xca, 0xe5, 0x72, 0x39,
0x9c, 0xce, 0x67, 0x33,
0x19, 0x8c, 0xc6, 0xe3,
0xf1, 0x78, 0x3c, 0x9e,
0x4f, 0x27, 0x13, 0x89,
0x44, 0x22, 0x11, 0x88,
0x44, 0xa2, 0xd1, 0xe8,
0x74, 0xba, 0xdd, 0xee,
0xf7, 0xfb, 0xfd, 0xfe,
0x7f, 0x3f, 0x1f, 0x8f,
0xc7, 0xe3, 0xf1, 0x78,
0xbc, 0x5e, 0x2f, 0x97,
0xcb, 0x65, 0x32, 0x19,
0x0c, 0x86, 0x43, 0x21,
0x10, 0x08, 0x84, 0xc2,
0x61, 0x30, 0x98, 0xcc,
0x66, 0x33, 0x99, 0xcc,
0x66, 0x33, 0x99, 0xcc,
0x66, 0x33, 0x19, 0x0c,
0x06, 0x03, 0x01, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x80, 0xc0, 0xe0,
0x70, 0x38, 0x1c, 0x0e,
0x07, 0x03, 0x01, 0x00,
0x80, 0xc0, 0x60, 0x30,
0x18, 0x0c, 0x86, 0xc3,
0x61, 0x30, 0x18, 0x8c,
0xc6, 0xe3, 0x71, 0xb8,
0xdc, 0x6e, 0xb7, 0xdb,
0x6d, 0xb6, 0x5b, 0x2d,
0x16, 0x0b, 0x85, 0xc2,
0x61, 0x30, 0x18, 0x0c,
0x06, 0x83, 0x41, 0x20,
0x10, 0x08, 0x84, 0xc2,
0x61, 0xb0, 0xd8, 0xec,
0xf6, 0x7b, 0xbd, 0xde,
0x6f, 0x37, 0x9b, 0xcd,
0xe6, 0x73, 0xb9, 0x5c,
0x2e, 0x17, 0x8b, 0x45,
0xa2, 0x51, 0x28, 0x94,
0x4a, 0xa5, 0x52, 0x29,
0x14, 0x8a, 0xc5, 0x62,
0xb1, 0xd8, 0xec, 0x76,
0xbb, 0xdd, 0xee, 0x77,
0xbb, 0x5d, 0xae, 0xd7,
0x6b, 0xb5, 0xda, 0xed,
0xf6, 0xfb, 0xfd, 0xfe,
0x7f, 0xbf, 0xdf, 0xef,
0x77, 0x3b, 0x9d, 0x4e,
0xa7, 0x53, 0x29, 0x94,
0x4a, 0xa5, 0xd2, 0xe9,
0x74, 0xba, 0xdd, 0xee,
0xf7, 0xfb, 0xfd, 0x7e,
0xbf, 0x5f, 0x2f, 0x97,
0xcb, 0xe5, 0xf2, 0x79,
0xbc, 0x5e, 0xaf, 0x57,
0x2b, 0x15, 0x8a, 0xc5,
0xe2, 0xf1, 0x78, 0x3c,
0x1e, 0x8f, 0x47, 0xa3,
0x51, 0xa8, 0x54, 0x2a,
0x95, 0x4a, 0xa5, 0x52,
0x29, 0x94, 0x4a, 0xa5,
0x52, 0x29, 0x94, 0xca,
0x65, 0xb2, 0xd9, 0xec,
0xf6, 0x7b, 0xbd, 0xde,
0xef, 0xf7, 0xfb, 0x7d,
0xbe, 0x5f, 0xaf, 0x57,
0x2b, 0x15, 0x8a, 0xc5,
0x62, 0xb1, 0xd8, 0x6c,
0x36, 0x9b, 0x4d, 0xa6,
0x53, 0xa9, 0x54, 0xaa,
0xd5, 0x6a, 0x35, 0x9a,
0x4d, 0xa6, 0xd3, 0xe9,
0x74, 0x3a, 0x1d, 0x8e,
0xc7, 0xe3, 0x71, 0xb8,
0xdc, 0x6e, 0x37, 0x9b,
0x4d, 0x26, 0x13, 0x09,
0x04, 0x02, 0x81, 0xc0,
0x60, 0xb0, 0x58, 0xac,
0x56, 0xab, 0x55, 0xaa,
0x55, 0xaa, 0xd5, 0xea,
0xf5, 0xfa, 0xfd, 0x7e,
0x3f, 0x1f, 0x0f, 0x07,
0x03, 0x81, 0x40, 0x20,
0x90, 0x48, 0xa4, 0xd2,
0x69, 0xb4, 0xda, 0x6d,
0xb6, 0x5b, 0xad, 0x56,
0x2b, 0x95, 0x4a, 0xa5,
0x52, 0x29, 0x14, 0x0a,
0x85, 0xc2, 0x61, 0xb0,
0xd8, 0x6c, 0xb6, 0xdb,
0xed, 0x76, 0x3b, 0x1d,
0x8e, 0xc7, 0xe3, 0x71,
0x38, 0x1c, 0x0e, 0x87,
0xc3, 0x61, 0x30, 0x18,
0x0c, 0x06, 0x03, 0x01,
0x00, 0x80, 0x40, 0xa0,
0xd0, 0x68, 0xb4, 0xda,
0xed, 0x76, 0x3b, 0x1d,
0x8e, 0x47, 0x23, 0x11,
0x88, 0x44, 0x22, 0x91,
0xc8, 0x64, 0x32, 0x19,
0x8c, 0xc6, 0xe3, 0xf1,
0xf8, 0xfc, 0x7e, 0xbf,
0x5f, 0x2f, 0x97, 0x4b,
0x25, 0x12, 0x89, 0xc4,
0x62, 0xb1, 0x58, 0x2c,
0x16, 0x8b, 0x45, 0x22,
0x91, 0xc8, 0x64, 0xb2,
0xd9, 0xec, 0x76, 0x3b,
0x9d, 0xce, 0xe7, 0x73,
0xb9, 0x5c, 0xae, 0x57,
0xab, 0xd5, 0x6a, 0xb5,
0x5a, 0xad, 0x56, 0xab,
0x55, 0xaa, 0x55, 0x2a,
0x95, 0xca, 0x65, 0xb2,
0xd9, 0x6c, 0x36, 0x1b,
0x0d, 0x06, 0x83, 0xc1,
0xe0, 0x70, 0xb8, 0x5c,
0x2e, 0x97, 0xcb, 0xe5,
0xf2, 0xf9, 0xfc, 0x7e,
0x3f, 0x9f, 0x4f, 0x27,
0x93, 0xc9, 0xe4, 0xf2,
0xf9, 0x7c, 0xbe, 0xdf,
0xef, 0xf7, 0x7b, 0x3d,
0x9e, 0xcf, 0xe7, 0xf3,
0xf9, 0x7c, 0xbe, 0xdf,
0x6f, 0x37, 0x9b, 0xcd,
0x66, 0xb3, 0xd9, 0xec,
0xf6, 0x7b, 0xbd, 0x5e,
0xaf, 0x57, 0x2b, 0x15,
0x8a, 0x45, 0xa2, 0x51,
0x28, 0x14, 0x0a, 0x85,
0x42, 0xa1, 0x50, 0xa8,
0xd4, 0x6a, 0xb5, 0xda,
0x6d, 0x36, 0x1b, 0x0d,
0x06, 0x83, 0x41, 0xa0,
0xd0, 0x68, 0x34, 0x1a,
0x8d, 0xc6, 0xe3, 0xf1,
0xf8, 0x7c, 0x3e, 0x1f,
0x8f, 0xc7, 0xe3, 0x71,
0x38, 0x1c, 0x8e, 0xc7,
0xe3, 0xf1, 0x78, 0x3c,
0x1e, 0x0f, 0x07, 0x03,
0x01, 0x00, 0x00, 0x00,
0x80, 0x40, 0xa0, 0x50,
0xa8, 0xd4, 0x6a, 0x35,
0x1a, 0x0d, 0x06, 0x83,
0x41, 0x20, 0x90, 0x48,
0xa4, 0xd2, 0xe9, 0xf4, };

static unsigned char key_table_2[ ] = {
0xec, 0xe1, 0x18, 0x0b,
0x2f, 0x82, 0x3f, 0x26,
0x53, 0xf1, 0x46, 0x81,
0x91, 0x37, 0x02, 0x61,
0x34, 0x52, 0xd4, 0xca
};

static unsigned char key_table_3[ ] = {
0xd7, 0x38, 0xe4, 0x9a,
0x94, 0x0b, 0x9d, 0x8a,
0x5a, 0xe7, 0xa3, 0xf4,
0x67, 0x3f, 0xf7, 0x7d,
0x35, 0x3b, 0x45, 0xb4
};