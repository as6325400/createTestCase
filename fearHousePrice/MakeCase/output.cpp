#include<bits/stdc++.h>
#define int long long

using namespace std;

int query(vector<vector<int>> &dp, int l, int r){
  int num = r - l + 1, ans = 0, val = 1;
  for(int i = 0; i < 32; i++){
    if(dp[r][i] - dp[l - 1][i] == num){
      ans += val;
    }
    val *= 2;
  }
  return ans;
}

void output(string caseName){
  ifstream input(caseName);
  string outputName = caseName;
  outputName.pop_back();
  outputName.pop_back();
  outputName += "ans";
  ofstream output(outputName);
  int n, q;
  input >> n >> q;
  vector<int> save(n);
  vector<vector<int>> dp(n + 1, vector<int>(32, 0));
  for(int i = 0; i < n; i++){
    input >> save[i];
    dp[i + 1] = dp[i];
    int num = save[i];
    int index = 0;
    while(num > 0){
      dp[i + 1][index] += num % 2;
      index++;
      num /= 2;
    }
  }
  for(int i = 0; i < q; i++){
    int l, k, ans = 0;
    input >> l >> k;
    int left = l, right = n;
    while(left <= right){
      int mid = (left + right) / 2;
      int num = query(dp, l, mid);
      // cout << "val" << left << ' ' << right << ' ' << num  <<'\n';
      if(num >= k){
        left = mid + 1;
        ans = mid;
      }
      else right = mid - 1;
    }
    if(right < l) output << -1 << '\n';
    else output << ans - l + 1 << '\n';
  }
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string path = "../data/";
  // sample testcase
  output(path + "sample/" + "1.in");
  // secret testcase
  int testCaseName = 20;
  for(int i = 2; i <= testCaseName; i++){
    string filename = path + "secret/" + to_string(i) + ".in";
    output(filename);
  }
  return 0;
}
 