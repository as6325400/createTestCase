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
  int concert, stay, ah, am, lh, lm;
  input >> concert >> stay >> ah >> am >> lh >> lm;
  int start = ah * 60 + am;
  int end = lh * 60 + lm;
  int ans = 0;
  if(end <= start){
    end += 1440;
    ans += stay;
  }
  int dis = (end - start) / 30;
  if(dis <= 4) ans += 30 * dis;
  else if(dis > 4 && dis <= 8) ans += (120 + (dis - 4) * 40);
  else ans += (280 + (dis - 8) * 60);
  output << ans + concert << '\n';
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string path = "../data/";
  // sample testcase
  output(path + "sample/" + "1.in");
  // secret testcase
  int testCaseName = 24;
  for(int i = 2; i <= testCaseName; i++){
    string filename = path + "secret/" + to_string(i) + ".in";
    output(filename);
  }
  return 0;
}
 