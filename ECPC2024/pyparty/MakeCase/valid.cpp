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
  for(int i = 0; i < n; i++){
    int a, b;
    input >> a >> b;
    if(b <= a) cout << "error " << caseName << '\n';
    if(a < 1 or b > 1e6) cout << "error " << caseName << '\n';
  }
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string path = "../data/";
  // sample testcase
  output(path + "sample/" + "1.in");
  // secret testcase
  int testCaseName = 13;
  for(int i = 2; i <= testCaseName; i++){
    string id;
    if(i < 10) id = "0" + to_string(i);
    else id = to_string(i);
    string filename = path + "secret/" + id + ".in";
    output(filename);
  }
  return 0;
}
 