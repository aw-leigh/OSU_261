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
	da->data[position] = value;

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

