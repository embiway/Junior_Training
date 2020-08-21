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
ll n;
vector<vector<pair<ll,ll>>> a;
map<ll , pair<pair<ll,ll> , ll>> edges;
map<pair<ll , ll> , ll> edge_rel;
map<ll , ll> edge_weight;
map<ll , pair<ll,ll>> comb_edge;

vector<ll> subtree_size;

void dfs(ll s , ll p = -1){
    for(auto it : a[s]){
        if(it.ff != p){
            dfs(it.ff , s);
            ll idx = edge_rel[{s , it.ff}];
            comb_edge[idx] = {subtree_size[it.ff] , n - subtree_size[it.ff]};
            subtree_size[s] += subtree_size[it.ff]; 
        }
    }
    subtree_size[s]++;
}
void solve(){
    cin >> n;
    a.resize(n+1);
    subtree_size.resize(n+1);
    for(ll i = 0 ; i < n-1 ; i++){
        ll x , y , w;
        cin >> x >> y >> w;
        a[x].pb({y , w});
        a[y].pb({x , w});

        edges[i] = {{x , y} , w};
        edge_rel[{x , y}] = i;
        edge_rel[{y , x}] = i;
        edge_weight[i] = w;
    }   

    // e(d(c1 , c2) + d(c2 , c3) + d(c3 , c1)) == 3 * e(d(c1 , c2)) due to generality
    /*
        to find e(d(c1 , c2)) = summation of (edge_weight * probability of it being in the path from c1 to c2) 
        for possible edges.

        e(d(c1 , c2)) = summation(wi * P(i));

        To find P(i) : for edge_i to be included c1 and c2 should belong to different components on removing the edge.
        Could be done using dfs.
    */

    dfs(1);

    double e_val = 0.0;
    for(ll i = 0 ; i < n-1 ; i++){
        e_val += edge_weight[i] * (comb_edge[i].ff * comb_edge[i].ss);
    }

    double den = (1.0 * n * (n-1) ) / 2;
    ll q;
    cin >> q;
    while(q--){
        ll edge_idx , new_edge;
        cin >> edge_idx >> new_edge;
        ll i = edge_idx - 1;
        e_val += ((comb_edge[i].ff * comb_edge[i].ss) * (new_edge - edge_weight[i]));
        edge_weight[i] = new_edge;

        printf("%.11lf\n" , 3.00 * e_val / den);
    }
}
signed main(){
	ll t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
}