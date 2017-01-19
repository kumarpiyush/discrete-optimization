#ifndef DP
#define DP

#include "headers.h"

class dp{
    private:
        int n,k;
        vector<bool> in_bag;
        vector<int> &W,&V;

    public:
        dp(int _n, int _k, vector<int> &_w, vector<int> &_v);
        pair<int,vector<bool>> solve();
};
#endif
