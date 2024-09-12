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
    ll  n ,k;
    cin>>n>>k;
    vector<ll> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll l=0, r=0;
    ll ans = 0;
    unordered_map<int,int> umap;
    while(r<n){
        umap[a[r]]++;
        while(umap.size()>k){
            umap[a[l]]--;
            if(umap[a[l]]==0){
                umap.erase(a[l]);
            }
            l++;
        }
        ans+=(r-l+1);
        r++;
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