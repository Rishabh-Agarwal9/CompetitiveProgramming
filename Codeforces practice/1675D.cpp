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
void dfs(int node, vector<vector<ll>> &adj, vector<ll> & v,vector<vector<ll>> &ans){
    v.push_back(node);

    for(auto x: adj[node]){
        dfs(x,adj,v,ans);
    }
    if(adj[node].size()==0){
        ans.push_back(v);
    }

    v.pop_back();
}
void solve(){
    ll n;
    cin>>n;
    vector<ll> par(n);
    for(int i=0;i<n;i++){
        cin>>par[i];
        par[i]--;
    }

    vector<vector<ll>> adj(n);
    vector<vector<ll>> ans;

    int root =-1;
    for(int i=0;i<n;i++){
        if(par[i]==i){
            root =i;
            continue;
        }
        adj[par[i]].push_back(i);
    }
    vector<ll> v;
    dfs(root, adj, v, ans);

    cout<<ans.size()<<"\n";
    set<ll> st;
    for(auto x: ans){
        vector<ll> temp;
        for(auto y:x){
            if(st.find(y)==st.end()){
                st.insert(y);
                temp.push_back(y);
            }
        }   
        cout<<temp.size()<<"\n";
        for(auto x: temp){
            cout<<x+1<<" ";
        }
        cout<<"\n";
    }


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