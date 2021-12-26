//
//  main.cpp
//  Codeforces
//
//  Created by Tien Long on 8/11/20.
//  Copyright © 2020 Tit muoi. All rights reserved.
//

#include <iostream>
#include<vector>
#include<utility>
 
using namespace std;
 
int passed=0;
int cost[23][23], minCost=INT_MAX;
int n,k,tempFee,remainPos,busSeat,result=INT_MAX;
 
void nextStop(int previousStop){
    if ( remainPos== 1) {
        result = min(result, tempFee+cost[previousStop][0]);
        return ;
    }
 
    if (busSeat<k) {
        for (int i=1; i<=n; ++i) {
            if (((passed>>i)&1) == 0) {
 
                tempFee += cost[previousStop][i];
                remainPos--;
                busSeat++;
                passed+=(1<<i);
 
                if (tempFee+remainPos*minCost<result) {
                    nextStop(i);
                }
                passed-=(1<<i);
                busSeat--;
                remainPos++;
                tempFee-= cost[previousStop][i];
            }
        }
    }
//    else {
        for (int i=n+1; i<=2*n; ++i) {
            if (((passed>>i)&1)==0) {
                if (((passed>>(i-n))&1)==1) {
                    
                    tempFee+=cost[previousStop][i];
                    remainPos--;
                    busSeat--;
                    passed+=(1<<i);
                    
                    if (tempFee+remainPos*minCost<result) {
                        nextStop(i);
                    }
                    passed-=(1<<i);
                    busSeat++;
                    remainPos++;
                    tempFee-= cost[previousStop][i];
                }
            }
        }
//    }
}
 
int main(){
    cin>>n>>k;
    int i, j;
    for (i=0; i<=2*n; ++i) {
        for (j=0;j<=2*n; ++j) {
            cin>> cost[i][j];
            if(i!=j){
                minCost = min(minCost, cost[i][j]);
            }
        }
    }
    
    remainPos=2*n+1;
    tempFee=0; busSeat=0;
    nextStop(0);
    cout<<result<<"\n";
    return 0;
}

// #include<iostream>
// #include<vector>
// #include<utility>

// using namespace std;

// int n,k; //k is the maximum load;
// int *passengers, *path, *busSeat, **cost;
// int minFee = INT_MAX, tempFee=0, minTwoPos=INT_MAX;

// void seePath() {
//     for (int i=0;i<=2*n;++i) {
//         cout<<path[i]<<" ";
//     }
//     cout<<"\n";
// }

// void nextStop(int next) {
//     int i;
//     bool pickedUp = false ;
//     for (i=0;i<k;++i) {
//         if (busSeat[i]) {
//             path[next] = busSeat[i] + n;
//             busSeat[i] = 0;
//             tempFee += cost[path[next-1]][path[next]] ;
//             if (next==2*n) {
//                 if (tempFee + cost[path[next]][0] < minFee) {
//                     minFee = tempFee + cost[path[next]][0];
//                 } 
//             } else {
//                 if (tempFee + (2*n+1-next)*minTwoPos < minFee) {
//                     nextStop(next+1);
//                 }
//             }
//             tempFee -= cost[path[next-1]][path[next]];
//             busSeat[i] = path[next] - n;
//         } else {
//             if (!pickedUp) {
//                 pickedUp = true ;
//                 for (int t=1;t<=n;++t) {
//                     if (passengers[t]) {
//                         path[next] = t; 
//                         passengers[t]--;
//                         busSeat[i] = t; 
//                         tempFee += cost[path[next-1]][t] ;
//                         if (tempFee + (2*n+1-i)*minTwoPos < minFee) {
//                             nextStop(next+1);
//                         }
//                         tempFee -=  cost[path[next-1]][t];
//                         busSeat[i] = 0;
//                         passengers[t]++;
//                     }
//                 }
//             }
//         }
//     }
// }

// int main(){
//     int i,j;
//     cin>>n>>k;
//     passengers = new int[n+1];
//     path = new int[2*n+1];
//     path[0] = 0 ;
//     busSeat = new int[k];
//     for (i=0;i<k;++i) {
//         busSeat[i]=0; 
//     }
//     cost = new int*[2*n+1] ;
//     int *temp = new int[(2*n+1)*(2*n+1)];
//     for (i=0;i<2*n+1;++i) {
//         cost[i] = temp;
//         temp+=2*n+1;
//     }

//     for (i=0;i<2*n+1;++i) {
//         for (j=0;j<2*n+1;++j) {
//             cin>>cost[i][j];
//             if (cost[i][j]!=0) {
//                 minTwoPos = min(minTwoPos, cost[i][j]);
//             }
//         }
//     }

//     for (i=1;i<=n;++i) {
//         passengers[i]  = 1;
//     }

//     nextStop(1);
//     cout<<minFee<<"\n";
//     return 0;
// }
