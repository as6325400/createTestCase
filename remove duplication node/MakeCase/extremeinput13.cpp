#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 13;
  srand(time(nullptr));
  // vector<int> num = {0, 0, 0, 0, 10, 20, 50, 100, 100, 1000, 200000};
  for(int i = 13; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    int num = 200000;
    inputFile << num << '\n';
    int offset = rand() % 5 + 1;
    int start = 6, count = 0;
    for(int j = 0; j < num; j++){
      if(j == 0) inputFile << start;
      else inputFile << ' ' << start;
    }
    inputFile << '\n';
    inputFile.close();
  }
  return 0;
}
