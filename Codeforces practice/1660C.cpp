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
    // either delete the char itself or delete all chars between it and its next occurance
    string s;
    cin>>s;
    int n = s.length();
    int m =0;
    vector<bool> p(26,false);
    for(int i=0;i<n;i++){
        if(p[s[i]-'a']){
            m+=2;
            vector<bool> t(26,false);
            p = t;
        }
        else{
            // cout<<s[i]<<" ";
            p[s[i]-'a']=true;
        }
    }    
    cout<<n-m<<"\n"; 
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