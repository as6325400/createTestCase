#include<bits/stdc++.h>
#include"base64.hpp"
#define int long long

using namespace std;

string random_string(int len){
  string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz_! @#$%^&*()_+{}|:<>?[];',./-=`~";
  string newstr;
  for(int i = 0; i < len; i++){
    newstr += str[rand() % str.size()];
  }
  return newstr;
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 10;
  srand(time(nullptr));
  std::random_device rd;  
  std::mt19937 gen(rd()); 
  std::uniform_int_distribution<int> dis(1, 1000000000);

  vector<int> vec = {0, 0, 0, 10, 20, 50, 1000, 10000, 100000, 1000000};
  for(int i = 3; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    string ans = random_string(vec[i]);
    auto encoded_str = base64::to_base64(ans);
    inputFile << encoded_str << endl;
    inputFile.close();
  }
  return 0;
}
