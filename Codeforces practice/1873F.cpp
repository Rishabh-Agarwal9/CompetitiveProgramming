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
ll n,k;
vector<ll> a;
vector<ll> h;


void solve(){
    cin>>n>>k;
    a.resize(n);
    h.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<n;i++){
        cin>>h[i];
    }

    vector<ll> div(n,1);
    vector<ll> pre(n,0);
    pre[0]=a[0];
    for(int i=1;i<n;i++){
        if(h[i-1]%h[i]==0){
            div[i]=div[i-1]+1;
        }
    }
    for(int i=1;i<n;i++){
        pre[i]=a[i]+pre[i-1];
    }
    ll ans=0;
    
    for(int i=0;i<n;i++){
        ll num = pre[i]-k;
        // first element greater than equal to num
        /// lowerbound;
        ll ind = lower_bound(pre.begin(), pre.end(), num ) - pre.begin();
        if(ind==i){
            if(a[i]<=k){
                ans = max(ans,1LL* 1);
            }
            continue;
        }
        if(ind==0){
            if(pre[i]<=k){
                ll t = min(1LL* i+1,div[i]);
                ans= max(ans,t);
            }            
        }

        ll temp = min(div[i], i -ind );
        ans = max(ans, temp);
        // cout<<i<<" "<<ans<<"\n";
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