#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 30;
  srand(time(nullptr));

  for(int i = 3; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    int n = rand() % 1000000000 + 1;
    int x = rand() % n + 1;
    int y = rand() % n + 1;
    inputFile << n << " " << x << " " << y << endl;
    inputFile.close();
  }
  return 0;
}