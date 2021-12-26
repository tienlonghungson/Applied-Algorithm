//
//  main.cpp
//  Codeforces
//
//  Created by Tien Long on 11/12/20.
//  Copyright © 2020 Tit muoi. All rights reserved.
//

#include <iostream>
#include <tuple>
#include <algorithm>
#include <string.h>

using namespace std;

const int MAX_NUM_OF_REC = 6*30+1;

int main(){
    int num_of_kind, num_case=1;
    int i,j;
    tuple<int,int,int> rec[MAX_NUM_OF_REC];
    int input[3], temp;
    int ans;
    int max_heights[MAX_NUM_OF_REC];
    
    bool (*compare)(tuple<int,int,int>, tuple<int,int,int>) = [](tuple<int,int,int> a, tuple<int,int,int>b)->bool{
        return (get<0>(a)!=get<0>(b))?(get<0>(a)>get<0>(b)):( (get<1>(a)!=get<1>(b) )?(get<1>(a)>get<1>(b)):get<2>(a)>get<2>(b) );
    };
    
    while (1) {
        cin>>num_of_kind;
        if (num_of_kind) {
            
            ans=0;
            memset(max_heights, 0, sizeof(max_heights));
            temp=0;
            
            for (i=1; i<=num_of_kind; ++i) {
                cin>>input[0]>>input[1]>>input[2];
                sort(input, input+3);
                do {
                    get<0>(rec[++temp]) = input[0];
                    get<1>(rec[temp]) = input[1];
                    get<2>(rec[temp]) = input[2];
                }while(next_permutation(input, input+3));
            }
            
            sort(rec+1, rec+temp+1, compare);
            get<0>(rec[0])=INT_MAX;
            get<1>(rec[0])=INT_MAX;
            get<2>(rec[0])=0;
            
            for (i=1;i<=temp;++i){
                for (j=0; j<i; ++j) {
                    if (get<0>(rec[j])>get<0>(rec[i])&&get<1>(rec[j])>get<1>(rec[i])){
                        max_heights[i] = max(max_heights[i], max_heights[j]+get<2>(rec[i]));
                    }
                }
                ans = max(ans, max_heights[i]);
            }
            cout<<"Case "<< num_case<<": maximum height = "<<ans<<"\n";
            num_case++;

        } else {
            break;
        }
    }
    return 0;
}
