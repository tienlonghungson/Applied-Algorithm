#include<iostream>
using namespace std;

const int SIZE = 1e5 +1;
int N,M;
int s[SIZE];

int count(){
    int left, right, mid, result=0, total=0;
    for (int i=1;i<=N;++i){
        left= 0, right = i+1;
        while(left<=right){
            mid = (left+right)/2;
            if (s[i]-s[mid]<=M){
                result = mid;
                right = mid-1;
            } else {
                left= mid+1;
            }
        }
        // cout<<i<< " result: "<<result<<"\n";
        total += (i-result);
    }
    return total;
}

int main(){
    cin>>N>>M;
    s[0]=0;
    int input;
    for (int i=1;i<=N;++i){
        cin>>input;
        s[i]=s[i-1]+input;
    }
    cout<<count()<<"\n";
    return 0;
}