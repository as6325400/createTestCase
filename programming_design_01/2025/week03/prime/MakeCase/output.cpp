#include<bits/stdc++.h>
#define int long long

using namespace std;

bool is_prime(int num){
  if(num == 1) return false;
  for(int i = 2; i * i <= num; i++){
    if(num % i == 0) return false;
  }
  return true;
}

int count_one(int num){
  int count = 0;
  while(num > 0){
    count += num % 2;
    num /= 2;
  }
  return count;
}

void output(string caseName){
  ifstream input(caseName);
  string outputName = caseName;
  outputName.pop_back();
  outputName.pop_back();
  outputName += "ans";
  ofstream output(outputName);
  int t;
  input >> t;
  for(int i = 0; i < t; i++){
    int num;
    input >> num;
    if(is_prime(num) and is_prime(count_one(num))) output << "YES\n";
    else output << "NO\n";
  }
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string path = "../data/";
  // sample testcase
  output(path + "sample/" + "01.in");
  output(path + "sample/" + "02.in");
  // secret testcase
  int testCaseName = 11;
  for(int i = 3; i <= testCaseName; i++){
    string id;
    if(i < 10) id = "0" + to_string(i);
    else id = to_string(i);
    string filename = path + "secret/" + id + ".in";
    output(filename);
  }
  return 0;
}
 