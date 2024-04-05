#include<bits/stdc++.h>
#define int long long

using namespace std;

int arr[6][3];

void output(string caseName){
  ifstream input(caseName);
  string outputName = caseName;
  outputName.pop_back();
  outputName.pop_back();
  outputName += "ans";
  ofstream output(outputName);
  for(int i = 0; i < 6; i++){
    for(int j = 0; j < 3; j++){
      input >> arr[i][j];
    }
  }
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      output << arr[i][j] + arr[i + 3][j] << ' ';
    }
    output << '\n';
  }
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      output << arr[i][j] - arr[i + 3][j] << ' ';
    }
    output << '\n';
  }
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string path = "../data/";
  // sample testcase
  output(path + "sample/" + "1.in");
  // secret testcase
  int testCaseName = 10;
  for(int i = 2; i <= testCaseName; i++){
    string filename = path + "secret/" + to_string(i) + ".in";
    output(filename);
  }
  return 0;
}
 