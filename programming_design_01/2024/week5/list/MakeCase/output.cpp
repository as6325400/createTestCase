#include<bits/stdc++.h>
#define int long long

using namespace std;


void output(string caseName){
  ifstream input(caseName);
  string outputName = caseName;
  outputName.pop_back();
  outputName.pop_back();
  outputName += "ans";
  ofstream output(outputName);
  int n, q;
  input >> n >> q;
  vector<vector<int>> vec(n);
  for(int i = 0; i < n; i++){
    int sum;
    input >> sum;
    vec[i].resize(sum);
    for(int j = 0; j < sum; j++){
      input >> vec[i][j];
    }
  }
  for(int i = 0; i < q; i++){
    int x, y;
    input >> x >> y;
    if(y >= vec[x].size()) output << -1 << endl;
    else output << vec[x][y] << endl;
  }
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string path = "../data/";
  // sample testcase
  output(path + "sample/" + "1.in");
  output(path + "sample/" + "2.in");
  // secret testcase
  int testCaseName = 10;
  for(int i = 3; i <= testCaseName; i++){
    string filename = path + "secret/" + to_string(i) + ".in";
    output(filename);
  }
  return 0;
}
 