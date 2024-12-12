#include<bits/stdc++.h>
#define int long long

using namespace std;

class Solution {
public:
    int isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {

      vector<int> bound = {1};
      int ans = 0;
      // for(int i = 0; i < nums.size(); i++){
      //   cout << nums[i] << " ";
      // }
      // cout << endl;
      for(int i = 1; i < nums.size(); i++){
        if((nums[i] & 1) == (nums[i - 1] & 1)) bound.push_back(i + 1);
      }
      bound.push_back(nums.size() + 1);

      for(int i = 0; i < queries.size(); i++){
        // cout << queries[i][0] << " " << queries[i][1] << endl;
        auto it1 = upper_bound(bound.begin(), bound.end(), queries[i][0]);
        auto it2 = upper_bound(bound.begin(), bound.end(), queries[i][1]);
        // cout << (it1 == it2) << endl;
        ans += (it1 == it2 ? true : false);
      }

      return ans;
    }
};


void output(string caseName){
  ifstream input(caseName);
  string outputName = caseName;
  outputName.pop_back();
  outputName.pop_back();
  outputName += "ans";
  ofstream output(outputName);
  int n, q;
  input >> n >> q;
  vector<int> nums(n);
  for(int i = 0; i < n; i++){
    input >> nums[i];
  }
  vector<vector<int>> queries(q, vector<int>(2));
  for(int i = 0; i < q; i++){
    input >> queries[i][0] >> queries[i][1];
  }
  Solution s;
  output << s.isArraySpecial(nums, queries) << endl;
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string path = "../data/";
  // sample testcase
  output(path + "sample/" + "01.in");
  // secret testcase
  int testCaseName = 36;
  for(int i = 2; i <= testCaseName; i++){
    string id;
    if(i < 10) id = "0" + to_string(i);
    else id = to_string(i);
    string filename = path + "secret/" + id + ".in";
    output(filename);
  }
  return 0;
}
 