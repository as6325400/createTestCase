#include<bits/stdc++.h>
#include<bits/extc++.h>
#define int long long

using namespace std;
using namespace __gnu_pbds;


struct node {
	int val;
	struct node *left, *right;
}typedef node;

node *insert(node *now, int val) {
	if (now == NULL) {
		node *newnode = (node*)malloc(sizeof(node));
		newnode->val = val;
		newnode->left = newnode->right = NULL;
		return newnode;
	}
	if (now->val < val) {
		now->right = insert(now->right, val);
	}
	else if (now->val > val) {
		now->left = insert(now->left, val);
	}
	return now;
}

int height(node *root){
  if(!root) return 0;
  return 1 + max(height(root -> left), height(root -> right));
}

void output(string caseName){
  ifstream input(caseName);
  string outputName = caseName;
  outputName.pop_back();
  outputName.pop_back();
  outputName += "ans";
  ofstream output(outputName);
  int n;
  input >> n;
  node *root = NULL;
	while (n--) {
    int val;
		input >> val;
		root = insert(root, val);
	}
  output << height(root) << '\n';
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  node *root = NULL;
	while (n--) {
    int val;
		cin >> val;
		root = insert(root, val);
	}
  cout << height(root) << '\n';
  return 0;
}
