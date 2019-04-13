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

/* the following were written in earlier lessons */
void initDynArr (struct DynArr * da, int initCap);
void addDynArr(struct DynArr * da, TYPE e);      

/* remove was shown earlier, to use removeAt */
void removeDynArr (struct DynArr * da, TYPE test) {
   int i;
   for (i = 0; i < da->size; i++) {
      if (EQ(test, da->data[i])) { /* found it */
         _dynArrayRemoveAt(da, i);
         return;
      }
   }
}

/* you must write the following */

int containsDynArr (struct DynArr * da, TYPE e) {

	int i;
	for(i = 0; i < da->size; i++)
	{
		if(EQ(da->data[i], e)) //if e is found, return 1 (true)
		{
			return 1;
		}
	}
	return 0;  //otherwise, return 0 (false)
}