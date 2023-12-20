#include<bits/stdc++.h>
#define int long long

using namespace std;

int choose(int num, int win, int loss){
  int temp = max(win, loss);
  int ans = 1;
  for(int i = num; i > temp; i--){
    ans *= i;
  }
  for(int i = 2; i <= num - temp; i++){
    ans /= i;
  }
  return ans;
}

void output(string caseName){
  ifstream input(caseName);
  string outputName = caseName;
  outputName.pop_back();
  outputName.pop_back();
  outputName += "ans";
  ofstream output(outputName);
  int num, player, win, loss;
  input >> num >> player >> win >> loss;
  int mom = 1, child = 1;
  if(player == 1 or player == 2){
    for(int i = 0; i < num; i++){
      if(i < win) child *= 3;
      else child *= 4;
      mom *= 7;
    }
  }
  else{
    for(int i = 0; i < num; i++){
      if(i < win) child *= 1;
      else child *= 6;
      mom *= 7;
    }
  }
  child *= choose(num, win, loss);
  while(child % 7 == 0 and mom % 7 == 0){
    child /= 7;
    mom /= 7;
  }
  output << child << '/' << mom << '\n';
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string path = "../data/";
  // sample testcase
  output(path + "sample/" + "1.in");
  // secret testcase
  int testCaseName = 54;
  for(int i = 2; i <= testCaseName; i++){
    string filename = path + "secret/" + to_string(i) + ".in";
    output(filename);
  }
  return 0;
}
 