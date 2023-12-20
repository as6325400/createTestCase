#include<bits/stdc++.h>
#include<bits/extc++.h>
#define int long long

using namespace std;
using namespace __gnu_pbds;


void output(string caseName){
  ifstream input(caseName);
  string outputName = caseName;
  outputName.pop_back();
  outputName.pop_back();
  outputName += "ans";
  ofstream output(outputName);
  tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> rbt;
  int n;
  input >> n;
  for(int i = 0; i < n; i++){
    int mode, num;
    input >> mode >> num;
    if(mode == 1){
      rbt.insert(num);
    }
    else if(mode == 2){
      rbt.erase(num);
    }
    else{
      if(num > rbt.size()) output << -1 << '\n';
      else{
        output << *rbt.find_by_order(num - 1) << '\n';
      }
    }
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
  for(int i = 3; i <= testCaseName; i++){
    string filename = path + "secret/" + to_string(i) + ".in";
    output(filename);
  }
  return 0;
}
