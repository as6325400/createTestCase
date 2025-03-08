#include<bits/stdc++.h>
#define int long long

using namespace std;

vector<int> prime_table(int n){
  vector<int> table(n + 1, false);
  for(int i = 2; i <= n; i++){
    for(int j = i; j <= n; j += i){
      table[j]++;
    }
  }
  return table;
}

auto table = prime_table(10000000);

vector<int> closestPrimes(int left, int right) {
      
  vector<int> tp;

  for(int i = max(left, 2LL); i <= right; i++){
    if(table[i] == 1) tp.push_back(i); 
  }

  if(tp.size() <= 1) return {-1, -1};
  
  int idx = -1, mx = 1e9;
  for(int i = 0; i < tp.size() - 1; i++){
    if(tp[i + 1] - tp[i] < mx){
      idx = i;
      mx = tp[i + 1] - tp[i];
    }
  }

  return {tp[idx], tp[idx + 1]};
}

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
    int left, right;
    input >> left >> right;
    output << closestPrimes(left, right)[0] << '\n';
  }
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string path = "../data/";
  // sample testcase
  output(path + "sample/" + "01.in");
  output(path + "sample/" + "02.in");
  // secret testcase
  int testCaseName = 11;
  for(int i = 3; i <= testCaseName; i++){
    string id;
    if(i < 10) id = "0" + to_string(i);
    else id = to_string(i);
    string filename = path + "secret/" + id + ".in";
    output(filename);
  }
  return 0;
}
 