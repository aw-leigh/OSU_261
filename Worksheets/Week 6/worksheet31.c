#ifndef BST
#define TYPE int 
#endif

struct AVLnode {
    TYPE value;
    struct AVLnode * left;
    struct AVLnode * right;
    int height;
};

struct AVLTree {
    struct AVLnode *root;
    int cnt;
};
 
 int _h(struct AVLnode * current){
    return current == 0 ? -1 : current->height;
}

 void _setHeight (struct AVLnode * current) {
      int lch = _h(current->left);
      int rch = _h(current->right);

      if (lch < rch) current->height = 1 + rch;
      else current->height = 1 + lch;
   }

struct AVLnode * _AVLnodeAdd (struct AVLnode* current, TYPE newValue) {
    struct AVLnode * newnode;

    if (current == 0) {
        newnode = (struct AVLnode *) malloc(sizeof(struct AVLnode));
        assert(newnode != 0);
        newnode->value = newValue;
        newnode->left = newnode->right = 0;
        newnode->height = 0;
        return newnode;
    } 

    if (LT(newValue, current->value)){
        current->left = AVLnodeAdd(current->left, newValue);
    }
    else {
        current->right = AVLnodeAdd(current->right, newValue);
    }
    return _balance(current);    /* <-   NEW  the call on balance */
}

int _bf (struct AVLnode * current){ 
    return _h(current->right) - _h(current->left);
}

struct AVLnode * _balance (struct AVLnode * current) {
    int cbf = _bf(current);
    if (cbf < -1) { //heavy left
        if (_bf(current->left) > 0){ // heavy right -> double rotation
            current->left = _rotateLeft(current->left);
        }
        return _rotateRight(current); // single rotation
    } else if (cbf > 1) { //heavy right
        if (_bf(current->right) < 0){  //heavy left -> double rotation
            current->right = _rotateRight(current->right);
        }
        return _rotateLeft(current);
    }
    setHeight(current);
    return current;
}

struct AVLnode * _rotateLeft (struct AVLnode * current) {

    struct AVLnode * newRoot = current->right;
    current->right = newRoot->left;
    newRoot->left = current;

    _setHeight(current);
    _setHeight(newRoot);

    return newRoot;

}

struct AVLnode * _rotateRight (struct AVLnode * current) {

    struct AVLnode * newRoot = current->left;
    current->left = newRoot->right;
    newRoot->right = current;

    _setHeight(current);
    _setHeight(newRoot);

    return newRoot;

}

void removeAVLTree(struct AVLTree * tree, TYPE val) {
   
   if (containsAVLTree(tree, val)) {
      tree->root = _removeNode(tree->root, val);
      tree->cnt--;
   }
}

TYPE _leftMost(struct AVLnode * cur) {
    
    while(cur->left != 0){
        cur = cur->left;
    }
    
    return cur->value;
}


struct AVLNode * _removeLeftmost(struct AVLnode * cur) {

    struct AVLNode *temp;

    if(cur->left != 0)
    {
        cur->left = _removeLeftmost(cur->left);
        return _balance(cur);
    }

    temp = cur->right;
    free(cur);
    return temp;
}

struct AVLNode *_removeNode(struct AVLnode * current, TYPE val) {

    //base case
    if(current->value == val){
        if(current->right == 0){
            struct AVLnode * temp = current->left;
            free(current);
            return temp;
        }
        else{
            current->value = _leftMost(current->right);
            current->right = _removeLeftmost(current->right);
        }
    }

    //recursive case
    if(current->value > val){
        current->left =_removeNode(current->left, val);
    }
    else{
        current->right = _removeNode(current->right, val);
    }
    return _balance(current);
}