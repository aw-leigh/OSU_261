struct DLink{
    int val;
    struct DLink * next;
    struct DLink * prev;
};

struct linkedList {
    struct DLink * frontSentinel;
    struct DLink * backSentinel;
};

struct linkedListIterator {
    struct linkedList * lst;
    struct DLink * cur;
};

void linkedListIteratorInit (struct linkedList *lst, struct linkedListIterator * itr){
    itr->lst = lst;
    itr->cur = lst->frontSentinel;
}
int linkedListIteratorHasNext (struct linkedListIterator *itr) {
    assert(itr);
    return itr->cur->next != itr->lst->backSentinel;
}


int linkedListIteratorNext (struct linkedListIterator *itr) {
    itr->cur = itr->cur->next;
    return itr->cur->val;
}