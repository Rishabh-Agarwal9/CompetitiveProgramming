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
    ll n,x,y;
    cin>>n>>x>>y;
    string a,b;
    cin>>a>>b;
    if(a==b){
        cout<<0<<"\n";
        return;
    }
    int count =0;
    for(int  i=0;i<n;i++){
        if(a[i]!=b[i]){
            count++;
        }
    }
    if(count%2==1){
        cout<<-1<<"\n";
        return;
    }
    if(n==2){
        cout<<x<<"\n";
    }
    int pairs = count/2;
    ll ans=0;
    int adj=0;
    for(int i=0;i<n-1;i++){
        if(a[i]!=b[i] && a[i+1]!=b[i+1]){
            adj++;
            i++;
        }
    }

    if(x<y){
        //adj replacement in cheaper;
        ans+=adj* x;
        for(int i=0;i<n-1;i++){
            if(a[i]!=b[i] && a[i+1]!=b[i+1]){
                i++;
                a[i]=b[i];
                a[i+1]=b[i+1];
            }
        }
        int prev =-1;
        int t=0;

        for(int i=0;i<n;i++){
            if(a[i]!=b[i]){
                if(prev==-1){
                    prev =i;
                }
                else{
                    int moves = (i - prev);
                    if(x  * moves < y){
                        ans+=x*moves;
                        prev =-1;
                        t++;
                    }
                    else{
                        prev =i;
                    }
                }
            }
        }
        ans += (pairs - adj - t) * y;
    }
    else{
        // far away replacement is cheaper;
        if(pairs == adj && adj==1){
            ans+= min(x, 2*y);
        }
        else{
            ans += pairs *y;
        }
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