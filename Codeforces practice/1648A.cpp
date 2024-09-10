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
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> grid( n , vector<ll> (m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<ll>> xv(1e5+1);
    vector<vector<ll>> yv(1e5+1);

    ll ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            xv[grid[i][j]].push_back(i);
            yv[grid[i][j]].push_back(j);
        }
    }

    for(auto x: xv){
        if(x.empty()) continue;
        sort(x.begin(), x.end());
        int sz = x.size();
        int num =-sz+1;
        for(int i=0;i<sz;i++){
            ans+=num * x[i];
            num+=2;
        }
    }

    for(auto x: yv){
        if(x.empty()) continue;
        sort(x.begin(), x.end());
        int sz = x.size();
        int num =-sz+1;
        for(int i=0;i<sz;i++){
            ans+=num * x[i];
            num+=2;
        }
    }

    cout<<ans<<"\n";

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

 
        solve();    
    
    return 0;
}