#include<iostream>

using namespace std;

int N,M;
int cost[16][16], min_cost=INT_MAX;
int city_on_path[16], total_cost;
bool check[16];
int count_satisfied_path;

void TSP(int index_city){
    if (index_city==N+1){
        if (total_cost+cost[city_on_path[N]][1]<=M){
            count_satisfied_path++;
        }
        return;
    }

    for (int i=1;i<=N;++i){
        if (!check[i]) {
            check[i]=true;
            city_on_path[index_city]=i;
            total_cost += cost[city_on_path[index_city-1]][i];

            if (total_cost + (N+1-index_city)*min_cost<=M){
                TSP(index_city+1);
            }
        
            total_cost -= cost[city_on_path[index_city-1]][i];
            check[i]=false;
        }
    }
}


int main(){
    cin>>N>>M;
    for (int i = 1;i<=N;++i){
        for (int j=1;j<=N;++j){
            cin>>cost[i][j];
            if (i!=j){
                min_cost= min(min_cost, cost[i][j]);
            }
        }
        check[i]=false;
    }
    city_on_path[1]=1;
    check[1]=true;
    TSP(2);
    cout<<count_satisfied_path<<"\n";
    return 0;
}