#include <iostream>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "validate.h"

#define ASK_TIME_LIMITS (100) // 猜測次數上限

using namespace std;

int main(int argc, char *argv[])
{
    init_io(argc, argv);

    int n;
    assert(judge_in >> n); // .in 用來放僅裁判可見之答案

    int request_times = 0, success = 0;
    while(1)
    {
        request_times++;
        if(request_times > ASK_TIME_LIMITS)
        {
            cerr << "Too many request, Expect: " << ASK_TIME_LIMITS << ", found: " << request_times << '\n';
            wrong_answer("Too many request\n");
            break;
        }
        std::string operation;
        if (!(author_out >> operation))
        {
            cerr << "missing required output operation at request times " << request_times << '\n';
            wrong_answer("missing required output operation\n");
        }

        int ask_number;
        if (!(author_out >> ask_number))
        {
            cerr << "missing required output of request number at request times " << request_times << '\n';
            wrong_answer("missing required output of request number\n");
        }
        if(operation != "?" && operation != "!")
        {
            cerr << "unknown operation\n"; 
            wrong_answer("unknown operation\n");
        }

        if(ask_number < (int)(-1e9) || ask_number > (int)(1e9))
        {
            cerr << "request number value " << ask_number << " out of bound at request times " << request_times << '\n';
            wrong_answer("request number value out of bound \n");
        }

        // 猜測
        if(operation == "?")
        {
            // cout << (n >= ask_number);
            // cout << std::endl;
            // cout.flush();
            // continue;
            if(ask_number < n){
              cout << -1 << endl;
              cout.flush();
            }
            else if(ask_number > n){
              cout << 1 << endl;
              cout.flush();
            }
            else{
              cout << 0 << endl;
              cout.flush();
            }
            continue;
        }

        // 確認答案
        if(n != ask_number)
        {
            cerr << "fail to guess correct number : " << n << ", request number : " << ask_number << '\n';
            wrong_answer("fail to guess correct number\n");
        }
        success = 1;
        break;
    }

    string trash;
    if(author_out >> trash) // 輸出多餘的東西
    {
        cerr << "trailing output : " << trash << '\n';
        wrong_answer("trailing output\n");
    }
    if(success)
        accept();
    else
    {
        cerr << "without answer it\n";
        wrong_answer("without answer it\n");
    }
    return 0;
}