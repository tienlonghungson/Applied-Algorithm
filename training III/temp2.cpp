#include <iostream>
#include <math.h>
#include <vector>
#include <utility>
 
using namespace std;
 
int n, K, Q;

int d[15], usedTruck[15], load[6], truck[6], fastestRoute[4100];
int dis[15][15];

int sumDis, ansTSP, minDis = INT_MAX, ans = INT_MAX;
 
 
vector<pair<int, bool> > bitMaskToList(int x)
{
    vector<pair<int, bool> > list;
 
    for (int i = 1; i <= n; i++)
    {
        if (x == 0)
        {
            break;
        }
 
        if (x % 2 == 1)
        {
            list.push_back(make_pair(i, false));
        }
 
        x = x / 2;
    }
 
    return list;
}
 
void TSP(vector<pair<int, bool> > list, int k, int p){
    int lenClis = (int) list.size();
    for (int i=0;i<lenClis;++i){
        if (!list[i].second) {
            
            list[i].second = true; 
            sumDis += dis[p][list[i].first] ;
            if (k<lenClis){
                if (sumDis + minDis*(lenClis-k+1) < ansTSP){
                    TSP(list, k+1, list[i].first);
                }
            } else {
            
                ansTSP= min (ansTSP, sumDis+dis[list[i].first][0]);
            
            }
            sumDis -= dis[p][list[i].first];
            list[i].second = false;
        }
    }
}
 
int TSP(int x)
{
    if (fastestRoute[x]==0) {
        sumDis = 0;
        ansTSP = INT_MAX;
        vector<pair<int, bool> > list = bitMaskToList(x);
        TSP(list, 1, 0);
        fastestRoute[x] = ansTSP;
    }
    // cout<<"fastestRoute["<<x<<"] = "<<fastestRoute[x]<<"\n";
    return fastestRoute[x];
}
 
void partition(int k)
{
    if ((K - usedTruck[k - 1]) > (n - k + 1))
    {
        return;
    }

    int boundRoute = min(usedTruck[k - 1] + 1, K);
 
    for (int i = 1; i <= boundRoute; i++)
    {
        if (i == (usedTruck[k - 1] + 1))
        {
            usedTruck[k] = usedTruck[k - 1] + 1;
        }
 
        else
        {
            if ((load[i] + d[k]) > Q)
            {
                continue;
            }
 
            usedTruck[k] = usedTruck[k - 1];
            
        }
        load[i] += d[k];
        truck[i] += (1<<(k-1));
        if (k == n) {
            if (usedTruck[k]==K) {
                int R = 0;
                for (int i = 1; i <= K; i++){
                    R += TSP(truck[i]);
                }
                ans = min(ans, R);
            }
        } else {
            partition(k+1);
        }
        load[i] -= d[k];
        truck[i] -= (1<<(k-1));
    }
}

int main()
{
    cin >> n >> K >> Q;
    usedTruck[0] = 0;
 
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
 
    for (int i = 1; i <= K; i++)
    {
        load[i] = 0;
        truck[i] = 0;
    }
 
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cin >> dis[i][j];
 
            if (i != j)
            {
                minDis = min(minDis, dis[i][j]);
            }
        }
    }

    partition(1);
    cout << ans<<"\n";
    return 0;
}