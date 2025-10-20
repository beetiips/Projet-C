#include <stdlib.h>
#include "linked_list.h"

DList new_dlist(void) {
    return NULL;
}

bool is_empty_dlist(DList dli) {
    if(dli == NULL)
        return true;

    return false;
}

int dlist_length(DList dli) {
    if(is_empty_dlist(dli))
        return 0;

    return dli->lenght;
}

int dlist_first(DList dli) {
    if(is_empty_dlist(dli))
        exit(1);

    return dli->begin->value;

}

int dlist_last(DList dli) {
    if(is_empty_dlist(dli))
        exit(1);

    return dli->end->value;
    
}