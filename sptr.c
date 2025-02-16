#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int * arr;
};

int isFull(struct stack* ptr){
     if (ptr->top == ptr->size-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(struct stack* ptr){
     if (ptr->top == -1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack * ptr, int val){
    if (isFull(ptr))
    {
        printf("stack overflow! cannot push %d to the stack \n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
    
}

int pop(struct stack * ptr){
    if (isEmpty(ptr))
    {
        printf("stack underflow! cannot pop %d to the stack \n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
    
}
int main(){
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("stack has been created successfully\n");
    
    printf(" before pushing, full: %d\n", isFull(sp));
    printf(" before pushing, empty:  %d\n", isEmpty(sp));
    push(sp, 5);
    push(sp, 6);
    push(sp, 86);
    push(sp, 46);
    push(sp, 66);
    push(sp, 59);
    push(sp, 51);
    push(sp, 46);
    push(sp, 36);
    push(sp, 1); // pushed 10 values
    // push(sp, 556); // stack overflow since the size of the stack is 10
    printf(" After pushing, full %d\n", isFull(sp));
    printf(" After pushing, empty %d\n", isEmpty(sp));

    printf("popped %d from the stack\n", pop(sp)); // last in first out!
    printf("popped %d from the stack\n", pop(sp)); // last in first out!
    printf("popped %d from the stack\n", pop(sp)); // last in first out!
    
    return 0;
}