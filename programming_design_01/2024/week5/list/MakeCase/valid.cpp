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
  if(n > 200000 || q > 200000){
    output << "error" << endl;
    return;
  }
  vector<vector<int>> vec(n);
  int M = -1e9;
  int count = 0;
  for(int i = 0; i < n; i++){
    int sum;
    input >> sum;
    M = max(M, sum);
    if(sum > 200000){
      output << "error" << endl;
      return;
    }
    count += sum;
    vec[i].resize(sum);
    for(int j = 0; j < sum; j++){
      input >> vec[i][j];
    }
  }
    if(count > 400000){
        output << "error" << endl;
        return;
    }
  for(int i = 0; i < q; i++){
    int x, y;
    input >> x >> y;
    if(x >= n || y >=M) output << "error" << endl;
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
    cout << "output " << i << endl;
    string filename = path + "secret/" + to_string(i) + ".in";
    output(filename);
  }
  return 0;
}
 