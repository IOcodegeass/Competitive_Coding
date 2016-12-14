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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b);}

int main(){
	fastscan	
	int t;
	cin>>t;
	F2(xx,1,t){
		ll np,ne,nt;
		cin>>np>>ne>>nt;
		ll v1[np],v2[ne],v3[nt];
		F1(i,0,np) cin>>v1[i];
		F1(i,0,ne) cin>>v2[i];
		F1(i,0,nt) cin>>v3[i];
		set< pair<ll,ll> > s;
		F1(i,0,ne){
			F1(j,0,ne){
				if(i!=j){
					ll x=gcd(v2[i],v2[j]);
					s.insert(mp(v2[i]/x,v2[j]/x));
				}
			}
		}
		int m;
		cin>>m;
		cout<<"Case #"<<xx<<": \n";
		F1(xx,0,m){
			bool b=false;
			ll p,q;
			cin>>p>>q;
			F1(i,0,np){
				if(b) break;
				F1(j,0,nt){
					ll x=gcd(v1[i]*q,v3[j]*p);
					if(s.find(mp(v1[i]*q/x,v3[j]*p/x))!=s.end()){
						b=true;
						break;
					}
				}
			}
			if(b) cout<<"Yes\n";
			else cout<<"No\n";
		}
	}
	return 0;
}
