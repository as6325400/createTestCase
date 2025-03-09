#include<bits/stdc++.h>
#define int long long

using namespace std;

int MAX_T = 100000;
int MAX = 1000000;

void output(string caseName){
  ifstream input(caseName);
  string outputName = caseName;
  outputName.pop_back();
  outputName.pop_back();
  outputName += "ans";
  // ofstream output(outputName);
  int n;
  input >> n;
  if(n > MAX_T) cout << caseName << '\n';
  for(int i = 0; i < n; i++){
    int s, e;
    input >> s >> e;
    if(s >= e){
      cout << caseName << '\n';
      break;
    }
  }
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string path = "../data/";
  // sample testcase
  output(path + "sample/" + "01.in");
  output(path + "sample/" + "02.in");
  // secret testcase
  int testCaseName = 11;
  for(int i = 2; i <= testCaseName; i++){
    string id;
    if(i < 10) id = "0" + to_string(i);
    else id = to_string(i);
    string filename = path + "secret/" + id + ".in";
    output(filename);
  }
  return 0;
}
 