//
//  main.cpp
//  Codeforces
//
//  Created by Tien Long on 8/11/20.
//  Copyright © 2020 Tit muoi. All rights reserved.
//

#include<iostream>

using namespace std;
int n, K, Q;
int d[11], capacity[6], currLoad[6], usedStruck[11];
int *factorial;
const int mod = 1e9+7;
int result;

void routing(int i) {
    int j, boundRoute = min(usedStruck[i-1]+1, K);
    for (j=1;j<=boundRoute;++j){
        if(j==(usedStruck[i-1]+1)){
            usedStruck[i] = usedStruck[i-1]+1;
        } else {
            if(currLoad[j]+d[i]>Q){
                continue;
            }
            usedStruck[i] =  usedStruck[i-1];
        }
        currLoad[j]+= d[i];
        capacity[j]++;
        if (i<n) {
            routing(i+1);
        } else {
            if (usedStruck[i]==K){
                int temp=1;
                for (int t=1;t<=K;++t){
                    // cout<<"capacity["<<t<<"]= "<<capacity[t]<<"\n";
                    temp = (temp*factorial[capacity[t]])%mod;
                }
                result = (result+temp)%mod;
            }
        }
        currLoad[j]-=d[i];
        capacity[j]--;
    }
}

int main(){
    cin>>n>>K>>Q;
    // d = new int[n];
    // capacity = new int[K];
    // currLoad = new int[K];
    factorial= new int[n-K+2];
    int i;
    for (i=1;i<=n;++i) {
        cin>>d[i];
    }    
    factorial[0] = 0; factorial[1] = 1;
    for (i=2;i<=n-K+1;++i) {
        factorial[i] = (factorial[i-1]*i)%mod;
    }
    usedStruck[0]=0; result = 0;
    routing(1);
    cout<<result<<"\n";
    return 0;
}

/*

// the below code is considering to see where it went wrong
//
//  main.cpp
//  Codeforces
//
//  Created by Tien Long on 8/11/20.
//  Copyright © 2020 Tit muoi. All rights reserved.
//

#include<iostream>

using namespace std;
int n, K, Q;
int d[11], capacity[6], currLoad[6];//, usedStruck[11];
int *factorial;
const int mod = 1e9+7;
int result;

void routing(int i) {
    int j, boundRoute = min(i, K);
    for (j=1;j<=boundRoute;++j){
        
        if (currLoad[j]+d[i]<=Q) {
            currLoad[j]+= d[i];
            capacity[j]++;
            if (i<n) {
                routing(i+1);
            } else {
                
                int temp=1;
                for (int t=1;t<=K;++t){
                    temp = (temp*factorial[capacity[t]])%mod;
                    if (temp==0) {
                        break;
                    }
                }
                result = (result+temp)%mod;
            }
            currLoad[j]-=d[i];
            capacity[j]--;
        }
    }
}

int main(){
    cin>>n>>K>>Q;
    // d = new int[n];
    // capacity = new int[K];
    // currLoad = new int[K];
    factorial= new int[n-K+2];
    int i;
    for (i=1;i<=n;++i) {
        cin>>d[i];
    }
    factorial[0] = 0; factorial[1] = 1;
    for (i=2;i<=n-K+1;++i) {
        factorial[i] = (factorial[i-1]*i)%mod;
    }
    //usedStruck[0]=0;
    result = 0;
    routing(1);
    cout<<result<<"\n";
    return 0;
}
*/