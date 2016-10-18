#include "basics.h"
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} node;

struct queue {
    node *head;
    node *tail;
    int size;
};

void queue_push(queue_t *q, int d) {
    struct node *nd = (node *)calloc(1, sizeof(node));
    nd->val = d;

    //First node inserted
    if (q->tail) q->tail->next = nd;
    if (!q->head) q->head = nd;

    //update the tail
    q->tail = nd;
   
    ++q->size;
}

//First in, first out
int queue_top(queue_t *q) {
    return q->head->val;
}

int queue_pop(queue_t *q) {
    struct node *topop = q->head;
    q->head = topop->next;
    --q->size;
    int v = topop->val;
    free(topop);
    return v;
}

bool queue_isempty(queue_t *q) {
    return q->size == 0;
}

int queue_size(queue_t *q) {
    return q->size;
}

queue_t* queue_new() {
    queue_t *q = (queue_t *)calloc(1, sizeof(queue_t));
    return q;
}

void queue_delete(queue_t **q) {
    if (*q) {
	while (!queue_isempty(*q)) {
	    queue_pop(*q);
        }
	free(*q);
    }
    *q = NULL;
}

