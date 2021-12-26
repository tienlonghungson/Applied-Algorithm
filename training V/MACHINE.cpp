#include <iostream>

using namespace std;

const int N=2e6+2;
int n;
int s[N], t[N];
int max_since[N];
int main() {
	cin>>n;
	int last_day_ever=0;
	for (int i=0;i<n;++i){
		scanf("%d %d",&s[i],&t[i]);
		last_day_ever = max(last_day_ever, t[i]);
		max_since[s[i]] = max(max_since[s[i]], t[i]-s[i]);
	}
	max_since[last_day_ever+1] = 0;
	max_since[last_day_ever] = 0;
	for (int i=last_day_ever-1;i>=0;--i){
		max_since[i] = max(max_since[i+1], max_since[i]);
	}
	int ans=-1;
	for (int i=0;i<n;++i){
		if(max_since[t[i]+1]>0){
			ans = max(ans, t[i]-s[i]+max_since[t[i]+1]);
		}
	}
	cout<<ans<<"\n";
	// cout<<N<<"\n";
	return 0;
}
