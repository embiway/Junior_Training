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
void solve(){
	ll n , x;
    cin >> n >> x;
    ll a[n];
    for(ll i = 0 ; i < n ; i++){
        cin >> a[i];
    }

    x--;
    ll index = 0 , min1 = a[0];
    for(ll i = 0 ; i < n ; i++){
        if(min1 > a[i]){
            min1 = a[i];
            index = i;
        }
    }
    
    if(a[x] == min1){
        index = x;
    }

    vector<ll> req(n , min1);
    if(index != x){
        for(ll i = (index + 1) % n ; i != x ; i = (i + 1) % n){
            req[i]++;
        }
        req[x]++;
    }
    
    ll sum = 0;
    for(ll i = 0 ; i < n ; i++){
        a[i] -= req[i];
        // cout << req[i] << " ";
        sum += req[i];
    }

    // cout << index <<"\n";
    a[index] = sum;

    for(ll i = 0 ; i < n ; i++){
        cout << a[i] << " ";
    }
}
signed main(){
	ll t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
}