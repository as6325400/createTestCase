#include<bits/stdc++.h>
#define int long long

using namespace std;

int mod = 1e9;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 10;
  srand(time(nullptr));

  vector<int> vec = {0, 0, 0, 10, 20, 50, 100, 1000, 10000, 100000, 1000000};
  for(int i = 3; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    inputFile << vec[i] << ' ' << vec[i] << '\n';
    set<int> s;
    for(int j = 0; j < vec[i]; j++){
      int num =  rand() % mod + 1;
      if(s.count(num)){
        continue;
        j--;
      }
      s.insert(num);
      inputFile << num << ' ';
    }
    inputFile << '\n';
    for(int j = 0; j < vec[i]; j++){
      inputFile << rand() % (mod - 3) + 3 << '\n';
    }
    inputFile.close();
  }
  return 0;
}
