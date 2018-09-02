#include <bits/stdc++.h>
 
#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define lol         1000000007
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
#define SIZE        1000005
#define debug(x)    cerr << #x << " = " << x << endl;

using namespace std;

void MOD(ll &x)
{
	if (x >= lol) x -= lol;
	if (x < 0) x += lol;
}

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }


int lps[SIZE];


void preprocess(string pat)
{
	int sz = pat.size();
	lps[0] = 0;
	int len = 0;
	rep(i,1,sz)
	{
		while(len>=0 && pat[i]!=pat[len])
		{
			if(len>=1) len = lps[len-1];
			else len = -1;
		}
		len++;
		lps[i] = len;
	}
}


int kmpmatch(string pat, string str)	//can return all occurences, first occurence and number of occurences
{
	int psz = pat.size();
	int sz = str.size();
	int num=0;
	int j=0;
	rep(i,0,sz)
	{
		while(j>=0 && str[i]!=pat[j])
		{
			if(j>=1) j = lps[j-1];
			else j = -1;
		}
		j++;
		if(j==psz)
		{
			j = lps[j-1];
			cout<<"Found at ["<<i-psz+1<<", "<<i<<"]"<<endl;
			num++;
		}
	}
	return num;
}


void solve()
{
	string str, pat;
	cin>>pat>>str;
	preprocess(pat);
	cout<<kmpmatch(pat, str);
	
	
	
}


// Remove  debugs!!

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	int t=1;
//	cin>>t;
	while(t--){
		//cout<<"Case #"<<i++<<": ";
		solve();
  	  	//cout<<endl;	
  	}
	return 0;
}