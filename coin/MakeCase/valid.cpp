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
  if(n > 1000) cout << "ERROR" << endl;
  int m, k;
  input >> m >> k;
  vector<int> vec;
  if(m > 1000000000 || k > 20) cout << "ERROR" << endl;
  for(int i = 0; i < k; i++){
    int temp;
    input >> temp;
    vec.push_back(temp);
  }
  for(int i = 1; i < k; i++) if(vec[i] % vec[i - 1] != 0) cout << "ERROR" << endl;
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string path = "../data/";
  // sample testcase
  // output(path + "sample/" + "1.in");
  // secret testcase
  int testCaseName = 10;
  for(int i = 3; i <= testCaseName; i++){
    cout << i << endl;
    string filename = path + "secret/" + to_string(i) + ".in";
    output(filename);
  }
  return 0;
}
 