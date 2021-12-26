#include <iostream>
#include <vector>
using namespace std;

const int N = 2e3+1;
vector<int> reaction_bugs[N];
int mark[N];

void dfs(int bug){
    for (int reaction_bug: reaction_bugs[bug]){
        if (mark[reaction_bug]==-1){
            mark[reaction_bug]=1-mark[bug];
            dfs(reaction_bug);
        }
    }
}
void solve(int num_scenario, int num_bugs){
    bool is_biparties=true;
    int i;
    for (i=1;i<=num_bugs;++i){
        mark[i]=-1;
    }

    for (i=1;i<=num_bugs;++i){
        if (mark[i]==-1){
            mark[i]=0;
            dfs(i);
        }
    }

    for (i=1;i<=num_bugs;++i){
        for (int reaction_bug : reaction_bugs[i]){
            is_biparties &= (mark[i]!=mark[reaction_bug]);
        }
    }
    if (is_biparties){
        cout<<"Scenario #"<<num_scenario<<":\nNo suspicious bugs found!\n";
    } else {
        cout<<"Scenario #"<<num_scenario<<":\nSuspicious bugs found!\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("/Users/tienlong/Documents/Xcode/io/input.txt","r",stdin);
    #endif
    int num_scenario,i,j;
    int num_bugs, num_reaction, reaction_bug1,reaction_bug2;
    cin>>num_scenario;
    for (j=1;j<=num_scenario;++j){
        cin>>num_bugs>>num_reaction;
        for (i=1;i<=num_bugs;++i){
            reaction_bugs[i].clear();
        }
        for (i=0;i<num_reaction;++i){
            cin>>reaction_bug1>>reaction_bug2;
            reaction_bugs[reaction_bug1].push_back(reaction_bug2);
            reaction_bugs[reaction_bug2].push_back(reaction_bug1);
        }
        solve(j,num_bugs);
    }
    return 0;
}