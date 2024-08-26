#include <bits/stdc++.h>
using namespace std;

#define mod 998244353
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
vector<ll> facto(2 * 1e5 +1,1);

void solve(){   
    string s;
    cin>>s;
    ll n = s.length();

    char prev = s[0];
    ll len = 1;
    vector<ll> vect;
    for(int i=1;i<n;i++){
        if(s[i]==prev){
            len++;
        }
        else{
            prev = s[i];
            vect.push_back(len);
            len=1;
        }
    }
    vect.push_back(len);

    ll ans =1;

    for(int i=0;i<vect.size();i++){
        ans = (ans * (vect[i]))%mod;
    }
    ans  = (ans * facto[n-vect.size()])%mod;

    cout<<n - vect.size()<<" "<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(ll i=1;i<facto.size();i++){
        facto[i] = (facto[i-1] * i)%mod;
    }
    int cases;
    cin >> cases;
    while (cases--){
        solve();    
    }
    return 0;
}