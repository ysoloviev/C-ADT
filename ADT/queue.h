#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdlib.h>

typedef int Item;

typedef struct Node {
    Item item;
    struct Node *next;
} node;

typedef struct {
    node *begin;
    node *end;
    size_t size;
} queue;

/* functions prototypes */

/* operation: initializate queue */
/* precondition: q_pt points to beginning of queue */
/* postcondition: queue initializate with NULL of begin and end pointers */
void queue_init(queue * const q_pt);

/* operation: add item to queue */
/* precondition: initializated queue and item for adding */
/* postcondition: item appends on the end of queue and function returns pointer of the item if allocation is successfull */
const Item* queue_add(queue * const q_pt, Item item);

/* operation: return the top element of queue */
/* precondition: initialized queue */
/* postcondition: return the top elelent of queue if exists and the NULL pointer otherwise */
const Item* queue_top(queue * const q_pt);

/* operation: remove the top element of queue */
/* precondition: initialized queue */
/* postcondition: function removes top item from queue and returns the pointer if success and the NULL otherwise */
const Item* queue_pop(queue * const q_pt);

/* operation: return size of queue */
/* precondition: initialized queue */
/* postcondition: function returns the size of queue */
size_t queue_size(queue * const q_pt);

/* operation: clean all queue */
/* precondition: initialized queue */
/* postcondition: clean up queue */
void queue_clean(queue * const pt);

#endif // _QUEUE_H_