#include "headers.h"
#include "bb.h"
#include "dp.h"
#include "greedy.h"

using namespace std;

int main(int args, char** argv){
    srand(time(0));
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

    greedy g1(n,k,W,V);

    auto s1=g1.solve();

    ll bst=0;
    vector<bool> selected;

    if(s1.first >= bst){
        bst=s1.first;
        selected=s1.second;
    }

    cout<<bst<<" 0\n";
    for(int i=0;i<n;i++){
        cout<<selected[i]<<" ";
    }
    printf("\n");
}
