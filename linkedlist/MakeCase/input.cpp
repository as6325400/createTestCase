#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 10;
  srand(time(nullptr));

  vector<int> n = {0, 0, 0, 5, 10, 20, 20, 100, 1000, 2000, 5000};
  vector<int> q = {0, 0, 0, 5, 10, 20, 100, 1000, 1000, 5000, 20000};

  for(int i = 3; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    inputFile << n[i] << ' ' << q[i] << '\n';
    for(int j = 0; j < n[i]; j++){
      int num = rand() % n[i] + 1;
      if(j == 0) inputFile << num;
      else inputFile << ' ' << num;
    }
    inputFile << '\n';
    for(int j = 0; j < q[i]; j++){
      int mode = rand() % 2 + 1;
      inputFile << mode;
      if(mode == 1){
        inputFile << ' ' << rand() % n[i] + 1 << '\n';
      }
      else{
        int site = rand() % n[i] + 1;
        int r = rand() % (n[i] - 1) + 2;
        inputFile << ' ' << site << ' ' << r << '\n';
      }
    }
    inputFile.close();
  }
  return 0;
}
