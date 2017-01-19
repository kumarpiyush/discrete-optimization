#ifndef BB
#define BB

#include "headers.h"

// branch and bound
class bb{
    private:
        int n,k;
        vector<bool> in_bag;
        vector<int> &W,&V;

        double allowed_time=10000000;   // 10 seconds
        double start_time;

        ll estimate_bound();

    public:
        bb(int _n, int _k, vector<int> &_w, vector<int> &_v);
        pair<int,vector<bool>> solve();
};
#endif
