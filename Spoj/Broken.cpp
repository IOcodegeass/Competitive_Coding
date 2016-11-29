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
	int m;
	while(cin>>m){
		if(m==0) return 0;
		string a;
		getline(cin,a);
		getline(cin,a);
		int curr=0,max=0,i=0,j=0,cnt=0;
		int v[500];
		for(i=0;i<500;i++) v[i]=0;
		for(i=0;i<a.size();i++){
			if(i>0){
				v[a[i-1]]--;
				if(v[a[i-1]]==0) cnt--;
			}
			while(cnt<=m && j<a.size()){
				if(v[a[j]]==0) cnt++;
				v[a[j]]++;
				if(cnt>m){
					cnt--;
					v[a[j]]--;
					break;;
				}
				max=maX(max,j-i+1);
				j++;
			}
		}
		cout<<max<<"\n";
	}
	return 0;
}

