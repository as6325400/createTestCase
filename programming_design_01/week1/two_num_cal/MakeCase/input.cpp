#include<bits/stdc++.h>

using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 10;
  srand(time(nullptr));

  for(int i = 3; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<int> dis(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

    int a = dis(gen);
    int b = dis(gen);
    int op = rand() % 3;
    inputFile << a << " " << b << " ";
    if(op == 0){
      inputFile << "+";
    }else if(op == 1){
      inputFile << "-";
    }else{
      inputFile << "*";
    }
    inputFile << endl;
    inputFile.close();
  }
  return 0;
}
