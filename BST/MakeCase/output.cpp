#include<bits/stdc++.h>
#define int long long

using namespace std;

class BST {
    
    struct node {
        int data;
        node* left;
        node* right;
    };


    node* makeEmpty(node* t) {
        if(t == NULL)
            return NULL;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }

    node* insert(int x, node* t)
    {
        if(t == NULL)
        {
            t = new node;
            t->data = x;
            t->left = t->right = NULL;
        }
        else if(x < t->data)
            t->left = insert(x, t->left);
        else if(x > t->data)
            t->right = insert(x, t->right);
        return t;
    }

    node* findMin(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    node* findMax(node* t) {
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }

    node* remove(int x, node* t) {
        node* temp;
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            t->left = remove(x, t->left);
        else if(x > t->data)
            t->right = remove(x, t->right);
        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }

        return t;
    }


    node* find(node* t, int x) {
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            return find(t->left, x);
        else if(x > t->data)
            return find(t->right, x);
        else
            return t;
    }

public:
    node* root;
    BST() {
        root = NULL;
    }

    ~BST() {
        root = makeEmpty(root);
    }

    void insert(int x) {
        root = insert(x, root);
    }

    void remove(int x) {
        root = remove(x, root);
    }

    void inorder(node* t, vector<int> &temp) {
        if(t == NULL)
            return;
        inorder(t->left, temp);
        temp.push_back(t -> data);
        inorder(t->right, temp);
    }

    void preorder(node* t, vector<int> &temp) {
        if(t == NULL)
            return;
        temp.push_back(t -> data);
        preorder(t->left, temp);
        preorder(t->right, temp);
    }

    void postorder(node* t, vector<int> &temp) {
        if(t == NULL)
            return;
        postorder(t->left, temp);
        postorder(t->right, temp);
        temp.push_back(t -> data);
    }

    void search(int x) {
        root = find(root, x);
    }
};


void output(string caseName){
  ifstream input(caseName);
  string outputName = caseName;
  outputName.pop_back();
  outputName.pop_back();
  outputName += "ans";
  ofstream output(outputName);
  int n;
  input >> n;
  BST t;
  for(int i = 0; i < n; i++){
    int mode, num;
    input >> mode >> num;
    if(mode == 1) t.insert(num);
    else if(mode == 2) t.remove(num);
    else if(mode == 3){
      vector<int> temp;
      if(num == 1) t.preorder(t.root, temp);
      else if(num == 2) t.inorder(t.root, temp);
      else t.postorder(t.root, temp);
      int count = 0;
      for(auto &num: temp){
        if(count == 0) output << num;
        else output << ' ' << num;
        count++;
      }
      output << '\n';
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
  int testCaseName = 10;
  for(int i = 3; i <= testCaseName; i++){
    string filename = path + "secret/" + to_string(i) + ".in";
    output(filename);
  }
  return 0;
}
 