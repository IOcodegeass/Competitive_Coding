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
bool visited[10005];
int n;
int cnt=0;
map<ii,int> m;
vector<ii> v;

void dfs(int i,int j){
	visited[m[mp(i,j)]]=true;
	auto it1=m.find(mp(i-1,j));auto it2=m.find(mp(i-1,j+1));auto it3=m.find(mp(i,j+1));auto it4=m.find(mp(i+1,j+1));auto it5=m.find(mp(i+1,j));auto it6=m.find(mp(i+1,j-1));auto it7=m.find(mp(i,j-1));auto it8=m.find(mp(i-1,j-1));
	if(it1!=m.end() && !visited[it1->se]) dfs(v[it1->se].fi,v[it1->se].se);
	if(it2!=m.end() && !visited[it2->se]) dfs(v[it2->se].fi,v[it2->se].se);
	if(it3!=m.end() && !visited[it3->se]) dfs(v[it3->se].fi,v[it3->se].se);
	if(it4!=m.end() && !visited[it4->se]) dfs(v[it4->se].fi,v[it4->se].se);
	if(it5!=m.end() && !visited[it5->se]) dfs(v[it5->se].fi,v[it5->se].se);
	if(it6!=m.end() && !visited[it6->se]) dfs(v[it6->se].fi,v[it6->se].se);
	if(it7!=m.end() && !visited[it7->se]) dfs(v[it7->se].fi,v[it7->se].se);
	if(it8!=m.end() && !visited[it8->se]) dfs(v[it8->se].fi,v[it8->se].se);
}

void DFSUtil(){
	for(int i=0;i<n;i++){
		if(!visited[i]){
			dfs(v[i].fi,v[i].se);cnt++;
		}
	}
}

int main(){
	fastscan	
	int t;
	cin>>t;
	for(int yy=1;yy<=t;yy++){
		cin>>n;
		cnt=0;									// clear count
		m.clear();								// clear previous map data
		v.clear();								// clear dependenies of vector data
		for(int i=0;i<n;i++){
			visited[i]=false;					// clear previous dependencies of node
			int a,b;
			cin>>a>>b;
			m[mp(a,b)]=i;						// (a,b) --> i
			v.pb(mp(a,b));						// i --> (a,b)
		}
		DFSUtil();
		cout<<"Case "<<yy<<": "<<cnt<<"\n";						// print result after exploring the cases
	}
	return 0;
}