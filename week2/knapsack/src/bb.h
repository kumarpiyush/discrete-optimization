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

        ll bst_val;
        vector<bool> in_bag_right_now;

        ll estimate_bound();
        void branch(int nd, ll optimistic_guess, int sack_space_left, ll earned_money);

    public:
        bb(int _n, int _k, vector<int> &_w, vector<int> &_v);
        pair<ll,vector<bool>> solve();
};
#endif
