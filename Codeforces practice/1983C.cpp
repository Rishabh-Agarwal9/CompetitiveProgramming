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

vector<vector<ll>> helper (vector<ll> &a,vector<ll> &b,vector<ll> &c, ll tot ){
    ll sum=0;
    for(int i=0;i<a.size();i++){
        sum+=a[i];
        if(sum>=tot){
            ll sum2=0;
            for(int j=i+1;j<a.size();j++){
                sum2+=b[j];

                if(sum2>=tot){
                    ll sum3=0;
                    for(int k=j+1;k<c.size();k++){
                        sum3+=c[k];
                    }
                    if(sum3>=tot){
                        return {{{1,i+1}, {i+2, j+1} , {j+2 , a.size()}}};
                    }
                    else{
                        return {};
                    }
                }
            }
            return {};
        }
    }
    return {};
}

void solve(){
    int  n ;
    cin>>n;
    vector<ll> a(n), b(n),c(n);
    ll sum =0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    ll tot = sum/3;
    if(sum%3>0) tot++;
    vector<vector<ll>> ans= helper(a,b,c,tot);
    if(ans.size()>0){
        cout<<ans[0][0]<<" "<<ans[0][1]<<" ";
        cout<<ans[1][0]<<" "<<ans[1][1]<<" ";
        cout<<ans[2][0]<<" "<<ans[2][1]<<" ";
        cout<<"\n";
        return;
    }

   ans= helper(a,c,b,tot);
    if(ans.size()>0){
        cout<<ans[0][0]<<" "<<ans[0][1]<<" ";
        cout<<ans[2][0]<<" "<<ans[2][1]<<" ";
        cout<<ans[1][0]<<" "<<ans[1][1]<<" ";
        cout<<"\n";
        return;
    }
    ans= helper(b,a,c,tot);

    if(ans.size()>0){
        cout<<ans[1][0]<<" "<<ans[1][1]<<" ";
        cout<<ans[0][0]<<" "<<ans[0][1]<<" ";
        cout<<ans[2][0]<<" "<<ans[2][1]<<" ";
        cout<<"\n";
        return;
    }
    ans= helper(b,c,a,tot);
    
    if(ans.size()>0){
        cout<<ans[2][0]<<" "<<ans[2][1]<<" ";
        cout<<ans[0][0]<<" "<<ans[0][1]<<" ";
        cout<<ans[1][0]<<" "<<ans[1][1]<<" ";
        cout<<"\n";
        return;
    }
    ans= helper(c,a,b,tot);

    if(ans.size()>0){
        cout<<ans[1][0]<<" "<<ans[1][1]<<" ";
        cout<<ans[2][0]<<" "<<ans[2][1]<<" ";
        cout<<ans[0][0]<<" "<<ans[0][1]<<" ";
        cout<<"\n";
        return;
    }
    ans= helper(c,b,a,tot);

    if(ans.size()>0){
        cout<<ans[2][0]<<" "<<ans[2][1]<<" ";
        cout<<ans[1][0]<<" "<<ans[1][1]<<" ";
        cout<<ans[0][0]<<" "<<ans[0][1]<<" ";
        cout<<"\n";
        return;
    }
    cout<<-1<<"\n";
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