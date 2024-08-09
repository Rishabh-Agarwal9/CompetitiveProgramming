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
    ll x,y,z,k;
    cin>>x>>y>>z>>k;
    //prime factorize k
    // every side of s should  be smaller than every side of b
    //most number of factors k can have is 33
    ll temp = k;
    vector<ll> pf={1};
    ll ans=0;
    for(ll a=1;a<=x;a++){
        for(ll b=1;b<=y;b++){
            if(k%(a*b)!=0) continue;
            ll c = k/(a*b);
            ans= max(ans, (x-a+1) * (y-b+1) * (z-c+1));
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