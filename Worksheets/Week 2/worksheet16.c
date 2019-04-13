#include <stdio.h>
#include <stdlib.h>

#ifndef ArrayBagStack
#define ArrayBagStack
#define MAX_SIZE 100


#define TYPE int
#define EQ(a, b) (a == b)


#endif 


struct DynArr {
        TYPE * data;
        int size;
        int capacity;
};


void dynArrayPush (struct DynArr * da, TYPE e) {

	//if stack is full, double its capacity
	if(da->size >= da->capacity)
		_setCapacityDynArr(da, 2 * da->capacity);
	
	da->data[da->size] = e;
	da->size++;

}

TYPE dynArrayTop (struct DynArr * da) {

	//check if stack is empty
	assert(da->size > 0);
	
	//return value at top of the stack
	return da->data[da->size - 1];

}

void dynArrayPop (struct DynArr * da) {

	//check if stack is empty
	assert(da->size > 0);

	da->size--;

}

int dynArrayIsEmpty (struct DynArr * da) {

	return da->size == 0;

}
