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
vector<ll> fact(51);
ll comb(ll i , ll j){
    if(i < j)return 0;
    return fact[i] / (fact[j] * fact[i - j]);
}
void solve(){
	ll n;
    cin >> n;
    vi a(n);
    for(ll i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    /*
        E(v1 + v2 .. vn) = E(v1) + E(v2) + ... E(vn)
    */

   sort(all(a));

   double sum = 0;

    double p[n][n+1];
    for(ll i = 0 ; i < n ; i++){
        for(ll j = 0 ; j <= n ; j++){
            p[i][j] = 0;
        }
    }

    p[0][1] = 0;
    for(ll i = 0 ; i < n ; i++){
        for(ll j = 1; j <= i + 1 ; j++){
            for(ll k = 0 ; k < n ; k++){
                auto it1 = upper_bound(all(a) , a[k]) - a.begin();
                ll greater = n - it1;
                ll lesser = k;

                if(j == i+1){
                    p[i][j] += comb(lesser , i) * fact[i] * fact[n - i - 1];
                }
                else{
                    p[i][j] += comb(lesser , j - 1) * greater * fact[j-1] * fact[n - j - 1];
                }
            }
        }
    }

    for(ll i = 0 ; i < n ; i++){
        double e_val = 0;
        for(ll j = 1 ; j <= i+1 ; j++){
            // cout << p[i][j] << " ";
            e_val += j * p[i][j];
        }
        // cout << "\n";
        sum += e_val;
    }

    printf("%.2lf\n" , sum / fact[n]);
}
signed main(){
    fact[0] = 1;
    for(ll i = 1 ; i <= 50 ; i++){
        fact[i] = fact[i-1] * i;
    }
	ll t = 1;
	cin >> t;
	while(t--){
		solve();
	}
}