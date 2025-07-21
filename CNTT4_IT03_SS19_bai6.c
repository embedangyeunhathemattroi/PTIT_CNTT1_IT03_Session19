#include<stdio.h>
#include<stdlib.h>


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


//3.4.6: xay dung ham lay phan tu ra khoi queue(b6)
void levelorderDFS(Node* root) {
    //b1: kiem tra cay rong
    if (root == NULL) {
        return;
    }
    //b2: kiem tra hang doi
    Queue *queue = createQueue(100);

    //b3: dua root vao hang doi
    enqueue(queue, root);

    //b4: thuc hien vong lap cho den khi hang doi trong
    while (!isEmpty(queue)) {
        //b5: lay phan tu ra khoi hang doi
        Node *node = queue->arr[queue->front++];  //tao node r luu nó lại
        printf("%d ", node->data);

        //b6: kiem tra va them con cay trai vao hang doi
        if (node->left != NULL) {
            enqueue(queue, node->left);
        }

        //b7: kiem tra va them con cay phai vao hang doi
        if (node->right != NULL) {
            enqueue(queue, node->right);
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



    printf("\n");
    printf("levelorder : \n");
    levelorderDFS(root);
printf("\n");

    return 0;
}
