#include<iostream>
#include<vector>

using namespace std;

int n_page[500], m ,k, longest_page;
long long sum;
vector<int> pos;

void print_result(long long result){
    // cout<<"result "<<result<<"\n";
    int next_slash=m-1, i, j;
    long long curr_num_page;
    pos.resize(k);
    for (i=k-1;i>=0;--i){
        curr_num_page=0;
        for (j=next_slash;j>=i;--j){
            if (curr_num_page+n_page[j]<=result){
                curr_num_page+=n_page[j];
            } else {
                break;
            }
        }
        pos[i]=j;
        next_slash=j;
    }
    pos[0]=-1; 
    // for (long long posi :pos){
    //     cout<<posi<<" ";
    // }
    // cout<<"\n";
    for (int i=1;i<k;++i){
        for (int j=pos[i-1]+1;j<=pos[i];++j){
            cout<<n_page[j]<<" ";
        }
        cout<<" / ";
    }
    for (int j=pos[k-1]+1;j<m;++j){
        cout<<n_page[j]<<" ";
    }
    cout<<"\n";
}

bool check(long long min_pages){
    long long num_scriber = 1, curr_num_page=0;
    for (int i=m-1;i>=0;--i){
        if (curr_num_page+n_page[i]<=min_pages){
            curr_num_page+=n_page[i];
        } else {
            curr_num_page=n_page[i];
            num_scriber++;
        }
    }
    if (num_scriber<=k){
        return true;
    }
    return false ;
}

void partition(){
    long long left = longest_page, right = sum+1, mid, res=-1;
    while(left<=right){
        mid = (left+right)/2;
        if (check(mid)){
            res = mid;
            right = mid-1;
        } else {
            left = mid+1;
        }
    }
    print_result(res);
}

int main(){
    int test, i,j;
    cin>>test;
    for ( i=0;i<test;++i){
        cin>>m>>k;
        longest_page=0; sum=0;
        for (j=0;j<m;++j){
            cin>>n_page[j];
            longest_page = max(longest_page, n_page[j]);
            sum+=n_page[j];
        }
        partition();
    }
    return 0;
}