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
  int n;
  input >> n;
  vector<int> v(31, 0);
  for(int i = 0; i < n; i++){
    int x;
    input >> x;
    v[x]++;
  }
  int ans;
  int M = -1e9;
  for(int i = 1; i <= 30; i++){
    if(v[i] > M){
      M = v[i];
      ans = i;
    }
  }
  output << ans << endl;
}


signed main(){
  cin.tie(nullptr);
  string path = "../data/";
  // sample testcase
  output(path + "sample/" + "1.in");
  output(path + "sample/" + "2.in");
  output(path + "sample/" + "3.in");
  output(path + "sample/" + "4.in");
  // secret testcase
  int testCaseName = 10;
  for(int i = 5; i <= testCaseName; i++){
    string filename = path + "secret/" + to_string(i) + ".in";
    output(filename);
  }
  return 0;
}
 