//
//  main.cpp
//  Codeforces
//
//  Created by Tien Long on 8/11/20.
//  Copyright © 2020 Tit muoi. All rights reserved.
//

#include<iostream>
#include<map>

using namespace std;

int n;
long long K, *s,*d,*r, *last;



int main(){
    cin>>n>>K;
    s = new long long[n]; d = new long long[n] ; r = new long long[n]; last = new long long[n];
    for (int i=0; i<n; ++i) {
        cin>>s[i]>>d[i]>>r[i];
        last[i] = s[i] + d[i] +K ;
    }
    return 0;
}
