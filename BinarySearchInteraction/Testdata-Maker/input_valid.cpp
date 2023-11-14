#include <bits/stdc++.h>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

void check(ifstream &in);

int main(){
    string dir = "../data/";
    for (auto &entry: fs::recursive_directory_iterator(dir)){
        if (is_directory(entry)){
            continue;
        }
        string in_name = entry.path();
        if (in_name.substr(in_name.size() - 3) != ".in")
            continue;
        ifstream in(in_name);
        cout << "at file " << entry << "\n";
        check(in);
        in.close();
    }
    return 0;
}

void check(ifstream &in){
    int n;
    if(!(in >> n)){
        cout << "no input\n";
        return;
    }
    if(n < 1 || n > 100000000){
        cout << "n out of range\n";
        return;
    }

    string trash;
    if (in >> trash){
        cout << "trailing output : " << trash << "\n";
    }
}