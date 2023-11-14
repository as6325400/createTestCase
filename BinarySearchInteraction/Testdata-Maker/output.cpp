#include <bits/stdc++.h>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

void solve(ifstream &, ofstream &);

int main(){
    string dir = "../data/";
    for (auto &entry : fs::recursive_directory_iterator(dir)){
        if (is_directory(entry))
            continue;
        string in_name = entry.path();
        if (in_name.substr(in_name.size() - 3) != ".in")
            continue;
        ifstream in(in_name);
        string out_name = in_name;
        out_name.pop_back(); out_name.pop_back();
        out_name += "ans";
        ofstream out;
        out.open(out_name, ios::trunc);


        cout << "deal with " << in_name << "\n";
        solve(in, out);


        in.close();
        out.close();
    }
    return 0;
}

void solve(ifstream &in, ofstream &out){
    int t;
    in >> t;
    
}