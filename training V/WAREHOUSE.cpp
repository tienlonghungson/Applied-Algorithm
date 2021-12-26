#include<iostream>

using namespace std;

const int MAX_N = 1e3+1;
int N,T,D;
int a[MAX_N], t[MAX_N];
int goods[MAX_N][101]; // goods[i][j] represents the amount of goods that have taken 
// in a route that stopped at i and total time didn't exceed T.

int main(){
    cin>>N>>T>>D;
    int i,j,k;
    for (i=1;i<=N;++i){
        cin>>a[i];
    }
    for (i=1;i<=N;++i){
        cin>>t[i];
    }

    for (i=0;i<=T;++i){
        if (t[1]>i){
            goods[1][i]=0;
        } else {
            goods[1][i]=a[1];
        }
    }

    int res=goods[1][T];
    // int res=0;
    int last_lower_stop;
    for (i=2;i<=N;++i){
        for (j=0;j<=T;++j){
            if (j<t[i]){
                goods[i][j]=0;
            } else {
                last_lower_stop = max(1,i-D);
                goods[i][j]=a[i];
                for (k=last_lower_stop;k<i;++k){
                    goods[i][j]=max(goods[i][j],goods[k][j-t[i]]+a[i]);
                }
            }
        }
        res = max(res, goods[i][T]);
        // cout<<i<<" "<<res<<"\n";
    }

    cout<<res<<"\n";
    return 0;
}