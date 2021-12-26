#include<iostream>

using namespace std;

const int MAX_N = 101, MAX_M=501;
const int mod = 1e9+7;
int total_ways[MAX_N][MAX_M];// total_ways[i][j] is the amount of ways to 
// distribute j retail outlets to i branches


int main(){
    int N,M;
    int a[MAX_N];
    cin>>N>>M;
    int i,j,k;
    for (i=1;i<=N;++i){
        cin>>a[i];
    }

    total_ways[0][0]=1;
    for (i=1;i<=N;++i){
        for (j=a[i];j<=M;++j){
            for (k=j-a[i];k>=0;k-=a[i]){
                total_ways[i][j] = (total_ways[i][j]+total_ways[i-1][k])%mod;
            }
            // cout<<"total_ways["<<i<<"]["<<j<<"] "<<total_ways[i][j];
        }
    }
    cout<<total_ways[N][M]<<"\n";
    return 0;
}