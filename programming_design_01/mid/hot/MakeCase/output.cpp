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
  int x_c, y_c, r;
  input >> x_c >> y_c >> r;
  int x_d, y_d;
  input >> x_d >> y_d;
  int dis = (x_c - x_d) * (x_c - x_d) + (y_c - y_d) * (y_c - y_d);
  if(dis <= r * r){
    output << "Yes" << endl;
  }
  else{
    output << "No" << endl;
  }
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string path = "../data/";
  // sample testcase
  output(path + "sample/" + "1.in");
  output(path + "sample/" + "2.in");
  output(path + "sample/" + "3.in");
  // secret testcase
  int testCaseName = 10;
  for(int i = 4; i <= testCaseName; i++){
    string filename = path + "secret/" + to_string(i) + ".in";
    output(filename);
  }
  return 0;
}
 