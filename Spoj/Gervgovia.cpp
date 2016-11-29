#include<bits/stdc++.h>
using namespace std;
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define mp make_pair // useful for working with pairs
#define fi first
#define se second
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi > vvi;
typedef pair<int,int> ii;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define present(c,x) ((c).find(x) != (c).end())
#define ll long long int
#define fastscan ios_base::sync_with_stdio(0);cin.tie(NULL); 
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b);}

int main(){
	fastscan	
	int n;
	while(cin>>n){
		ll ans=0;
		if(n==0)return 0;
		vector<ll> v(n);
		for(int i=0;i<n;i++)cin>>v[i];
		int i=0,j=0;
		while(i<n && j<n){
			if(v[i]<=0){
				i++;
			}
			if(v[j]>=0){
				j++;
			}
			if(v[i]>0 && v[j]<0){
				ll t1=v[i];
				ll t2=-v[j];
				ans+=abs(j-i)*miN(t1,t2);
				v[i]-=miN(t1,t2);
				v[j]+=miN(t1,t2);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}