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
  sort(v.begin(), v.end());
  if(v[30] == v[29]) cout << caseName << endl;
}

signed main(){
  ios_base::sync_with_stdio(false);
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
 