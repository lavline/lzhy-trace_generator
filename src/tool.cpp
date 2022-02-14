#include"tool.h"

void add_rule(ACL_rules* rules, rule* r) {
	if (rules->size < rules->capacity) {
		memcpy(rules->list + rules->size, r, sizeof(rule));
		rules->size++;
	}
	else {
		rules->capacity += 8;
		rule* p = (rule*)realloc(rules->list, rules->capacity * sizeof(rule));
		if (p == NULL) {
			fprintf(stderr, "Error - unable to allocate required memory\n");
		}
		else {
			rules->list = p;
			memcpy(rules->list + rules->size, r, sizeof(rule));
			rules->size++;
		}
	}
}

void add_message(ACL_messages* messages, message* m) 
{
	if (messages->size < messages->capacity) {
		memcpy(messages->list + messages->size, m, sizeof(message));
		messages->size++;
	}
	else {
		messages->capacity += 8;
		message* p = (message*)realloc(messages->list, messages->capacity * sizeof(message));
		if (p == NULL) {
			fprintf(stderr, "Error - unable to allocate required memory\n");
		}
		else {
			messages->list = p;
			memcpy(messages->list + messages->size, m, sizeof(message));
			messages->size++;
		}
	}
}