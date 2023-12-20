#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 11;
  srand(time(nullptr));
  // vector<int> num = {0, 0, 0, 5, 10, 15, 20, 50, 100, 1000, 100000};
  for(int i = 11; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    int num = 1000000;
    inputFile << num << '\n';
    int count = 0;
    for(int j = 0; j < num / 2; j++){
      inputFile << 1 << ' ' << rand() % num + 1 << '\n';
      inputFile << 3 << ' ' << 1 << '\n';
    }
    inputFile.close();
  }
  return 0;
}
