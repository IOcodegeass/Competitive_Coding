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
int mat[2101][2101];
string a,b;

int comp(int i,int j){
	if(i==0 && j==0) return 0;
	if(i==0 && j>0) return j;
	if(i>0 && j==0) return i;
	if(mat[i][j]!=-1) return mat[i][j];
	if(a[i]==b[j]){
		mat[i][j]=miN(1+comp(i-1,j),miN(1+comp(i,j-1),comp(i-1,j-1)));
	}
	else{
		mat[i][j]=miN(1+comp(i-1,j),miN(1+comp(i,j-1),1+comp(i-1,j-1)));
	}
	return mat[i][j];
}

int main(){
	fastscan	
	int t;
	cin>>t;
	while(t--){
		cin>>a>>b;
		a=" "+a;
		b=" "+b;
		for(int i=0;i<=a.size();i++){
			for(int j=0;j<=b.size();j++){
				mat[i][j]=-1;
			}
		}
		cout<<comp(a.size(),b.size())<<"\n";
	}
	return 0;
}