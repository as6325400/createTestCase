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
  int width = n * 2 - 1;
  int left = n - 1, right = n - 1;
  for(int i = 0; i < n - 1; i++){
    for(int j = 0; j < width; j++){
      if(j == left && left == right){
        output << "*";
        break;
      }
      else if(j == left || j == right){
        output << "*";
        if(j == right){
          break;
        }
      }
      else output<< " ";
    }
    left--;
    right++;
    output << "\n";
  }
  for(int i = 0; i < width; i++) output << "*";
  output << "\n";
  // else

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(j == n - 1) output << "*\n";
      else output << " ";
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
  int testCaseName = 18;
  for(int i = 3; i <= testCaseName; i++){
    string filename = path + "secret/" + to_string(i) + ".in";
    output(filename);
  }
  return 0;
}
 