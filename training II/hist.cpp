//
//  main.cpp
//  Codeforces
//
//  Created by Tien Long on 8/11/20.
//  Copyright © 2020 Tit muoi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;
vector<long long> heights;

long long maxArea(vector<long long> heights, long long size){
    long long maxS = 0, i;
    stack<long long> indexHeights;
    vector<long long> left(size+1), right(size+1);

    indexHeights.push(0);

    for(i=1;i<=size;++i){
        if (heights[i]>heights[indexHeights.top()]){
            left[i]= indexHeights.top();
        } else {
            while(heights[i]<=heights[indexHeights.top()]){
                indexHeights.pop();
            }
            left[i] = indexHeights.top();
        }
        indexHeights.push(i);
    }

    while(!indexHeights.empty()){
        indexHeights.pop();
    }
    indexHeights.push(size+1);

    for(i=size;i>=1;i--){
        if(heights[i]>heights[indexHeights.top()]){
            right[i] = indexHeights.top();
        } else {
            while(heights[i]<=heights[indexHeights.top()]){
                indexHeights.pop();
            }
            right[i] = indexHeights.top();
        }
        indexHeights.push(i);
    }

    for (i=1;i<=size;++i){
        maxS = max(maxS, (right[i]-left[i]-1)*heights[i]);
    }
    return maxS;
}

int main(){
    long long n, i;
    cin>>n;
    while (n!=0) {
        heights.resize(n+2); 
        heights[0] = -1; heights[n+1]=-1;
        for (i=1; i<=n; ++i) {
            cin>>heights[i];
        }
        cout<<maxArea(heights, n)<<"\n";
        cin>>n;
    }
    return 0;
}


