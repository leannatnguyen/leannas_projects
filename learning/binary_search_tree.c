#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

/* BST - binary search tree
- all nodes on the left of a root will be <= to the root
-roughly log(n) 
-only matters if the BST is balanced
*/
typedef struct tree_node {
    int value;
    struct tree_node *left;
    struct tree_node *right;
} tree_node;

tree_node *create_node(int value){
    tree_node* result = malloc(sizeof(tree_node));
    if (result != NULL){
        result->left = NULL;
        result->right = NULL;
        result->value = value;
    }
    return result;
}
void printtabs(int numtabs){
    for (int i = 0; i < numtabs; i++){
        printf("\t");
    }
}
void print_tree_rec(tree_node *root, int level){
    if (root == NULL){
        printtabs(level);
        printf("---<empty>---\n");
        return;
    }
    // pre-order traversal: go to node first then left then right
    printtabs(level);
    printf("value = %d\n", root->value);

    printf("left\n");
    printtabs(level);
    print_tree_rec(root->left, level + 1);

    printf("right\n");
    printtabs(level);
    print_tree_rec(root->right, level + 1); 

    printtabs(level);
    printf("done\n");
}
void print_tree(tree_node *root){
    print_tree_rec(root, 0);
}

//if tree root is null, need to change address root points to
bool insertnumber(tree_node **rootptr, int value){
    tree_node *root = *rootptr;
    if (root == NULL){
        //tree is empty
        (*rootptr) = create_node(value); //create a root node
        return true;
    }

    if (value == root->value){
        //do_nothing (already in tree no duplicates)
        return false;
    }

    if(value < root->value){
        //pass in address of the left node so we can change the value
        return insertnumber(&(root->left), value);
    } else {
        //pass in address of the right node so we can change the value
        return insertnumber(&(root->right),value);
    }
}

// this time did not pass in double pointer bc we're not changing the tree! (and its values)
//Recursive function!
bool findnumber(tree_node *root, int value){
    if (root == NULL){ //empty tree
        return false;
    }
    if (root->value == value){
        return true;
    }
    if (value < root->value){
        return findnumber(root->left, value);
    }
    else{
        return findnumber(root->right, value);
    }
}

int main(){
    tree_node *root = NULL;
    insertnumber(&root, 15);
    insertnumber(&root, 11);
    insertnumber(&root, 24);
    insertnumber(&root, 5);
    insertnumber(&root, 19);
    insertnumber(&root, 16);
    //print the tree
    print_tree(root);

    printf("%d (%d)\n", 16, findnumber(root, 16));
    printf("%d (%d)\n", 15, findnumber(root, 15));
    printf("%d (%d)\n", 5, findnumber(root, 5));
    printf("%d (%d)\n", 115, findnumber(root, 115));
    printf("%d (%d)\n", 1, findnumber(root, 1));
    printf("%d (%d)\n", 7, findnumber(root, 7));


}
