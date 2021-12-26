#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int f,s,g,u,d;

void BFS(){
    vector<long long> distance((f+1), -1LL);
    queue<int> queue_for_bfs;

    distance[s]=0;
    queue_for_bfs.push(s);
    int next_ver;

    while (!queue_for_bfs.empty()){
        next_ver= queue_for_bfs.front();
        queue_for_bfs.pop();

        if ( (next_ver+u<=f) && (distance[next_ver+u]==-1)){
            distance[next_ver+u]=distance[next_ver]+1;
            if (next_ver+u==g){
                break;
            }
            queue_for_bfs.push((next_ver+u));
        }

        if ( (next_ver-d>=1) && (distance[next_ver-d]==-1) ){
            distance[next_ver-d] = distance[next_ver]+1;
            if (next_ver-d==g){
                break;
            }
            queue_for_bfs.push((next_ver-d));
        }
    }

    if (distance[g]==-1){
        cout<<"use the stairs\n";
    } else {
        cout<<distance[g]<<"\n";
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("/Users/tienlong/Documents/Xcode/io/ELEVTRBL.txt","r",stdin);
    #endif
    cin>>f>>s>>g>>u>>d;
    BFS();
    return 0;
}