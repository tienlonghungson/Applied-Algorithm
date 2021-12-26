#include <iostream>
#include <algorithm>

using namespace std;
const int N=1e3;
int x[N],y[N];

bool compare(int x,int y){
    return (x>y);
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("/Users/tienlong/Documents/Xcode/io/input.txt","r",stdin);
    #endif
    int num_test, n,i;
    long long scalar;
    cin>>num_test;
    for (int j=1;j<=num_test;++j){
        cin>>n;
        for (i=0;i<n;++i){
            cin>>x[i];
        }
        for (i=0;i<n;++i){
            cin>>y[i];
        }
        sort(x,x+n);
        sort(y,y+n,compare);
        scalar=0LL;
        for (i=0;i<n;++i){
            scalar+=(long long)x[i]*(long long)y[i];
        }
        cout<<"Case #"<<j<<": "<<scalar<<"\n";
    }
    return 0;
}