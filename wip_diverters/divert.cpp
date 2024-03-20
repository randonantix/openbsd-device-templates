// doas pkg_add -v protobuf-c py3-protobuf
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <err.h>
#include <unistd.h>
#include <errno.h>
//#include "divert.pb.h"

#define DIVERT_PORT 700
#define SEND_PORT 9999
#define RECV_PORT 9998
#define BUF_SIZE 1024

static size_t read_buffer (unsigned max_length, uint8_t *out)
{
	return 128;
  /* size_t cur_len = 0; */
  /* size_t nread; */
  /* while ((nread=fread(out + cur_len, 1, max_length - cur_len, stdin)) != 0) */
  /* { */
  /*   cur_len += nread; */
  /*   if (cur_len == max_length) */
  /*   { */
  /*     warn("max message length exceeded\n"); */
  /*     //exit(1); */
  /*   } */
  /* } */
  /* return cur_len; */
}

int main(int argc, char *argv[])
{

	int fd, client_fd, server_fd, s, g;
	struct sockaddr_in sin, client_sock, server_sock;
	socklen_t sin_len;
	char buf[BUF_SIZE];
	
	//DivertMessage divert_msg = DIVERT_MESSAGE__INIT;
	// pointer example
	//char* src_host = "192.168.8.8";
	//divert_msg.src_host = malloc(strnlen(src_host, 64) + 1);
	//strlcpy(divert_msg.src_host, src_host, 64);

	//divert_msg.dst_host = malloc(sizeof (char*));
	//strlcpy(divert_msg.dst_host, dst_host);
	//divert_msg.src_port = 443;
	//divert_msg.dst_port = 12343;
	//divert_msg.src_host = "192.16.8.8";
	//divert_msg.dst_host = "32.32.32.32";
	//unsigned msg_len = divert_message__get_packed_size(&divert_msg);
	//void *msg_buf;
	//msg_buf = malloc(msg_len);
	//divert_message__pack(&divert_msg, msg_buf);
	//warn("Writing %d serialized bytes\n", msg_len); // See the length of message
  //warn(msg_buf, msg_len); // Write to stdout to allow direct command line piping

	//uint8_t unpacked_buf[1024];
	//size_t unpacked_len = read_buffer(1024, unpacked_buf);
	//warn("read buffer done %zu", unpacked_len);
	//DivertMessage *unpacked_msg = divert_message__unpack(NULL, unpacked_len, unpacked_buf);
	//if (unpacked_msg == NULL) {
		//warn("unpacked message is NULL!");
	//}

	//if (unpacked_msg->has_src_port) {
	//	warn("src port: %d", unpacked_msg->src_port);
	//}
	//divert_message__free_unpacked(unpacked_msg, NULL);

	//free(divert_msg.src_host);
	//free(divert_msg.dst_host);
  //free(msg_buf);

	
	fd = socket(AF_INET, SOCK_RAW, IPPROTO_DIVERT);
	if (fd == -1)
		err(1, "socket");
	
  // TODO: make another sockaddr_in on the port for our app and sendto() there. Then recvfrom() back. Will also need another sockaddr_in for the second recvfrom()?
	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(DIVERT_PORT);
	sin.sin_addr.s_addr = 0;
	
	sin_len = sizeof(struct sockaddr_in);
	
	  // TODO: Needs to call unlink. How does this work when using Ctrl-C?
	  // https://man.openbsd.org/bind.2#NOTES
	  // Also, how to see it running? Netstat shows no obvious port
	s = bind(fd, (struct sockaddr *) &sin, sin_len);
	if (s == -1)
		err(1, "bind");
	
	g = getsockname(s, (struct sockaddr *) &sin, &sin_len);
	if (g == -1) {
		warn("getsockname %d", errno);
	}
 	printf("socket name %d", g);


	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd == -1) {
		warn("Unable to create recv socket %d", errno);
		//return 1;
	}

	server_sock.sin_addr.s_addr = inet_addr("127.0.0.1");
	//recv_sock.sin_port = htons(atoi(RECV_PORT));
	//server_sock.sin_port = htons(RECV_PORT);
	server_sock.sin_port = htons(SEND_PORT);
	server_sock.sin_family = AF_INET;
	memset(buf, 0, sizeof(buf));

	//int ret = bind(server_fd, (struct sockaddr*)&server_sock, sizeof(server_sock));
	int ret = connect(server_fd, (struct sockaddr*)&server_sock, sizeof(server_sock));
	if (ret < 0) {
		warn("Unable to bind TCP socket %d", errno);
		//return 1;
	}

	//listen(server_fd, 128);
	int len = sizeof(struct sockaddr_in);

	 
	for (;;) {
		ssize_t n;
		char packet[IP_MAXPACKET];
		struct ip *ip;
		struct tcphdr *th;
		int hlen;
		char src[48], dst[48];
	
		memset(packet, 0, sizeof(packet));
		n = recvfrom(fd, packet, sizeof(packet), 0,
		    (struct sockaddr *) &sin, &sin_len);
		if (n == -1) {
			warn("recvfrom");
			continue;
		}
		if (n < sizeof(struct ip)) {
			warnx("packet is too short");
			continue;
		}
	
		ip = (struct ip *) packet;
		hlen = ip->ip_hl << 2;
		if (hlen < sizeof(struct ip) || ntohs(ip->ip_len) < hlen ||
		    n < ntohs(ip->ip_len)) {
			warnx("invalid IPv4 packet");
			continue;
		}
	
		th = (struct tcphdr *) (packet + hlen);

	
		if (inet_ntop(AF_INET, &ip->ip_src, src,
		    sizeof(src)) == NULL)
			(void)strlcpy(src, "?", sizeof(src));
	
		if (inet_ntop(AF_INET, &ip->ip_dst, dst,
		    sizeof(dst)) == NULL)
			(void)strlcpy(dst, "?", sizeof(dst));
	
		// TODO: accept client connections (python app)
		// use write() to send this data there.
		// python app then sends back data using send()
		// But, then this needs another recvfrom()?
		// Can this just reinject the packets back to the kernel
		// and let pf rules set by the python processing
		// do the rest of the work?
		
		/* client_fd = accept(server_fd, (struct sockaddr*)&client_sock, (socklen_t*)&len); */
		/* if (client_fd < 0) { */
		/* 	warn("Unable to accept connections %d", errno); */
		/* } */
		
		// Print client IP address
		/* char *client_addr = inet_ntoa(client_sock.sin_addr); */
		/* int client_port = ntohs(client_sock.sin_port); */
		/* printf("New connection from %s:%d\n", client_addr, client_port); */

		/* snprintf(buf,  */
		/*                 sizeof(buf),  */
		/*                 "server> You've reached me %d time(s)\n",  */
		/*                 ++count); */
		snprintf(buf, sizeof(buf), "%s:%u -> %s:%u\n", src, ntohs(th->th_sport), dst, ntohs(th->th_dport));
    //write(client_fd, buf, strlen(buf));
		//n = sendto(server_fd, buf, strlen(buf), n, (struct sockaddr*)&server_sock, len);
		int ret = send(server_fd, buf, strlen(buf), 0);
		if(ret < 0) {
			warn("Unable to send data to remote server %d", errno);
    }

		printf("%s:%u -> %s:%u\n",
		    src,
		    ntohs(th->th_sport),
		    dst,
		    ntohs(th->th_dport)
		);
	
		// TODO: why does this hang if we send to the python socket client?
		// what if this works the other way around and this divert connects() to
		// the python app, sends it a message, then disconnects. Then python
		// does whatever it wants?
		n = sendto(fd, packet, n, 0, (struct sockaddr *) &sin,
		    sin_len);
		if (n == -1)
			warn("sendto");
	}

  //close(fd);
	//unlink(s);

	return 0;
}

