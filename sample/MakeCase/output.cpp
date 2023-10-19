#include <iostream>
#include <fstream>
using namespace std;

const int N = 7;

void open_file(ifstream &finput, ofstream &foutput, int t_case) {
    string dir_path = "../data/secret/";
    
    string input_name = to_string(t_case) + ".in";
    string input_path = dir_path + input_name;

    string output_name = to_string(t_case) + ".ans";
    string output_path = dir_path + output_name;

    finput.open(input_path, ios::in);
    foutput.open(output_path, ios::out | ios::trunc);
    if(!finput) {
        cerr << "cannot open input file " << t_case << endl;
        exit(1);
    }
    if(!foutput) {
        cerr << "cannot open output file " << t_case << endl;
        exit(1);
    }
}

void solve(ifstream &finput, ofstream &foutput, int t_case) {
    long long a;
    finput >> a;
    if(a % 4 == 0)
        foutput << a << '\n';
    else if(a % 4 == 1)
        foutput << 1 << '\n';
    else if(a % 4 == 2)
        foutput << a + 1 << '\n';
    else
        foutput << 0 << '\n';
}
void close_file(ifstream &finput, ofstream &foutput, int t_case) {
    finput.close();
    foutput.close();
}
int main() {
    for(int i = 1; i <= N; i++) {
        ifstream finput;
        ofstream foutput;
        open_file(finput, foutput, i);
        solve(finput, foutput, i);
        close_file(finput, foutput, i);
    }
    return 0;
}
