#include "pch.h"
#include "a3parser.h"
#include "cheat.h"

a3parser* g_parser = nullptr;
network_hack* g_cheat = nullptr;

static int filter_callback(struct nfq_q_handle* queue, struct nfgenmsg* nfmsg, struct nfq_data* nfad, void* data) {
    nfqnl_msg_packet_hdr* ph = nfq_get_msg_packet_hdr(nfad);
    if (ph) {
        unsigned char* raw = nullptr;
        int len = nfq_get_payload(nfad, &raw);
        if (len) {
            pkt_buff* pkbuf = pktb_alloc(AF_INET, raw, len, 0x1000);
            if (pkbuf) {
                iphdr* ip = nfq_ip_get_hdr(pkbuf);
                nfq_ip_set_transport_header(pkbuf, ip);

                if (ip->protocol == UDP_PROTOCOL && g_parser->parse_packet(pktb_data(pkbuf))) {
                    return nfq_set_verdict(queue, ntohl(ph->packet_id), NF_ACCEPT, ntohs(ip->tot_len), pktb_data(pkbuf));
                }
            }
        }
    }
    return nfq_set_verdict(queue, ntohl(ph->packet_id), NF_ACCEPT, 0, nullptr);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Invalid amount or arguments (%i recieved, 1 expected) \n", argc - 1);
        return 0;
    }

    nfq_handle* handler = nfq_open();
    if (!handler) {
        printf("Failed to open nfq\n");
        return 0;
    }

    nfq_q_handle* queue = nfq_create_queue(handler, 0, filter_callback, nullptr);
    if (!queue) {
        printf("Couldn't create queue handler\n");
        nfq_close(handler);
        return 0;
    }

    if (nfq_set_mode(queue, NFQNL_COPY_PACKET, 0xFFFF)) {
        printf("Couldn't set nfq mode\n");
        nfq_close(handler);
        nfq_destroy_queue(queue);
        return 0;
    }

    // create the "cheat" object
    uint32_t addr = inet_addr(argv[1]);
    printf("Searching for arma server on ip %s\n", argv[1]);
    g_parser = new a3parser((uint8_t*)&addr);
    g_cheat = new network_hack();

    int fd = nfq_fd(handler);
    static char buffer[0xFFFF];
    while (true) {
        int len = recv(fd, buffer, 0xFFFF, 0);
        if (len < 0) {
            printf("Negative packet length (?)\n");
            continue;
        }
        nfq_handle_packet(handler, buffer, len);
    }

    delete g_parser;
    delete g_cheat;
    nfq_close(handler);
    nfq_destroy_queue(queue);

    return 0;
}