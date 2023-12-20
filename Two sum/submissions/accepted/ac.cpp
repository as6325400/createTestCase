#include <bits/stdc++.h>
#define int long long

using namespace std;

struct node {
    int val;
    struct node *left, *right;
} typedef node;

node* insert(node *now, int val){
    if(now == NULL){
        node *tmp = (node*)malloc(sizeof(node));
        tmp->left = tmp->right = NULL;
        tmp->val = val;
        return tmp;
    }
    if(val < now->val) now->left = insert(now->left, val);
    else if(val > now->val) now->right = insert(now->right, val);
    return now;
}

bool search(node *root, int num){
  if(!root) return false;
  if(num > root -> val) return search(root -> right, num);
  else if(num < root -> val) return search(root -> left, num);
  return true;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<int> arr(n);
  node *root = NULL;
  for(int i = 0; i < n; i++){
    int num;
    cin >> num;
    root = insert(root, num);
    arr[i] = num;
  }
  for(int i = 0; i < q; i++){
    int num;
    int flag = 1;
    cin >> num;
    for(int j = 0; j < n; j++){
      if(arr[j] * 2 == num) continue;
      if(search(root, num - arr[j])){
        cout << "Yes\n";
        flag = 0;
        break;
      }
    }
    if(flag == 1) cout << "No\n";
  }
}