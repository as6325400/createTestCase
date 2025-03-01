#include<bits/stdc++.h>

using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 30;
  srand(time(nullptr));

  for(int i = 4; i <= teseCaseNum; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<int> dis(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    auto a = make_pair(dis(gen), dis(gen));
    auto b = make_pair(dis(gen), dis(gen));
    inputFile << a.first << " " << a.second << " " << b.first << " " << b.second << " ";
    if(i % 2 == 0){
      inputFile << b.first - a.first + b.first << " " << b.second - a.second + b.second << endl;
    }
    else{
      inputFile << dis(gen) << " " << dis(gen) << endl;
    }
    inputFile.close();
  }
  return 0;
}
