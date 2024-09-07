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

    vector<ll> temp;
    for(int i=0;i<n-1;i++){
        if(2 * vect[i+1] > vect[i]){
            temp.push_back(1);
        }
        else{
            temp.push_back(0);
        }
    }
 
    ll ans=0;
    int i=0;
    while(i<n-1){
        int count =0;
        while(i<n-1 && temp[i]==1){
            i++;
            count++;
        }
        ans+= max( 1LL *0 , count -k+1  );

        i++;
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