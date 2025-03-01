#include<bits/stdc++.h>
#define int long long

using namespace std;

int gcd(int a, int b){
  if(b == 0) return a;
  return gcd(b, a % b);
}


void output(string caseName){
  cout << caseName << ':';
  ifstream input(caseName);
  string outputName = caseName;
  outputName.pop_back();
  outputName.pop_back();
  outputName += "ans";
  ofstream output(outputName);
  int n;
  input >> n;
  if(n > 1000 || n < 1) cout << "n is out of range" << endl;    
  for(int i = 0; i < n; i++){
    int x;
    input >> x;
    if(x > 1000000000 || x < 1) cout << "x is out of range" << endl;
  }
  cout << '\n';
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string path = "../data/";
  // sample testcase
  output(path + "sample/" + "1.in");
  output(path + "sample/" + "2.in");
  // secret testcase
  int testCaseName = 11;
  for(int i = 3; i <= testCaseName; i++){
    string filename = path + "secret/" + to_string(i) + ".in";
    output(filename);
  }
  return 0;
}
 