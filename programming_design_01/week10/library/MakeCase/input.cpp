#include<bits/stdc++.h>
#define int long long

using namespace std;

string random_string(int len){
  string pattern = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string str = "";
  for(int i = 0; i < len; i++){
    str += pattern[rand() % 52];
  }
  return str;
}

string random_long_number(int len){
  string pattern = "0123456789";
  string str = "";
  for(int i = 0; i < len; i++){
    str += pattern[rand() % 10];
  }
  return str;
}

string random_mix(int len){
  string pattern = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  string str = "";
  for(int i = 0; i < len; i++){
    str += pattern[rand() % 62];
  }
  return str;
}

int random_price(){
  return rand() % 10000 + 1;
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 10;
  srand(time(nullptr));
  std::random_device rd;  
  std::mt19937 gen(rd()); 
  std::uniform_int_distribution<int> dis(1, 1000000000);

  vector<int> num = {1, 5, 5, 7, 7, 10, 10, 10, 10, 10, 100};
  vector<int> qry = {1, 3, 3, 4, 4, 10, 10, 10, 10, 10, 200};

  for(int i = 2; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    inputFile << num[i] << '\n';
    for(int j = 0; j < num[i]; j++){
      inputFile << random_string(rand() % 30 + 1) << '\n';
      inputFile << random_long_number(rand() % 30 + 1) << '\n';
      inputFile << random_price() << '\n';
    }
    for(int j = 0; j < qry[i]; j++){
      int mode = rand() % 3;
      if(mode == 0) inputFile << random_long_number(rand() % 10 + 1) << '\n';
      else if(mode == 1) inputFile << random_string(rand() % 10 + 1) << '\n';
      else inputFile << random_mix(rand() % 10 + 1) << '\n';
    }
    inputFile.close();
  }
  return 0;
}
