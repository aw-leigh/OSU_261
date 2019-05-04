#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifndef LinkedListDeque
#define LinkedListDeque
#define MAX_SIZE 100
#define TYPE int
#define EQ(a, b) (a == b)
#define null 0

#endif 

struct dlink {
   TYPE value;
   struct dlink * next;
   struct dlink * prev;
};

struct linkedList {
   int size;
   struct dlink * frontSentinel;
   struct dlink * backSentinel;
};

/* these functions are written for you */
void LinkedListInit (struct linkedList *q) {
   q->frontSentinel = (struct dlink *) malloc(sizeof(struct dlink));
   assert(q->frontSentinel != 0);
   q->backSentinel = (struct dlink *) malloc(sizeof(struct dlink));
   assert(q->backSentinel);
   q->frontSentinel->next = q->backSentinel;
   q->backSentinel->prev = q->frontSentinel;
   q->size = 0;
}

void linkedListFree (struct linkedList *q) {
   while (q->size > 0)
      linkedListRemoveFront(q);
   free (q->frontSentinel);
   free (q->backSentinel);
   q->frontSentinel = q->backSentinel = null;
}

void LinkedListAddFront (struct linkedList *q, TYPE e)
   { _addLink(q, q->frontSentinel->next, e); }

void LinkedListAddback (struct linkedList *q, TYPE e)
   { _addLink(q, q->backSentinel, e); }

void linkedListRemoveFront (struct linkedList *q) {
   assert(! linkedListIsEmpty(q));
   _removeLink (q, q->frontSentinel->next);
}

void LinkedListRemoveBack (struct linkedList *q) {
   assert(! linkedListIsEmpty(q));
   _removeLink (q, q->backSentinel->prev);
}

int LinkedListIsEmpty (struct linkedList *q) {
   return q->size == 0;
}
 
/* write addLink and removeLink. Make sure they update the size field correctly */

/* _addLink places a new link BEFORE the provide link, lnk */
void _addLink (struct linkedList *q, struct dlink *lnk, TYPE e) {

    //create new node and set value
    struct dlink * newNode = malloc(sizeof(struct dlink));
    assert(newNode);

    newNode->value = e;

    lnk->prev->next = newNode;  //node before lnk points to newNode
    newNode->prev = lnk->prev;  //newNode points to node before lnk
    lnk->prev = newNode;        //lnk points to newNode
    newNode->next = lnk;        //newNode points to lnk
    
    q->size++;

}

void _removeLink (struct linkedList *q, struct dlink *lnk) {
    //ensure deque is not empty
    assert(!LinkedListIsEmpty(q));

    lnk->prev->next = lnk->next;  //node before lnk points to node after lnk
    lnk->next->prev = lnk->prev;  //node after lnk points to node before lnk
    free(lnk);  //delete lnk
    lnk = 0;

    q->size--;
}

TYPE LinkedListFront (struct linkedList *q) {
    assert(!LinkedListIsEmpty(q));
    return q->frontSentinel->next->value;
}

TYPE LinkedListBack (struct linkedList *q) {
    assert(!LinkedListIsEmpty(q));
    return q->backSentinel->prev->value;
}

// NEW FUNCTIONS START HERE //
// NEW FUNCTIONS START HERE //
// NEW FUNCTIONS START HERE //

int linkedListContains (struct linkedList *lst, TYPE e) {

//The method contains must use a loop to cycle over the chain of links. 
//Each element is tested against the argument, using the EQ (equal to) macro. 
//If any are equal, then the Boolean value true is returned. 
//Otherwise, if the loop terminates without finding any matching element, the value False is returned.
    
    //set node pointer to first node after front sentinel
    struct dlink * temp = lst->frontSentinel->next;

    //loop until we reach the back sentinel
    while(!EQ(temp, lst->backSentinel)) {
        
        //return true if value found
        if(EQ(temp->value, e)){
            return 1;
        }
        
        temp = temp->next;
    }
    return 0;
}

void linkedListRemove (struct linkedList *lst, TYPE e) {

//The remove method uses a similar loop. 
//However, this time, if a matching value is found, then the method removeLink is invoked. 
//The method then terminates, without examining the rest of the collection.

    struct dlink * temp = lst->frontSentinel->next;

    //loop until we reach the back sentinel
    while(!EQ(temp, lst->backSentinel)) {
        
        //if value is found, remove node and return to calling function
        if(EQ(temp->value, e)){
            _removeLink(lst, temp);
            return;
        }
        else{
            temp = temp->next;
        }
    }
    return;
}