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
    vector<string> vect(2);
    cin>>vect[0];
    cin>>vect[1];
    vector<string> wall = vect;
    bool ans = false;
    if(n==1){
        cout<<"YES"<<"\n";
        return;
    }
    if(wall[0][0]=='B'){
        bool found = true;
        int currCol = 0;
        for(int i=0;i<n;i++){
            wall[currCol][i]='W';
            if(wall[1-currCol][i]=='B'){
                currCol = 1-currCol;
                wall[currCol][i]='W';
            }
            if(i==n-1 || wall[currCol][i+1]=='B'){
                continue;
            }
            else{
                found = false;
                break;
            }
        }    
        ans = ans|found;
    }
    wall = vect;

    if(wall[1][0]=='B'){
        bool flag = true;
        int currCol = 1;
        for(int i=0;i<n;i++){
            wall[currCol][i]='W';
            if(wall[1-currCol][i]=='B'){
                currCol = 1-currCol;
                wall[currCol][i]='W';
            }
            if(i==n-1 || wall[currCol][i+1]=='B'){
                continue;
            }
            else{
                flag = false;
                break;
            }
        }  
        ans = ans|flag;  
    }
    if(ans){
        cout<< "YES"<<"\n";
        return;
    }
    cout<< "NO"<<"\n";

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