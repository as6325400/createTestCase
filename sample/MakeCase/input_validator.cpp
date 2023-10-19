#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
using namespace std;

const int N = 7;

void open_file(ifstream &finput, int t_case) {
    string dir_path = "../data/secret/";
    string file_name = to_string(t_case) + ".in";
    string input_path = dir_path + file_name;
    finput.open(input_path, ios::in);
    if(!finput) {
        cerr << "cannot open input file" << input_path << endl;
        exit(1);
    }
}

void check(ifstream &finput, int t_case) {
    long long a;

    cerr << "in test " << t_case << endl;

    if(!(finput >> a)) {
        cerr << "input error, missing a" << endl;
        exit(1);
    }

    if(a < 1 || a > 1'000'000'000'000'000'000) {
        cerr << "a out of range" << endl;
        exit(1);
    }
    string check;
    if(finput >> check) {
        cerr << "too many input" << endl;
        exit(1);
    }
    cerr << "ok" << endl;
}

void close_file(ifstream &finput, int t_case) {
    finput.close();
}

int main() {
    for(int i = 1;i <= N;i++) {
        ifstream finput;
        open_file(finput, i);
        check(finput, i);
        close_file(finput, i);
    }
    return 0;
}
