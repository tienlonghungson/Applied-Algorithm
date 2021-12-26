//
//  main.cpp
//  Codeforces
//
//  Created by Tien Long on 8/11/20.
//  Copyright © 2020 Tit muoi. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> sigs, maxLeft,maxRight;

int main(){
    int n,b;
    cin>>n>>b;
    sigs.resize(n);
    maxLeft.resize(n);
    maxRight.resize(n);

    cin>>sigs[0]; maxLeft[0] = sigs[0];
    for(int i=1;i<n;++i){
        cin>>sigs[i];
        maxLeft[i]= max(maxLeft[i-1], sigs[i]);
    }

    maxRight[n-1] = sigs[n-1];
    for (int i=n-2;i>=0;--i){
        maxRight[i] = max(maxRight[i+1],sigs[i]);
    }

    int measureSig = -1; 
    for (int i=1;i<n-1;++i){
        if((maxLeft[i-1]-sigs[i]>=b)&&(maxRight[i+1]-sigs[i]>=b)){
            measureSig = max(measureSig, maxLeft[i-1]+maxRight[i+1]-2*sigs[i]);
        }
    }

    cout<<measureSig<<"\n";
    return 0;
}
