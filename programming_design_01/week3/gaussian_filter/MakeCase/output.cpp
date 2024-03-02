#include<bits/stdc++.h>
#define int long long

using namespace std;

double pic[3][518][518];
int gray[518][518];

double filter[3][3] = 
{{0.045, 0.122, 0.045}, 
 {0.122, 0.332, 0.122}, 
 {0.045, 0.122, 0.045}};

void output(string caseName){
  ifstream input(caseName);
  string outputName = caseName;
  outputName.pop_back();
  outputName.pop_back();
  outputName += "ans";
  ofstream output(outputName);
  int n, m;
  input >> n >> m;
  for(int i = 0; i < 3; i++){
    for(int j = 1; j <= n; j++)
    {
      for(int k = 1; k <= m; k++)
      {
        input >> pic[i][j][k];
      }
    }
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      gray[i][j] = lround(pic[0][i][j] * 0.299 + pic[1][i][j] * 0.587 + pic[2][i][j] * 0.114);
    }
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      double num = 0;
      for(int k = -1; k < 2; k++){
        for(int q = -1; q < 2; q++){
          num += filter[k + 1][q + 1] * gray[i + k][j + q];
        }
      }
      output << lround(num) << ' ';
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
