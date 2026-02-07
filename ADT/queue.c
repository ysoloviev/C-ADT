#include "queue.h"


void queue_init(queue * const q_pt) {
    q_pt->begin = NULL;
    q_pt->end = NULL;
    q_pt->size = 0;
}

const Item* queue_add(queue * const q_pt, Item item) {
    node *node_pt = (node*)malloc(sizeof(node));
    if (node_pt == NULL) { // Error with memory allocation
        return NULL;
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
    return &(q_pt->end->item);
}

const Item* queue_top(queue * const q_pt) {
    if (q_pt->begin != NULL) {
        return &(q_pt->begin->item);
    } else {
        return NULL;
    }
}

const Item* queue_pop(queue * const q_pt) {
    if (q_pt->begin != NULL) {
        node *next = q_pt->begin->next;
        free(q_pt->begin); // Clean up pointer memory
        q_pt->begin = next;
        q_pt->size--;
        return &(next->item);
    } else {
        return NULL;
    }
}

size_t queue_size(queue * const q_pt) {
    return q_pt->size;
}

void queue_clean(queue * const q_pt) {
    node *begin = q_pt->begin;
    while (begin != q_pt->end) {
        node *next = begin->next;
        free(begin);
        begin = next;
        if (begin == NULL)
            return;
    }
}