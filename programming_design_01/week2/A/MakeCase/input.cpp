#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 17;
  srand(time(nullptr));

  for(int i = 17; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    inputFile << 200000 << endl;
    for(int j = 0; j < 100000; j++){
      inputFile << j + 1 << ' ';
    }
    for(int j = 0; j < 100000; j++){
      inputFile << j + 1 << ' ';
    }
    inputFile << '\n';
    inputFile.close();
  }
  return 0;
}
