#include<bits/stdc++.h>
#define int long long

using namespace std;




struct student{
  int grade[5];
  char name[20];
}typedef student;

bool compare(student a, student b){
  int sum1 = 0, sum2 = 0;
  for(int i = 0; i < 5; i++){
    sum1 += a.grade[i];
    sum2 += b.grade[i];
  }
  if(sum1 != sum2) return sum1 > sum2;
  for(int i = 0; i < 5; i++){
    if(a.grade[i] != b.grade[i]) return a.grade[i] > b.grade[i];
  }
  return strcmp(a.name, b.name) < 0;
}

void swap(student *a, student *b){
  student temp = *a;
  *a = *b;
  *b = temp;
}

void sort(student arr[], int n){

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n - i - 1; j++){
      if(!compare(arr[j], arr[j + 1])){
        swap(&arr[j], &arr[j + 1]);
      }
    }
  }
}


  

  
void output(string caseName){
  freopen(caseName.c_str(), "r", stdin);
  string outputName = caseName;
  outputName.pop_back();
  outputName.pop_back();
  outputName += "ans";
  freopen(outputName.c_str(), "w", stdout);
  int n;
  scanf("%lld", &n);
  student num[n + 3];

  for(int i = 0; i < n; i++){
    scanf("%s%lld%lld%lld%lld%lld", num[i].name, &num[i].grade[0], &num[i].grade[1], &num[i].grade[2], &num[i].grade[3], &num[i].grade[4]);
  }

  sort(num, n);

  for(int i = 0; i < n; i++){
    printf("%s\n", num[i].name);
  }
}

signed main(){
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
 