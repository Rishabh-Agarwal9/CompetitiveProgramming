#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
typedef set<string> ss;
typedef vector<int> vi;
typedef map<int, char> msi;
typedef pair<int, int> pa;
typedef long long int ll;

ll gcd (ll a, ll b) {
    return b ? gcd (b, a % b) : a;
}
//mmi
ll inv(ll a) {
  return a <= 1 ? a : mod - (ll)(mod/a) * inv(mod % a) % mod;
}

//make a fact vect filled to maxN you want to query.
long long binomial_coefficient(ll n, ll k, vector<ll> &fact) {
    if(k>n) return 0;
    return fact[n] * inv(fact[k] * fact[n - k] % mod) % mod;
}

void print(vi &a){
    for(auto x : a){
        cout << x << " ";
    }
    cout << "\n";
}
int n;
vector<ll> a;
vector<ll> b;
vector<ll> c;
bool dfs(int node,vector<vector<int>> &adj ,vector<bool> &vis, set<int> &st){
    vis[node] = true;
    bool ans = true;
    if(st.find(node)!=st.end()) ans = false;
    for(auto x: adj[node]){
        if(!vis[x]){
            if(!dfs(x,adj,vis,st)) ans = false;
        }
    }
    return ans;
}
void solve(){
    ll n;
    cin>>n;
    a.resize(n);
    b.resize(n);
    c.resize(n);
    vector<vector<int>> adj(n+1);
    vector<bool> vis(n+1, false);
    set<int> st;
    for(int i =0;i<n;i++){
        cin>>a[i];
    }
    for(int i =0;i<n;i++){
        cin>>b[i];
    }
    for(int i =0;i<n;i++){
        cin>>c[i];
        st.insert(c[i]);
    }

    for(int i=0;i<n;i++){
        if(a[i]==b[i]){
            vis[a[i]]=true;
        }
        else{
            adj[a[i]].push_back(b[i]);
        }
    }
    ll ans =1;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(dfs(i,adj,vis,st)){
                ans = ans* 2;
                ans = ans % mod;
            }
        }
    }
    cout<<ans<<"\n";

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin >> cases;
    while (cases--){
        solve();    
    }
    return 0;
}