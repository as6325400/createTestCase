#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct stack {
    char val;
    stack *nxt;
} typedef stack;   

int empty(stack *ptr){
    if(ptr->nxt == nullptr) return 1;
    return 0;
}
void push(stack **ptr, char c){
    stack *tmp = (stack*)calloc(1, sizeof(stack));
    tmp->nxt = (*ptr)->nxt;
    tmp->val = c;
    (*ptr)->nxt = tmp;
}
void pop(stack **ptr){
    if(empty(*ptr)) return;
    stack *tmp = (*ptr)->nxt;
    (*ptr)->nxt = tmp->nxt;
    free(tmp);
}
char top(stack *ptr){
    return ptr->nxt->val;
}
int main(){
    int n; scanf("%d", &n);
    stack *ptr = (stack*)calloc(1, sizeof(stack));
    while(n--){
        int op; scanf("%d", &op);
        if(op == 1){
            char c; scanf(" %c", &c);
            push(&ptr, c);
        }
        else if(op == 2){
            pop(&ptr);
        }
        else {
            char ans = top(ptr);
            if(ans == '0') printf("no character\n");
            else printf("%c\n", ans);
        }
    }
    return 0;
}