#include <stdio.h>
#include <stdlib.h>

#define maxSize 50

typedef struct {
    int data[maxSize];
    int top;
} Stack;

void initStack(Stack *stack) {
    stack->top = -1;
}

void push(Stack *stack, int value) {
    stack->data[++stack->top] = value;
}

int pop(Stack *stack) {
    return stack->data[stack->top--];
}

int peek(Stack *stack) {
    return stack->data[stack->top];
}

int isStackEmpty(Stack *stack) {
    return stack->top == -1;
}

int isStackFull(Stack *stack) {
    return stack->top == maxSize - 1;
}

int twoStacks(int maxSum, int a[], int b[], int x, int y) {
    Stack stackA, stackB;
    initStack(&stackA);
    initStack(&stackB);
    
    // Push elements to stacks
    for (int i = x - 1; i >= 0; i--) {
        push(&stackA, a[i]);
    }
    for (int i = y - 1; i >= 0; i--) {
        push(&stackB, b[i]);
    }

    int total = 0, count = 0;
    int length = x >= y ? y : x;

    for (int i = 0; i < length; i++) {
        if (total + peek(&stackA) <= maxSum) {
            total += pop(&stackA);
            count++;
        }
        if (total + peek(&stackB) <= maxSum) {
            total += pop(&stackB);
            count++;
        }
    }
    return count;
}

int main() {
    int total;
    printf("Masukan berapa total game: ");
    scanf("%d", &total);

    while (total--) {
        int x, y, maxSum;
        printf("Masukan maksimal array a, b, dan maksimal perttambahan secara berturut:\n");
        scanf("%d %d %d", &x, &y, &maxSum);

        int a[x], b[y];
        printf("Masukan angka yang ada di array a:\n");
        for (int i = 0; i < x; i++) {
            scanf("%d", &a[i]);
        }
        printf("Masukan angka yang ada di array b:\n");
        for (int i = 0; i < y; i++) {
            scanf("%d", &b[i]);
        }
        int result = twoStacks(maxSum, a, b, x, y);
        printf("Total pengoerasian yang terjadi: %d\n", result);
    }
    return 0;
}