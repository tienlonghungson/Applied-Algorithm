#include <iostream>

using namespace std;

const int N = 1e3+1;
int n,K1,K2;
int rest[N];// rest at day i

int main(int argc, char** argv) {
	cin>>n>>K1>>K2;
	
	rest[0]=1;
	rest[1]=1;
	int first_low_term_work, first_upper_term_work,j;
	for (int i=2;i<=n+1;++i){
		first_low_term_work = max(1, i-K2);
		first_upper_term_work = i-K1;
		rest[i]=0;
		for (j=first_low_term_work;j<=first_upper_term_work;++j){
			rest[i]+=rest[j-1];
		}
		// cout<<"rest["<<i<<"] "<<rest[i]<<"\n";
	}	
	cout<<rest[n]+rest[n+1]<<"\n";
	return 0;
}
