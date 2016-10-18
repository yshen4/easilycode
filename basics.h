#ifndef _BASICS_H_
#define _BASICS_H_
#include <stdbool.h>

typedef struct stack stack_t;
void stack_push(stack_t *stack, int d);
int stack_top(stack_t *stack);
int stack_pop(stack_t *stack);
bool stack_isempty(stack_t *stack);
int stack_size(stack_t *stack);
stack_t* stack_new();
void stack_delete(stack_t **stack);

typedef struct queue queue_t;
void queue_push(queue_t *q, int d);
int queue_top(queue_t *q);
int queue_pop(queue_t *q);
bool queue_isempty(queue_t *q);
int queue_size(queue_t *q);
queue_t* queue_new();
void queue_delete(queue_t **q);

typedef struct binaryheap binaryheap_t;
bool binaryheap_isempty(binaryheap_t *heap);
int binaryheap_size(binaryheap_t *heap);
int binaryheap_max(binaryheap_t *heap);
int binaryheap_popmax(binaryheap_t *heap);
void binaryheap_insert(binaryheap_t *heap, int v);
binaryheap_t *binaryheap_new(int *data, int n, int (*compf)(int a, int b), bool copy);
void binaryheap_delete(binaryheap_t **heap);
#endif
