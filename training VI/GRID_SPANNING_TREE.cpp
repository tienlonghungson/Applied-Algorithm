#include <iostream>

using namespace std;
const int mod = 1e9+7;

int main(){
#ifndef ONLINE_JUDGE
    freopen("/Users/tienlong/Documents/Xcode/io/input.txt","r",stdin);
#endif
    int n;
    cin>>n;
    unsigned long long a=1,b=4,c=4;
    for (int i=3;i<=n;++i){
        c=((4*b)%mod-a);
        a=b;
        b=c;
    }
    cout<<c<<"\n";
    return 0;
}