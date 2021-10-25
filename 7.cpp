// Елементи лівого піддерева збалансованого дерева пошуку зменшити на 1, 
//а правого – збільшити у 10 разів.
#include <iostream>
using namespace std;
struct node { 
    int x;
    int height;
    node* left;
    node* right;
    node(int num) { 
        x = num; 
        left = NULL;
        right = NULL; 
        height = 1; 
    }
};

int height(node *tree) { 
    if(tree) { 
        return tree->height; 
    }
    else {
        return 0;
    }
}

int bfactor(node *tree) { 
    int h;
    h = height(tree->right) - height(tree->left);
    return h;
}

void fixheight(node *tree) { 
    int h_left = height(tree->left);
    int h_right = height(tree->right);
    if (h_left > h_right) {
         tree->height = h_left + 1;
    }
    else {
        tree->height = h_right + 1;
    }
}

node *rotateright(node *tree) { 
    node *t = tree->left;
    tree->left = t->right;
    t->right = tree;
    fixheight(tree);
    fixheight(t);
    return t;
}

node *rotateleft(node *tree) { 
    node *t = tree->right;
    tree->right = t->left;
    t->left = tree;
    fixheight(tree);
    fixheight(t);
    return t;
}

node *balance(node * tree) {
    node *t; 
    fixheight(tree);
    if( bfactor(tree)==2 ) {
        if( bfactor(tree->right) < 0 ) {
            tree->right = rotateright(tree->right);
        }
        t=rotateleft(tree);
        return t;
    }
    if( bfactor(tree)==-2 ) {
        if( bfactor(tree->left) > 0 ) {
            tree->left = rotateleft(tree->left);
        }
        t=rotateright(tree);
        return t;
    }
    return tree; 
}

node *add(node *tree, int x) {
    node *t;
    if(!tree) { 
        return new node(x);
    }
    if( x < tree->x ) {
        tree->left = add(tree->left, x);
    }
    else {
        tree->right = add(tree->right, x);
    }
    t=balance(tree);
    return t;
}

void print(node *tree, int n) { 
    if (tree == NULL) {
        return;
    }
    n = n + 5;
    print(tree->right, n);
    cout << endl;
    for (int i = 5; i < n; i++) {
        cout << " ";
    }
    cout << tree->x << endl;
    print(tree->left, n);
}

void function_left(node *tree){
    if (tree != NULL) {
        function_left( tree->left );
        tree->x = tree->x - 1;
        function_left( tree->right );
    }
}

void function_right (node *tree) {
    if (tree != NULL) {
        function_right( tree->left );
        tree->x = tree->x * 10;
        function_right( tree->right );
    }
}

int main(){
    node *tree = NULL;
    int a;
    srand(time(0));
    for(int i; i<10;i++) {
        a = rand() % 100;
        tree=add(tree, a);
    }
    cout << "Начальное дерево:" << endl;
    print(tree, 0);
    cout << "Измененное дерево:" << endl;
    function_left(tree->left);
    function_right(tree->right);
    print(tree, 0);

}