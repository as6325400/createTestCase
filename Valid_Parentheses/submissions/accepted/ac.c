#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <stdbool.h>
#define int long long

struct stack {
    char val;
    struct stack *nxt;
} typedef stack;   

bool empty(stack *ptr){
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

char rv(char a){
    if(a == '}') return '{';
    if(a == ']') return '[';
    if(a == ')') return '(';
    return '#';
}

bool isValid(char * s){
    int num = strlen(s);
    stack *ss = (stack*)malloc(sizeof(stack));
    ss -> nxt = NULL;
    for(int i = 0; i < num; i++){
        if(!empty(ss) && rv(s[i]) == top(ss)) pop(&ss);
        else push(&ss, s[i]);
    }
    return empty(ss);
}

signed main(){
  int n;
  scanf("%d", &n);
  char s[200001];
  for(int i = 0; i < n; i++){
    scanf(" %c", &s[i]);
  }
  if(isValid(s)) printf("Yes\n");
  else printf("No\n");
  return 0;
}