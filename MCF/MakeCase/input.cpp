#include<bits/stdc++.h>
#define int long long

using namespace std;

int randnum(){
  int mode = rand() % 2;
  int num = rand() % 100001;
  if(mode == 0) return num;
  return -num;
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 10;
  srand(time(nullptr));
  vector<int> num = {0, 0, 0, 1, 5, 10, 10, 100, 500, 1000, 1000};
  for(int i = 3; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    inputFile << num[i] << '\n';
    set<pair<int, int>> ss;
    for(int j = 0; j < num[i]; j++){
      int x = randnum();
      int y = randnum();
      if(ss.count({x, y})) j--;
      ss.insert({x, y});
    }
    for(auto j:ss){
      inputFile << j.first << ' ' << j.second << '\n';
    }
    inputFile.close();
  }
  return 0;
}
