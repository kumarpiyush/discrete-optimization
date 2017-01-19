#include "headers.h"

vector<string> split(const string& s, char c) {
    vector<string> v;stringstream ss(s);string x;
    while (getline(ss, x, c)) v.push_back(x);
    return move(v);
}
void err(vector<string>::iterator it) {cerr<<endl;}
template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
    cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << "  "; err(++it, args...);
}
