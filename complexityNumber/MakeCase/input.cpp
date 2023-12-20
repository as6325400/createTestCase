#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 15;
  srand(time(nullptr));
  vector<int> caseNum = {1, 3, 5, 7, 15, 50, 50, 100, 100, 500, 500, 750, 750, 1000, 1000};

  for(int i = 1; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i + 1) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i + 1 << endl;
    }
    int t = caseNum[i - 1];
    inputFile << t << endl;
    for(int i = 0; i < t; i++){
      int num = rand() % 5000 + 1;
      inputFile << num << ' ';
      string s;
      for(int j = 0; j < num; j++){
        s += to_string(rand() % 10);
      }
      inputFile << s << endl;
    }
    inputFile.close();
  }
  return 0;
}
