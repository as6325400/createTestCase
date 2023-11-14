#include <iostream>

using namespace std;

int main()
{
    int l = 1, r = 10000000, ans;
    int mid;
    while(l <= r)
    {
        mid = (l + r) / 2;
        cout << "? " << mid << endl;
        cout.flush();
        int a;
        cin >> a;
        if(a == 0)
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << "! " << ans << endl;
    return 0;
}