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

vector< vector< pair< int, vector<ll> >  > > G;
int main(){
	fastscan	
	int t;
	cin>>t;
	F2(xx,1,t){
		int n,m,k;
		cin>>n>>m>>k;
		for(int i=0;i<n;i++){
			vector< pair< int , vector<ll> > > vp;
			G.pb(vp);
		}
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			a--;b--;
			vector<ll> v;
			F1(j,0,24){
				ll x;cin>>x;v.pb(x);
			}
			G[a].pb(mp(b,v));
			G[b].pb(mp(a,v));
		}
		ll g[24][n];
		F1(i,0,24){
			F1(j,0,n) g[i][j]=1e15;
		}
		F1(k,0,24){
			ll d[n];
			bool v[n];
			set< pair<ll,int> > Q;
			for(int i=0;i<n;i++){
				d[i]=1e15;
				v[i]=false;
				Q.insert(mp(d[i],i));
			}
			int st=0;
			Q.erase(mp(d[st],st));
			d[st]=0;
			Q.insert(mp(d[st],st));
			while(!Q.empty()){
				pair<int,int> p = *(Q.begin());
				v[p.se]=true;
				g[k][p.se]=d[p.se];
				Q.erase(Q.begin());
				auto it=G[p.se].begin();
				for(;it!=G[p.se].end();it++){
					if((!v[it->fi]) && (d[it->fi] > d[p.se] + it->se[(d[p.se]+k)%24])){
						Q.erase(mp(d[it->fi],it->fi));
						d[it->fi] = d[p.se] + it->se[(d[p.se]+k)%24];
						Q.insert(mp(d[it->fi],it->fi));
					}
				}
			}
		}
		cout<<"Case #"<<xx<<": ";
		F1(i,0,k){
			int a,b;
			cin>>a>>b;
			a--;
			if(g[b][a]!=1e15) cout<<g[b][a]<<" ";
			else cout<<"-1 ";
		}
		cout<<"\n";
		G.clear();
	}
	return 0;
}
