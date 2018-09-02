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



int arr[SIZE];      //original array            //0-indexed
int block[1005];    //decomposed array          //0-indexed
int block_size;     //block size




void preprocess(int input[], int n)
{
    block_size = sqrt(n);    
    int block_ind = -1;    
    rep(i,0,n)
    {
        arr[i] = input[i];
        if(!(i%block_size))	block_ind++;        
        block[block_ind] += arr[i];     //CHANGES ACCORDING TO QUERY
    }    
}




void update(int ind, int val)
{
    int block_number = ind/block_size;
    block[block_number] += (val - arr[ind]);        //CHANGES ACCORDING TO QUERY
    arr[ind] = val;
}




ll query(int l, int r)
{
    ll sum = 0;        //CHANGES ACCORDING TO QUERY
    while(l<r && (l%block_size) && l!=0)
    {
        sum += arr[l];        //CHANGES ACCORDING TO QUERY
        l++;
    }
    while((l+block_size) <= r)
    {
        sum += block[l/block_size];        //CHANGES ACCORDING TO QUERY
        l += block_size;
    }    
    while(l<=r)
    {
        sum += arr[l];        //CHANGES ACCORDING TO QUERY
        l++;
    }
    return sum;
}




void solve()
{
	int n, m;
	cin>>n>>m;;
	int input[n];
	rep(i,0,n)
	{
	    cin>>input[i];
	}
	preprocess(input, n);
	rep(i,0,m)
	{
	    int type, x, y;
	    cin>>type>>x>>y;
	    if(type==1)
	    {
	        update(x,y);
	    }
	    else
	    {
	        cout<<query(x,y)<<endl;
	    }
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