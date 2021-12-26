#include <iostream>
#include <math.h>
#include <vector>
#include <utility>
 
using namespace std;

int n,K,Q;
const int N = (1<<12);//2=n=12,1=K=5,1=Q=50
int truck[6];
int result, load[6], usedTruck[15],sumDis, minDis=INT_MAX, ansTSP ;
int dis[15][15], d[15];
int fastestRoute[N];



vector<pair<int,bool> > bitMaskToList(int x) {
    // cout<<"Resol "<<x<<"\n";
    vector<pair<int, bool> > listClis;
    for (int k=1; k<=n;++k) {
        if (x==0){
            break;
        } 

        if (x%2) {
            listClis.push_back(make_pair(k, false));
            // cout<<"push "<< k<< " on "<< x<<"\n";
        }

        x /= 2;
    }
    return listClis ;
}

void TSP(vector<pair<int,bool> > clis, int prev, int order){
    int lenClis = (int) clis.size();
    for (int k=0;k<lenClis;++k){
        if (!clis[k].second) {
            
            clis[k].second = true; 
            sumDis += dis[prev][clis[k].first] ;
            if (order<lenClis){
                if (sumDis + minDis*(lenClis-order+1) < ansTSP){
                    TSP(clis, clis[k].first, order+1);
                }
            } else {
                ansTSP = min (ansTSP, sumDis+dis[clis[k].first][0]);
           
            }
            sumDis -= dis[prev][clis[k].first];
            clis[k].second = false;
        }
    }
}

int TSP(int x){
    if (fastestRoute[x]==0){
        ansTSP = INT_MAX;
        sumDis = 0;
        vector<pair<int, bool> > clis = bitMaskToList(x);
        TSP(clis, 0, 1);
        fastestRoute[x] = ansTSP;
        
    }
    // cout<<"fastestRoute["<<x<<"] = "<< fastestRoute[x] <<"\n";
    return fastestRoute[x];
}

void partition(int k){
    if (K-usedTruck[k-1]>(n-k+1)) {
        return ;
    }
    int i , boundRoute = min(usedTruck[k-1]+1, K);
    for (i=1;i<=boundRoute;++i){
        if (i== (usedTruck[k-1]+1)) {
            usedTruck[k] = usedTruck[k-1] + 1;
        } else {
            if (load[i]+d[k]>Q){
                continue;
            }
            usedTruck[k] = usedTruck[k-1];
        }

        load[i] += d[k];
        truck[i] += (1<<(k-1)) ;
        // cout<<"Load "<<k<<" on "<<i<<"\n";
        if (k==n){
            if (usedTruck[k]==K){
                int temp = 0;
                for (int t=1;t<=K;++t){
                    temp += TSP(truck[t]);
                }
                result = min(result, temp);
                // cout<<"Updating result "<< result<<"\n";
            }
        } else { 
            partition(k+1);
        }
        load[i] -= d[k];
        truck[i] -= (1<<(k-1));
    }
}


int main(){
    cin>>n>>K>>Q;
    usedTruck[0] = 0;
    
    int j,i;
    for(j=1;j<=n;++j){
        cin>>d[j];
    }

    for (j=1;j<=K;++j){
        truck[j]= 0 ;
        load[j] = 0;
    }

    for(j=0;j<=n;++j){
        for ( i = 0; i <=n; i++)
        {
            cin>>dis[j][i];
            if (j!=i){
                minDis = min(minDis, dis[j][i]);
            }
        }
        
    }  

    // for (j=1;j<=N;++j){
    //     fastestRoute[j] = 0;
    // }
   
    result = INT_MAX;
    partition(1);
    cout<<result<<"\n";
    return 0;
}

/************************************************************************************
*************************************************************************************
*************************************************************************************/

