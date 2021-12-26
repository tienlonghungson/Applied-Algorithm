//
//  main.cpp
//  Codeforces
//
//  Created by Tien Long on 11/12/20.
//  Copyright © 2020 Tit muoi. All rights reserved.
//

#include <iostream>

using namespace std;

int main(){
    int W,H;
    int N;
    cin>>W>>H;
    cin>>N;
    int *w = new int[N+1], *h = new int[N+1];
    int i,j,k;
    for (i=1;i<=N;++i){
        cin>>w[i]>>h[i];
    }
    
    int **min_remainder_area = new int*[W+1];
    int *temp= new int[(W+1)*(H+1)];
    for (i=0;i<=W;++i){
        min_remainder_area[i] = temp;
        temp+=H+1;
    }

//    int min_remainder_area[601][601];
    for (i=1;i<=W;++i){
        for (j=1;j<=H;++j){
            min_remainder_area[i][j]=i*j;
            for (k=1;k<=N;++k){
                if (i==w[k]&&j==h[k]){
                    min_remainder_area[i][j]=0;
                    break;
                }
            }
            
            for (k=1; k<i; ++k) {
                min_remainder_area[i][j] = min(min_remainder_area[i][j], min_remainder_area[i-k][j]+ min_remainder_area[k][j]);
            }
            
            for (k=1; k<j; ++k) {
                min_remainder_area[i][j] = min(min_remainder_area[i][j], min_remainder_area[i][k]+min_remainder_area[i][j-k]);
            }
        }
    }
    cout<<min_remainder_area[W][H]<<"\n";
    return 0;
}
