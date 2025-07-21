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

//b3: xay dung cacc phuong thuc cua cay
//b3.1: xay dung ham preorder
void preorderDFS(Node* root) {  //in cay theo thu tu goc trai phai
    //xay dung de quy
    if ( root == NULL) {
        return;
    }
    //luon in ra node dang dc xet
    printf("%d ",root->data);
    //giai quyet bai toan vs cay con ben tay trai
    preorderDFS(root->left);
    //gia ai quyet bai toan vs cay con ben phai
    preorderDFS(root->right);
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

    printf("Preoder DFS :\n");
    preorderDFS(root);
    printf("\n");

    return 0;
}
