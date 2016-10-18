#include "basics.h"
#include <stdlib.h>

#define DEFAULT_CAPACITY 64
struct stack {
    int capacity;
    int size;
    int *data;
};

static void stack_double_buffer(stack_t *stack) {
    stack->capacity *= 2;
    stack->data = (int *)realloc(stack->data, sizeof(int) * stack->capacity);
}

static void stack_half_buffer(stack_t *stack) {
    stack->capacity /= 2;
    stack->data = (int *)realloc(stack->data, sizeof(int) * stack->capacity);
}

void stack_push(stack_t *stack, int d) {
    if (stack->size >= stack->capacity) {
	stack_double_buffer(stack);
    }
    stack->data[stack->size++] = d;
}

int stack_top(stack_t *stack) {
    return stack->data[stack->size - 1];
}

int stack_pop(stack_t *stack) {
    int v = stack->data[--stack->size];
    if (stack->capacity > 2 * DEFAULT_CAPACITY && stack->size * 4 < stack->capacity) {
	stack_half_buffer(stack);
    }
    return v;
}

bool stack_isempty(stack_t *stack) {
    return stack->size == 0;
}

int stack_size(stack_t *stack) {
    return stack->size;
}

stack_t* stack_new() {
    stack_t *stack = (stack_t *)calloc(1, sizeof(stack_t));
    stack->capacity = DEFAULT_CAPACITY;
    stack->data = (int *)calloc(stack->capacity, sizeof(int));
    return stack;
}

void stack_delete(stack_t **stack) {
    if (*stack) {
	if ((*stack)->data) free((*stack)->data);
    	free(*stack);
    }
    *stack = NULL;
}

