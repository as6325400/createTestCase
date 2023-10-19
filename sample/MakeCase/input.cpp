#include<fstream>
#include<iostream>
#include<random>
#include<ctime>
using namespace std;

const int N = 7;

void open_input(ofstream &fout, int t_case) {
    string dir_path = "../data/secret/";
    string file_name = to_string(t_case) + ".in";
    string input_path = dir_path + file_name;
    fout.open(input_path, ios::out | ios::trunc);
    if(!fout) {
        cerr << "cannot open file" << input_path << endl;
        exit(1);
    }
}

default_random_engine gen(time(NULL));
uniform_int_distribution<int> unif(0, 2147483647);

void make_input(ofstream &fout, int t_case) {
    if(t_case == 1) {
        // example
        fout << "3" << endl;
    } else if(t_case <= 4) {
        // small
        int num1 = unif(gen) % 100 + 1;
        fout << num1 << endl;
    } else if(t_case == 5) {
        // extreme
        fout << "1000000000000000000" << endl;
    } else {
        // normal
        long long num1 = unif(gen) % 1'000'000'000'000'000'000 + 1;
        fout << num1 << endl;
    }
}
void close_input(ofstream &fout, int t_case) {
    fout.close();
}
int main() {
    for(int i = 1; i <= N; i++) {
        ofstream fout;
        open_input(fout, i);
        make_input(fout, i);
        close_input(fout, i);
    }
    return 0;
}
