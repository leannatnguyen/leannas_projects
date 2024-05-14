#include <stdio.h>
#include <stdlib.h>
/* Trees
- can represent file systems
-hierarchical relationships
-where data elements are connected

trees are really good with recursion
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

int main(){
    tree_node *n1 = create_node(10);
    tree_node *n2 = create_node(11);
    tree_node *n3 = create_node(12);
    tree_node *n4 = create_node(13);
    tree_node *n5 = create_node(14);

    // set n1 as the head node (root)
    n1->left = n2;
    n1->right = n3;

    // set n4 and n5 as the children of n3
    n3->left = n4;
    n3->right = n5;

    //print the tree
    print_tree(n1);

    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
}