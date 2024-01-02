#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 11;
  srand(time(nullptr));

  vector<int> num = {0, 0, 8, 8, 20, 20, 20, 50, 300, 300, 10, 2};
  vector<int> e = {0, 0, 12, 20, 25, 40, 80, 125, 300, 150 * 299, 8, 1};

  for(int i = 3; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    int n = num[i], m = e[i];
    inputFile << n << ' ' << m << '\n';
    set<pair<int, int>> ss;
    while(ss.size() < m){
      int a = rand() % n + 1;
      int b = rand() % n + 1;
      if(a == b) continue;
      if(ss.count({a, b}) || ss.count({b, a})) continue;
      ss.insert({a, b});
      inputFile << a << ' ' << b << ' ' << rand() %(1000000) + 1 << '\n';
    }
    inputFile.close();
  }
  return 0;
}
