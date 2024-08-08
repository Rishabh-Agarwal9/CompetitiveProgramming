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
    ll n;
    cin>>n;
    vi vect(n);
    for(int i=0;i<n;i++){
        cin>>vect[i];
    }
    map<vector<int> ,int> mp;



    ll ans=0;
    for(int i =0;i<n-2;i++){
        int x=vect[i];
        int y=vect[i+1];
        int z=vect[i+2];
        ans+=-3*mp[{x,y,z}]+mp[{0,y,z}]+mp[{x,0,z}]+mp[{x,y,0}];

        mp[{x,y,z}]++;
        mp[{0,y,z}]++;
        mp[{x,0,z}]++;
        mp[{x,y,0}]++;

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