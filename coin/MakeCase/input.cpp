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
  vector<int> v = {0, 0, 0, 5, 10, 20, 50, 100, 200, 500, 1000};
  for(int i = 3; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    inputFile << v[i] << endl;
    for(int j = 0; j < v[i]; j++){
      int num = dis(gen), startnum = rand() % 5 + 1, temp, count = 0;
      temp = startnum;
      vector<int> save;
      while(temp <= num){
        if(save.size() > 20) break;
        save.push_back(temp);
        int rate = rand() % 10 + 1;
        temp *= rate;
      }
      inputFile << num << " " << save.size() << endl;
      for(auto k : save){
        inputFile << k << " ";
      }
      inputFile << '\n';
    }
    inputFile.close();
  }
  return 0;
}
