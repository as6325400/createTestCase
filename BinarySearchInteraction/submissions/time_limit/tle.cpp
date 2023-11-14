#include <iostream>

using namespace std;

int main()
{
    int l = 1, r = 10000000, last_ret = -1;
    for(int i = 1; i <= 1000000; i++)
    {
        cout << "? " << l << endl;
        cout.flush();
        int a;
        cin >> a;
        if(last_ret == 0 && a)
        {
            cout << "! " << a - 1 << endl;
            return 0;
        }
        last_ret = a;
    }
    return 0;
}