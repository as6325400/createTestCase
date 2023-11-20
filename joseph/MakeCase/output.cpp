#include<bits/stdc++.h>
#define int long long

using namespace std;

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


void output(string caseName){
  ifstream input(caseName);
  string outputName = caseName;
  outputName.pop_back();
  outputName.pop_back();
  outputName += "ans";
  ofstream output(outputName);
  int n, q;
  input >> n >> q;
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
    output << ptr -> num;
    if(ll.count != 1) output << ' ';
    node *t = ptr;
    pre -> next = ptr -> next;
    ptr = pre;
    free(t);
    ll.count--;
  }
  output << '\n';
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string path = "../data/";
  // sample testcase
  output(path + "sample/" + "1.in");
  output(path + "sample/" + "2.in");
  output(path + "sample/" + "3.in");
  // secret testcase
  int testCaseName = 11;
  for(int i = 4; i <= testCaseName; i++){
    string filename = path + "secret/" + to_string(i) + ".in";
    output(filename);
  }
  return 0;
}
 