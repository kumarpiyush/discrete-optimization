#include "bb.h"
#define ll long long int

bb::bb(int _n, int _k, vector<int> &_w, vector<int> &_v) : W(_w), V(_v) {
    n=_n;
    k=_k;
}

pair<int,vector<bool>> bb::solve(){
    int val=0;

    for(int i=0;i<n;i++){
        in_bag.push_back(false);
    }

    return make_pair(val, in_bag);
}

ll bb::estimate_bound(){
    vector<pair<double,int>> density_ind;
    for(int i=0;i<n;i++){
        density_ind.push_back(make_pair((double)V[i]/W[i], i));
    }

    sort(density_ind.begin(),density_ind.end());
    reverse(density_ind.begin(),density_ind.end());

    int lft=k;
    double ret=0;

    for(auto e : density_ind){
        if(W[e.second] <= lft){
            lft-=W[e.second];
            ret+=V[e.second];
        }
        else{
            ret+=e.first*lft;
            lft=0;
            break;
        }
    }

    return (0.5+ret);
}
