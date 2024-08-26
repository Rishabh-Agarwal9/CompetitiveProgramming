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
void primeFactors(int n , map<int,int> & mp) 
{ 
    while (n % 2 == 0) 
    { 
        mp[2]++;
        n = n/2; 
    } 
    for (int i = 3; i <= sqrt(n); i = i + 2){ 
        while (n % i == 0){ 
            mp[i]++;
            n = n/i; 
        } 
    } 
    if (n > 2)  mp[n]++;
} 
void solve(){
    ll n;
    cin>>n;
    vector<ll> vect(n);
    for(int i=0;i<n;i++){
        cin>>vect[i];
    }
    // number with 3 prime factors are always strongly compsite
    // numbers with 2 prime factors are strongly composite if square root

    ll ans=0;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        primeFactors(vect[i], mp);
    }
    ll rem =0;
    for(auto x: mp){
        rem+= x.second %2;
        ans+=x.second/2;
    }
    ans +=rem/3;
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