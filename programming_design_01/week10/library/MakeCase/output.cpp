#include<bits/stdc++.h>
#define int long long

using namespace std;

struct lib{
  string name;
  string id;
  int price;
}typedef lib;

string to_lower(string a){
  for(int i = 0; i < a.size(); i++){
    if(a[i] >= 'A' && a[i] <= 'Z'){
      a[i] = a[i] - 'A' + 'a';
    }
  }
  return a;
}

bool cmp(string a, string b){
  a = to_lower(a);
  b = to_lower(b);
  if(a.size() > b.size()){
    return false;
  }
  for(int i = 0; i < a.size(); i++){
    if(a[i] != b[i]){
      return false;
    }
  }
  return true;
}

void output(string caseName){
  ifstream input(caseName);
  string outputName = caseName;
  outputName.pop_back();
  outputName.pop_back();
  outputName += "ans";
  ofstream output(outputName);
  int n;
  input >> n;
  vector<lib> v(n);
  for(int i = 0; i < n; i++){
    input >> v[i].name;
    input >> v[i].id;
    input >> v[i].price;
  }
  string str;
  int case_num = 1;
  while(input >> str){
    output << "Case " << case_num++ << ":\n";
    int flag = 0;
    for(int i = 0; i < n; i++){
      if(cmp(str, v[i].name)){
        flag = 1;
        output << v[i].name << '\n';
        output << v[i].id << '\n';
        output << v[i].price << '\n';
      }
      else if(cmp(str, v[i].id)){
        flag = 1;
        output << v[i].name << '\n';
        output << v[i].id << '\n';
        output << v[i].price << '\n';
      }
    }
    if(flag == 0){
      output << "NULL" << '\n';
    }
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
 