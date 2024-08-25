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
    //looks like brute force if ive ever seen one
    ll n;
    cin>>n;
    vector<ll> vect(n);
    map<int,int> umap;
    for(int i=0;i<n;i++){
        cin>>vect[i];
        umap[vect[i]%10]++;
    }
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<=9;k++){
                int sum = i+j+k;
                if(sum%10!=3)  continue;

                if(umap[i]==0){
                    continue;
                }
                else{
                    umap[i]--;
                }

                if(umap[j]==0){
                    umap[i]++;
                    continue;
                }
                else{
                    umap[j]--;
                }

                if(umap[k]>0){
                    cout<<"YES"<<"\n";
                    return;
                }
                umap[i]++;
                umap[j]++;
            }
        }
    }
    cout<<"NO"<<"\n";
    return;

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