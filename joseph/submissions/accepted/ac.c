#include<stdio.h>
#include<stdlib.h>
#define int long long

struct node{
  int num;
  struct node *next;
}typedef node;

struct li{
  struct node* front;
  struct node *back;
  int count;
}typedef li;

void init(li *ll){
  ll -> front = NULL;
  ll -> back = NULL;
  ll -> count = 0;
}

void push_back(li *ll, int num){
  node *temp = (node*)malloc(sizeof(node));
  temp -> num = num;
  temp -> next = NULL;
  if(ll -> count == 0){
    ll -> front = temp;
    ll -> back = temp;
  }
  else{
    ll -> back -> next = temp;
    ll -> back = temp;
  }
  ll -> back -> next = ll -> front;
  ll -> count++;
}

signed main(){
  int n, q;
  scanf("%lld%lld", &n, &q);
  li ll;
  init(&ll);
  for(int i = 1; i <= n; i++){
    push_back(&ll, i);
  }
  node *pre = ll.front, *ptr = ll.front;
  while(ll.count){
    for(int i = 0; i < q; i++){
      pre = ptr;
      ptr = ptr -> next;
    }
    printf("%lld ", ptr -> num);
    node *t = ptr;
    pre -> next = ptr -> next;
    ptr = pre;
    free(t);
    ll.count--;
  }
  printf("\n");
  return 0;
}