#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 13;
  srand(time(nullptr));
  // 第 13 筆，刪到整個 linked list 都沒了還要反轉及刪除
  for(int i = 13; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    int n = 10, q = 5;
    inputFile << n << ' ' << q << '\n';
    for(int j = 0; j < n; j++){
      int num = rand() % 3 + 1;
      if(j == 0) inputFile << num;
      else inputFile << ' ' << num;
    }
    inputFile << '\n';
    for(int j = 0; j < q; j++){
      int mode = rand() % 2 + 1;
      if(j == 0){
        inputFile << 1 << ' ' << 1 << '\n';
      }
      if(j == 1){
        inputFile << 2 << ' ' << 1 << ' ' << 3 << '\n';
      }
      if(j == 2){
        inputFile << 1 << ' ' << 2 << '\n';
      }
      if(j == 3){
        inputFile << 1 << ' ' << 3 << '\n';
      }
      if(j == 4){
        inputFile << 2 << ' ' << 1 << ' ' << 5 << '\n';
      }
    }
    inputFile.close();
  }
  return 0;
}
