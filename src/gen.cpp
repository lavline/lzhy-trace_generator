#include "gen.h"

void gen_trace(char* file_name, ACL_rules* rules, unsigned int size)
{
    std::random_device seed;
    std::mt19937 rd(seed());
    std::uniform_int_distribution<> dis(0, rules->size - 1);

    int protocol[] = { 1,2,3,4,5,6,7,8,17,47,50,51,88,89 };
    
    char trace_file[50] = "";
    strcat(trace_file, file_name);
    strcat(trace_file, "_trace-1.txt");
    printf("%s\n", trace_file);

    FILE* fp = NULL;
    fp = fopen(trace_file, "w");
    if (fp == NULL)fprintf(stderr, "Error - creat trace file faild.");

    unsigned int sip, dip, index;
    unsigned short sport, dport;
    unsigned int smask, dmask;
    for (unsigned int i = 0; i < size; i++) {
        index = dis(rd);
        rule* r = rules->list + index;
        memcpy(&sip, r->source_ip, sizeof(int));
        memcpy(&dip, r->destination_ip, sizeof(int));
        smask = r->source_mask; dmask = r->destination_mask;
        if (smask == 0)sip = rd();
        else if (smask < 32) {
            int mbit = 32 - smask;
            unsigned int temp = sip >> mbit;
            temp = (temp << mbit) + (rd() % (1 << mbit));
            if (temp >> mbit == sip >> mbit)sip = temp;
            else fprintf(stderr, "Error - gen sip error.\n");
        }
        fprintf(fp, "%u\t", sip);
        if (dmask == 0)dip = rd();
        else if (dmask < 32) {
            int mbit = 32 - dmask;
            unsigned int temp = dip >> mbit;
            temp = (temp << mbit) + (rd() % (1 << mbit));
            if (temp >> mbit == dip >> mbit)dip = temp;
            else fprintf(stderr, "Error - gen dip error.\n");
        }
        fprintf(fp, "%u\t", dip);
        int Pwidth = r->source_port[1] - r->source_port[0];
        if (Pwidth == 0)
            sport = r->source_port[0];
        else {
            sport = rd() % Pwidth + r->source_port[0];
            if (sport < r->source_port[0] || sport > r->source_port[1])
                fprintf(stderr, "Error - gen sport error.\n");
        }
        fprintf(fp, "%hu\t", sport);
        Pwidth = r->destination_port[1] - r->destination_port[0];
        if (Pwidth == 0)
            dport = r->destination_port[0];
        else {
            dport = rd() % Pwidth + r->destination_port[0];
            if (dport < r->destination_port[0] || dport > r->destination_port[1])
                fprintf(stderr, "Error - gen dport error.\n");
        }
        fprintf(fp, "%hu\t", dport);
        if (r->protocol[0] == 0)
            fprintf(fp, "%u\t%u\t", protocol[rd() % (sizeof(protocol) / 4)], r->protocol[0]);
        else
            fprintf(fp, "%u\t%u\t", r->protocol[1], r->protocol[0]);
        fprintf(fp, "%u\n", index);
    }
    fclose(fp);
}
