#include<bits/stdc++.h>
#define int long long

using namespace std;

int randomnum(int bound){
  return rand() % bound;  
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 9;
  srand(time(nullptr));
  vector<int> caseNum = {1, 1, 5, 10, 20, 50, 70, 100, 100};
  vector<vector<int>> p = {{3, 5}, {6, 10}, {25, 25}, {50, 50}, {50, 50}, {75, 75}, {500, 500}, {5000, 5000}, {1, 50000}};
  for(int i = 1; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i + 1) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i + 1 << endl;
    }
    int t = caseNum[i - 1];
    inputFile << t << endl;
    int bound = 2e6;
    for(int j = 0; j < t; j++){
      inputFile << p[i - 1][0] << ' ' << p[i - 1][1] << endl;
      for(int j = 0; j < p[i - 1][0]; j++){
        inputFile << randomnum(bound) << ' ';
      }
      inputFile << endl;
    }
    inputFile.close();
  }
  return 0;
}
