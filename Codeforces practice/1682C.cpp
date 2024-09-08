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
    // if no dups then answer is just n/2

    ll n;
    cin>>n;
    vector<ll> vect(n);
    map<ll,ll> mp;
    ll maxi =-1;
    for(int i=0;i<n;i++){
        cin>>vect[i];
        mp[vect[i]]++;
        maxi = max(maxi, vect[i]);
    } 
    

    int nums = mp.size();

    int dups=0;
    for(auto x: mp){
        if(x.second>1){
            dups++;
        }
    }

    cout<<dups + (nums - dups +1)/2<<"\n";
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