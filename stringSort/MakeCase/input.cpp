#include<bits/stdc++.h>
#define int long long

using namespace std;

char randomChar(){
  return (char)('a' + rand() % 26);  
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 1;
  srand(time(nullptr));
  vector<int> caseNum = {1, 1, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10};

  for(int i = 1; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i + 1) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i + 1 << endl;
    }
    // int t = caseNum[i - 1];
    // inputFile << t << endl;
    int num = 6e6;
    inputFile << num << ' ';
    string s;
    for(int j = 0; j < num; j++){
      s += randomChar();
    }
    inputFile << s << endl;
    inputFile.close();
  }
  return 0;
}
