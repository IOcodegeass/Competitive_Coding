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
string a;
ll mat[2101][2101];

ll c(int i,int j){
	int x = a[i]=='{' ? 0 : 1;
	int y = a[j]=='}' ? 0 : 1;
	return x+y;
}

ll compute(int i,int j){
	if(i>j) return 0;
	if((j-i)%2==0) return INT_MAX;
	if(mat[i][j]!=-1) return mat[i][j];
	ll mini=INT_MAX;
	for(int p=i+1;p<=j;p++){
		mini=miN(mini,c(i,p)+compute(i+1,p-1)+compute(p+1,j));
	}
	mat[i][j]=mini;
	return mat[i][j];
}

int main(){
	fastscan	
	ll cnt=1;
	while(cin>>a){
		if(a[0]=='-') return 0;
		for(int i=0;i<a.size();i++){
			for(int j=0;j<a.size();j++){
				mat[i][j]=-1;
			}
		}
		cout<<cnt<<". "<<compute(0,a.size()-1)<<"\n";
		cnt++;
	}
	return 0;
}