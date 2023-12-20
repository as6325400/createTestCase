#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 12;
  srand(time(nullptr));

  vector<int> save = {0, 0, 0, 5, 5, 5, 10, 10, 10, 1000, 10000, 100000, 1000000};
  for(int i = 3; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    int n = save[i];
    inputFile << n << '\n';
    for(int j = 0; j < n; j++){
      int mode = rand() % 2 + 1, num = 2 * (rand() % (500000000) + 1);
      if(j == 0) inputFile << 1 << ' ' << num << '\n';
      else{
        if(mode == 1) inputFile << 1 << ' ' << num << '\n';
        else inputFile << 2 << '\n';
      }
    }
    inputFile.close();
  }
  return 0;
}
