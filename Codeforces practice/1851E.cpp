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

void solve(){   
    ll n,k;
    cin>>n>>k;
    vector<ll> cost(n);
    vector<ll> unlim(k);
    vector<vector<ll>> mix(n);
    vector<vector<ll>> adj(n);
    vector<ll> ans(n , -1);

    for(int i=0;i<n;i++){
        cin>>cost[i];
    }

    for(int i=0;i<k;i++){
        cin>>unlim[i];
        unlim[i]--;
    }

    for(int i=0;i<n;i++){
        ll t;
        cin>>t;
        vector<ll> temp;
        for(int j=0;j<t;j++){
            ll x;
            cin>>x;
            x--;
            temp.push_back(x);
            adj[x].push_back(i);
        }
        mix[i]=temp;
        if(temp.size()==0){
            ans[i]=cost[i];
        }
    }
    
    for(auto x: unlim){
        ans[x]=0;
    }
    vector<ll> indeg(n,0);
    for(auto x:adj){
        for(auto y:x){
           indeg[y]++; 
        }
    }
    queue<ll> Q;
    for(int i=0;i<n;i++){
        if(indeg[i]==0){
            Q.push(i);
        }
    }

    while(!Q.empty()){
        ll node = Q.front();
        Q.pop();
        if(ans[node]==-1){
            ll sum =0;
            for(auto x: mix[node]){
                sum+=ans[x];
            }
            ans[node] = min(cost[node], sum);
        }

        for(auto nei : adj[node]){
            indeg[nei]--;
            if(indeg[nei]==0){
                Q.push(nei);
            }
        }
    }

    for(auto x: ans){
        cout<<x<<" ";
    }
    cout<<"\n";
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