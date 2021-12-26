#include<iostream>
 
using namespace std;

long long M;
int a[1000000], N;
int h=0;
 
long long count_wood(int height){
    long long total_cut_off = 0;
    for (long long i=0;i<N;++i){
        if(a[i]>height){
            total_cut_off += (a[i]-height);
        }
    }
     return total_cut_off;
}
 
void binary_search_height(){
    int left= 0, right = h+1;
    
    while(left<right){
        h = (left+right)/2;
        // cout<<left<<" "<<right<<" "<<h<<" "<<count_wood(h)<<"\n";
        if (left== right - 1){
            break;
        }
        if (count_wood(h)>=M){
            left = h;
        } else {
            right = h;
        }
    }
    cout<<h<<"\n";
}
 
int main(){
    ios_base::sync_with_stdio(false); // this code is used to boot up the speed of cin
    cin>>N>>M;
    for(long long i=0;i<N;++i){
        cin>>a[i];
        h = max(h, a[i]);
    }
    binary_search_height();
    return 0;
}