#include<bits/stdc++.h>
#include "testlib.h"
#define int long long

using namespace std;

signed main(int argc, char* argv[]){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 11;
  registerGen(argc, argv, 1);

  for(int i = 10; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string id;
    if(i < 10) id = "0" + to_string(i);
    else id = to_string(i);
    string filename = path + id + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    int t = 10;
    inputFile << t << '\n';
    for(int j = 0; j < t; j++){
      int left = rnd.next(1, 100);
      int right = rnd.next(1000000 - 100, 1000000);
      inputFile << left << ' ' << right << '\n';
    }
    inputFile.close();
  }
  return 0;
}
