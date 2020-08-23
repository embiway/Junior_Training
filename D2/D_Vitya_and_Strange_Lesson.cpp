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
struct TRIE{
    map<int , TRIE*> edge;
};

map<TRIE* , int> subtree;
int n , m;
TRIE* insert(TRIE* root , int num){
    TRIE* curr = root;
    for(int i = 2 ; i >= 0 ; i--){
        int rem = ((num & (1 << i)) ? 1 : 0);
        if(!curr->edge[rem])curr->edge[rem] = new TRIE();
        curr = curr->edge[rem];
    }
    return root;
}

void build(TRIE* root){
    if(root == NULL)return;
    build(root->edge[0]);
    build(root->edge[1]);

    subtree[root] = 1 + subtree[root->edge[0]] + subtree[root->edge[1]];
}

int mex(TRIE* root , int x){
    int min1 = n , num = 0;
    TRIE* curr = root;
    for(int i = 2 ; i > 0 ; i--){
        debug(num);
        if(x & (1 << i)){
            if(curr->edge[0] && curr->edge[1]){
                if(subtree[curr->edge[1]] < power(2 , i)){
                    curr = curr->edge[1];
                }
                else {
                    curr = curr->edge[0];
                    num += (1 << (i-1));
                }
            }
            else if(curr->edge[0]){
                if(subtree[curr->edge[0]] < power(2 , i) - 1){    
                    curr = curr->edge[0];
                    num += (1 << (i-1));
                }
                else{
                    return num;
                }
            }
            else {
                if(subtree[curr->edge[1]] < power(2 , i) - 1)
                curr = curr->edge[1];
                else {
                    num += (1 << (i-1));
                    return num;
                }
            }
        }
        else{
            
            if(curr->edge[0] && curr->edge[1]){
                if(subtree[curr->edge[0]] < power(2 , i) - 1){
                    curr = curr->edge[0];
                }
                else {
                    curr = curr->edge[1];
                    num += (1 << (i-1));
                }
            }
            else if(curr->edge[1]){
                if(subtree[curr->edge[1]] < power(2 , i) - 1){    
                    curr = curr->edge[1];
                    num += (1 << (i-1));
                }
                else{
                    return num;
                }
            }
            else {
                assert(curr->edge[0]);
                if(subtree[curr->edge[0]] < power(2 , i) - 1)
                    curr = curr->edge[0];
                else {
                    num += (1 << (i-1));
                    debug(i , "hello");
                    return num;
                }
            }
        }
    }

    return num;
}

void solve(){
	cin >> n >> m;
    int a[n];
    TRIE* root = new TRIE();
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        root = insert(root , a[i]);
    }
    build(root);
    vector<int> q(m);
    for(int i = 0 ; i < m ; i++){
        cin >> q[i];
    }

    for(int i = 1 ; i < m ; i++){
        q[i] ^= q[i-1];
    }
    for(int i = 0 ; i < m ; i++){
        cout << mex(root , q[i]) << "\n";
    }
}
signed main(){
	int t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
}