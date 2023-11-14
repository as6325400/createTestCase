#include <bits/stdc++.h>
#include <filesystem>

#define N_MAX 10000000

using namespace std;
random_device rd;
uniform_int_distribution<long long> dist(0, LLONG_MAX);

vector<ofstream> open(string testcase_name, int num);
void close(vector<ofstream> &files);
void small_random();
void large_random();
void limit();
string path = "../data/secret/";

int main(){
    small_random();
    large_random();
    limit();
    return 0;
}

typedef __int128_t lll;

vector<ofstream> open(string testcase_name, int num){
    vector<ofstream> res(num);
    for (int i = 0; i < num; i++){
        string file_name = path + testcase_name + to_string(i + 1) + ".in";
        ofstream out;
        res[i].open(file_name, ios::trunc);
        cout << "create " << file_name << "\n";
    }
    return res;
}

void close(vector<ofstream> &files){
    for (auto &out: files)
        out.close();
}

void small_random(){
    cout << "generate small random testcases...\n";
    auto files = open("small random", 5);
    for (int i = 0; i < files.size(); i++){
        auto &out = files[i];
        cout << "generate small random" << i + 1 << ".in\n";
        int t = (dist(rd) % 100 + 1);
        out << t << "\n";
    }
    close(files);
}

void large_random(){
    cout << "generate large random testcases...\n";
    auto files = open("large random", 7);
    for (int i = 0; i < files.size(); i++){
        auto &out = files[i];
        cout << "generate large random" << i + 1 << ".in\n";
        int t = dist(rd) % N_MAX + 1;
        out << t << "\n";
    }
    close(files);
}

void limit(){
    cout << "generate limit testcases...\n";
    auto files = open("limit", 3);

    cout << "generate limit1.in testcases\n";
    files[0] << 1 << "\n";

    cout << "generate limit2.in testcases\n";
    files[1] << N_MAX << "\n";

    cout << "generate limit3.in testcases\n";
    files[2] << (1 + N_MAX) / 2 << "\n";

    close(files);
}
