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
    vector<string> grid (n);
    vector<vector<int>> dp (n ,  vector<int> (n , 0));
    for(int i=0;i<n;i++){
        cin>>grid[i];
    }

    if(grid[0][0]== '*'){
        cout<<0<<"\n";
        return;
    }

    dp[0][0]=1;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='*'){
                continue;
            }
            int left =0, up =0;
            if(i>0){
                left = dp[i-1][j];
            }
            if(j>0){
                up = dp[i][j-1];
            }

            dp[i][j] += up  + left;
            dp[i][j] %= mod;
        }
    }
    
    cout<< dp[n-1][n-1]<<"\n";

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();    
    return 0;
}