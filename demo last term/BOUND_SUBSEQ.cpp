#include <iostream>

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("/Users/tienlong/Documents/Xcode/io/input.txt","r",stdin);
    #endif
    const int N=20000+1;
    int n,m,M;
    int partial_sum[N], a[N];
    cin>>n>>m>>M;
    partial_sum[0]=0;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        partial_sum[i]=partial_sum[i-1]+a[i];
    }
    int tmp, res=0;
    for (int i=0;i<n;++i){
        for (int j=i+1;j<=n;++j){
            tmp = partial_sum[j]-partial_sum[i];
            if (tmp>=m && tmp<=M){
                res++;
            }
        }
    }
    cout<<res<<"\n";
    return 0;
}