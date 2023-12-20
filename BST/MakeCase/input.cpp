#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 10;
  srand(time(nullptr));
  vector<int> num = {0, 0, 0, 20, 30, 50, 50, 100, 100, 1000, 100000};
  for(int i = 3; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    inputFile << num[i] << '\n';
    int insert = (int)(0.6 * (double)num[i]);
    for(int j = 0; j < insert; j++){
      inputFile << 1 << ' ' << rand() % (num[i]) + 1 << '\n';
    }
    inputFile << 3 << ' ' << 1 << '\n';
    inputFile << 3 << ' ' << 2 << '\n';
    inputFile << 3 << ' ' << 3 << '\n';
    for(int j = insert + 3; j < num[i] - 1; j++){
      int mode = rand() % 2 + 1;
      inputFile << mode << ' ' << rand() % (int)(num[i]) + 1 << '\n';
    }
    inputFile << 3 << ' ' << 2 << '\n';
    inputFile.close();
  }
  return 0;
}
