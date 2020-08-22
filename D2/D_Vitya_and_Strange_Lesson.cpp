
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define vi vector<ll>
#define vll vector<ll> 
#define all(x) (x).begin() , (x).end()
#define inf 1000000000
#define mod 1000000007

void dbg(){
	cerr << endl;
}
template<typename Head , typename... Tail>
void dbg(Head h , Tail... t){
	cerr << h << " ";
	dbg(t...);
}

#ifdef EMBI_DEBUG
#define debug(...) cerr << "(" << #__VA_ARGS__  << "): ", dbg(__VA_ARGS__)
#else 
#define debug(...)
#endif

const ll max_n = 1e5 + 9;

typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
ll power(ll a , ll b)
{
    ll prod = 1;
    while(b)
    {
        if(b&1)
        prod = (prod*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return prod;
}
struct TRIE{
	map<ll , TRIE*> edge;
};
ll n, m;
TRIE* insert(TRIE* root , ll num){
	TRIE* curr = root;
	for(ll i = 30 ; i >= 0 ; i--){
		ll rem = ((num & (1 << i)) ? 1 : 0);
		if(curr->edge[rem] == NULL)curr->edge[rem] = new TRIE();
		curr = curr->edge[rem];
	}
	
	return root;
}

ll mex(TRIE* root , ll x){
	ll mex = n , num = 0;
	TRIE* curr = root;
	for(ll i = 30 ; i >= 0 ; i--){
		if(curr->edge[0] && curr->edge[1]){
			if(x & (1 << i))curr = curr->edge[1];
			else curr = curr->edge[0];
		}
		else{
			if(curr->edge[0]){
				mex = min(mex , num);
				return mex;
			}
			else{
				num += (1 << i);
				mex = min(mex , num);
				return mex;
			}
		}
	}
	return mex;
}
void solve(){
	TRIE* root = new TRIE();
	cin >> n >> m;
	set<ll> s;
	for(ll i = 0 ; i < n ; i++){
		ll x;
		cin >> x;
		root = insert(root , x);
		s.insert(x);
	}
	
	vector<ll> q(m);
	for(ll i = 0 ; i < m ; i++){
		cin >> q[i];
	}
	
	for(ll i = 1 ; i < m ; i++){
		q[i] ^= q[i-1];
	}
	
	map<ll , ll> ma;
	for(auto it : q){
		if(!s.count(it)){
			cout << 0 << "\n";
			ma[it] = 0;
		}
		else{
			if(ma.find(it) == ma.end()){
				ma[it] = mex(root , it);
				cout << ma[it] << "\n";
			}
			else cout << ma[it] << "\n";
		}
	}
}
signed main(){
	ll t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
}