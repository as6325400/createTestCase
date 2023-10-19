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
    string s;
    input >> s;
    if(s == "inf") output << 0 << '\n';
    else if(s == "NaN") output << "inf" << '\n';
    else{
      stringstream ss(s);
      double num;
      ss >> num;
      output << 1 / num << '\n';
    }
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
    string filename = path + "secret/" + to_string(i) + ".in";
    output(filename);
  }
  return 0;
}
 