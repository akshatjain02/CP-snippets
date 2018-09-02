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




// Variables, that hold current "state" of computation
long long current_answer=0;
long long cnt[SIZE] = {0};         //may have to use a map if constraints allow bigger and -ve values




int n, q;
ll arr[SIZE], answers[SIZE];
int blk_size;
pair<pair<int,int>, int> queries[SIZE];




bool mo_compare(pair<pair<int,int>, int> x, pair<pair<int,int>, int> y)
{
    int block_x = x.first.first/blk_size;
    int block_y = y.first.first/blk_size;
    
    if(block_x!=block_y)return block_x < block_y;
    
    return (block_x & 1) ? (x.first.second < y.first.second) : (x.first.second > y.first.second);
}




void add_ind(int i)             //nullify current effect on answer and add its new effect
{
    cnt[i]++;
    current_answer += (cnt[i]==1);          //CHANGES ACCORDING TO QUERY
}




void remove_ind(int i)
{
    cnt[i]--;
    current_answer -= (cnt[i])?0:1;
}




void solve()
{
	cin>>n;
	
	rep(i,0,n)cnt[i] = 0;       //may change if map is used
	current_answer=0;
	
	blk_size = (int)sqrt(n);
	
	rep(i,0,n)cin>>arr[i];
	
	cin>>q;
	rep(i,0,q)
	{
	    cin>>queries[i].first.first>>queries[i].first.second;
	    queries[i].first.first--;queries[i].first.second--;     //may not neccessary
	    queries[i].second = i;
	}
	
	sort(queries, queries + q, mo_compare);
	
	int mo_left = 0, mo_right = -1;
	
	rep(i,0,q)
	{
	    int left = queries[i].first.first;
	    int right = queries[i].first.second;
	    
	    while(mo_right < right)
	    {
	        mo_right++;
	        add_ind(arr[mo_right]);
	    }
	    
	    while(mo_right > right)
	    {
            remove_ind(arr[mo_right]);
            mo_right--;
        }

        while(mo_left < left)
        {
            remove_ind(arr[mo_left]);
            mo_left++;
        }
        while(mo_left > left)
        {
            mo_left--;
            add_ind(arr[mo_left]);
        }
	    
	    answers[queries[i].second] = current_answer;
	}
	
	rep(i,0,q)cout<<answers[i]<<endl;
	
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