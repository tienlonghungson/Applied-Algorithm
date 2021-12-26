#include <iostream>

using namespace std;

//input2 must get full path
//input8 must get full path
int n,Q;
const int N=51;
int a[N];
int main(){
    #ifndef ONLINE_JUDGEMENT
    freopen("/Users/tienlong/Documents/Xcode/Codeforces/Codeforces/End Term/input/input_1.txt","r",stdin);
//    freopen("/Users/tienlong/Documents/Xcode/io/output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>Q;
    int sum=0;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        sum+=a[i];
    }
    cout<<sum<<"\n";
    cout<<sum-Q<<"\n";
}
