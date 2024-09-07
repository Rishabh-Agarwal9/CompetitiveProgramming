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
    string s;
    cin>>s;
    ll score =0;
    if(s[n-1]=='0'){
        int ind = -1;
        for(int i=n-2;i>=0;i--){
            if(s[i]=='1'){
                ind =i;
                break;
            }
        }

        if(ind!=-1){
            if(n-1 - ind <=k){
                k-= n-1-ind;
                swap(s[ind], s[n-1]);
            }
        }
    }

    if(s[0]=='0'){
        int ind =-1;
        for(int i=1;i<n;i++){
            if(s[i]=='1'){
                ind =i;
                break;
            }
        }

        if(ind!=-1 && ind != n-1){
            if(ind <=k){
                swap(s[0], s[ind]);
            }
        }
    }

    for(int i=0;i<n-1;i++){
        score += ((int)(s[i]-'0')) *10 +(int)(s[i+1]-'0'); 
    }
    cout<<score<<"\n";
}   
    
//move 1s to the end and start is the only way we can reduce the score

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