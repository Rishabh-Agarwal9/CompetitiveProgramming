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
    ll  n,c,d;
    cin>>n>>c>>d;
    vector<ll> vect(n);
    ll ans =0;
    ll extra=0;
    set<ll> st;
    for(int i=0;i<n;i++){
        cin>>vect[i];

        if(st.find(vect[i])!=st.end()){
            extra += c;
        }
        st.insert(vect[i]);
    }

    vector<ll> perm(st.begin(), st.end());

    if(perm[0]!=1){
        extra+=d;
        perm.insert(perm.begin(),1LL* 1);
    }
    
    ll  num =1;
    ll auxAns = LLONG_MAX;
    for(int i=0;i<perm.size();i++){
        if(num==perm[i]){
            num++;
            continue;
        }
        ll diff = perm[i] - num;
        auxAns =min(auxAns, ans +(perm.size()-i)*c);
        if(diff *d <(perm.size()-i)*c){
            ans+=diff*d;
            num = perm[i]+1;
        }
        else{
            ans +=(perm.size()-i)*c;
            break;
        }


    }
    cout<<min(ans, auxAns) + extra<<"\n";

    // must remove duplicates


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