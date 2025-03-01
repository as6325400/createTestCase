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
  vector<int> num = {0, 0, 0, 5, 5, 10, 20, 50, 100, 2000, 200000};
  vector<int> qry = {0, 0, 0, 10, 10, 20, 50, 100, 200, 20000, 1000000};
  for(int i = 3; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
      cerr << "Cants open file " << i << endl;
    }
    inputFile << num[i] << '\n';
    for(int j = 0; j < num[i]; j++){
      inputFile << dis(gen) % 1000000000 + 1 << " ";
    }
    inputFile << '\n';
    inputFile << qry[i] << '\n';
    for(int j = 0; j < qry[i]; j++){
      int left = dis(gen) % num[i] + 1;
      int right = dis(gen) % num[i] + 1;
      if(left > right){
        swap(left, right);
      }
      inputFile << left << " " << right << '\n';
    }
    inputFile.close();
  }
  return 0;
}
