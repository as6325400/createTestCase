#include<bits/stdc++.h>
#define int long long

using namespace std;

class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>> up;
    priority_queue<int,vector<int>,less<int>> down;
    MedianFinder() {
    }
    void addNum(int num) {
        if(down.empty() or down.top() > num) down.push(num);
        else up.push(num);
        
        if(down.size() + 1 < up.size()){
            down.push(up.top());
            up.pop();
        }
        else if(up.size() + 1 < down.size()){
            up.push(down.top());
            down.pop();
        }
        return;
    }
    
    int findMedian() {
        if(up.size() == down.size()) return (down.top() + up.top())/2;
        if(up.size() > down.size()) return up.top();
        return down.top();
    }
};


void output(string caseName){
  ifstream input(caseName);
  string outputName = caseName;
  outputName.pop_back();
  outputName.pop_back();
  outputName += "ans";
  ofstream output(outputName);
  int n;
  input >> n;
  MedianFinder m;
  for(int i = 0; i < n; i++){
    int mode;
    input >> mode;
    if(mode == 1){
      int num;
      input >> num;
      m.addNum(num);
    }
    else
    {
      output << m.findMedian() << '\n';
    }
    
  }
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string path = "../data/";
  // sample testcase
  output(path + "sample/" + "1.in");
  output(path + "sample/" + "2.in");
  // secret testcase
  int testCaseName = 13;
  for(int i = 3; i <= testCaseName; i++){
    string filename = path + "secret/" + to_string(i) + ".in";
    output(filename);
  }
  return 0;
}
 