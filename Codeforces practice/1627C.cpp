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
vector<int> states = {2,3};
int ind;




void dfs(int node,vector<vector<int>> &adj, vector<bool> &vis ,map<pair<int,int>,int> &mp ,vector<int> &ans){
    vis[node]= true;
    for(auto x: adj[node]){
        if(!vis[x]){
            ans[mp[{node,x}]] = states[ind];
            ind= (ind+1)%2;
            dfs(x,adj,vis,mp,ans);
        }
    }
}
void solve(){
    ll n;
    cin>>n;
    ind=0;
    vector<vector<int>> adj(n+1);
    vector<bool> visited(n+1,false);
    map<pair<int,int>,int> mp;
    vector<int> ans(n+1,0);
    
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        mp[{u,v}] = i+1;
        mp[{v,u}] = i+1;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    for(int i=1;i<=n;i++){
        if(adj[i].size()>=3){
            cout<<-1<<"\n";
            return;
        }
    }
    for(int i=1;i<=n;i++){
        if(adj[i].size()==1){
            dfs(i,adj,visited,mp,ans);
            break;
        }
    }

    for(int i=1;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";

}
// if any vertex has 3 or more edges then impossible
//else assign primes alternating with 2;
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