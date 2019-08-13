#pragma once
#include "pch.h"

static constexpr uint32_t crc_table[ ] = {
    0x00000000, 0x77073096, 0xee0e612c, 0x990951ba, 0x076dc419, 0x706af48f,
    0xe963a535, 0x9e6495a3, 0x0edb8832, 0x79dcb8a4, 0xe0d5e91e, 0x97d2d988,
    0x09b64c2b, 0x7eb17cbd, 0xe7b82d07, 0x90bf1d91, 0x1db71064, 0x6ab020f2,
    0xf3b97148, 0x84be41de, 0x1adad47d, 0x6ddde4eb, 0xf4d4b551, 0x83d385c7,
    0x136c9856, 0x646ba8c0, 0xfd62f97a, 0x8a65c9ec, 0x14015c4f, 0x63066cd9,
    0xfa0f3d63, 0x8d080df5, 0x3b6e20c8, 0x4c69105e, 0xd56041e4, 0xa2677172,
    0x3c03e4d1, 0x4b04d447, 0xd20d85fd, 0xa50ab56b, 0x35b5a8fa, 0x42b2986c,
    0xdbbbc9d6, 0xacbcf940, 0x32d86ce3, 0x45df5c75, 0xdcd60dcf, 0xabd13d59,
    0x26d930ac, 0x51de003a, 0xc8d75180, 0xbfd06116, 0x21b4f4b5, 0x56b3c423,
    0xcfba9599, 0xb8bda50f, 0x2802b89e, 0x5f058808, 0xc60cd9b2, 0xb10be924,
    0x2f6f7c87, 0x58684c11, 0xc1611dab, 0xb6662d3d, 0x76dc4190, 0x01db7106,
    0x98d220bc, 0xefd5102a, 0x71b18589, 0x06b6b51f, 0x9fbfe4a5, 0xe8b8d433,
    0x7807c9a2, 0x0f00f934, 0x9609a88e, 0xe10e9818, 0x7f6a0dbb, 0x086d3d2d,
    0x91646c97, 0xe6635c01, 0x6b6b51f4, 0x1c6c6162, 0x856530d8, 0xf262004e,
    0x6c0695ed, 0x1b01a57b, 0x8208f4c1, 0xf50fc457, 0x65b0d9c6, 0x12b7e950,
    0x8bbeb8ea, 0xfcb9887c, 0x62dd1ddf, 0x15da2d49, 0x8cd37cf3, 0xfbd44c65,
    0x4db26158, 0x3ab551ce, 0xa3bc0074, 0xd4bb30e2, 0x4adfa541, 0x3dd895d7,
    0xa4d1c46d, 0xd3d6f4fb, 0x4369e96a, 0x346ed9fc, 0xad678846, 0xda60b8d0,
    0x44042d73, 0x33031de5, 0xaa0a4c5f, 0xdd0d7cc9, 0x5005713c, 0x270241aa,
    0xbe0b1010, 0xc90c2086, 0x5768b525, 0x206f85b3, 0xb966d409, 0xce61e49f,
    0x5edef90e, 0x29d9c998, 0xb0d09822, 0xc7d7a8b4, 0x59b33d17, 0x2eb40d81,
    0xb7bd5c3b, 0xc0ba6cad, 0xedb88320, 0x9abfb3b6, 0x03b6e20c, 0x74b1d29a,
    0xead54739, 0x9dd277af, 0x04db2615, 0x73dc1683, 0xe3630b12, 0x94643b84,
    0x0d6d6a3e, 0x7a6a5aa8, 0xe40ecf0b, 0x9309ff9d, 0x0a00ae27, 0x7d079eb1,
    0xf00f9344, 0x8708a3d2, 0x1e01f268, 0x6906c2fe, 0xf762575d, 0x806567cb,
    0x196c3671, 0x6e6b06e7, 0xfed41b76, 0x89d32be0, 0x10da7a5a, 0x67dd4acc,
    0xf9b9df6f, 0x8ebeeff9, 0x17b7be43, 0x60b08ed5, 0xd6d6a3e8, 0xa1d1937e,
    0x38d8c2c4, 0x4fdff252, 0xd1bb67f1, 0xa6bc5767, 0x3fb506dd, 0x48b2364b,
    0xd80d2bda, 0xaf0a1b4c, 0x36034af6, 0x41047a60, 0xdf60efc3, 0xa867df55,
    0x316e8eef, 0x4669be79, 0xcb61b38c, 0xbc66831a, 0x256fd2a0, 0x5268e236,
    0xcc0c7795, 0xbb0b4703, 0x220216b9, 0x5505262f, 0xc5ba3bbe, 0xb2bd0b28,
    0x2bb45a92, 0x5cb36a04, 0xc2d7ffa7, 0xb5d0cf31, 0x2cd99e8b, 0x5bdeae1d,
    0x9b64c2b0, 0xec63f226, 0x756aa39c, 0x026d930a, 0x9c0906a9, 0xeb0e363f,
    0x72076785, 0x05005713, 0x95bf4a82, 0xe2b87a14, 0x7bb12bae, 0x0cb61b38,
    0x92d28e9b, 0xe5d5be0d, 0x7cdcefb7, 0x0bdbdf21, 0x86d3d2d4, 0xf1d4e242,
    0x68ddb3f8, 0x1fda836e, 0x81be16cd, 0xf6b9265b, 0x6fb077e1, 0x18b74777,
    0x88085ae6, 0xff0f6a70, 0x66063bca, 0x11010b5c, 0x8f659eff, 0xf862ae69,
    0x616bffd3, 0x166ccf45, 0xa00ae278, 0xd70dd2ee, 0x4e048354, 0x3903b3c2,
    0xa7672661, 0xd06016f7, 0x4969474d, 0x3e6e77db, 0xaed16a4a, 0xd9d65adc,
    0x40df0b66, 0x37d83bf0, 0xa9bcae53, 0xdebb9ec5, 0x47b2cf7f, 0x30b5ffe9,
    0xbdbdf21c, 0xcabac28a, 0x53b39330, 0x24b4a3a6, 0xbad03605, 0xcdd70693,
    0x54de5729, 0x23d967bf, 0xb3667a2e, 0xc4614ab8, 0x5d681b02, 0x2a6f2b94,
    0xb40bbe37, 0xc30c8ea1, 0x5a05df1b, 0x2d02ef8d
};

