#ifndef BB
#define BB

#include "headers.h"

// branch and bound
class bb{
    private:
        int n,k;
        vector<bool> in_bag;
        vector<int> &W,&V;
        vector<int> shuffler;

        double allowed_time=60 * 1000 * 1000;   // in microseconds
        double start_time;

        ll bst_val;
        vector<bool> in_bag_right_now;

        double estimate_bound(int sp, int lft);
        void branch(int nd, int sack_space_left, ll earned_money);

    public:
        bb(int _n, int _k, vector<int> &_w, vector<int> &_v);
        pair<ll,vector<bool>> solve();
};
#endif
