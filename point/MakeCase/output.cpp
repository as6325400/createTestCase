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
  string s;
  input >> s;
  stack<char> ss;
  int x = 0, y = 0;
  for(int i = 0; i < n; i++){
    if(s[i] != 'b'){
      ss.push(s[i]);
      if(s[i] == 'u') y++;
      if(s[i] == 'l') x--;
      if(s[i] == 'd') y--;
      if(s[i] == 'r') x++;
    }
    else{
      if(ss.empty()) continue;
      char c = ss.top();
      ss.pop();
      if(c == 'u') y--;
      if(c == 'l') x++;
      if(c == 'd') y++;
      if(c == 'r') x--;
    }
  }
  output << x << ' ' << y << '\n';
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string path = "../data/";
  // sample testcase
  output(path + "sample/" + "01.in");
  output(path + "sample/" + "02.in");
  output(path + "sample/" + "03.in");
  // secret testcase
  int testCaseName = 15;
  for(int i = 4; i <= testCaseName; i++){
    string filename = path + "secret/"; 
    if(i < 10) filename += "0";
    filename += to_string(i) + ".in";
    output(filename);
  }
  return 0;
}
 