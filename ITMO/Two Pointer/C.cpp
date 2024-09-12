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
    ll  n ,s;
    cin>>n>>s;
    vector<ll> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll l=0, r=0;
    ll ans = 0;
    ll sum =0;
    while(r<n){
        sum += a[r];
        while(sum> s){
            sum-=a[l];
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