#include<bits/stdc++.h>
#define int long long

using namespace std;

char rv(char a){
    if(a == '}') return '{';
    if(a == ']') return '[';
    if(a == ')') return '(';
    return '#';
}

bool isValid(string s) {
    stack<char> save;
    // save.push(s[0]);
    for(int i = 0; i < s.size(); i++){
        if(!save.empty() and rv(s[i]) == save.top()) save.pop();
        else save.push(s[i]);
    }
    return save.empty();
}


void output(string caseName){
  ifstream input(caseName);
  string outputName = caseName;
  outputName.pop_back();
  outputName.pop_back();
  outputName += "ans";
  ofstream output(outputName);
  int n;
  string s;
  input >> n >> s;
  if(isValid(s)) output << "Yes\n";
  else output << "No\n";
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
  int testCaseName = 21;
  for(int i = 5; i <= testCaseName; i++){
    string filename = path + "secret/" + to_string(i) + ".in";
    output(filename);
  }
  return 0;
}
 