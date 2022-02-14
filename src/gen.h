#ifndef _GEN_H_
#define _GEN_H_
#include <random>
#include <string.h>
#include "tool.h"

void gen_trace(char* file_name, ACL_rules* rules, unsigned int size);
void gen_trace_with_alpha(char* file_name, ACL_rules* rules, unsigned int size, float alpha);
#endif // !_GEN_H_
