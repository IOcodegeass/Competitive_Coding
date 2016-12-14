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

int main(){
	fastscan	
	ll t;
	scanf("%lld",&t);
	while(t--){
		ll n,sum=0;
		scanf("%lld",&n);
		vector<ll> v1(n);
		vector<ll> v2(n);
		bool b=false;
		for(int i=0;i<n;i++){
			scanf("%lld",&v1[i]);
			sum+=v1[i];
			v2[i]=sum;
			if(sum<0)sum=0;
			if(v1[i]>=0)b=true;
		}
		ll maxi=LONG_MIN,curi=0,cnt=0,mult=1,sub=0,t1=0,t2=0;
		if(b){
			for(int i=0;i<n;i++){
				if(curi+v1[i]<0){
					curi=0;
				}
				else{
					curi=curi+v1[i];
					maxi=maX(maxi,curi);
				}
			}
			for(int i=0;i<n;i++){
				if(v2[i]<0){
					cnt+=t1*mult-sub;
					mult=1,sub=0,t1=0,t2=0;
				}
				else{
					if(v2[i]==maxi){
						t2++;
						t1++;
					}
					if(v2[i]==0){
						mult++;
						sub+=t2;
					}
				}
			}
			cnt+=t1*mult-sub;
			printf("%lld %lld\n",maxi,cnt);
		}
		else{
			maxi=v1[0];
			for(int i=0;i<n;i++){
				maxi=maX(maxi,v1[0]);
			}
			for(int i=0;i<n;i++){
				if(maxi==v1[i]) cnt++;
			}
			printf("%lld %lld\n",maxi,cnt);
		}
	}
	return 0;
}