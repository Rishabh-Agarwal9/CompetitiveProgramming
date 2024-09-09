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
    int n , x;
    cin>>n>>x;
    vector<int> price(n);
    vector<int> pages(n);

    for(int i=0;i<n;i++){
        cin>>price[i];
    }

    for(int i=0;i<n;i++){
        cin>>pages[i];
    }

    vector<vector<int>> dp(n ,vector<int> (x+1 , 0) );

    if(price[0]<=x){
        dp[0][price[0]]=pages[0];
    }

    for(int i=0;i<n;i++){
        for(int j=1;j<=x;j++){
            int pick =0, notPick =0;
            if(j>0){
                notPick = dp[i][j-1];
            }
            if(i>0){
                notPick = max(notPick , dp[i-1][j]);
            }

            if(i>0 && j- price[i]>=0){
                pick = dp[i-1][j-price[i]] + pages[i];
            }

            dp[i][j] = max({pick , notPick, dp[i][j]});
        }
    }
    cout<<dp[n-1][x]<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();    
    
    return 0;
}