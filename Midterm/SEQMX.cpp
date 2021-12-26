#include<iostream>
using namespace std;

int n, k;
int a[5001];
long long s[5001];
// double tbc[5001];
double tbc;
double re = -999999.0;

int main(){
    cin>>n>>k;
    s[0]=0;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
        // tbc[i] = -999999;
    }
    
    int start;
    for (int i=1;i<=n-k+1;++i){
        for (int j=i+k-1;j<=n;++j){
            tbc=((double)(s[j]-s[i-1]))/((double)(j-i+1));
            re = max(re, tbc);
        }
    }
    printf("%.5lf\n", re);
    return 0;
}

