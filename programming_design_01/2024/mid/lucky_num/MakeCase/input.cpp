#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
  cin.tie(nullptr);
  int teseCaseNum = 10;
  srand(time(nullptr));
  std::random_device rd;  
  std::mt19937 gen(rd()); 
  std::uniform_int_distribution<int> dis(1, 1000000000);
  vector<int> v = {0, 0, 0, 0, 0, 15, 20, 50, 100, 500, 200000};
  for(int i = 5; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    freopen(filename.c_str(), "w", stdout);
    int n = v[i];
    cout << n << endl;
    for(int j = 0; j < n; j++){
      cout << rand() % 30 + 1 << ' ';
    }
    cout << endl;
  }
  return 0;
}
