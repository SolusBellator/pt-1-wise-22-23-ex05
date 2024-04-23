#include "grading_table.h"
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void print_results(grading_table_ptr entry)
{
    printf("%d hat in %d %d Punkt(e) erreicht.\n", entry->matnr, entry->tasknr, entry->points);
}

void print_if_lower(grading_table_ptr entry)
{
    if(entry->points < 10)
    {
        printf("%d %d\n", entry->matnr, entry->tasknr);
    }
}

int entry_count(grading_table_ptr entry, int val)
{
    return val + 1;
}

int find_max(grading_table_ptr entry, int val)
{
    if(val > entry->points)
    {
        return val;
    }
    else if(val < entry->points)
    {
        return entry->points;
    }
    else
    {
        return val;
    }
}

int sum_points(grading_table_ptr entry, int val)
{
    if(entry->tasknr == 3)
    {
        return val + entry->points;
    }
    else
    {
        return val;
    }
}

int main(int argc, char* args[])
{
    grading_table_ptr table;

    if(argc == 3)
    {
        table = read_list(fopen(args[2], "rb"));      
    }
    else if(argc == 2)
    {
        table = read_list(stdin);
    }
    else if(argc < 2)
    {
        printf("Invalid call: Too few arguments specified!\n");
        printf("usage: %s < a | b | c | d | e > <input file name>\n", args[0]);
        exit(-1);
    }
    else if(argc > 3)
    {
        printf("Invalid call: Too many arguments specified!\n");
        printf("usage: %s < a | b | c | d | e > <input file name>\n", args[0]);
        exit(-2);
    }

    switch(args[1][0])
    {
        case 'a':
            traverse_list(table, print_results);
            break;

        case 'b':
            traverse_list(table, print_if_lower);
            break;

        case 'c':
            printf("%d\n", reduce_list(table, entry_count, 0));
            break;

        case 'd':
            printf("%d\n", reduce_list(table, find_max, 0));
            break;

        case 'e':
            printf("%d\n", reduce_list(table, sum_points, 0));
            break;
    }

    delete_list(table);

    exit(0);
}