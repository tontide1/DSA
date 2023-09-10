#include <stdio.h>
#include <math.h>
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
int isPrime(int n){
    if(n < 2)
        return 0;
    for(int i = 2; i <= sqrt(n); ++i){
        if(n % i == 0)
            return 0;
    }
    return 1;
}
// cách 1: đơn giản nhất ! Ta sẽ sử dụng hàm siêu số nguyên tố. Nếu true thì enqueue
int isSuperPrime(int n){
    if(!isPrime(n))
        return 0;
    while(n > 0){
        if(!isPrime(n))
            return 0;
        n = n / 10;
    }
    return 1;
}
int main(){
    Q myQueue;
    createQueue(&myQueue);
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n && i < 10; ++i) // enqueue các siêu số nguyên tố nhỏ hon 10: 2 3 5 7
    {
        if(isPrime(i)){
            enqueue(&myQueue, i);
        }
    }
    while(!isEmpty(&myQueue)){
        for(int i = 1; i <= 9; i++){
            /*Với mỗi số nguyên tố hiện tại trong hàng đợi (ban đầu là 2, 3, 5, 7), chúng ta lặp qua các chữ số từ 1 đến 9 và ghép nối chúng thành một số mới. Nếu số mới nhỏ hơn n và là một số nguyên tố, thì chúng ta thêm số mới này vào hàng đợi.*/
            int k = myQueue.arr[myQueue.front] * 10 + i;
            if(k < n && isPrime(k)){
                enqueue(&myQueue, myQueue.arr[myQueue.front] * 10 + i);
            }
        }
        // sau đó in ra và xóa khỏi queue và lặp lại 1 lần nữa
        printf("%d ", dequeue(&myQueue));
    }
    return 0;
}
//test case: 30 -> 2 3 5 7 23 29