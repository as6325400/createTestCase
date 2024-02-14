#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void wa(){
    exit(43); // 答案錯誤時呼叫這個
}

void accept(){
    exit(42); // 答案正確時呼叫這個
}

// user_output: stdin
// .ans: argv[2]
// .in: argv[1]

int main(int argc, char *argv[]){
    ll n, m;
    ifstream input;
    input.open(argv[1]);
    ifstream ansFile;
    ansFile.open(argv[2]);
    if(!input)
    {
        cerr << "cannot open the input file" << argv[1] << '\n';
        wa();
    }
    input >> n >> m;
    ll ans, correct_ans;
    ansFile >> correct_ans;
    string check;
    cin >> ans;
    // 最小生成樹值錯誤
    if(ans != correct_ans){
      cerr << "Error MST weights.\n";
      cerr << "Your MST weights is " << ans << " Correct MST weights is " << correct_ans << '\n';
      wa();
    }


    // 存題目正確的圖
    vector<vector<ll>> graph(n + 1, vector<ll>(n + 1, 0));

    for(ll i = 0; i < m; i++){
      ll a, b, w;
      input >> a >> b >> w;
      graph[a][b] = w;
      graph[b][a] = w;
    }


    // 用 set 避免使用者輸出多條一樣的邊
    set<pair<ll, ll>> ss;
    for(ll i = 0; i < n - 1; i++){
      ll a, b;
      cin >> a >> b;
      ss.insert({a, b});
      // 單純讀掉答案的邊
      ansFile >> a >> b;
    }

    // 重複邊
    if(ss.size() != n - 1){
      cerr << "repeat edges.\n";
      wa();
    }


    // 輸出不存在的邊
    ll count_weight = 0;
    for(auto i:ss){
      if(i.first > n or i.second > n or i.first <= 0 or i.second <= 0){
        cerr << "does not exist point.\n";
        wa();
      }
      if(graph[i.first][i.second] == 0){
        cerr << "does not exist edge.\n";
        wa();
      }
      else count_weight += graph[i.first][i.second];
    }

    // 計算權重錯誤
    if(ans != count_weight){
      cerr << "count weight error.\n";
      wa();
    }

    int max_edge, correct_max_edge;
    cin >> max_edge;
    ansFile >> correct_max_edge;

    if(max_edge != correct_max_edge){
      cerr << "Error MST MaxEdge.\n";
      cerr << "Your MST MaxEdge is " << max_edge << " Correct MST MaxEdge is " << correct_max_edge << '\n';
      wa();
    }

    if(cin >> check){
        // 避免參賽者亂輸出一坨東西
        cerr << "Too much output for the user!\n";
        wa();
    }
    accept();
    return 0;
}