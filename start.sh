#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo -e "Invalid amount of arguments, 1 expected"
    echo -e "Argument should be server ip!"
    exit 1
fi

server_ip="$1"

function ctrl_c() {
    echo "Cleaning up iptables..."
    iptables -t mangle -D POSTROUTING -p udp -d "$server_ip" -j NFQUEUE
    iptables -t mangle -D PREROUTING -p udp -s "$server_ip" -j NFQUEUE
    exit 1
}

trap ctrl_c SIGINT
trap ctrl_c SIGTERM

iptables -t mangle -A POSTROUTING -p udp -d "$server_ip" -j NFQUEUE
iptables -t mangle -A PREROUTING -p udp -s "$server_ip" -j NFQUEUE

sudo ./arma_hack "$server_ip"

iptables -t mangle -D POSTROUTING -p udp -d "$server_ip" -j NFQUEUE
iptables -t mangle -D PREROUTING -p udp -s "$server_ip" -j NFQUEUE
