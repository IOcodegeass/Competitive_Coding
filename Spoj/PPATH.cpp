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
#define inf 1000000
#define fastscan ios_base::sync_with_stdio(0);cin.tie(NULL); 
#define F1(x,y,z) for(int x=y;x<z;x++)
#define F2(x,y,z) for(int x=y;x<=z;x++)
#define F3(x,y,z) for(int x=y;x>z;x--)
#define F4(x,y,z) for(int x=y;x>=z;x--)
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b);}

void sieve(bool A[], int n){
	for(int i=0;i<n;i++) A[i]=true;
	for(int i=2;i<n;i++){
		if(A[i]){
			for(int j=2;i*j<n;j++){
				A[i*j]=false;
			}
		}
	}
}

int main(){
	fastscan	
	bool A[100000];
	sieve(A,100000);
	int t;
	cin>>t;
	while(t--){
		int start,end,minDistance=inf;
		cin>>start>>end;
		bool visited[100000];
		for(int i=0;i<100000;i++) visited[i]=false;
		queue< pair<int,int> > q;
		q.push(mp(start,0));
		visited[start]=true;
		while(q.size()!=0){
			pair<int,int> top = q.front();
			q.pop();
			if(top.fi==end){
				minDistance = top.se;
				break;
			}
			if(top.fi*10<10000) continue;	// Cannot explore these word as they must have leading zero's
			int tmp=top.fi,mult=1;
			while(tmp!=0){
				for(int i=9;i>=0;i--){
					int num;
					if((tmp%10)-i>=0){
						num=top.fi-i*mult;
						if(!visited[num]&&A[num]){
							q.push(mp(num,top.se+1));
							visited[num]=true;
						}
					}
					if((tmp%10)+i<=9){
						num=top.fi+i*mult;
						if(!visited[num]&&A[num]){
							q.push(mp(num,top.se+1));
							visited[num]=true;
						}
					}
				}
				mult*=10;
				tmp/=10;
			}
		}
		if(minDistance==inf) cout<<"Impossible\n";
		else cout<<minDistance<<"\n";
	}
	return 0;
}
