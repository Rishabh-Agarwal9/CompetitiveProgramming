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
    ll n,q;
    cin>>n>>q;
    set<int> xset, yset;
    unordered_map<int, int> xmap;
    unordered_map<int, int> ymap;
    for(int i=1;i<=n;i++){
        xset.insert(i);
        yset.insert(i);
        xmap[i]++;
        ymap[i]++;

    }

    for(int i=0;i<q;i++){
        int ind;
        cin>>ind;
        if(ind !=3){
            int x,y;
            cin>>x>>y;
            if(ind==1){
                xmap[x]--;
                ymap[y]--;

                xset.erase(x);
                yset.erase(y);
            }
            else{
                xmap[x]++;
                ymap[y]++;
                if(xmap[x]==1){
                    xset.insert(x);
                }
                if(ymap[y]==1){
                    yset.insert(y);
                }
            }
        }
        else{
            int x1,x2,y1,y2;
            cin>>x1>>y1>>x2>>y2;

            auto it = xset.lower_bound(x1);
            if(it == xset.end() || (*it) > x2){
                cout<<"YES"<<"\n";
                continue;
            }
            
            auto it2 = yset.lower_bound(y1);
            if(it2 == yset.end() || (*it2) > y2){
                cout<<"YES"<<"\n";
                continue;
            }
            cout<<"NO"<<"\n";
        }
    }
}


//binary search??????
//ofc
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();    
    return 0;
}