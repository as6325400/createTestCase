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
  int n, q;
  input >> n >> q;
  set<int> s;
  for(int i = 0; i < n; i++){
    int num;
    input >> num;
    s.insert(num);
  }
  for(int i = 0; i < q; i++){
    int num;
    int flag = 1;
    input >> num;
    for(auto &j:s){
      if(num - j == j) continue;
      if(s.count(num - j)){
        output << "Yes\n";
        flag = 0;
        break;
      }
    }
    if(flag == 1) output << "No\n";
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
