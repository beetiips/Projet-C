#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#ifndef DLIST
#define DLIST

typedef struct DListnode {
    int value;
    struct DListnode *back;
    struct DListnode *next;
}DListnode;

typedef struct DList {
    int lenght;
    struct DListnode *begin;
    struct DListnode *end;
}*DList;


DList new_dlist(void);
bool is_empty_dlist(DList dli);
int dlist_length(DList dli);
int dlist_first(DList dli);
int dlist_last(DList dli);
DList push_back(DList dli, int x);



#endif