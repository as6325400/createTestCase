#include<bits/stdc++.h>
#define int long long

using namespace std;

string random_string(int n){
  string s = "";
  for(int i = 0; i < n; i++){
    s += 'a' + rand() % 26;
  }
  return s;
}

signed main(){
  cin.tie(nullptr);
  int teseCaseNum = 10;
  srand(time(nullptr));
  std::random_device rd;  
  std::mt19937 gen(rd()); 
  std::uniform_int_distribution<int> dis(1, 1000000000);

  vector<int> v = {0, 0, 5, 8, 10, 15, 20, 30, 50, 500, 1000};
  for(int i = 2; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    freopen(filename.c_str(), "w", stdout);
    int n = v[i];
    cout << n << endl;
    for(int j = 0; j < n; j++){
      int len = dis(gen) % 10 + 1;
      cout << random_string(len);
      for(int k = 0; k < 5; k++){
        cout << ' ' << dis(gen) % 101; 
      }
      cout << endl;
    }
  }
  return 0;
}
