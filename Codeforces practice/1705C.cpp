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
    ll n,c,q;
    cin>>n>>c>>q;
    string s;
    cin>>s;
    vector<ll> left={0};
    vector<ll> right= {n-1};
    vector<ll> dist = {0};
    for(int i=0;i<c;i++){
        ll t1,t2;
        cin>>t1>>t2;
        t1--;
        t2--;

        left.push_back(right[right.size()-1]+1);
        right.push_back(left[left.size()-1] + t2-t1);

        dist.push_back(left[left.size()-1] - t1);
    }
    vector<ll> k(q);
    for(int  i=0;i<q;i++){
        cin>>k[i];
        k[i]--;

        if(k[i]<n){
            cout<<s[k[i]]<<"\n";
            continue;;
        }
        for(int j=c;j>=1;j--){
            if(k[i] <= right[j] && k[i] >= left[j]){
                k[i]-=dist[j];
            }
        }

        cout<<s[k[i]]<<"\n";
    }
}
//binary search coming to mind rn
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