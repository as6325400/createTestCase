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
  long long ax, ay, bx, by, px, py;
  input >> ax >> ay >> bx >> by >> px >> py;
  long long atob_x = bx - ax;   // ab 的 x
  long long atob_y = by - ay;   // ab 的 y
  long long atop_x = px - ax;   // ap 的 x
  long long atop_y = py - ay;   // ap 的 y
  long long cross = atob_x * atop_y - atop_x * atob_y;  // 外積
  if (cross == 0) {
    output << "Touch\n";  // 共線
  }
  else if (cross < 0) {   // 右邊
    output << "Right\n";
  }
  else {
    output << "Left\n";
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
  int testCaseName = 30;
  for(int i = 4; i <= testCaseName; i++){
    string filename = path + "secret/" + to_string(i) + ".in";
    output(filename);
  }
  return 0;
}
 