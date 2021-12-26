#include<iostream>

using namespace std;

int N,M,K;
int cost[21][31]; // max 20 stafves and max 30 task
int num_task_2_staff[21];
int min_total_cost=INT_MAX, curr_cost, min_task_cost=INT_MAX;

void assign(int index_task){
    if (index_task==N+1){
        min_total_cost = min(min_total_cost, curr_cost);
        // cout<<"update min_total "<<min_total_cost<<"\n";

        return;
    }

    for (int j=1;j<=M;++j){
        num_task_2_staff[j]++;
        if (num_task_2_staff[j]<=K) {
            curr_cost += cost[j][index_task];
            // cout<<"task "<<index_task<<" is assigned to "<<j<<"\n";
            // cout<<"curr_cost is "<<curr_cost<<"\n";
            if (curr_cost + min_task_cost*(N-index_task)<min_total_cost){
                assign(index_task+1);
            }
            // cout<<"unassign task "<<index_task<<" from "<<j<<"\n";
            curr_cost -= cost[j][index_task];
        }
        num_task_2_staff[j]--;
    }
}

int main(){
    cin>>N>>M>>K;
    for (int i=1;i<=M;++i){
        for (int j=1;j<=N;++j){
            cin>>cost[i][j];
            min_task_cost = min(min_task_cost, cost[i][j]);
        }
    }

    assign(1);
    cout<<min_total_cost<<"\n";
    return 0;
}