#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    bool judge(vector<int> &time, int trip, long long k){
      long long ans = 0;
      for(auto &i:time){
        ans += k / i;
        if(ans >= trip) return true;
      }
      return ans >= trip;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
      long long left = 0, right = 1e14, mid;
      while(left <= right){
        mid = left + (right - left) / 2;
        auto now = judge(time, totalTrips, mid);
        auto next = judge(time, totalTrips, mid - 1);
        if(now == true and next == false) break;
        else if((now and next) == true) right = mid - 1; 
        else left = mid + 1;
      }
      return mid;
    }
};

void solve(){
    int num, trip;
    cin >> num >> trip;
    vector<int> time(num);
    for(int i = 0; i < num; i++){
        cin >> time[i];
    }
    Solution s;
    cout << s.minimumTime(time, trip) << '\n';
}

int main()
{
    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }
}