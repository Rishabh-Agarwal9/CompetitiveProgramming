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
    ll n,k;
    cin>>n>>k;
    vector<ll> vect(n);

    for(int i=0;i<n;i++){
        cin>>vect[i];
    }
    k--;
    ll ans =0;
    ll num = vect[k];
    swap(vect[k], vect[0]);

    ll maxi = vect[0];

    for(int i=1;i<n;i++){
        if(vect[i]>maxi){
            maxi = vect[i];
        }
        if(maxi==num) ans++;
    }
    swap(vect[k], vect[0]);

    for(int i=0;i<n;i++){
        if(i==k) break;
        if(vect[i]>vect[k]){
            swap(vect[i], vect[k]);
            break;
        }
    }
    
    ll sum =0;
    maxi = vect[0];

    for(int i=1;i<n;i++){
        if(vect[i]>maxi){
            maxi = vect[i];
        }
        if(maxi==num) sum++;
    }

    
    cout<<max(ans, sum)<<"\n";
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