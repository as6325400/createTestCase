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
    int len;
    string s;
    input >> len >> s;
    int ans = 1;
    for(int j = 0; j < len; j++){
      ans = max(ans, (int)(s[j] - '0'));
    }
    output << ans << endl;
  } 
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string path = "../data/";
  // sample testcase
  output(path + "sample/" + "1.in");
  int testCaseName = 17;
  for(int i = 2; i <= testCaseName; i++){
    string filename = path + "secret/" + to_string(i) + ".in";
    output(filename);
  }
  return 0;
}
 