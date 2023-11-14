#include<bits/stdc++.h>
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
  
}

int del[5005];

void output(string caseName){
  ifstream input(caseName);
  string outputName = caseName;
  outputName.pop_back();
  outputName.pop_back();
  outputName += "ans";
  ofstream output(outputName);
  int n, q;
  list *li = (list*)malloc(sizeof(list));
  init(li);
  input >> n >> q;
  for(int i = 0; i < n; i++){
    int num;
    input >> num;
    insert(li, num);
  }

  for(int i = 0; i < q; i++){
    int mode;
    input >> mode;
    if(mode == 1){
      int num;
      input >> num;
      if(del[num] == 1) continue;

    }
  }
  
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string path = "../data/";
  // sample testcase
  output(path + "sample/" + "1.in");
  output(path + "sample/" + "2.in");
  // secret testcase
  int testCaseName = 13;
  for(int i = 3; i <= testCaseName; i++){
    string filename = path + "secret/" + to_string(i) + ".in";
    output(filename);
  }
  return 0;
}
 