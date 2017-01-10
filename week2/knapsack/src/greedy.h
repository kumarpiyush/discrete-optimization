#ifndef GREEDY
#define GREEDY

#include <bits/stdc++.h>
using namespace std;

class greedy{
    private:
        int n,k;
        vector<int> in_bag;
        vector<int> &W,&V;

    public:
        greedy(int _n, int _k, vector<int> &_w, vector<int> &_v);
        pair<int,vector<int>> solve();
};
#endif
