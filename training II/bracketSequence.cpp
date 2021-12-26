//
//  main.cpp
//  Codeforces
//
//  Created by Tien Long on 8/11/20.
//  Copyright © 2020 Tit muoi. All rights reserved.
//

#include <iostream>
// #include <utility>
#include <string>
#include<string.h>
// #include <algorithm>
// #include <math.h>
#include<stack>
#include <vector>
// #include<map>

using namespace std;

void count(string input){
    const int LENGTH = (int) input.size();
    int end[LENGTH];
    memset(end,-1, sizeof end);
    
    stack<int> brackets;
    for (int i=0;i<LENGTH;++i) {
        if (input[i]=='('||input[i]=='[') {
            brackets.push(i);
        } else {
            if (!brackets.empty()) {
                if ((input[brackets.top()]=='('&& input[i]==')') ||
                    (input[brackets.top()]=='['&& input[i]==']')) {
                    end[brackets.top()] = i;
                    brackets.pop();
                } else {
                    while (!brackets.empty()) {
                        brackets.pop();
                    }
                }
            }
        }
    }
//    cout<<"Check Stuck\n";
    int maxBra=0, temp=0,count,pre=0;
    int start, stop, tempStart=-1,tempStop=-1;
//    cout<<"see end\n";
//    for (int i=0; i<LENGTH; ++i) {
//        cout<<end[i]<<"\t";
//    }
//
    int i=0;
    while(i<LENGTH){
        if (end[i]!=-1) {
            count=0;
            for(int j=1;j<=end[i];++j){
                if(input[j]=='['){
                    count++;
                }
            }
            if ((i-1)==pre) {
                temp+=count;
                pre = end[i];
            } else {
                temp = count;
                tempStart=i;
            }
            tempStop = end[i];
            if (maxBra<temp) {
                maxBra=temp;
                start = tempStart;
                stop = tempStop;
            }
            i=end[i]+1;
        } else {
            i++;
        }
    }
    cout<<maxBra<<"\n";
    if (maxBra) {
        for (i=start;i<=stop; ++i) {
            cout<<input[i];
        }
        cout<<"\n";
    }
}
int main(){
    string input;
    cin>>input;
    count(input);
}
