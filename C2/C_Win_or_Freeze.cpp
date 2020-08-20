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
#define vi vector<int>
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

const int max_n = 1e5 + 9;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
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
	ll n , idx;
    cin >> n;

    idx = n;
    map<ll , ll> m;
    vector<ll> primes;
    for(ll i = 2 ; i*i <= n ; i++){
        if(n % i == 0){
            int cnt = 0;
            while(n%i == 0){
                n /= i;
                cnt++;
            }
            primes.pb(i);
            m[i] = cnt;
        }
    }
    if(n > 1){
        m[n] = 1;
        primes.pb(n);
    }
    // cout << primes.size() << "\n";
    for(auto it : m){
        if(it.ss >= 2 && idx != (it.ff * it.ff)){
            cout << 1 << "\n" << (it.ff * it.ff) << "\n";
            return;
        }
    }
    if(primes.size() > 2){
        cout << 1 << "\n" << primes[0] * primes[1] << "\n";
        return;
    }
    if(primes.size() == 0 || (primes.size() == 1 && m[primes[0]] == 1)){
        cout << "1\n0\n";
        return;
    }

    cout << 2 << "\n";
}
signed main(){
	int t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
}