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
#define F1(x,y,z) for(int x=y;x<z;x++)
#define F2(x,y,z) for(int x=y;x<=z;x++)
#define F3(x,y,z) for(int x=y;x>z;x--)
#define F4(x,y,z) for(int x=y;x>=z;x--)
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b);}

int main(){
	fastscan	
	int t;
	cin>>t;
	F2(xx,1,t){
		ll n,m;
		cin>>n>>m;	
		vector< pair<ll, pair<ll,ll> > > v;
		ll G[n][n];
		F1(i,0,n){
			F1(j,0,n){
				if(i!=j) G[i][j]=1e17;
				else G[i][i]=0;
			}
		}
		F1(i,0,m){
			ll a,b,c;
			cin>>a>>b>>c;
			G[a][b]=miN(c,G[a][b]);
			G[b][a]=miN(c,G[b][a]);
			v.pb(mp(a,mp(b,c)));
		}
		F1(k,0,n){
			F1(i,0,n){
				F1(j,0,n){
					if(G[i][k]+G[k][j]<G[i][j]) G[i][j]=G[i][k]+G[k][j];
				}
			}
		}
		cout<<"Case #"<<xx<<": \n";
		F1(i,0,m){
			if(G[v[i].fi][v[i].se.fi]<v[i].se.se) cout<<i<<"\n";
		}
	}
	return 0;
}
