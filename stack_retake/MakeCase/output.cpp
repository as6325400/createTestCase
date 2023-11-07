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
  stack<char> s;
  int n;
  input >> n;
  for(int i = 0; i < n; i++){
    int mode;
    input >> mode;
    if(mode == 1){
      char c;
      input >> c;
      s.push(c);
    }
    else if(mode == 2){
      if(!s.empty()){
        output << s.top() << '\n';
        s.pop();
      }
      else
      {
        output << "no character\n";
      }
    }
    else{
      if(!s.empty()){
        output << s.top() << '\n';
      }
      else{
        output << "no character\n";
      }
    }
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
  int testCaseName = 12;
  for(int i = 3; i <= testCaseName; i++){
    string filename = path + "secret/" + to_string(i) + ".in";
    output(filename);
  }
  return 0;
}
 