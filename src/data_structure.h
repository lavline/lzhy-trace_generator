#ifndef __DATA_STRUCTURE_H_
#define __DATA_STRUCTURE_H_
#include<stdio.h>

typedef struct rule {
	int PRI;  //priority
	unsigned char protocol[2];  // [0] : mask [1] : protocol
	unsigned char source_mask;
	unsigned char destination_mask;
	unsigned char source_ip[4];
	unsigned char destination_ip[4];
	unsigned short source_port[2];
	unsigned short destination_port[2];
}rule;

typedef struct ACL_rules
{
	unsigned int size;
	unsigned int capacity;
	rule* list;
}ACL_rules;

typedef struct message
{
	unsigned int protocol;
	unsigned int source_ip;
	unsigned int destination_ip;
	unsigned short source_port;
	unsigned short destination_port;
}message;

typedef struct ACL_messages
{
	unsigned int size;
	unsigned int capacity;
	message* list;
}ACL_messages;

#endif //__DATA_STRUCTURE_H_