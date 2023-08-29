#ifndef DICTMETRICS_H
#define DICTMETRICS_H

struct dict_metrics_t {
    char name[50];
    unsigned long usages;
    unsigned long total_time;
    unsigned long extra_1;
    unsigned long extra_2;
    unsigned long extra_3;
};

extern struct dict_metrics_t dict_metrics[];

void print_dict_metrics(void);

unsigned long elapsed(struct timespec);

#endif //DICTMETRICS_H
