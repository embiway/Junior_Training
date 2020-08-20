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
	ll n , k , d1 , d2;
    cin >> n >> k >> d1 >> d2;


    if(n % 3 != 0){
        cout << "no\n";
        return;
    }
    if((k - 2*d1 + d2) >= 0 && (k - 2*d1 + d2) % 3 == 0){
        int num = (k - 2*d1 + d2) / 3;
        if(max(num + d1 , num + d1 - d2) <= n/3){
            cout << "yes\n";
            return;
        }
    }
    if((k - 2*d1 - d2) >= 0 && (k - 2*d1 - d2) % 3 == 0){
        int num = (k - 2*d1 - d2) / 3;
        if(max(num + d1 , num + d1 + d2) <= n/3){
            cout << "yes\n";
            return;
        }
    }
    if((k - d1 + d2) >= 0 && (k - d1 + d2) % 3 == 0){
        int num = (k - d1 + d2) / 3;
        if(max(num + d1 , num - d2) <= n/3){
            cout << "yes\n";
            return;
        }
    }
    if((k - d1 - d2) >= 0 && (k - d1 - d2) % 3 == 0){
        int num = (k - d1 - d2) / 3;
        if(max(num + d1 , num + d2) <= n/3){
            cout << "yes\n";
            return;
        }
    }
    
    cout << "no\n";
}
signed main(){
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
}