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

double a[10001];

double po(double a,ll b){
	if(b==0) return 1.0;
	if(b==1) return a;
	if(b%2==0){
		double x=po(a,b/2);
		return x*x;
	}
	else{
		double x=po(a,b/2);
		return x*x*a;
	}
}

double sub(double l,double r,double x,ll d){
	double mid=(l+r)/2;
	if(r-l<1e-11) return mid;
	if(po(mid,d)==x)
		return mid;
	else if(po(mid,d)<x)
		return sub(mid,r,x,d);
	else return sub(l,mid,x,d);
}

int main(){
	fastscan	
	cout << fixed << setprecision(20);
	int t;
	cin>>t;
	F2(xx,1,t){
		ll n,m;
		cin>>n>>m;
		F1(i,0,n) cin>>a[i];
		cout<<"Case #"<<xx<<":\n";
		F1(i,0,m){
			double l,r,ans=1.0;
			cin>>l>>r;
			F2(i,l,r){
				ans=ans*sub(0,1e10,a[i],r-l+1);
			}	
			cout<<ans<<"\n";
		}

	}
	return 0;
}
