#define TYPE int

void dynArrayRemoveAt (struct dynArray * dy, int index);


struct dynArrayIterator {
    struct dynArray * da;
    int currentIndex; 
};

struct dynArray
{
	TYPE *data;	/* pointer to the data array */
	int size;		/* Number of elements in the array */
	int capacity;	/* capacity of the array */
};


void dynArrayIteratorInit (struct dynArray *da, struct dynArrayIterator *itr) {
 
    itr->da = da;
    itr->currentIndex = 0;
}

int dynArrayIteratorHasNext (struct dynArrayIterator *itr) {

    return(itr->currentIndex < itr->da->size);
}

TYPE dynArrayIteratorNext (struct dynArrayIterator *itr) {

    //return currentIndex, then increment currentIndex
    return (itr->da->data[itr->currentIndex++]);
}

void dynArrayIteratorRemove (struct dynArrayIterator *itr) {

    //step back to the index returned by the preceding Next() call
    itr->currentIndex--;
    dynArrayRemoveAt(itr->da, itr->currentIndex);
}