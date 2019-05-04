#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_SIZE 100
#define TYPE int
#define null 0

struct linkedListIterator {
    struct linkedList * lst;
    struct dlink * currentLink;
};

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

void _removeLink (struct linkedList *q, struct dlink *lnk) {
    //ensure list is not empty
    assert(!LinkedListIsEmpty(q));

    lnk->prev->next = lnk->next;  //node before lnk points to node after lnk
    lnk->next->prev = lnk->prev;  //node after lnk points to node before lnk
    free(lnk);  //delete lnk
    lnk = 0;

    q->size--;
}

void linkedListIteratorInit (struct linkedList  *lst, struct linkedListIterator * itr) {
   itr->lst = lst;
   itr->currentLink = itr->lst->frontSentinel;
}

int linkedListIteratorHasNext (struct linkedListIterator *itr) {

    return(itr->currentLink->next != itr->lst->backSentinel);
}

TYPE linkedListIteratorNext (struct linkedListIterator *itr) {

    itr->currentLink = itr->currentLink->next;
    return itr->currentLink->value;

}

/* think about the next one carefully. Draw a picture. What should itr->currentLink be pointing to after the remove operation? */

void linkedListIteratorRemove (struct linkedListIterator *itr) {
   
    itr->currentLink = itr->currentLink->prev;
    _removeLink(itr->lst, itr->currentLink->next);
}
