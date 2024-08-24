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
    string s;
    cin>>s;
    ll n = s.length();
    //simulation?? nope
    //check for each char 
    ll ans=LLONG_MAX;

    for(char c ='a';c<='z';c++){
        ll maxi=0;
        bool found = false;
        ll l = -1;
        ll r =0;
        while(r<n){
            if(s[r]!=c){ //zero case
                if(l==-1){
                    l=r;
                }
            }

            else{
                found=true;
                 if(l!=-1){
                    maxi = max(maxi, r-l);
                }
                l=-1;
            }
            r++;

        }
        if(l!=-1){
            maxi = max(maxi, r-l);
        }
        ll num =0;
        if(found==false) continue;
        while(maxi>=1){
            num++;  
            maxi/=2;
        }
        ans = min(ans, num);

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