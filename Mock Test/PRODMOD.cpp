#include<iostream>

using namespace std;

const int mod = 1e9+7;

int main(){
    int N;
    long long product=1, input;
    cin>>N;
    for (int i=0;i<N;++i){
        cin>>input;
        product = (product*input)%mod;
    }
    cout<<product<<"\n";
    return 0;
}