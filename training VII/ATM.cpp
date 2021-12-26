#include <iostream>

using namespace std;

long long square(long long a){
    return a*a;
}

long long pow(int base, int exponent){
    if (exponent==0) {
        return 1;
    }
    if (exponent==1) {
        return base;
    }

    if (exponent%2==0){
        return square(pow(base, exponent/2));
    } else {
        return base*square(pow(base, exponent/2));
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("/Users/tienlong/Documents/Xcode/io/input.txt","r",stdin);
#endif    
    int num_test;
    int min_amount_for_values[13],num_ways[13];
    min_amount_for_values[1]=1; num_ways[1]=1;
    min_amount_for_values[2]=1; num_ways[2]=1;
    min_amount_for_values[3]=1; num_ways[3]=1;
    min_amount_for_values[4]=2; num_ways[4]=2;
    min_amount_for_values[5]=1; num_ways[5]=1;
    min_amount_for_values[6]=2; num_ways[6]=2;
    min_amount_for_values[7]=2; num_ways[7]=1;
    min_amount_for_values[8]=2; num_ways[8]=1;
    min_amount_for_values[9]=3; num_ways[9]=3;
    min_amount_for_values[10]=2; num_ways[10]=1;
    min_amount_for_values[11]=3; num_ways[11]=2;
    long long n, e, auxiliary, min_amount, num_way;
    int c;
    cin>>num_test;
    while(num_test--){
        cin>>n>>c;
        if (n%1000){
            cout<<0<<"\n";
        } else {
            n/=1000;
            min_amount = 0LL;
            num_way=1LL;
            for (int i=c;i>=0 && n>0;--i){
                e = pow(10,i);
                auxiliary = (n-5*e)/(5*e);
                min_amount += auxiliary;
                n -= auxiliary*5*e;

                auxiliary = n/e;

                if (auxiliary){
                    min_amount += min_amount_for_values[auxiliary];
                    num_way *= num_ways[auxiliary];
                    n-= e*auxiliary;
                }
            }
            cout<<min_amount<<" "<<num_way<<"\n";
        }
    }
    return 0;
}