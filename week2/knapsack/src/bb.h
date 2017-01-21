#ifndef BB
#define BB

#include "headers.h"

// branch and bound
class bb{
    private:
        int n,k;
        vector<int> &W,&V;
        vector<int> shuffler;

        double allowed_time=120 * 1000000.0;   // in microseconds
        double start_time;

        const double optimistic_guess_factor = 1.0001;

        ll bst_val;
        vector<bool> in_bag, in_bag_right_now;

        double estimate_bound(int sp, int lft);
        void branch(int nd, int sack_space_left, ll earned_money);

        void greedy_extention();

    public:
        bb(int _n, int _k, vector<int> &_w, vector<int> &_v);
        pair<ll,vector<bool>> solve();
};
#endif
