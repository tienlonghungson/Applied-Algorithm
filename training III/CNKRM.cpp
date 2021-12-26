#include<iostream>

using namespace std;
const int mod = 1e9+7;
int n,k;
long long *factorial, *invFactorial;

int powMod(long long base, int exp){
    long long result = 1;
    while(exp){
        if (exp%2){
            result *= base;
            result %= mod;
        }
        base *= base;
        base %= mod;
        exp /= 2;
    }
    
    return (int)(result%mod);
}

void preComputeWithPow(){
    long long i;
    factorial[0]=1;
    for (i=1;i<=n;++i){
        factorial[i] = (factorial[i-1]*i)%mod;
    }
    invFactorial[n] = powMod(factorial[n], mod-2);
    for (i=n-1;i>=0;--i){
        invFactorial[i]= ((i+1)*invFactorial[i+1])%mod;
    }
}

void gcdDiophant(int a, int b,int &x, int &y){
    if(b==0){
        x=1;
        y=0;
    } else {
        gcdDiophant(b,a%b, x, y);
        int temp = x;
        x= y;
        y = temp - (a/b)*y;
    }
}

int inverseModulo(int base){
    int x,y;
    gcdDiophant(base,mod, x,y);
    return (x%mod+mod)%mod;
}

void preComputeWithGcd(){
    int i;
    factorial[0]=1;
    for (int i=1;i<=n;++i){
        factorial[i] = (factorial[i-1]*i)%mod;
    }
    invFactorial[n] = inverseModulo(factorial[n]);
    for (int i=n-1;i>=0;--i){
        invFactorial[i]= ((i+1)*invFactorial[i+1])%mod;
    }
}

int combMod(int a, int b){ // cal aCb%mod
    long long result = factorial[a];
    result *= invFactorial[b];
    result %= mod;
    result *= invFactorial[a-b];
    result %= mod;
    return (int) result;
}

int main(){
    cin>>k>>n;
    factorial = new long long[n+1];
    invFactorial = new long long[n+1];
    preComputeWithPow();
    cout<<combMod(n, k)<<"\n";
   
    return 0;
}