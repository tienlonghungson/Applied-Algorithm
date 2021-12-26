#include <iostream>
#include <vector>

using namespace std;
const int N=13;
vector<int> clique;
vector<int> is_added;
int edges[N][N];
int n,m;
int res=1;

void find_points(int num_point){
    if (num_point==(n+1)){
        return;
    }
    if (res==n){
        return;
    }

    bool can_add;
    for (int i=num_point;i<=n;++i){
        if (!is_added[i]){
            can_add = true;
            for (int curr_vers : clique){
                if (!edges[i][curr_vers]){
                    can_add=false;
                    break;
                }
            }
            if (can_add){
                res=max(res,num_point);
                is_added[i]=true;
                clique.push_back(i);
                find_points((num_point+1));
                clique.pop_back();
                is_added[i]=false;
            }
        }
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("/Users/tienlong/Documents/Xcode/io/input.txt","r",stdin);
#endif
    cin>>n>>m;
    int first_ver, second_ver;
    for (int i=0;i<m;++i){
        cin>>first_ver>>second_ver;
        edges[first_ver][second_ver]=edges[second_ver][first_ver]=1;
    }

    is_added.assign((n+1),false);
    find_points(1);
    cout<<res<<"\n";
    return 0;
}