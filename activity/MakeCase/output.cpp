#include<bits/stdc++.h>
#define int long long

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
  return a.second < b.second;
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
  vector<pair<int, int>> vec(n);
  for(int i = 0; i < n; i++){
    int m, k;
    input >> m >> k;
    vec[i] = {m, k};
  }
  sort(vec.begin(), vec.end(), compare);
  int end = 0, count = 0;
  for(int i = 0; i < n; i++){
    if(end < vec[i].first){
      end = vec[i].second;
      count++;
    }
  }
  output << count << endl;
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string path = "../data/";
  // sample testcase
  output(path + "sample/" + "1.in");
  output(path + "sample/" + "2.in");
  // secret testcase
  int testCaseName = 10;
  for(int i = 3; i <= testCaseName; i++){
    string filename = path + "secret/" + to_string(i) + ".in";
    output(filename);
  }
  return 0;
}
 