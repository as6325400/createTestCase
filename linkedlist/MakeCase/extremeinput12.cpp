#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 12;
  srand(time(nullptr));
  // 第 12 筆，linked list 翻轉的範圍一直超出去，要讓他們用 count 判掉
  for(int i = 12; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    int n = 5000, q = 20000;
    inputFile << n << ' ' << q << '\n';
    for(int j = 0; j < n; j++){
      int num = rand() % 5000 + 1;
      if(j == 0) inputFile << num;
      else inputFile << ' ' << num;
    }
    inputFile << '\n';
    for(int j = 0; j < q; j++){
      int mode = rand() % 2 + 1;
      if(j != q - 1){
        int site = (rand() % (n / 2)) + (n / 2) + 1;
        int r = (rand() % (n / 2)) + (n / 2) + 1;
        inputFile << 2 << ' ' << site << ' ' << r << '\n';
      }
      else{
        inputFile << 2 << ' ' << 1 << ' ' << n <<'\n';
      }
    }
    inputFile.close();
  }
  return 0;
}
