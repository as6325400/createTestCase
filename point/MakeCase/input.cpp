#include<bits/stdc++.h>
#define int long long

using namespace std;

char randomchar(){
  vector<char> c = {'u', 'l', 'd', 'r', 'b'};
  return c[rand() % 5];
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 15;
  srand(time(nullptr));

  vector<int> save = {0, 0, 0, 0, 10, 15, 15, 15 , 20, 25, 30, 50, 50, 1000, 10000, 200000};
  for(int i = 4; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path;
    if(i < 10) filename += "0";
    filename += to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    int num = save[i];
    inputFile << num << '\n';
    for(int i = 0; i < num; i++){
      inputFile << randomchar();
    }
    inputFile << '\n';
    inputFile.close();
  }
  return 0;
}
