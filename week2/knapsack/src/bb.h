#ifndef BB
#define BB

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

// branch and bound
class bb{
    private:
        int n,k;
        vector<bool> in_bag;
        vector<int> &W,&V;

    public:
        bb(int _n, int _k, vector<int> &_w, vector<int> &_v);
        pair<int,vector<bool>> solve();

    private:
        ll estimate_bound();
};
#endif
