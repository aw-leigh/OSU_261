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

struct linkedListStack {
   struct link *firstLink;
};

int linkedListStackIsEmpty (struct linkedListStack *s);
void linkedListStackPop (struct linkedListStack *s);


void linkedListStackInit (struct linkedListStack *s)
{ s->firstLink = 0; }

void linkedListStackFree (struct linkedListStack *s)
	{ while (! linkedListStackIsEmpty(s)) linkedListStackPop(s); }

void linkedListStackPush (struct linkedListStack *s, TYPE d) {
    struct link * newLink = malloc(sizeof(struct link));
    assert (newLink != 0);

    newLink->value = d;
    newLink->next = s->firstLink;
    s->firstLink = newLink;

}

TYPE linkedListStackTop (struct linkedListStack *s) {

    assert(!linkedListStackIsEmpty(s));
    return s->firstLink->value;
}

void linkedListStackPop (struct linkedListStack *s) {

    assert(!linkedListStackIsEmpty(s));

    //store pointer to 2nd element
    struct link * temp = s->firstLink->next;

    //delete top element
    free(s->firstLink);

    //new top is old 2nd element
    s->firstLink = temp;

}
int linkedListStackIsEmpty (struct linkedListStack *s) {

    return s->firstLink == 0;

}

/*
int main()
{
    return 0;
}*/