#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 18;
  srand(time(nullptr));
  vector<int> v = {0, 0, 0, 3, 6, 10, 20, 40, 80, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100};
  for(int i = 3; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    inputFile << v[i] << '\n';
    inputFile << '\n';
    inputFile.close();
  }
  return 0;
}
