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
  int t;
  input >> t;
  for(int i = 0; i < t; i++){
    int m, k;
    input >> m >> k;
    vector<int> vec(k);
    for(int i = 0; i < k; i++){
      input >> vec[i];
    }
    int ans = 0;
    for(int i = k - 1; i >= 0; i--){
      ans += m / vec[i];
      m %= vec[i];
    }
    if(m != 0) output << -1 << endl;
    else output << ans << endl;
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
 