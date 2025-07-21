#include<stdio.h>
#include<stdlib.h>

//b1: XD cau truc can thiet
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;

//b2:xay dung ham khoi tao node
Node* createNode(int data) {
    Node * node=(Node*)malloc(sizeof(Node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}


//tim chieu cao cua cay nhi phan tu goc toi la
int heightBFS(Node* root) {
    if ( root == NULL) {
        return 0;
    }
    int ledt = heightBFS(root->left);
    int redt = heightBFS(root->right);
    if ( ledt > redt) {
        return ledt + 1;
    }
    else {
        return redt + 1;
    }
}

int main(void) {
    Node *root = NULL;
    root = createNode(1);
    Node* node1= createNode(2);
    Node* node2= createNode(3);
    Node* node3= createNode(4);
    Node* node4= createNode(5);
    Node* node5= createNode(6);
    Node* node6= createNode(7);
    Node* node7= createNode(8);
     root -> left = node1;
     root -> right = node2;
     node1 -> left = node3;
     node1 -> right = node4;
     node2 -> left = node5;
     node2 -> right = node6;
     node3 -> left = node7;


    heightBFS(root);
    printf( " chieu cao cua cay nhi phan la : %d \n",heightBFS(root));
    printf("\n");

    return 0;
}
