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


//b3.4:xay dung ham levelorder
typedef struct Queue {
    Node ** arr;
    int cap;
    int front;
    int rear;
}Queue;
//b3.4.2: xay dung ham khoi tao queue
Queue * createQueue(int cap) {
    Queue * queue = (Queue*)malloc(sizeof(Queue));
    queue->arr = (Node**)malloc(sizeof(Node*)*cap);
    queue->cap = cap;
    queue->front = 0;
    queue->rear = -1;
    return queue;
}

//b3.4.3: xay dung ham kiem tra ham doi trong
int isEmpty(Queue * queue) {
    if ( queue -> front > queue -> rear) {
        return 1;
    }
    return 0;
}

//3.4.5: xay dung ham them phan tu vao queue
void enqueue(Queue * queue, Node * node) {
    if ( queue->rear == queue->cap - 1) {
        printf("Queue is full");
        return;
    }
    queue->rear++;
    queue->arr[queue->rear] = node;
}

Node * dequeue(Queue * queue) {
    if (isEmpty(queue)) {
        return NULL;
    }

    return queue -> arr[queue -> front ++];
}

//them node
void insertNode(Node* root, int data) {
    Node * node = createNode(data);
    if (root == NULL) {
        root= node;
        return;
    }
    Queue * queue = createQueue(100);
    enqueue(queue, root);
    while (!isEmpty(queue)) {
        Node * temp= dequeue(queue);
        if (temp->left == NULL) {
            temp->left = node;
            break;
        }else {
            enqueue(queue, temp->left);
        }
        if (temp->right == NULL) {
            temp->right = node;
            break;
        }else {
            enqueue(queue, temp->right);
        }
    }
}



void levelorderDFS(Node * root) {
    if (root == NULL) {
        return;
    }
    Queue * queue = createQueue(100);
    enqueue(queue, root);
    while (!isEmpty(queue)) {
        Node * temp = dequeue(queue);
        printf("%d ", temp->data);
        if (temp->left != NULL) {
            enqueue(queue, temp->left);
        }
        if (temp->right != NULL) {
            enqueue(queue, temp->right);
        }
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




printf("Them node vao cay nhin phan : \n");
insertNode(root,9);
    insertNode(root,10);
    printf("\n");

    levelorderDFS(root);
    printf("insert Node thanh cong \n");



    return 0;
}
