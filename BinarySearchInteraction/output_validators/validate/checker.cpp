#include <iostream>
#include "testlib.h"

using namespace std;

int main(int argc, char *argv[])
{
    setName("Guess the Number");
    registerTestlibCmd(argc, argv);
    int n = inf.readInt(1, 10000000);
    cout.flush();
    int left = 50;
    bool ok = false;
    char interact_operator;
    int interact_number;
    while((interact_operator = ouf.readChar()) != EOF)
    {
        left--;
        ouf.readSpace(); // read the space after !
        if(interact_operator == '!')
        {
            interact_number = ouf.readInt(1, 10000000);
            if(interact_number == n)
                ok = true;
            break;
        }
        else if(interact_operator == '?')
        {
            interact_number = ouf.readInt(1, 10000000);
            if(interact_number <= n)
                cout << "0" << endl;
            else
                cout << "1" << endl;
        }
        else
            quitf(_wa, "Invalid interaction");
        ouf.readEoln(); // read the end of line after the number
    }
    if(left < 0)
        quitf(_wa, "Too many queries");
    if(!ok)
        quitf(_wa, "Wrong answer");
    if(!ouf.seekEof())
        quitf(_wa, "Extra information in the output file");
    quitf(_ok, "OK, you guessed the number in %d queries", 30 - left);
    return 0;
}