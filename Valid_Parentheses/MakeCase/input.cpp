#include<bits/stdc++.h>
#define int long long

using namespace std;

char rv(char a){
  if(a == '(') return ')';
  if(a == '{') return '}';
  return ']';
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 18;
  srand(time(nullptr));
  int num = 200000;
  for(int i = 18; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    stack<char> s;
    // cout << i - 5 << ' ' << save[] << '\n';
    inputFile << num << '\n';
    for(int j = 0; j < (num); j++){
      int mode = rand() % 3;
      char c, r;
      if(mode == 0){
        c = '(';
        r = ')';
      }
      if(mode == 1){
        c = '{';
        r = '}';
      }
      if(mode == 2){
        c = '[';
        r = ']';
      }
      int rr = rand() % 2;
      if(rr == 0) inputFile << c;
      else if(rr == 1) inputFile << r;
      s.push(c);
    }
    // for(int j = 0; j < num / 2; j++){
    //   auto temp = s.top();
    //   s.pop();
    //   inputFile << rv(temp);
    // }
    inputFile.close();
  }
  return 0;
}
