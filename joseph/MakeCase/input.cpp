#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 11;
  srand(time(nullptr));
  vector<int> n = {0, 0, 0, 0, 5, 10, 100, 1000, 10000, 10000, 100000, 1};
  vector<int> q = {0, 0, 0, 0, 20, 10, 3, 100, 20, 1000, 1, 100000};
  for(int i = 4; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    inputFile << n[i] << ' ' << q[i] << '\n';
    inputFile.close();
  }
  return 0;
}
