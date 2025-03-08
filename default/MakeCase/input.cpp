#include"testlib.h"
#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(int argc, char* argv[]){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 10;

  for(int i = 2; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string id;
    if(i < 10) id = "0" + to_string(i);
    else id = to_string(i);
    string filename = path + id + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    inputFile.close();
  }
  return 0;
}
