#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct stack {
    char val;
    struct stack *nxt;
} typedef stack;   

int empty(stack *ptr){
    if(ptr -> nxt == NULL) return 1;
    return 0;
}

void push(stack **ptr, char c){
    stack *tmp = (stack*)malloc(sizeof(stack));
    tmp -> nxt = (*ptr) -> nxt;
    tmp -> val = c;
    (*ptr) -> nxt = tmp;
}

void pop(stack **ptr){
    if(empty(*ptr)) return;
    stack *tmp = (*ptr) -> nxt;
    (*ptr) -> nxt = tmp -> nxt;
    free(tmp);
}

char top(stack *ptr){
    return ptr -> nxt -> val;
}

int main(){
    int n; scanf("%d", &n);
    stack *s = (stack*)malloc(sizeof(stack));
    while(n--){
        int op; scanf("%d", &op);
        if(op == 1){
            char c; scanf(" %c", &c);
            push(&s, c);
        }
        else if(op == 2){
            pop(&s);
        }
        else {
            if(empty(s)) printf("no character\n");
            else{
                char ans = top(s);
                printf("%c\n", ans);
            }
        }
    }
    return 0;
}