#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 20;
  srand(time(nullptr));
  int MAXNUM = 200000, MAXQ = 100000;
  vector<vector<int>> num = {{}, {}, {5, 5}, {10, 10}, {10, 15}, {100, 50}, {1000, 5000}};
  for(int i = 2; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    if(i < num.size()){
      inputFile << num[i][0] << ' ' << num[i][1] << '\n';
      for(int j = 0; j < num[i][0]; j++){
        inputFile << rand() % 100000 + 1;
        if(j != num[i][0] - 1) inputFile << ' ';
      }
      inputFile << '\n';
      for(int j = 0; j < num[i][1]; j++){
        inputFile << rand() % num[i][0] + 1 << ' ' << rand() % 1000 + 1 << '\n';
      }
    }
    else{
      inputFile << MAXNUM << ' ' << MAXQ << '\n';
      for(int j = 0; j < MAXNUM; j++){
        inputFile << rand() % 100000 + 1;
        if(j != MAXNUM - 1) inputFile << ' ';
      }
      inputFile << '\n';
      for(int j = 0; j < MAXQ; j++){
        inputFile << rand() % MAXNUM + 1 << ' ' << rand() % 1000 + 1 << '\n';
      }
    }
    inputFile.close();
  }
  return 0;
}
