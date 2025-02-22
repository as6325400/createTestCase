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
  vector<int> odd;
  vector<int> even;
  int n;
  input >> n;
  vector<pair<int, int>> a(n);
  for(int i = 0; i < n; i++){
    input >> a[i].first >> a[i].second;
  }
  sort(a.begin(), a.end());
  for(int i = 0; i < n; i++){
    output << a[i].first << ' ' << a[i].second << '\n';
  }
  output << '\n';
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string path = "../data/";
  // sample testcase
  output(path + "sample/" + "1.in");
  output(path + "sample/" + "2.in");
  output(path + "sample/" + "3.in");
  // secret testcase
  int testCaseName = 10;
  for(int i = 4; i <= testCaseName; i++){
    string filename = path + "secret/" + to_string(i) + ".in";
    output(filename);
  }
  return 0;
}
 