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
ll n,x;
vector<ll> coins;


void solve(){
    cin>>n>>x;
    coins.resize(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    sort(coins.begin(), coins.end());
    
    vector<vector<ll>> dp( n+1 , vector<ll> (x+1,0));
    dp[0][0] = 1;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=x;j++){
            dp[i][j]=dp[i-1][j];
            if(j - coins[i-1]>=0){
                dp[i][j]+=dp[i][j - coins[i-1]];
            }
            dp[i][j]%=mod;
        }
    }
    cout<<dp[n][x]<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();    
    return 0;
}