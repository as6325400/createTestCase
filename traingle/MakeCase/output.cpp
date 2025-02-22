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
  pair<int, int> p1, p2, p3;
  input >> p1.first >> p1.second;
  input >> p2.first >> p2.second;
  input >> p3.first >> p3.second;
  int x1 = p2.first - p1.first;
  int y1 = p2.second - p1.second;
  int x2 = p3.first - p1.first;
  int y2 = p3.second - p1.second;
  output << (abs(x1 * y2 - y1 * x2) + 1) / 2 << '\n';
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
 