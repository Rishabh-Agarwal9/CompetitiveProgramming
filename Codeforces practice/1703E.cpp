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
    vector<string> vect(n);
    for(int i=0;i<n;i++){
        cin>>vect[i];
    } 
    ll  ans=0;
    for(int i=0;i<n/2;i++){
        for(int j=i;j<n-i-1;j++){
            int z=0,o=0;
            if(vect[i][j]=='1'){
                o++;
            }
            else{
                z++;
            }

            if(vect[n-j-1][i]=='1'){
                o++;
            }
            else{
                z++;
            }

            if(vect[j][n-i-1]=='1'){
                o++;
            }
            else{
                z++;
            }
            if(vect[n-i-1][n-j-1]=='1'){
                o++;
            }
            else{
                z++;
            }
            // cout<<i<<" "<<j<<" "<<z<<" "<<o<<"\n";
            ans+= min(z,o);
        }
    }
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