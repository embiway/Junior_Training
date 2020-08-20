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

double find_prob(int l , int r , int p){
    double total = (r - l + 1);

    int end = (r / p) * p;
    int start = (l / p) * p;
    if(start < l)start += p;

    double num = (end - start + p)/p;

    return num / total;
}
void solve(){
	int n , p;
    cin >> n >> p;

    vector<pair<int,int>> bounds(n);
    vector<double> prob(n);

    for(int i = 0 ; i < n ; i++){
        int x , y;
        cin >> x >> y;
        bounds[i] = {x , y};
    }

    for(int i = 0 ; i < n ; i++){
        prob[i] = find_prob(bounds[i].ff , bounds[i].ss , p);
    }

    double total_expec = 0.0;
    for(int i = 0 ; i < n ; i++){
        int left = (i - 1 + n) % n , right = (i + 1) % n;
        double prob_1 = prob[left] * (1 - prob[i]) * (1 - prob[right]) + (1 - prob[left]) * (1 - prob[i]) * prob[right];
        double prob_2 = prob[i] + (1 - prob[i]) * prob[left] * prob[right];

        total_expec += 1000 * prob_1 + 2000 * prob_2;
    }

    printf("%.11lf\n" , total_expec);
}
signed main(){
	int t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
}