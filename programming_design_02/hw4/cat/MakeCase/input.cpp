#include<bits/stdc++.h>
#define int long long

using namespace std;

string random_string(int n){
  string str = "";
  for(int i = 0; i < n; i++){
    str += (char)('a' + rand() % 26);
  }
  str[0] -= 32;
  return str;
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 10;
  srand(time(nullptr));
  std::random_device rd;  
  std::mt19937 gen(rd()); 
  std::uniform_int_distribution<int> dis(1, 20);

  vector<int> v = {0, 0, 5, 8, 10, 15, 20, 30, 50, 500, 1000};
  for(int i = 2; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    freopen(filename.c_str(), "w", stdout);
    
    int n = v[i];
    for(int i = 0; i < n; i++){
      int len = dis(gen);
      cout << random_string(len) << endl;
    }
  }
  return 0;
}
