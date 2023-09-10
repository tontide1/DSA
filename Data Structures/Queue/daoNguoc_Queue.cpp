#include <stdio.h>
#define MAX_SIZE 100
typedef struct QUEUE{
    int arr[MAX_SIZE];
    int front;
    int rear;
}Q;

void createQueue(Q *queue){
    queue->rear = -1;
    queue->front = -1;
}
int isFull(Q *queue){
    return (queue->front == MAX_SIZE - 1);
}
int isEmpty(Q *queue){
    return (queue->front == -1 && queue->rear == -1);
}
void enqueue(Q *queue, int n){
    if(isFull(queue)){
        printf("QUEUE IS FULL !\n");
        return;
    }
    if(isEmpty(queue))
        queue->front = 0;
    queue->rear++;
    queue->arr[queue->rear] = n;    
}
int dequeue(Q *queue){
    if(isEmpty(queue)){
        printf("QUEUE IS EMPTY !\n");
        return -1;
    }

    int res = queue->arr[queue->front];
    if(queue->front == queue->rear){
        queue->front = -1;
        queue->rear = -1;
    }else{
        queue->front++;
    }
    return res;
}

int main(){
    Q myQueue;
    createQueue(&myQueue);
    int n, a[MAX_SIZE], k;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
        enqueue(&myQueue, a[i]);
    }
    scanf("%d", &k);
    for (int i = 0; i < k; ++i)
    {
        int x = myQueue.arr[myQueue.front]; // lưu lại giá trị front trước khi deque
        dequeue(&myQueue);
        enqueue(&myQueue, x);
    }
    while(!isEmpty(&myQueue)){
        printf("%d ", myQueue.arr[myQueue.front]);
        dequeue(&myQueue);
    }
    return 0;
}