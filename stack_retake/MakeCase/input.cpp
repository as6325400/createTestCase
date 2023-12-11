#include<bits/stdc++.h>
#define int long long

using namespace std;

char randomchar(){
  int shift = rand() % 26;
  return 'A' + shift;
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 12;
  srand(time(nullptr));
  vector<int> s = {0, 0, 0, 10, 15, 20, 20, 20, 200, 200, 2000, 20000, 200000};
  for(int i = 3; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    inputFile << s[i] << '\n';
    for(int j = 0; j < s[i]; j++){
      int mode = rand() % 3 + 1;
      if(mode == 1){
        inputFile << mode << ' ' << randomchar() << '\n';
      }
      else inputFile << mode << '\n';
    }
    inputFile.close();
  }
  return 0;
}
