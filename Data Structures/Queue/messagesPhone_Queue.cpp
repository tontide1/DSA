#include <stdio.h>
#define MAX_SIZE 100

typedef struct QUEUE{
    int arr[MAX_SIZE];
    int front;
    int rear;
}Q;
void createQueue(Q *queue){
    queue->front = -1;
    queue->rear = -1;
}
int isFull(Q *queue){
    return queue->rear == MAX_SIZE-1;
}
int isEmpty(Q *queue){
    return (queue->rear == -1 && queue->front == -1);
}
int getSize(Q *queue) {
    if (isEmpty(queue)) {
        return 0;
    } else {
        return (queue->rear - queue->front + 1);
    }
}
void enqueue(Q *queue, int n){
    if(isFull(queue)){
        printf("QUEUE IS FULL \n");
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
    int n, k ,a[MAX_SIZE];
    int check[MAX_SIZE] = {0};
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%d", &k);
    for (int i = 0; i < n; ++i){
    // Kiểm tra xem số điện thoại a[i] đã xuất hiện trước đó hay chưa (kiểm tra bằng mảng check)
    if (!check[a[i]]) {
        // Nếu số điện thoại a[i] chưa xuất hiện trước đó thì thực hiện các bước sau:
        if (getSize(&myQueue) < k) {
            // Nếu queue chưa đủ k phần tử, thêm số điện thoại a[i] vào queue
            check[a[i]] = 1; // để đánh dấu là phần tử nào đã xuất hiện
            enqueue(&myQueue, a[i]);
        } else {
            // Nếu queue đã đủ k phần tử, loại bỏ phần tử đầu tiên (front) của queue
            check[myQueue.arr[myQueue.front]] = 0;
            // Thêm số điện thoại a[i] vào cuối queue
            check[a[i]] = 1;
            enqueue(&myQueue, a[i]);
            dequeue(&myQueue);
        }
    }
}
    while(!isEmpty(&myQueue)){
        printf("%d ", dequeue(&myQueue));
    }     
    return 0;
}