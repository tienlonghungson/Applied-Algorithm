#include<iostream>
#include<algorithm>

using namespace std;

int N,C;
int x[100001];

bool check_valid_result(int min_dis){
    int pre_stall=x[0], count=1;
    for (int i=1;i<N;++i){
        if(x[i]-pre_stall>=min_dis){
            pre_stall=x[i];
            count++;
        }
    }
    return count>=C;

}

int aggrcow(){
    sort(x,x+N);
    int bottom = 0, top = x[N-1]-x[0]+1, mid, min_dis=-1;
    bool check;
    while(bottom<=top){
        mid = (bottom+top)/2;
        if(check_valid_result(mid)){
            min_dis=mid;
            bottom=mid+1;
        } else {
            top = mid-1;
        }
    }
    return min_dis;
}

int main(){
    int test, i,j;
    cin>>test;
    for (i=0;i<test;++i){
        cin>>N>>C;
        for (j=0;j<N;++j){
            // cin>>x[j];
            scanf("%d", &x[j]);
        }
        
        cout<<aggrcow()<<"\n";
    }
    return 0;
}