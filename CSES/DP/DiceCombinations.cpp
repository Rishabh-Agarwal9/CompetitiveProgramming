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
    ll n ;
    cin>>n;
    vector<ll> dp(n+1,0);
    dp[1]=1;
    dp[0]=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=6;j++){
            if(i-j<0){
                break;
            }
            dp[i]+= dp[i-j];
            dp[i]%=mod;
        }
    }
   
    cout<<dp[n]%mod<<"\n";
}   

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}