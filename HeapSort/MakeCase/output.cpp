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
  vector<int> odd;
  vector<int> even;
  int n;
  input >> n;
  for(int i = 0; i < n; i++){
    int num;
    input >> num;
    if(num % 2 == 1) odd.push_back(num);
    else even.push_back(num);
  }
  sort(odd.begin(), odd.end());
  sort(even.rbegin(), even.rend());
  for(auto i:odd){
    output << i << ' ';
  }
  output << '\n';
  for(auto i:even){
    output << i << ' ';
  }
  output << '\n';
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
  int testCaseName = 12;
  for(int i = 4; i <= testCaseName; i++){
    string filename = path + "secret/" + to_string(i) + ".in";
    output(filename);
  }
  return 0;
}
 