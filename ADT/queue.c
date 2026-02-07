#include "queue.h"


void queue_init(queue *q_pt) {
    q_pt->begin = NULL;
    q_pt->end = NULL;
    q_pt->size = 0;
}

void queue_add(queue *q_pt, Item item) {
    node *node_pt = (node*)malloc(sizeof(node));
    if (node_pt == NULL) { // Error with memory allocation
        return;
    }
    node_pt->item = item;
    if (q_pt->begin != NULL) {
        q_pt->end->next = node_pt;
        q_pt->end = node_pt;
    } else {
        q_pt->begin = node_pt;
        q_pt->end = node_pt;
    }
    q_pt->size++;
}

const Item* queue_top(queue *q_pt) {
    if (q_pt->begin != NULL) {
        return &(q_pt->begin->item);
    } else {
        return NULL;
    }
}

const Item* queue_pop(queue *q_pt) {
    if (q_pt->begin != NULL) {
        node *next = q_pt->begin->next;
        q_pt->begin = next;
        q_pt->size--;
        return &(next->item);
    } else {
        return NULL;
    }
}

size_t queue_size(queue *q_pt) {
    return q_pt->size;
}