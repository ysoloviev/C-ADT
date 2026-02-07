#include <stdio.h>
#include "ADT/queue.h"

int main() {

    queue q;

    queue_init(&q);

    queue_add(&q, 1);
    queue_add(&q, 2);
    queue_add(&q, 3);

    printf("%d %p %zd\n", *queue_top(&q), queue_top(&q), queue_size(&q));
    queue_pop(&q);
    printf("%d %p %zd\n", *queue_top(&q), queue_top(&q), queue_size(&q));
    queue_pop(&q);
    printf("%d %p %zd\n", *queue_top(&q), queue_top(&q), queue_size(&q));
    queue_pop(&q);
    // printf("%d %p\n", *queue_top(&q), queue_top(&q));

    queue_add(&q, 1);
    queue_add(&q, 2);
    queue_add(&q, 3);
    queue_add(&q, 4);

    queue_clean(&q);

    printf("%zd\n", queue_size(&q));
    // queue_pop(&q);
    // printf("%d %p\n", *queue_top(&q), queue_top(&q));
    // queue_pop(&q);
    // printf("%d %p\n", *queue_top(&q), queue_top(&q));

    return 0;
}