#include <stddef.h>
#include "ll_cycle.h"

int ll_has_cycle(node *head) {
    /* your code here */
    if(head == NULL) {
        return 0;
    }
    node *hare = head;
    node *tortoise = head;
    do {
        hare = hare->next->next;
        tortoise = tortoise->next;
    } while(hare->next->next != NULL && hare != tortoise);
    if(tortoise == hare) {
        return 1;
    }
    return 0;
}