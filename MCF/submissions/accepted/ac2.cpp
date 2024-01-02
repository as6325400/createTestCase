#include <bits/stdc++.h>
#define int long long

using namespace std;

class Solution {
public:
    template<typename T>
    class dsu
    {
        private:
            // unordered_map<T,T> parent; 如果可以hash_可以改用umap加速
            vector<T> parent; // 都數字可以再用vector加速，然後建構子要改一下
            // map<T,T> parent;
        public:
            dsu(int number){
                parent.resize(number);
                for(int i = 0; i < number; i++)
                    parent[i] = i;
            }
            dsu(vector<T> save){
                for(auto &i:save){
                    parent[i] = i;
                }
            }
            int parent_number(){
                int count = 0;
                for(auto &i:parent){
                    if(i.first == i.second) count++;
                }
                return count;
            }
            T find_root(T x){
                if(x == parent[x]) return x;
                return parent[x] = find_root(parent[x]);
            }
            bool Same(T a, T b){
                return find_root(a) == find_root(b);
            }
            void Union(T a, T b){
                //將a併進b
                parent[find_root(a)] = find_root(b);
            }
    };
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<tuple<int, int, int>> save;
        for(int i = 0; i < points.size(); i++){
            for(int j = 0; j < points.size(); j++){
                int val = abs(points[i][1] - points[j][1]) + abs(points[i][0] - points[j][0]);
                save.push_back({val, i, j});
            }
        }
        sort(save.begin(), save.end());
        dsu<int> a(points.size());
        int ans = 0;
        for(auto [w,u,v]:save){
            if(!a.Same(u, v)){
                ans += w;
                a.Union(u, v);
            }
        }
        return ans;
    }
};

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> graph(n, vector<int>(2));
  for(int i = 0; i < n; i++){
    cin >> graph[i][0] >> graph[i][1];
  }
  Solution s;
  cout << s.minCostConnectPoints(graph) << '\n';
}