#define DO1 crc = crc_table[((int)crc ^ (*buf++)) & 0xff] ^ (crc >> 8)
#define DO8 DO1; DO1; DO1; DO1; DO1; DO1; DO1; DO1

#define POLY 0x8408

static uint32_t crc32(uint32_t crc, uint8_t* buf, uint32_t len) {
    if (!buf)
        return 0;

    crc = crc ^ 0xffffffffUL;
    while (len >= 8) {
        DO8;
        len -= 8;
    }
    if (len) do {
        DO1;
    } while (--len);
    return crc ^ 0xffffffffUL;
}

/*
//                                      16   12   5
// this is the CCITT CRC 16 polynomial X  + X  + X  + 1.
// This works out to be 0x1021, but the way the algorithm works
// lets us use 0x8408 (the reverse of the bit pattern).  The high
// bit is always assumed to be set, thus we only use 16 bits to
// represent the 17 bit value.
*/
static unsigned short crc16(unsigned char *ptr, int count)
{
    unsigned short crc;
    char i;
    crc = 0xFFFF;
    while (--count >= 0)
    {
        crc = crc ^ (int)*ptr++ << 8;
        i = 8;
        do
        {
            if (crc & 0x8000)
                crc = crc << 1 ^ 0x1021;
            else
                crc = crc << 1;
        } while (--i);
    }
    return (crc);
}


typedef unsigned short u16;
typedef uint32_t u32;

