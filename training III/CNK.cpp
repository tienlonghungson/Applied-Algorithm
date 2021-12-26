#include<iostream>

using namespace std;

long long n, m;
int k;
long long factorialN, invFactorialK, invFactorial_N_minus_K;

void gcdDiophant(long long a, long long b, long long &x, long long &y){
    if(b==0){
        x=1;
        y=0;
    } else {
        gcdDiophant(b, a%b, x, y);
        long long temp = x;
        x= y;
        y = temp-(a/b)*x;
    }
}

long long inverseModulo(long long base, long long modulo){
    long long x, y;
    gcdDiophant(base, modulo, x, y);
    return (x%modulo+modulo)%modulo;
}

void preComputWithGcd(long long n, long long k, long long modulo){
    long long i, temp;
    factorialN=1;
    for (i=1;i<=n;++i){
        factorialN *= i;
        factorialN %= modulo;
    }
    temp = inverseModulo(factorialN, modulo);
    for (i=n-1;i>=0;--i){
        temp = ((i+1)*temp)%modulo;
        if (i==k){
            invFactorialK = temp;
        }
        if (i==(n-k)) {
            invFactorial_N_minus_K = temp;
        }
    }
    
}

long long comb(long long n, int k, long long modulo){
    long long result = factorialN;
    result *= invFactorialK;
    result %= modulo;
    result *= invFactorial_N_minus_K;
    result %= modulo;
    return result;
}

int main(){
    int numTest;
    cin>>numTest;
    int i;
    for (i=0;i<numTest;++i){
        cin>>n>>k>>m;
        if (n%m==0) {
            cout<<0<<"\n";
        } else {
            preComputWithGcd(n,k,m);
            cout<<comb(n,k,m)<<"\n";
        }
    }
    return 0;
}