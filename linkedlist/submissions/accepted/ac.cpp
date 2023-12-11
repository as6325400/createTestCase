#include<iostream>
#include<stdlib.h>
#include<istream>
#include<fstream>
#include<ostream>

#define int long long

using namespace std;

struct node{
  int num;
  struct node *next;
}typedef node;

struct list{
  struct node *head;
  int count;
}typedef list;

void init(list *li){
  li -> head = NULL;
  li -> count = 0;
}

void insert(list *li, int num){
  node *temp = (node*)malloc(sizeof(node));
  temp -> num = num;
  temp -> next = NULL;
  if(li -> head == NULL){
    li -> head = temp;
  }
  else if(num <= li -> head -> num){
    temp -> next = li -> head;
    li -> head = temp;
  }
  else{
    node *t = li -> head;
    int flag = 0;
    while(t -> next){
      if(t -> next -> num > num && t -> num <= num){
        temp -> next = t -> next;
        t -> next = temp;
        flag = 1;
        break;
      }
      t = t -> next;
    }
    if(flag == 0){
      t -> next = temp;
    }
  }
  li -> count += 1;
}


void Delete(list *li, int num){
  if(li -> head == NULL) return;

  // 避免刪開頭狀況
  node *n = li -> head;
  while(n && n -> num == num){
    li -> count--;
    node *t = n;
    n = n -> next;
    free(t);
  }
  li -> head = n;
  node *temp = NULL;
  while(n){
    if(n -> num == num){
      temp -> next = n -> next;
      li -> count--;
    }
    else temp = n;
    n = n -> next;
  }
}

int del[5005];

void reverse(list *li, int site, int r){
  node *n = li -> head, *t;
  if(n == NULL) return;
  for(int i = 0; i < site - 1; i++){
    t = n;
    n = n -> next;
  }
  node *tail = n, *start, *temp;
  for(int i = 0; i < r; i++){
    temp = start;
    start = n;
    n = n -> next;
    start -> next = temp;
  }
  if(site == 1){
    li -> head -> next = n;
    li -> head = start;
  }
  else{
    tail -> next = n;
    t -> next = start;
  }
}

signed main(){
    int n, q;
    cin >> n >> q;
    list *li = (list*)malloc(sizeof(list));
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        insert(li, num);
    }
    for(int i = 0; i < q; i++){
        int mode;
        cin >> mode;
        if(mode == 1){
            int num;
            cin >> num;
            Delete(li, num);
        }
        else{
            int site, r;
            cin >> site >> r;
            // 特判已經出界的
            if(site + r - 1 > li -> count) continue;
            else
            {
                reverse(li, site, r);
            }
        }
    }
    node *t = li -> head;
    while(t){
        cout << t -> num << ' ';
        t = t -> next;
    }
    cout << '\n';
}