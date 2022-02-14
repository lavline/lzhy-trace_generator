#include <stdlib.h>
#include"gen.h"
#include"read.h"

int main() {
	unsigned int trace_size = 1000000;
	//printf("Please inpute trace number: ");
	//scanf("%u", &trace_size);
	
	ACL_rules datasets = { 0,0,0 };
	ACL_messages message_sets = { 0,0,0 };

	char* file_name = "/root/ACL_dataset/ipc2_256k";
	char rule_file[50] = "";
	strcat(rule_file, file_name);
	strcat(rule_file, ".txt");
	printf("%s\n", rule_file);

	read_rules(rule_file, &datasets);
	gen_trace(file_name, &datasets, trace_size);

	printf("program complete\n");
	return 0;
}

