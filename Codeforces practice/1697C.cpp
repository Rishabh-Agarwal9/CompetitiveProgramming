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
    string s,t;
    cin>>s>>t;
    int i =0;
    int countAB= 0;
    int countBC= 0;
    while(i<n){
        if(s[i]==t[i]){
            if(s[i]=='c' && countAB){
                cout<<"NO"<<"\n";
                return;
            }
            if(s[i]=='a' && countBC){
                cout<<"NO"<<"\n";
                return;
            }
        }
        else if(s[i]=='a' && t[i]=='b'){
            if(countBC){
                cout<<"NO"<<"\n";
                return;
            }
            countAB++;
        }
        else if(s[i]=='b' && t[i]=='c'){
            if(countAB){
                cout<<"NO"<<"\n";
                return;
            }
            countBC++;
        }
        else if(s[i]=='b' && t[i]=='a'){
            if(countAB==0){
                cout<<"NO"<<"\n";
                return;
            }
            countAB--;
        }
        else if(s[i]=='c' && t[i]=='b'){
            if(countBC==0){
                cout<<"NO"<<"\n";
                return;
            }
            countBC--;
        }
        else{
            cout<<"NO"<<"\n";
            return;
        }
        i++;
    }
    if(countAB==0 && countBC==0){
        cout<<"YES"<<"\n";
    }
    else{
        cout<<"NO"<<"\n";

    }

}
//if mismatch of a and c then it is not possible

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