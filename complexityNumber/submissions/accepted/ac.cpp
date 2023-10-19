#include <iostream>

using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int len, ans = 1;
        string s;
        cin >> len >> s;
        for(int j = 0; j < len; j++){
            ans = max(ans, s[j] - '0');
        }
        cout << ans << '\n';
    }
    return 0;
}