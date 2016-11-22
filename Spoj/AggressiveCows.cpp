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
#define ll long long
#define fastscan ios_base::sync_with_stdio(0);cin.tie(NULL); 
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b);}

vector<ll> v;
ll n,c;

bool check(ll diff){
	ll cnt=0,sum=0;
	for(int i=1;i<n;i++){
		sum+=v[i]-v[i-1];
		if(sum>=diff){
			cnt++;sum=0;
		}
	}
	return (cnt+1>=c);
}

ll binSearch(ll l,ll r){
	if(r-l<=1){
		if(check(r)) return r;
		if(check(l)) return l;
		return -1;
	}
	else{
		ll m=(l+r)/2;
		if(check(m)) return binSearch(m,r);
		else return binSearch(l,m-1);
	}
}

int main(){
	fastscan	
	ll t;
	cin>>t;
	while(t--){
		v.clear();
		cin>>n>>c;
		for(int i=0;i<n;i++){
			ll x;cin>>x;v.pb(x);
		}
		sort(v.begin(),v.end());
		cout<<binSearch(0,1e10)<<"\n";
	}
	return 0;
}