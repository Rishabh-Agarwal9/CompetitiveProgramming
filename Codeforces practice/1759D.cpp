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
ll powerFunc(ll num , ll p){
    ll res = 1;
    while(p>0){
        res*=num;
        p--;
    }
    return res;
}
ll helper(ll need, ll num , ll m){
    ll temp=1;
    for(int i=0;i<need;i++){
        if(temp*num<=m){
            temp *=num;
        }
    }
    return temp;
}
void solve(){
    ll n,m;
    cin>>n>>m;
    ll numT=0;
    ll numF=0;
    ll temp = n;
    while(temp%2 ==0){
        numT++;
        temp/=2;
    }
    while(temp%5 ==0){
        numF++;
        temp/=5;
    }
    ll mul = 1;
    if(numT>numF){
        mul = helper(numT-numF,5,m);
         
    }
    else if(numF>numT){
        mul =helper(numF-numT,2,m);
    }

    while(mul * 10< m){
        mul = mul*10;
    }

    cout<< (m/mul) * mul * n<<"\n";

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