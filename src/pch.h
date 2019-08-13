#pragma once

#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <linux/netfilter.h>
#include <sys/socket.h>
#include <arpa/inet.h>

extern "C" {
    #include <libnetfilter_queue/libnetfilter_queue.h>
    #include <libnetfilter_queue/pktbuff.h>
    #include <libnetfilter_queue/libnetfilter_queue_ipv4.h>
    #include <libnetfilter_queue/libnetfilter_queue_udp.h>
}

#include <math.h>
#include <float.h>
#include <xmmintrin.h>
#include <cstring>
#include <thread>
#include <stdio.h>
#include <functional>
#include <queue>
#include <array>
#include <vector>
#include <string>
#include <atomic>
#include <unordered_set>
#include <pcap/pcap.h>
#include <mutex>
#include <chrono>
#include <ostream>
#include <sstream>
#include <queue>
#include <mutex>
#include <unordered_map>
#include "crc.h"

#define LOWORD(l)           ((uint16_t)(((uintptr_t)(l)) & 0xffff))
#define HIWORD(l)           ((uint16_t)((((uintptr_t)(l)) >> 16) & 0xffff))
#define LOBYTE(w)           ((uint8_t)(((uintptr_t)(w)) & 0xff))
#define HIBYTE(w)           ((uint8_t)((((uintptr_t)(w)) >> 8) & 0xff))