#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "grading_table.h"
#include <unistd.h>

grading_table_ptr prev;

int read_bytes;

void delete_list(grading_table_ptr head)
{
    if(head != NULL)
    {
        struct grading_entry_t* temp = head->next_entry;
        free(head);
        delete_list(temp);
    }
    
}

void traverse_list(grading_table_ptr head, void (*visitor)(grading_table_ptr current))
{
    if(head != NULL)
    {
        (*visitor)(head);
        traverse_list(head->next_entry, (*visitor));
    }
    
}

int reduce_list(grading_table_ptr head, int (*visitor)(grading_table_ptr current, int val), int start_val)
{
    static int final_val = 0;

    if(head != NULL)
    {
        final_val = (*visitor)(head, start_val);
        reduce_list(head->next_entry, (*visitor), final_val);
    }

    return final_val;
}

grading_table_ptr read_list(FILE* fp)
{
    uint16_t tasknr;
    uint16_t points;
    uint32_t matnr;

    struct grading_entry_t* prev = 0;

    struct grading_entry_t* head = 0;

    uint32_t* buf = malloc(sizeof(uint32_t));

    while ((read_bytes = read(fileno(fp), buf, 4)) != 0)
    {

        matnr = *buf;

        uint16_t* buf2 = malloc(sizeof(uint16_t));
        read_bytes = read(fileno(fp), buf2, 2);
        tasknr = *buf2;

        read_bytes = read(fileno(fp), buf2, 2);
        points = *buf2;
        free(buf2);

        struct grading_entry_t* pt = malloc(sizeof(struct grading_entry_t));
        struct grading_entry_t entry = {matnr, tasknr, points};
        *pt = entry;

        if(head == 0)
        {
            head = pt;
        }

        if(prev == 0)
        {
            prev = pt;
        }
        else
        {
            (*prev).next_entry = pt;
            prev = pt;
        }
    }

    return head;
    
}