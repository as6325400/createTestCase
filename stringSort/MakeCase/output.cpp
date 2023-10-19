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
  int t = 1;
  for(int i = 0; i < t; i++){
    int len;
    string s, ans;
    input >> len >> s;
    vector<int> c(26);
    for(int j = 0; j < len; j++){
      c[s[j] - 'a']++;
    }
    for(int j = 0; j < 26; j++){
      for(int k = 0; k < c[j]; k++){
        ans += (char)('a' + j);
      }
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
  int testCaseName = 2;
  for(int i = 2; i <= testCaseName; i++){
    string filename = path + "secret/" + to_string(i) + ".in";
    output(filename);
  }
  return 0;
}
 