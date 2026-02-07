#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdlib.h>

typedef int Item;

typedef struct Node {
    Item item;
    struct Node *next;
} node;

typedef struct {
    Node *begin;
    Node *end;
} queue;

/* functions prototypes */

/* operation: initializate queue */
/* precondition: q_pt points to beginning of queue */
/* postcondition: queue initializate with NULL of begin and end pointers */
void queue_init(queue *q_pt);

/* operation: add item to queue */
/* precondition: initializated queue and item for adding */
/* postcondition: item appends on the end of queue */
void queue_add(queue *q_pt, Item item);

/* operation: return the top element of queue */
/* precondition: initialized queue */
/* postcondition: return the top elelent of queue if exists and the NULL pointer otherwise */
const Item* queue_top(queue *q_pt);

/* operation: remove the top element of queue */
/* precondition: initialized queue */
/* postcondition: function removes top item from queue and returns the pointer if success and the NULL otherwise */
const Item* queue_pop(queue *q_pt);

/* operation: return size of queue */
/* precondition: initialized queue */
/* postcondition: function returns the size of queue */
size_t queue_size(queue *q_pt);

#endif // _QUEUE_H_