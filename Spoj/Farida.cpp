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
ll m1[100000],m2[100000];

ll compute(int i){
	if(i==0){
		m1[i]=m2[i];
		return m1[i];
	}
	if(i<0) return 0;
	if(m1[i]!=-1)return m1[i];
	m1[i]=maX(compute(i-1),m2[i]+compute(i-2));
	return m1[i];
}

int main(){
	fastscan	
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		ll n,maxi=0;
		cin>>n;
		for(int i=0;i<n;i++){
			m1[i]=-1;
			cin>>m2[i];
		}
		for(int i=0;i<n;i++){
			maxi=maX(maxi,compute(i));	
		}
		cout<<"Case "<<i<<": "<<maxi<<"\n";
	}
	return 0;
}