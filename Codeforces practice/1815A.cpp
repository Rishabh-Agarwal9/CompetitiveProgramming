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
    vector<ll> vect(n);
    for(int i=0;i<n;i++){
        cin>>vect[i];
    }
    if(n%2==1){
        cout<<"YES"<<"\n";
        return;
    }
    vector<ll> diff;
    for(int i=1;i<n;i++){
        diff.push_back(vect[i] - vect[i-1]);
    }
    ll sum =0;
    for(int i=0;i<n-1;i+=2){
        sum+=diff[i];
    }
    if(sum>=0){
        cout<<"YES"<<"\n";
        return;
    }
    cout<<"NO"<<"\n";
        return;
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