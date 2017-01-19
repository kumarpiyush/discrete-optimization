#include "dp.h"
#define ll long long int

dp::dp(int _n, int _k, vector<int> &_w, vector<int> &_v) : W(_w), V(_v) {
    n=_n;
    k=_k;
}

pair<int,vector<bool>> dp::solve(){
    int val=0;

    for(int i=0;i<n;i++){
        in_bag.push_back(false);
    }

    if(n*k >= 50000000){
        return make_pair(val,in_bag);
    }

    ll** dp = new ll*[n];
    for(int i=0;i<n;i++){
        dp[i]=new ll[k+1];
    }

    for(int j=0;j<=k;j++){
        if(W[0]<=j) dp[0][j]=V[0];
        else dp[0][j]=0;
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<=k;j++){
            dp[i][j]=dp[i-1][j];
            if(W[i]<=j){
                dp[i][j]=max(dp[i][j],V[i]+dp[i-1][j-W[i]]);
            }
        }
    }

    int lft=k;
    for(int i=n-1;i>=0;i--){
        if((i>0 and dp[i][lft] != dp[i-1][lft]) or (i==0 and dp[i][lft]>0)){
            in_bag[i]=true;
            val+=V[i];
            lft-=W[i];
        }
    }

    return make_pair(val,in_bag);
}
