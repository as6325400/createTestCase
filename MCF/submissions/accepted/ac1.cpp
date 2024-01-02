#include <bits/stdc++.h>
#define int long long

using namespace std;

class Solution {
public:
    int mst(vector<vector<int>> &graph, int node_num){
        vector<bool> in_mst(node_num, false);
        vector<int> mst_ans(node_num);
        vector<int> d(node_num);
        in_mst[0] = true;
        for(int i = 0; i < node_num; i++){
            d[i] = graph[0][i];
            mst_ans[i] = 0;
        }
        for(int i = 0; i < node_num; i++){
            int min = 10000000;
            int this_node = -1;
            for(int j = 0; j < node_num; j++){
                if(!in_mst[j] and d[j] < min){
                    min = d[j];
                    this_node = j;
                }
            }
            if(this_node == -1) break;
            in_mst[this_node] = true;
            for(int j = 0; j < node_num; j++){
                if(!in_mst[j] and graph[this_node][j] < d[j]){
                    d[j] = graph[this_node][j];
                    mst_ans[j] = this_node;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < node_num; i++){
            ans += graph[i][mst_ans[i]];
        }
        return ans;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> adjcent_matrix(points.size(),vector<int>(points.size(), 0));
        for(int i = 0; i < points.size(); i++){
            for(int j = 0; j < points.size(); j++){
                int val = abs(points[i][1] - points[j][1]) + abs(points[i][0] - points[j][0]);
                adjcent_matrix[i][j] = val;
            }
        }
        return mst(adjcent_matrix, points.size());
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