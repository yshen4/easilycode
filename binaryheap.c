#include "basics.h"
#include <stdlib.h>
#include <string.h>

static int default_compare(int a, int b) {
    return a - b;
}

struct binaryheap {
    int *data;
    int capacity;
    int size;
    int (*compare)(int a, int b);
};

static void double_buffer(binaryheap_t *heap) {
    heap->capacity *= 2;
    heap->data = (int *)realloc(heap->data, heap->capacity * sizeof(int));
}

static int left(int k) {
    return 2*k+1;
}

static int right(int k) {
    return 2*k+2;
}

static int parent(int k) {
    return (k-1)/2;
}

static void swap(int *data, int i, int j) {
    int t = data[i];
    data[i] = data[j];
    data[j] = t;
}

// d[k/2] >= data[k]
static void swim(binaryheap_t *heap, int k) {
    int p = parent(k);

    //parent is less than the child
    while (k > 0 && heap->compare(heap->data[p], heap->data[k]) < 0) {
	swap(heap->data, k, p);
	k = p;
	p = parent(k);
    }
}

static void sink(binaryheap_t *heap, int k) {
    int l = left(k);
    while(l < heap->size) {
 	int j = l, r = l + 1;

	//Get the max of l and r
	if (r < heap->size && heap->compare(heap->data[l], heap->data[r]) < 0) j = r;

	//parent is less than the child
	if (heap->compare(heap->data[k], heap->data[j]) >= 0) break;

	swap(heap->data, k, j);

	//Next layer 
	k = j;
	l = left(k);
    }
}

static void heapify(binaryheap_t *heap) {
    int r = parent(heap->size - 1);
    while( r >= 0) {
	sink(heap, r);
	--r;
    }
}

int binaryheap_max(binaryheap_t *heap) {
    return heap->data[0];
}

int binaryheap_popmax(binaryheap_t *heap) {
    int max = heap->data[0];
    swap(heap->data, 0, --heap->size);
    sink(heap, 0);
    return max;
}

bool binaryheap_isempty(binaryheap_t *heap) {
    return heap->size == 0;
}

int binaryheap_size(binaryheap_t *heap) {
    return heap->size;
}

void binaryheap_insert(binaryheap_t *heap, int v) {
    if (heap->size >= heap->capacity) double_buffer(heap);
    heap->data[heap->size++] = v;
    swim(heap, heap->size - 1);
}


binaryheap_t *binaryheap_new(int *data, int n, int (*compf)(int a, int b)) {
    binaryheap_t *heap = (binaryheap_t *)calloc(1, sizeof(binaryheap_t));
    heap->capacity = n;
    heap->size = n;
    heap->data = (int *)calloc(n, sizeof(int));
    memcpy(heap->data, data, n * sizeof(int));

    if (compf) heap->compare = compf;
    else heap->compare = &default_compare;

    heapify(heap);
    return heap;
}

void binaryheap_delete(binaryheap_t **heap) {
    if (*heap) {
	if ((*heap)->data) free((*heap)->data);
        free(*heap);
    }
    *heap = NULL;
}
