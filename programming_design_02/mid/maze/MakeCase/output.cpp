#include<bits/stdc++.h>
#define int long long

using namespace std;

int c(int a, int b){
  int ans = 1;
  for(int i = 1; i <= a; i++){
    ans *= i;
  }
  for(int i = 1; i <= b; i++){
    ans /= i;
  }
  for(int i = 1; i <= a - b; i++){
    ans /= i;
  }
  return ans;
}

void output(string caseName){
  ifstream input(caseName);
  string outputName = caseName;
  outputName.pop_back();
  outputName.pop_back();
  outputName += "ans";
  ofstream output(outputName);
  int x1, y1, idx;
  input >> x1 >> y1 >> idx;
  if(idx == 0){
    output << c(x1 + y1, x1) << '\n';
  }
  else{
    int x2, y2;
    input >> x2 >> y2;
    output << c(x1 - x2 + y1 - y2, y1 - y2) * c(x2 + y2, x2) << '\n';
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
 