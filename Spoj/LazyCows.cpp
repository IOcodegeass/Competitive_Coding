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
#define inf 1000000000000000
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b);}

int main(){
	fastscan	
	ll t;
	cin>>t;
	while(t--){
		ll n,k,b;
		cin>>n>>k>>b;
		ll c[b];
		F2(i,1,b) c[i]=0;
		for(int i=0;i<n;i++){
			ll a,b; cin>>a>>b;
			if(c[b]==0) c[b]=a;
			else c[b]=3;
		}
		if(k>=n){
			cout<<k<<"\n";
			continue;
		}
		ll curr[k+1][4], prev[k+1][4];
		for(int i=0;i<k+1;i++){
			for(int j=0;j<4;j++){
				prev[i][j]=inf;
				curr[i][j]=inf;
			}

		}
		prev[0][0]=0;
		for(int g=1;g<=b;g++){
			curr[0][0]=c[g]==0?prev[0][0]:inf;
			for(int j=1;j<k+1;j++){
				int no;
				if(c[g]==0) no=0;
				else if(c[g]==1||c[g]==2) no=1;
				else no=2;
				if(no==0){
					curr[j][0]=miN(prev[j][0],miN(prev[j][1],miN(prev[j][2],prev[j][3])));
					curr[j][1]=miN(prev[j-1][0],miN(prev[j-1][3],miN(miN(prev[j-1][1],prev[j][1]),prev[j-1][2])))+1;
					curr[j][2]=miN(prev[j-1][0],miN(prev[j-1][3],miN(miN(prev[j-1][2],prev[j][2]),prev[j-1][1])))+1;
					curr[j][3]=miN(prev[j-1][0],miN(prev[j-1][1],miN(prev[j-1][2],miN(prev[j-1][3],prev[j][3]))))+2;
				}
				else if(no==1){
					curr[j][c[g]]=miN(prev[j-1][0],miN(prev[j-1][3],miN(miN(prev[j-1][c[g]],prev[j][c[g]]),prev[j-1][3-c[g]])));
					curr[j][3]=miN(prev[j-1][0],miN(prev[j-1][1],miN(prev[j-1][2],miN(prev[j-1][3],prev[j][3]))))+1;
				}
				else{
					curr[j][3]=miN(prev[j-1][0],miN(prev[j-1][1],miN(prev[j-1][2],miN(prev[j-1][3],prev[j][3]))));
				}
			}
			for(int i=0;i<k+1;i++){
				for(int j=0;j<4;j++){
					prev[i][j]=curr[i][j];
					curr[i][j]=inf;
				}
			}
		}
		cout<<n+miN(prev[k][0],miN(prev[k][1],miN(prev[k][2],prev[k][3])))<<"\n";
	}
	return 0;
}
