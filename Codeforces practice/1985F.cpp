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

bool check(ll x,ll k, vector<ll> &a, vector<ll> &c){

    for(int i =0;i<a.size();i++){
        if(((x-1)/c[i]) >=LLONG_MAX/a[i]){
            return true;
        }
        k-= ((x-1)/c[i] +1) * a[i];
        if(k<=0) return true;
    }

    return false;
}

void solve(){
    ll h,n;
    cin>>h>>n;
    vector<ll> a(n,0);
    vector<ll> c(n,0);
    for(int i =0;i<n;i++){
        cin>>a[i];
    }
    for(int i =0;i<n;i++){
        cin>>c[i];
    }
    ll ans=0;
    ll l=1, r=LLONG_MAX;

    while(l<=r){
        ll mid = l + (r-l)/2;
        if(check(mid,h,a,c)){
            r = mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<l<<"\n";
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