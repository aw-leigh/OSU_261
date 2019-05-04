/*Assume you have access to all existing dynArr functions */

#include <stdio.h>
#include <stdlib.h>

# ifndef TYPE
# define TYPE int
# endif

struct DynArr
{
	TYPE *data;	/* pointer to the data array */
	int size;		/* Number of elements in the array */
	int capacity;	/* capacity of the array */
};

void initDynArr(struct DynArr *v, int capacity)
{
	v->data = malloc(sizeof(TYPE) * capacity);
	assert(v->data != 0);
	v->size = 0;
	v->capacity = capacity;

}	
void freeDynArr(struct DynArr *v)
{
	if(v->data != 0)
	{
		free(v->data); 	/* free the space on the heap */
		v->data = 0;   	/* make it point to null */
	}
	v->size = 0;
	v->capacity = 0;
}



int sizeDynArr( struct DynArr *v)
{
	return v->size;
}

void   addDynArr(struct DynArr *v, TYPE val)
{
	/* Check to see if a resize is necessary */
	if(v->size >= v->capacity)
		_setCapacityDynArr(v, 2 * v->capacity);
	
	v->data[v->size] = val;
	v->size++;	
}

//The only thing missing now is the _setCapacityDynArr function.   Complete the implementation of _setCapacityDynArr.  Pay careful attention to the order of operations.  Remember that since you�re creating a new array, you�ll want to eventually get rid of the old one to avoid a �memory leak�.  

void _setCapacityDynArr(struct DynArr *v, int newCap)
{
	struct DynArr newArray;
	initDynArr(&newArray, newCap);

	//copy contents of old array into new array
	for(int i = 0; i < v->capacity; i++)
	{
		newArray.data[i] = v->data[i];
	}

	//update size
	newArray.size = v->size;

	//delete old array
	freeDynArr(v);

	//set v pointer to new array
	*v = newArray;

}

//In order to allow a dynamically allocated array to be used in the same fashion as a normal array, 
//we need functions that will get and set values at a given position. We can also make our function more robust than the regular C array by checking index positions.
//Complete the implementation of the following functions. Use assert to check that index positions are legal.


TYPE getDynArr (struct DynArr * da, int position) {

	assert((position < da->size) && (position >= 0));
	return da->data[position];

}

void putDynArr(struct DynArr * da, int position, TYPE value) {

	assert((position < da->size) && (position >= 0));

	if (da->size > da->capacity - 1)
	{
		_setCapacityDynArr(da, da->capacity * 2);
	}
	for(int i = position; i < da->size - 1; i++)
	{	
		da->data[i] = da->data[i + 1];
	}

	da->data[position] = value;
	da->size++;

}



//Write the function swap, which will exchange the values in two positions of a dynamic array.
//We will use this function in later chapters.
void swapDynArr (struct DynArr * da, int i, int j) {

	TYPE temp;
	
	//ensure indices are valid
	assert((i < da->size) && (i >= 0));
	assert((j < da->size) && (j >= 0));

	//swap
	temp = da->data[i];
	da->data[i] = da->data[j];
	da->data[j] = temp;

}

//Write the function removeAtDynArr, which will remove a value at a specified index.
//Remember, we do not want to leave gaps in the partially filed array.
//We will use this function in later chapters.
void removeAtDynArr (struct DynArr * da, int index) {

	//index check
	assert((index < da->size) && (index >= 0));

	for(int i = index + 1; i < da->size; i++)
	{
		da->data[i - 1] = da->data[i];
	}
	da->size--;

}

/* _binarySearch is also included in dynArr.c now as an internal function! */
int _binarySearch(TYPE *data, int size, TYPE testValue);


/* These are the new functions to take advantage of the ordered dynamic array 
   and available to the end user , so they will be declared in the .h file */

int dyArrayBinarySearch (struct DynArr * da, TYPE testValue) {
   return _binarySearch (da->data, da->size, testValue); }

void orderedArrayAdd (struct DynArr *da, TYPE newElement) {
   int index = _binarySearch(da->data, da->size, newElement);
   dyArrayAddAt (da, index, newElement);  /* takes care of resize if necessary*/
}


///// WORKSHEET FUNCTIONS START HERE //////

   /* you must complete the following */

 int orderedArrayContains (struct DynArr *da, TYPE testElement) {
    int index = _binarySearch(da, da->size, testElement);

    //if legal index, return if it matches data
    if(index < da->size){ 
        return da->data[index] == testElement;
    }
    
    //if illegal index, return false
    return 0; 
}

 void orderedArrayRemove (struct DynArr *da, TYPE testElement) {

    int index = _binarySearch(da, da->size, testElement);

    //if index is legal and testElement is found, delete that index
    if(index < da->size){ 
        if(da->data[index] == testElement){
            removeAtDynArr(da, index);
        }
    }
}