#include <bits/stdc++.h>
#include "greedy.h"
#include "dp.h"

using namespace std;

int main(int args, char** argv){
    freopen(argv[1],"r",stdin);

    int n,k;
    scanf("%d%d",&n,&k);

    vector<int> W,V;

    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        W.push_back(y);
        V.push_back(x);
    }

    dp g1(n,k,W,V);
    greedy g2(n,k,W,V);

    auto s1=g1.solve();
    auto s2=g2.solve();

    int bst=0;
    vector<bool> selected;

    if(s1.first >= bst){
        bst=s1.first;
        selected=s1.second;
    }
    if(s2.first >= bst){
        bst=s2.first;
        selected=s2.second;
    }

    printf("%d 0\n",bst);
    for(int i=0;i<n;i++){
        cout<<selected[i]<<" ";
    }
    printf("\n");
}
