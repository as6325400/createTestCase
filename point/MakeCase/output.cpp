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
      if(s[i] == 'w') y++;
      if(s[i] == 'a') x--;
      if(s[i] == 's') y--;
      if(s[i] == 'd') x++;
    }
    else{
      if(ss.empty()) continue;
      char c = ss.top();
      ss.pop();
      if(c == 'w') y--;
      if(c == 'a') x++;
      if(c == 's') y++;
      if(c == 'd') x--;
    }
  }
  output << x << ' ' << y << '\n';
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
  int testCaseName = 15;
  for(int i = 4; i <= testCaseName; i++){
    string filename = path + "secret/" + to_string(i) + ".in";
    output(filename);
  }
  return 0;
}
 