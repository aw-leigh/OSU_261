#define TYPE int 
#define LT(a, b) (a < b)

void heapRemoveFirst(struct dyArray *heap) {
    int last = dyArraySize(heap)-1;
    assert(dyArraySize(heap) > 0);    /* make sure we have at least one element */
            /* Copy the last element to the first  position */
    dyArrayPut(heap, 0, dyArrayrGet(heap, last)); 
    dyArrayRemoveAt(heap, last);       /* Remove last element.*/
    adjustHeap(heap, last, 0);/* Rebuild heap */
}

/*
void adjustHeap (struct dyArray * heap, int max, int pos)
    int leftChild = 2*pos + 1; int rightChild = 2 * pos + 2;

    if (rightChild < max) { /* we have two children 
        get index of smallest child
        if value at pos > value of smallest child
        swap with smallest child,  call adjustHeap (max, index of smallest child)
    else if (leftchild < max) { /* we have one child 
        if value at pos > value of child
            swap with smallest child, call adjustHeap (max, index of left child)
    /* else no children, done */

void swap (struct dyArray * v, int i, int j) {  /* swap elements i j */
    TYPE temp = dyArrayGet(v, i);  
    dyArrayPut(v, i, dyArrayGet(v, j)); 
    dyArrayPut(v, j, temp); 
}

int indexSmallest (struct dyArray * v, int i, int j) {   
    /* return index of smallest element */
    if (LT(dyArrayGet(v, i), dyArrayGet(v, j))){
        return i;
    }
    return j;
}

TYPE heapGetFirst (struct dyArray *heap) {   
    assert(dyArraySize(heap) > 0);    
    return dyArrayGet(heap, 0);  
}

void heapRemoveFirst(struct dyArray *heap) {
      int last = dyArraySize(heap)-1;
      assert(dyArraySize(heap) > 0);    /* make sure we have at least one element */
                    /* Copy the last element to the first  position */
      dyArrayPut(heap, 0, dyArrayrGet(heap, last)); 
      dyArrayRemoveAt(heap, last);       /* Remove last element.*/
      adjustHeap(heap, last, 0);/* Rebuild heap */
}

void adjustHeap(struct dyArray * heap, int max, int pos) {
    int leftChild = 2 * pos + 1;
    int rightChild = 2 * pos + 2;

    if(rightChild < max){
        int smallChildIndex = indexSmallest(heap, leftChild, rightChild);

        if(dyArrayGet(heap, pos) > dyArrayGet(heap, smallChildIndex)){
            swap(heap, pos, smallChildIndex);
            adjustHeap(heap, max, smallChildIndex);
        }
    }

    else if(leftChild < max){
        if(dyArrayGet(heap, pos) > dyArrayGet(heap, leftChild)){
            swap(heap, pos, leftChild);
            adjustHeap(heap, max, leftChild);
            //AW: Why is this necessary? if you have only a left child,
            //then by definition you're at the bottom of the tree
        }
    }
}
void heapAdd(struct dyArray * heap, TYPE newValue) {
    dyArrayAdd(heap, newValue); /* adds to end – now need to adjust position */

    int currentIndex = dyArraySize(heap) - 1;
    int parent;

    while(currentIndex != 0){
        parent = (currentIndex - 1) / 2;
        if(dyArrayGet(heap, parent) < newValue){
            swap(heap, parent, currentIndex);
            currentIndex = parent;
        }
        else return;
    }
}
