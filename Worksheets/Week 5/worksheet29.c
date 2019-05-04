#ifndef BST
#define TYPE int 
#endif

struct Node {
    TYPE value;
    struct Node * left;
    struct Node * right;
};

struct BinarySearchTree {
    struct Node *root;
    int size;
};

void initBST(struct BinarySearchTree *tree);
void addBST(struct BinarySearchTree *tree, TYPE newValue);
int sizeBST (struct BinarySearchTree *tree);
struct Node * _nodeAddBST (struct Node *current, TYPE newValue);
int containsBST (struct BinarySearchTree *tree, TYPE d);
void removeBST (struct BinarySearchTree *tree, TYPE d);
TYPE _leftMostChild (struct Node * current);
struct Node * _removeLeftmostChild (struct Node *current);
struct Node * _nodeRemoveBST (struct Node * current, TYPE d);
void freeBST(struct BinarySearchTree *tree);
TYPE getFirst(struct BinarySearchTree *tree);
void removeFirst(struct BinarySearchTree *tree);
void outputPriorityQueue(struct BinarySearchTree *tree);
int equalsBST(struct BinarySearchTree *tree1, struct BinarySearchTree *tree2);

void initBST(struct BinarySearchTree *tree) {
    tree->size = 0;
    tree->root = 0;
}

void addBST(struct BinarySearchTree *tree, TYPE newValue) {
    tree->root = _nodeAddBST(tree->root, newValue);
    tree->size++;
}

int sizeBST (struct BinarySearchTree *tree) {
    return tree->size;
}

struct Node * _nodeAddBST (struct Node *current, TYPE newValue) {

	if(current == 0){
        struct Node * newNode = (struct Node *) malloc(sizeof(struct Node));
        assert(newNode != 0);
        newNode->value = newValue;
        newNode->left = 0;
        newNode->right = 0;

        return newNode;
    }

	if(newValue < current->value){
        current->left = _nodeAddBST (current->left, newValue);
    }
    else{
        current->right = _nodeAddBST (current->right, newValue);
    }
    return current;
}

int containsBST (struct BinarySearchTree *tree, TYPE d) {

    struct Node * currentNode = tree->root;

    while(currentNode != 0){
        if(currentNode->value == d){
            return 1;
        }
        if(currentNode->value > d){
            currentNode = currentNode->left;
        }
        else{
        currentNode = currentNode->right;
        } 
    }
	return 0;
}
void removeBST (struct BinarySearchTree *tree, TYPE d) {
    if(containsBST(tree, d)){
        tree->root = _nodeRemoveBST(tree->root, d);
        tree->size--;
    }
}

TYPE _leftMostChild (struct Node * current) {
    assert(current != 0);

    while(current->left != 0){
        current = current->left;
    }
    return current->value;
}

struct node * _removeLeftmostChild (struct Node *current) {
    assert(current != 0);

    struct Node * temp = current->right;

    if(current->left == 0){
        free(current);
        return temp;
    }
    else{
        current->left = _removeLeftmostChild(current->left);
    }
    return current;
}

struct Node *  _nodeRemoveBST (struct Node * current, TYPE d) {

    if(current->value == d){
        if(current->right == 0){
            struct Node * temp = current->left;
            free(current);
            return temp;
        }
        else{
            current->value = _leftMostChild(current->right);
            current->right = _removeLeftmostChild(current->right);
        }
    }
    else if(current->value > d){
        current->left =_nodeRemoveBST(current->left, d);
    }
    else{
        current->right = _nodeRemoveBST(current->right, d);
    }
    return current;
}