#include <stdio.h>
#include<stdlib.h>


typedef struct Binary_tree
{
    int data;
    struct Binary_tree * right;
    struct Binary_tree * left;
}NODE;

NODE * create_node(int value);


int main(int argc, char const *argv[])
{
    NODE * root = create_node(10);
    NODE * n1 = create_node(20);
    NODE * n2 = create_node(30);
    NODE * n3 = create_node(40);
    NODE * n4 = create_node(50);

    root->right = n1;
    root->left = n2;
    n1->right = n3;
    n2->left = n4;
    
    

    return 0;
}

NODE * create_node(int value){
    NODE * newnode = (NODE * )malloc(sizeof(NODE));
    if (newnode == NULL)
    {
        perror("Allocation Failed !!");
        exit(-1);
    }
    
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}