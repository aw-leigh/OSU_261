#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifndef LinkedList
#define LinkedList
#define MAX_SIZE 100
#define TYPE int
#endif 


struct link {
   TYPE value;
   struct link * next;
};

struct listQueue {
   struct link *firstLink;
   struct link *lastLink;
};

void listQueueInit (struct listQueue *q) {
   struct link *lnk = (struct link *) malloc(sizeof(struct link));
   assert(lnk != 0); /* lnk is the sentinel */
   lnk->next = 0;
   q->firstLink = q->lastLink = lnk;
}

void listQueueAddBack (struct listQueue *q, TYPE e) {
    struct link * newLink = malloc(sizeof(struct link));
    assert(newLink != 0);

    newLink->value = e;
    newLink->next = q->lastLink->next;

    q->lastLink = q->lastLink->next = newLink;
}

TYPE listQueueFront (struct listQueue *q) {
    //ensure queue is not empty
    assert(q->firstLink != q->lastLink);

    //return the value of the link after the sentinel
    return q->firstLink->next->value;
}


void listQueueRemoveFront (struct listQueue *q) {
    //ensure queue is not empty
    assert(q->firstLink != q->lastLink);

    //store old front element
    struct link * temp = q->firstLink->next;

    //sentinel's next = new front element
    q->firstLink->next = temp->next;

    //free front element
    free(temp);

    //if the sentinel points to 0, then the list is empty. Point lastLink to sentinel
    if(q->firstLink->next == 0){
        q->lastLink = q->firstLink;
    }
}

int listQueueIsEmpty (struct listQueue *q) {
    return q->firstLink == q->lastLink;
}
