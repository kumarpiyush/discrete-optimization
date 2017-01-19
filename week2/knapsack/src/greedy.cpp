#include "greedy.h"

greedy::greedy(int _n, int _k, vector<int> &_w, vector<int> &_v) : W(_w), V(_v) {
    n=_n;
    k=_k;
}

pair<int,vector<bool>> greedy::solve(){
    int val=0;

    for(int i=0;i<n;i++){
        in_bag.push_back(false);
    }

    for(int i=0;i<n;i++){
        if(k>=W[i]){
            k-=W[i];
            val+=V[i];
            in_bag[i]=true;
        }
    }

    return make_pair(val,in_bag);
}
