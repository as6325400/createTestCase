#include<bits/stdc++.h>
#define int long long

using namespace std;


// id input[1/0] [狀態/output]
int arr[200005][2][2];

void output(string caseName){
  ifstream input(caseName);
  string outputName = caseName;
  outputName.pop_back();
  outputName.pop_back();
  outputName += "ans";
  ofstream output(outputName);
  int n, q;
  input >> n >> q;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < 2; j++){
      int id, in, out;
      input >> id >> in >> out;
      arr[i][in][0] = id;
      arr[i][in][1] = out;
    }
  }
  int now = 0;
  for(int i = 0; i < q; i++){
    int x;
    input >> x;
    output << arr[now][x][1] << "\n";
    now = arr[now][x][0];
  }
  output << "S" << now << '\n';
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
  for(int i = 2; i <= testCaseName; i++){
    string filename = path + "secret/" + to_string(i) + ".in";
    output(filename);
  }
  return 0;
}
 