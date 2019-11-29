#include "sol_AdHoc.h"

#define HEAP_SIZE 8192


static char heap[HEAP_SIZE];
static char *current_brk = (void*) 0;

void *_sbrk(size_t size)
{
    void *ptr;
    if (current_brk == ((void*)0))
        current_brk = heap;
    ptr = current_brk;
    current_brk += size;
    if ((current_brk - heap) > HEAP_SIZE)
        return (void*) 0;
    return ptr;
}
