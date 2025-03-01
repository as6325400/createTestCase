#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 10;
  srand(time(nullptr));
  std::random_device rd;  
  std::mt19937 gen(rd()); 
  std::uniform_int_distribution<int> dis(1, 1000000000);

  vector<int> n = {0, 0, 3, 4, 10, 20, 50, 1000, 5000, 10000, 200000};
  vector<int> q = {0, 0, 5, 3, 4, 100, 200, 1000, 2000, 200000, 200000};

  for(int i = 2; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    inputFile << n[i] << " " << q[i] << '\n';
    for(int j = 0; j < n[i]; j++){
      int r = rand() % 2;
      if(r == 0){
        inputFile << dis(gen) % n[i] << ' ' << 1 << ' ' << rand() % 2 << ' ';
        inputFile << dis(gen) % n[i] << ' ' << 0 << ' ' << rand() % 2 << '\n';
      }
      else
      {
        inputFile << dis(gen) % n[i] << ' ' << 0 << ' ' << rand() % 2 << ' ';
        inputFile << dis(gen) % n[i] << ' ' << 1 << ' ' << rand() % 2 << '\n';
      }
    }
    for(int j = 0; j < q[i]; j++){
      inputFile << rand() % 2 << '\n';
    }
  }
  return 0;
}
