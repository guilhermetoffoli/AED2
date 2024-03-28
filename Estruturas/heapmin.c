#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEFT(i) (2 * (i) + 1)
#define RIGHT(i) (2 * (i) + 2)
#define PARENT(i) ((i) / 2)

typedef struct {
  int size;
  int capacity;
  char **heap;
} MinHeap;

MinHeap *create_heap(int capacity) {
  MinHeap *min_heap = malloc(sizeof(MinHeap));
  min_heap->size = 0;
  min_heap->capacity = capacity;
  min_heap->heap = malloc(capacity * sizeof(char *));
  return min_heap;
}

void swap(char **a, char **b) {
  char *temp = *a;
  *a = *b;
  *b = temp;
}

void push(MinHeap *min_heap, char *value) {
  if (min_heap->size == min_heap->capacity) {
    fprintf(stderr, "Error: heap is full\n");
    return;
  }

  min_heap->heap[min_heap->size] = value;
  int current = min_heap->size;
  min_heap->size++;

  while (current != 0 && strcmp(min_heap->heap[current], min_heap->heap[PARENT(current)]) < 0) {
    swap(&min_heap->heap[current], &min_heap->heap[PARENT(current)]);
    current = PARENT(current);
  }
}

char *pop(MinHeap *min_heap) {
  if (min_heap->size == 0) {
    fprintf(stderr, "Error: heap is empty\n");
    return NULL;
  }

  char *result = min_heap->heap[0];
  min_heap->heap[0] = min_heap->heap[min_heap->size - 1];
  min_heap->size--;
  min_heapify(min_heap, 0);

  return result;
}

void min_heapify(MinHeap *min_heap, int index) {
  int left = LEFT(index);
  int right = RIGHT(index);
  int smallest = index;

  if (left < min_heap->size && strcmp(min_heap->heap[left], min_heap->heap[index]) < 0) {
    smallest = left;
  }

  if (right < min_heap->size && strcmp(min_heap->heap[right], min_heap->heap[smallest]) < 0) {
    smallest = right;
  }

  if (smallest != index) {
    swap(&min_heap->heap[index], &min_heap->heap[smallest]);
    min_heapify(min_heap, smallest);
  }
}
