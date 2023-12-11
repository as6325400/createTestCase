#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 11;
  srand(time(nullptr));
  // 第 11 筆，linked list 的每個數字都相同，一直刪除不在的數字，最後一筆才全部刪掉
  for(int i = 11; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    int n = 5000, q = 20000;
    inputFile << n << ' ' << q << '\n';
    for(int j = 0; j < n; j++){
      int num = 2;
      if(j == 0) inputFile << num;
      else inputFile << ' ' << num;
    }
    inputFile << '\n';
    for(int j = 0; j < q; j++){
      int mode = rand() % 2 + 1;
      if(j != q - 1){
        inputFile << 1 << ' ' << 3 << '\n';
      }
      else{
        inputFile << 1 << ' ' << 2 << '\n';
      }
    }
    inputFile.close();
  }
  return 0;
}
