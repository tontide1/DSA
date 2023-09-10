#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
}Q;

void createQueue(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

bool isEmpty(struct Queue *queue) {
    return (queue->front == -1 && queue->rear == -1);
}

bool isFull(struct Queue *queue) {
    return (queue->rear == MAX_SIZE - 1);
}

void enqueue(struct Queue *queue, int item) { // thêm 1 phần tử mới vào queue
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue item: %d\n", item);
        return;
    }

    if (isEmpty(queue)) { // cập nhật chỉ số index đầu tiên cho phần tử khi mà queue rỗng
        queue->front = 0;
    }

    queue->rear++;
    queue->items[queue->rear] = item;
}

int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Giá trị -1 có thể được sử dụng để biểu thị queue trống.
    }

    int item = queue->items[queue->front];
    
    /*kiểm tra đây có phải là phần tử cuối cùng của hàng đợi hay không.
    nếu cùng trỏ đến 1 index thì chứng tỏ phần tử cuối cùng */
    if (queue->front == queue->rear) {
        // cập nhập index = -1 cho đầu (front) và cuối (rear) -> rỗng
        queue->front = -1; 
        queue->rear = -1;
    } else {
        //Nếu không phải, ta chỉ cần tăng giá trị của front lên một đơn vị để trỏ đến phần tử tiếp theo trong hàng đợi.
        queue->front++;
    }
    return item;
}

int peek(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot peek.\n");
        return -1; // Giá trị -1 có thể được sử dụng để biểu thị queue trống.
    }

    return queue->items[queue->front];
}

int rear(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot get rear.\n");
        return -1; // Giá trị -1 có thể được sử dụng để biểu thị queue trống.
    }

    return queue->items[queue->rear];
}

int main() {
    struct Queue myQueue;
    createQueue(&myQueue);

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);

    printf("Front of the queue: %d\n", peek(&myQueue));
    printf("Rear of the queue: %d\n", rear(&myQueue));

    printf("Dequeued item: %d\n", dequeue(&myQueue));
    printf("Dequeued item: %d\n", dequeue(&myQueue));

    printf("Front of the queue after dequeuing: %d\n", peek(&myQueue));
    printf("Rear of the queue after dequeuing: %d\n", rear(&myQueue));
    return 0;
}
