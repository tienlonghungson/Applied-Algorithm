#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin>>n;

    int *t = new int[n];
    for (int i=0;i<n;++i){
        cin>>t[i];
    }
    sort(t,t+n);
    int last_day=0;

    for (int i=n-1;i>=0;--i){
        last_day = max(last_day,(n-i)+t[i]);
    }
    cout<<(last_day+1)<<"\n";

    delete[] t;
    return 0;
}