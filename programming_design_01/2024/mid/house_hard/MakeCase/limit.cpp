#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 11;
  srand(time(nullptr));
  std::random_device rd;  
  std::mt19937 gen(rd()); 
  std::uniform_int_distribution<int> dis(1, 1000000000);
  for(int i = 11; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
      cerr << "Cants open file " << i << endl;
    }
    int num = 200000, query = 1000000;
    inputFile << num << '\n';
    for(int j = 0; j < num; j++){
      inputFile << (1 << (rand() % 30 + 1)) - 1 << " ";
    }
    inputFile << '\n';
    inputFile << query << '\n';
    for(int j = 0; j < query; j++){
      int left = dis(gen) % num + 1;
      int right = dis(gen) % num + 1;
      if(left > right){
        swap(left, right);
      }
      inputFile << left << " " << right << '\n';
    }
    inputFile.close();
  }
  return 0;
}
