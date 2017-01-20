#include "bb.h"

bb::bb(int _n, int _k, vector<int> &_w, vector<int> &_v) : W(_w), V(_v) {
    n=_n;
    k=_k;
}

pair<ll,vector<bool>> bb::solve(){
    for(int i=0;i<n;i++){
        in_bag.push_back(false);
        in_bag_right_now.push_back(false);
    }

    ll bound=estimate_bound();

    bst_val=0;
    start_time=clock();
    branch(0,bound,k,0);

    return make_pair(bst_val, in_bag);
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

    return (0.5+ret);   // round up
}

void bb::branch(int nd, ll optimistic_guess, int sack_space_left, ll earned_money){
    if(clock()-start_time >= allowed_time) return;  // play time is over
    cout<<nd<<endl;

    if(nd>=n){
        if(earned_money >= bst_val){
            bst_val=earned_money;
            in_bag=in_bag_right_now;
        }
        return;
    }

    if(optimistic_guess < bst_val){
        // no way man
        return;
    }

    in_bag_right_now[nd]=false;
    branch(nd+1,optimistic_guess-W[nd],sack_space_left,earned_money);

    if(sack_space_left >= W[nd]){
        in_bag_right_now[nd]=true;
        branch(nd+1,optimistic_guess,sack_space_left-W[nd],earned_money+V[nd]);
    }
}
