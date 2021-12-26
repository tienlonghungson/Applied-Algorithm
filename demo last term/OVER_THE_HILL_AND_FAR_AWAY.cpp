#include <iostream>

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("/Users/tienlong/Documents/Xcode/io/input.txt","r",stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    const int N=1e6+1;
    int n;
    int a[N];
    long long hill_height=0, valley_height=0;
    int prev_state=0; // 1 is up, -1 is down, 0 is stay
    long long curr_up, curr_down;
    cin>>n;
    cin>>a[0];
    for (int i=1;i<n;++i){
        cin>>a[i];
        if (a[i]>a[i-1]){
            if (prev_state!= 1){
                curr_up=1LL;
                prev_state=1;
            } else {
                curr_up++;
            }
            valley_height = max(valley_height, min(curr_down, curr_up));
        } else if (a[i]<a[i-1]){
            if (prev_state!=-1){
                curr_down=1LL;
                prev_state=-1;
            } else {
                curr_down++;
            }
            hill_height = max(hill_height, min(curr_down, curr_up));
        } else {
            curr_up = curr_down = 0LL;
            prev_state = 0;
        }
    }
    cout<<hill_height<<" "<<valley_height<<"\n";
    return 0;
}