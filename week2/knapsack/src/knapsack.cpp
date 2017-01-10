#include <bits/stdc++.h>
#include "greedy.h"

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

    greedy g(n,k,W,V);

    auto s=g.solve();

    printf("%d 0\n",s.first);
    for(int i=0;i<n;i++){
        printf("%d ",s.second[i]);
    }
    printf("\n");
}
