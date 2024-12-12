#include<bits/stdc++.h>
#define int long long

using namespace std;

int count(vector<vector<int>> data, int state){
  vector<bool> check(1001, false);
  int ans = 0;
  if(state & 1){
    for(int i = data[0][0]; i <= data[0][1]; i++){
      if(check[i]) return -1;
      check[i] = true;
    }
    ans += data[0][2];
  }
  if(state & 2){
    for(int i = data[1][0]; i <= data[1][1]; i++){
      if(check[i]) return -1;
      check[i] = true;
    }
    ans += data[1][2];
  }
  if(state & 4){
    for(int i = data[2][0]; i <= data[2][1]; i++){
      if(check[i]) return -1;
      check[i] = true;
    }
    ans += data[2][2];
  }
  return ans;
}


void output(string caseName){
  ifstream input(caseName);
  string outputName = caseName;
  outputName.pop_back();
  outputName.pop_back();
  outputName += "ans";
  ofstream output(outputName);
  vector<vector<int>> data(3, vector<int>(3));
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      input >> data[i][j];
    }
  }
  int ans = 0;
  for(int i = 0; i < 8; i++){
    ans = max(ans, count(data, i));
  }
  output << ans << endl;
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string path = "../data/";
  // sample testcase
  output(path + "sample/" + "01.in");
  // secret testcase
  int testCaseName = 31;
  for(int i = 2; i <= testCaseName; i++){
    string id;
    if(i < 10) id = "0" + to_string(i);
    else id = to_string(i);
    string filename = path + "secret/" + id + ".in";
    output(filename);
  }
  return 0;
}
 