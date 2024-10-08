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
vector<ll> coins(n);

void solve(){
    cin>>n>>x;
    coins.resize(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    vector<ll> dp(x+1,1e8);
    sort(coins.begin(), coins.end());

    dp[0]= 0;

    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i-coins[j]<0){
                break;
            }
            dp[i] = min(dp[i] , 1+ dp[i-coins[j]]);
        }
    } 


    int ans = dp[x];
    if(ans>=1e8){
        cout<<-1;
    }
    else{
        cout<<ans;
    }
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();    
    return 0;
}