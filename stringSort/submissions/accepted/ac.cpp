#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int len;
    string s;
    cin >> len >> s;
    vector<int> c(26);
    for(int i = 0; i < len; i++)
    {
        c[s[i] - 'a']++;
    }
    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < c[i]; j++)
        {
            cout << (char)('a' + i);
        }
    }
    cout << '\n';
}

int main()
{   
    int tt = 1;
    while(tt--){
        solve();
    }
}