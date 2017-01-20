#include "bb.h"

bb::bb(int _n, int _k, vector<int> &_w, vector<int> &_v) : W(_w), V(_v) {
    n=_n;
    k=_k;
}

pair<ll,vector<bool>> bb::solve(){
    for(int i=0;i<n;i++){
        in_bag.push_back(false);
        in_bag_right_now.push_back(false);
        shuffler.push_back(i);
    }

    random_shuffle(shuffler.begin(),shuffler.end());

    bst_val=0;
    start_time=clock();
    branch(0,k,0);

    return make_pair(bst_val, in_bag);
}

vector<pair<double,int>> density_ind;

double bb::estimate_bound(int sp, int lft){
    density_ind.clear();
    for(int i=sp;i<n;i++){
        density_ind.push_back(make_pair((double)V[shuffler[i]]/W[shuffler[i]], i));
    }

    sort(density_ind.begin(),density_ind.end());
    reverse(density_ind.begin(),density_ind.end());

    double ret=0;

    for(auto& e : density_ind){
        if(W[e.second] <= lft){
            lft-=W[shuffler[e.second]];
            ret+=V[shuffler[e.second]];
        }
        else{
            ret+=e.first*lft;
            lft=0;
            break;
        }
    }

    return ret;
}

void bb::branch(int nd, int sack_space_left, ll earned_money){
    if(clock()-start_time >= allowed_time) return;  // play time is over

    if(nd>=n){
        if(earned_money >= bst_val){
            bst_val=earned_money;
            in_bag=in_bag_right_now;
        }
        return;
    }

    double optimistic_guess=estimate_bound(nd,sack_space_left)+earned_money;

    if(optimistic_guess < 1.000 * bst_val){
        // no way man
        return;
    }

    in_bag_right_now[shuffler[nd]]=false;
    branch(nd+1,sack_space_left,earned_money);

    if(sack_space_left >= W[shuffler[nd]]){
        in_bag_right_now[shuffler[nd]]=true;
        branch(nd+1,sack_space_left-W[shuffler[nd]],earned_money+V[shuffler[nd]]);
    }
}
