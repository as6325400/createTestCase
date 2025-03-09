#include"testlib.h"
#include<bits/stdc++.h>

using namespace std;

int MAX_T = 100000;
int MAX = 1000000;

int main(int argc, char* argv[]){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 10;
  registerGen(argc, argv, 1);

  for(int i = 8; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string id;
    if(i < 10) id = "0" + to_string(i);
    else id = to_string(i);
    string filename = path + id + ".in";
    ofstream inputFile(filename);
    int t = MAX_T;
    inputFile << t << '\n';
    for(int j = 0; j < t; j++){
      int start = rnd.next(2, MAX) - 1;
      int end = rnd.next(start + 1, MAX);
      inputFile << start << ' ' << end << '\n';
    }
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    inputFile.close();
  }
  return 0;
}
