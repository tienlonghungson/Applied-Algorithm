#include<iostream>

using namespace std;

const int MAX_N = 3001, MAX_K = 101;
int N,K;
int a[MAX_N],c[MAX_N];
int total_goods[MAX_N][MAX_K];
//total_goods[i][j] is amount of goods in a route that has j points and stops at  point i

int main(){
    cin>>N>>K;
    K=K+1;
    int i,j,k;
    for (i=1;i<=N;++i){
        cin>>c[i];
    }
    for (i=1;i<=N;++i){
        cin>>a[i];
    }

    total_goods[1][1]=c[1];
    for (i=2;i<=K;++i){
        for (k=i-1;k<=N;++k){
            if (total_goods[k][i-1]!=0){
                for (j=k+1;(j<=k+a[k])&&(j<=N);++j){
                    total_goods[j][i] = max(total_goods[j][i],total_goods[k][i-1]+c[j]);
                    // cout<<"total_goods["<<j<<"]["<<i<<"]= "<<total_goods[j][i]<<"\n";
                }
            }
        }
    }
    cout<<total_goods[N][K]<<"\n";
    return 0;
}