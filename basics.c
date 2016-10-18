#include "basics.h"
#include <stdio.h>

void test_stack() {
    int data[] = {1, 2, 3, 4, 5, 6};
    stack_t *stack = stack_new();
    for(int i = 0; i < 6; ++i) {
	stack_push(stack, data[i]);
	printf("push to stack: %d, size - %d, top - %d\n", data[i], stack_size(stack), stack_top(stack));
    }
    while(!stack_isempty(stack)) {
	int v = stack_pop(stack);
	printf("pop from stack: %d, size - %d\n", v, stack_size(stack));
    }
    stack_delete(&stack);
}

void test_queue() {
    int data[] = {1, 2, 3, 4, 5, 6};
    queue_t *queue = queue_new();
    for(int i = 0; i < 6; ++i) {
	queue_push(queue, data[i]);
	printf("push to queue: %d, size - %d, top - %d\n", data[i], queue_size(queue), queue_top(queue));
    }
    while(!queue_isempty(queue)) {
	int v = queue_pop(queue);
	printf("pop from queue: %d, size - %d\n", v, queue_size(queue));
    }

    queue_delete(&queue);
}

void test_binaryheap() {
    int data[] = {1, 2, 3, 4, 5, 6};
    binaryheap_t *heap = binaryheap_new(data, sizeof(data)/sizeof(int), NULL);
    while(!binaryheap_isempty(heap)) {
	int v = binaryheap_popmax(heap);
	printf("max to heap: %d, size - %d\n", v, binaryheap_size(heap));
    }
    binaryheap_delete(&heap);
}

int main(void) {
    test_stack();
    test_queue();
    test_binaryheap();
}
