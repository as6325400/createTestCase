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
  vector<int> arr(n);
  vector<int> dp(n);
  for(int i = 0; i < n; i++) input >> arr[i];
  int odd = 0, counto = 0;
  for(int i = 0; i < n; i += 2){
    odd = max(odd, arr[i]);
    counto++;
  }
  int even = 0, counte = 0;
  for(int i = 1; i < n; i += 2){
    even = max(even, arr[i]);
    counte++;
  }
  output<< max(odd + counto, even + counte) << '\n';
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string path = "../data/";
  // sample testcase
  output(path + "sample/" + "01.in");
  output(path + "sample/" + "02.in");
  // secret testcase
  int testCaseName = 10;
  for(int i = 3; i <= testCaseName; i++){
    string id;
    if(i < 10) id = "0" + to_string(i);
    else id = to_string(i);
    string filename = path + "secret/" + id + ".in";
    output(filename);
  }
  return 0;
}
 