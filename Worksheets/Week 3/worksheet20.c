#include <stdio.h>
#include <stdlib.h>

#ifndef ArrayDeque
#define ArrayDeque

#define MAX_SIZE 100

#define TYPE int
#define EQ(a, b) (a == b)

struct deque {
    TYPE * data;
    int capacity;
    int size;
    int beg;
};

/* Interface */
void _dequeSetCapacity (struct deque *d, int newCap);
void dequeFree (struct deque *d);
void dequeInit (struct deque *d, int initCapacity);
int dequeSize (struct deque *d);
void dequeAddFront (struct deque *d, TYPE newValue);
void dequeAddBack (struct deque *d, TYPE newValue);
TYPE dequeFront (struct deque *d);
TYPE dequeBack (struct deque *d);
void dequeRemoveFront (struct deque *d);
void dequeRemoveBack (struct deque *d);

#endif 

/*Using this idea, complete the implementation of the Deque. 
//Implement the methods that will add, retrieve, or remove an element from either the front or back.
//Explain why each operation will have constant (or amortized constant) execution time.
*/

void _dequeSetCapacity (struct deque *d, int newCap) {
	int i;
	
	/* Create a new underlying array*/
	TYPE *newData = malloc(sizeof(TYPE)*newCap);
	assert(newData != 0);
	
	/* copy elements to it */
	int j = d->beg;
	for(i = 0; i < d->size; i++)
	{
		newData[i] = d->data[j];
		j = j + 1;
		if(j >= d->capacity)
			j = 0;
	}
	
	/* Delete the oldunderlying array*/
	free(d->data);
    
	/* update capacity and size and data*/
	d->data = newData;
	d->capacity = newCap;
	d->beg = 0;
}

void dequeFree (struct deque *d) {
   free(d->data); d->size = 0; d->capacity = 0;
} 


void dequeInit (struct deque *d, int initCapacity) {
   d->size = d->beg = 0;
   d->capacity = initCapacity; assert(initCapacity > 0);
   d->data = malloc(initCapacity * sizeof(TYPE));
   assert(d->data != 0);
}

int dequeSize (struct deque *d) { return d->size; }


/* ASSIGNMENT STARTS HERE */

void dequeAddFront (struct deque *d, TYPE newValue) {
    if (d->size >= d->capacity) _dequeSetCapacity(d, 2*d->capacity);

    //decrement beg, and loop to back index if we are already at front
    if(--d->beg < 0){
        d->beg = d->capacity - 1;
    }

    d->data[d->beg] = newValue;
    ++d->size;
}

void dequeAddBack (struct deque *d, TYPE newValue) {
   if (d->size >= d->capacity) _dequeSetcapacity(d, 2* d->capacity);

    //if size + begin > capacity, loop to front
    d->data[(d->size + d->beg) % d->capacity] = newValue;
    ++d->size;
}


TYPE dequeFront (struct deque *d) {
    assert(d->size > 0);
    return d->data[d->beg];
}

TYPE dequeBack (struct deque *d) {
    assert(d->size > 0);
    return d->data[((d->size + d->beg) % d->capacity) - 1];
}


void dequeRemoveFront (struct deque *d) {
    assert(d->size > 0);

    //if begin is last element, loop to front
    d->beg = (d->beg + 1) % d->capacity;

    --d->size;

}

void dequeRemoveBack (struct deque *d) {
    assert(d->size > 0);
    --d->size;
}
