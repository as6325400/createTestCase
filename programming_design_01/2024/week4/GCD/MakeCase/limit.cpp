#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1000000000;

bool isprime(int j){
    if(j == 1) return false;
    for(int i = 2; i * i <= j; i++){
        if(j % i == 0) return false;
    }
    return true;
    
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 11;
  srand(time(nullptr));
  std::random_device rd;  
  std::mt19937 gen(rd()); 
  std::uniform_int_distribution<int> dis(1, 1000000000);
  int num = 1000;
  for(int i = 11; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    inputFile << num << '\n';
    int count = 0;
    for(int j = MAX; j >= 0; j--){
        if(count == num) break;
        if(isprime(j)){
            inputFile << j << ' ';
            count++;
        }
    }
    inputFile << '\n';
    inputFile.close();
  }
  return 0;
}
