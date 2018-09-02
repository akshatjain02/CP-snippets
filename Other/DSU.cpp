#include <bits/stdc++.h>
 
#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define lol        1000000007
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
#define SIZE        1000005
#define debug(x)        cerr << #x << " = " << x << endl;

using namespace std;

void MOD(ll &x)
{
	if (x >= lol) x -= lol;
	if (x < 0) x += lol;
}


int dsu[26];
int size[26];


int root(int v)
{
    if(v==dsu[v]) return v;
    return dsu[v]=root(dsu[v]);
}


void merge(int a, int b)
{
    a = root(a);
    b = root(b);
    if(a!=b)
    {
        if(size[a]<size[b]) swap(a,b);
        dsu[b] = a;
        size[a] += size[b];
    }
}


void solve()
{
    int n;
    cin>>n;
    string s1, s2;
    cin>>s1>>s2;
    int n1=26;
    rep(i,0,n1){dsu[i]=i;size[i]=1;}
    vector<pair<char,char>> ans;
    rep(i,0,n)
    {
        int a = s1[i] - 'a';
        int b = s2[i] - 'a';
        if(root(a)!=root(b))
        {
            ans.pb(mp((char)(97+a), (char)(97+b)));
            merge(a,b);
        }
    }
    cout<<ans.size()<<endl;
    rep(i,0,ans.size())
    {
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
	
	
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}