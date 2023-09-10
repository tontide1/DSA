#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
#define MAX 100

typedef struct STACK
{
    int top;
    int arr[MAX];
}S;
void createStack(S *stack){
    stack->top = -1;
}
int isEmpty(S *stack){
    return (stack->top == -1);
}
int isFull(S *stack){
    return (stack->top == MAX - 1);
}
void push(S *stack, int n){
    if(isFull(stack)){
        printf("STACK IS FULL");
        return;
    }
    stack->top++;
    stack->arr[stack->top] = n;
}
int pop(S *stack){
    if(isEmpty(stack)){
        printf("STACK IS EMPTY");
        return -1;
    }
    int item = stack->arr[stack->top];
    stack->top--;
    return item;
}
int main(){
    int* nums;
    int numsSize;
    int target;
    int* returnSize;
    S myStack;
    createStack(&myStack);
    scanf("%d", &numsSize);

    nums = (int*)malloc(numsSize * sizeof(int));
    returnSize = (int*)malloc(numsSize * sizeof(int));
    for(int i = 0; i < numsSize; ++i)    
        scanf("%d", &nums[i]);
    int temp;
    scanf("%d", &target);
    for(int i = 0; i < numsSize - 1; ++i){
        for(int j = i + 1; j < numsSize; ++j){
            if(nums[i] > nums[j]){
                temp=nums[j];
                nums[j] = nums[i];
                nums[i]= temp;
            }
        }
    }
    int left = 0, right = numsSize - 1, idx = -1;
    while(left <= right){
        int mid = (left + right)/2;
        if(nums[mid] == target){
            idx++;
            push(&myStack,mid);
            right = mid-1;
        }else if(nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    while(!isEmpty(&myStack))
        printf("%d ", pop(&myStack));
    free(nums);
    free(returnSize);
    return 0;
}