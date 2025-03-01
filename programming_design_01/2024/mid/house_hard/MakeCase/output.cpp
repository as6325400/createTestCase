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
  int n, m;
  input >> n;
  // 紀錄每個 bits 0 的數量
  cout << n << endl;
  vector<vector<int>> dp(n + 1, vector<int>(32, 0));
  for(int i = 0; i < n; i++){
    int num;
    input >> num;
    dp[i + 1] = dp[i];
    for(int j = 0; j < 32; j++){
      if(num % 2 == 0) dp[i + 1][j]++;
      num /= 2;
    }
  }
  input >> m;
  for(int i = 0; i < m; i++){
    int l, r;
    input >> l >> r;
    int ans = 0;
    for(int j = 0; j < 32; j++){
      if(dp[r][j] - dp[l - 1][j] == 0) ans += (1 << j);
    }
    output << ans << endl;
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
  int testCaseName = 11;
  for(int i = 11; i <= testCaseName; i++){
    string filename = path + "secret/" + to_string(i) + ".in";
    output(filename);
  }
  return 0;
}
 