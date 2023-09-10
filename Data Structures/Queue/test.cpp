#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct Queue {
    int arr[MAX_SIZE];
    int front;
    int rear;
    int size;
} Queue;

void createQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
}

bool isFull(Queue *queue) {
    return queue->size == MAX_SIZE;
}

bool isEmpty(Queue *queue) {
    return queue->size == 0;
}

void enqueue(Queue *queue, int item) {
    if (isFull(queue)) {
        // Loại bỏ phần tử đầu tiên (ở front) nếu queue đã đầy
        queue->front = (queue->front + 1) % MAX_SIZE;
        queue->size--;
    }

    // Thêm phần tử mới vào cuối queue
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->arr[queue->rear] = item;
    queue->size++;
}

bool contains(Queue *queue, int item) {
    for (int i = 0; i < queue->size; i++) {
        int index = (queue->front + i) % MAX_SIZE;
        if (queue->arr[index] == item) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int k;
    scanf("%d", &k);

    Queue queue;
    createQueue(&queue);
    enqueue(&queue, arr[0]);

    for (int i = 1; i < n; i++) {
        if (!contains(&queue, arr[i]) && queue.size < k) {
            enqueue(&queue, arr[i]);
        } else if (!contains(&queue, arr[i]) && queue.size == k) {
            // Loại bỏ phần tử đầu tiên (ở front) và thêm phần tử mới vào cuối queue
            queue.front = (queue.front + 1) % MAX_SIZE;
            queue.arr[queue.rear] = arr[i];
        }
    }

    for (int i = 0; i < queue.size; i++) {
        int index = (queue.front + i) % MAX_SIZE;
        printf("%d ", queue.arr[index]);
    }

    return 0;
}