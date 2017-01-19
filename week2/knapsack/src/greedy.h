#ifndef GREEDY
#define GREEDY

#include "headers.h"

class greedy{
    private:
        int n,k;
        vector<bool> in_bag;
        vector<int> &W,&V;

    public:
        greedy(int _n, int _k, vector<int> &_w, vector<int> &_v);
        pair<int,vector<bool>> solve();
};
#endif