static uint16_t cksum_generic(unsigned char *p, size_t len, uint16_t initial)
{
    uint32_t sum = htons(initial);
    const uint16_t *u16 = (const uint16_t *)p;

    while (len >= (sizeof(*u16) * 4)) {
        sum += u16[0];
        sum += u16[1];
        sum += u16[2];
        sum += u16[3];
        len -= sizeof(*u16) * 4;
        u16 += 4;
    }
    while (len >= sizeof(*u16)) {
        sum += *u16;
        len -= sizeof(*u16);
        u16 += 1;
    }

    /* if length is in odd bytes */
    if (len == 1)
        sum += *((const uint8_t *)u16);

    while (sum >> 16)
        sum = (sum & 0xFFFF) + (sum >> 16);
    return (uint16_t)~sum;

}


//================================================================
// Routine to calculate the UDP checksum.  Orignally from
// http://www.netfor2.com/udpsum.htm, however that code does
// not work on Linux 32 or 64 bit systems.  This modified
// version does.
//
// In the case of an odd length buffer, an extra zero
// byte is padded to the end. 
//
// IP addresses are in network byte order.
//
//================================================================
static uint16_t udp_sum_calc(u16 len_udp, uint32_t src_ip, uint32_t dst_ip,
    char unsigned * b) {
    u16 prot_udp = 17;
    u16 padd = 0;
    u16 word16;
    u32 sum;
    int i;
    u16 *buff;

    buff = (u16 *)b;

    // Find out if the length of data is even or odd number. If odd,
    // effectively add a zero padding byte at the end of packet

    padd = len_udp % 2;


    //initialize sum to zero
    sum = 0;

    // make 16 bit words out of every two adjacent 8 bit words and 
    // calculate the sum of all 16 bit words
    for (i = 0; i < len_udp - padd; i = i + 2) {
        word16 = (u16)((*(b + i) << 8) & 0xFF00) + *(b + i + 1);
        sum = sum + (uint32_t)word16;
    }

    // Need padding byte?  If so, the last byte of the packet
    // also needs to be added.
    if (padd) {
        word16 = (u16)((*(b + i) << 8) & 0xFF00);
        sum = sum + (uint32_t)word16;
    }


    // add the UDP pseudo header which contains the IP source and
    // destinationn addresses
    word16 = src_ip & 0xFFFF;
    sum = sum + word16;
    word16 = src_ip >> 16 & 0xFFFF;
    sum = sum + word16;

    word16 = dst_ip & 0xFFFF;
    sum = sum + word16;
    word16 = dst_ip >> 16 & 0xFFFF;
    sum = sum + word16;

    // the protocol number and the length of the UDP packet  are
    // also in the pseudoheader.
    sum = sum + prot_udp + len_udp;

    // keep only the last 16 bits of the 32 bit calculated sum and add the carries
    while (sum >> 16)
        sum = (sum & 0xFFFF) + (sum >> 16);

    // Take the one's complement of sum
    sum = ~sum;

    return htons(((uint16_t)sum));
}

static uint16_t get_udp_checksum(unsigned char *packet) {
    //================================================================
    // Update the udp checksum for the packet	
    //================================================================

    unsigned char *udp_data_ptr = packet + sizeof(struct iphdr);
    struct udphdr *udp;
    struct iphdr *ip;
    int payload_length;
    int packet_length;

    ip = (struct iphdr *)packet;
    auto src_ip = *(uint32_t*)&ip->saddr;
    auto dst_ip = *(uint32_t*)&ip->daddr;
    // Cast the headers from the raw packets
    udp = (struct udphdr *) udp_data_ptr;

    // This includes length of udp header
    packet_length = ntohs(udp->len);
    payload_length = packet_length - sizeof(struct udphdr);
    udp->check = 0;  // Dont care what it was and needs to be 0 for calc

    return udp_sum_calc(packet_length, ntohl(src_ip), ntohl(dst_ip), udp_data_ptr);
}