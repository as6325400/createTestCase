#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int teseCaseNum = 10;
  srand(time(nullptr));
  std::random_device rd;  
  std::mt19937 gen(rd()); 
  std::uniform_int_distribution<int> dis(1, 1000000000);

  vector<int> vec = {0, 0, 0, 5, 10, 20, 50, 100, 200, 500, 200000};
  for(int i = 3; i <= 10; i++){
    string path = "../data/secret/";
    string filename = path + to_string(i) + ".in";
    ofstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cants open file " << i << endl;
    }
    int q = vec[i];
    inputFile << vec[i] << ' ' << q << endl;
    vector<int> sum(vec[i], 0);
    int count = 0;
    while(1){
      int bound = min((int)400000, vec[i] * 10);
      int num = dis(gen) % (bound / 5) + 1;
      if(count + num > bound) break;
      int idx = dis(gen) % vec[i];
      if(sum[idx] + num <= bound){
        sum[idx] += num;
        count += num;
      }
    }
    for(int j = 0; j < vec[i]; j++){
      inputFile << sum[j] << ' ';
      for(int k = 0; k < sum[j]; k++){
        inputFile << dis(gen) % 1000000000 + 1 << " ";
      }
      inputFile << endl;
    }
    int M = *max_element(sum.begin(), sum.end());
    for(int j = 0; j < q; j++){
      int x = dis(gen) % vec[i];
      int y = dis(gen) % M;
      inputFile << x << ' ' << y << endl;
    }
    inputFile.close();
  }
  return 0;
}
