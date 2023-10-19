#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 10;
  srand(time(nullptr));

  for(int i = 2; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    int num = rand() % 8 + 1;
    inputFile << num << '\n';
    for(int i = 0; i < num; i++){
      inputFile << rand() % 9 + 1 << ' ';
    }
    inputFile << '\n';
    inputFile.close();
  }
  return 0;
}
