#include <bits/stdc++.h>
#define int long long

using namespace std;

int count(vector<vector<int>> &vec, int state){
  vector<bool> check(1001, false);
  int ans = 0;
  if(state & 1){
    for(int i = vec[0][0]; i <= vec[0][1]; i++){
      if(check[i]) return -1;
      check[i] = true;
    }
    ans += vec[0][2];
  }
  if(state & 2){
    for(int i = vec[1][0]; i <= vec[1][1]; i++){
      if(check[i]) return -1;
      check[i] = true;
    }
    ans += vec[1][2];
  }
  if(state & 4){
    for(int i = vec[2][0]; i <= vec[2][1]; i++){
      if(check[i]) return -1;
      check[i] = true;
    }
    ans += vec[2][2];
  }
  return ans;
}

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<vector<int>> data(3, vector<int>(3));
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cin >> data[i][j];
    }
  }
  sort(data.begin(), data.end(), [](vector<int> &a, vector<int> &b){
    return a[2] > b[2];
  });
  vector<bool> check(1001, false);
  int ans = 0;
  for(int i = 0; i < 3; i++){
    int flag = 0;
    for(int j = data[i][0]; j <= data[i][1]; j++){
      if(check[j]){
        flag = 1;
        break;
      }
    }
    if(flag) continue;
    for(int j = data[i][0]; j <= data[i][1]; j++){
      check[j] = true;
    }
    ans += data[i][2];
  }
  cout << ans << endl;
}