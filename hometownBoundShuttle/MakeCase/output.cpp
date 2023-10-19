#include<bits/stdc++.h>
#define int long long

using namespace std;

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

void output(string caseName){
  ifstream input(caseName);
  string outputName = caseName;
  outputName.pop_back();
  outputName.pop_back();
  outputName += "ans";
  ofstream output(outputName);
  int t;
  input >> t;
  for(int i = 0; i < t; i++){
    Solution ans;
    int num, trip;
    input >> num >> trip;
    vector<int> time(num);
    for(int j = 0; j < num; j++)
    {
      input >> time[j];
    }
    output << ans.minimumTime(time, trip) << endl;
  }
  output.close();
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string path = "../data/";
  // sample testcase
  output(path + "sample/" + "1.in");
  int testCaseName = 12;
  for(int i = 2; i <= testCaseName; i++){
    string filename = path + "secret/" + to_string(i) + ".in";
    output(filename);
  }
  return 0;
}
 