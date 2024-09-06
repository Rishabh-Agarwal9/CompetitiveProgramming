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
int countDig(ll  num){
    if(num==0) return 1;

    int ans =0;

    while(num){
        ans++;
        num/=10;
    }

    return ans;
}
void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n),b(n);
    map<ll,ll> mp1;
    map<ll,ll> mp2;

    for(int i=0;i<n;i++){
        cin>>a[i];
        mp1[a[i]]++;
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
        if(mp1.find(b[i])!=mp1.end()){
            mp1[b[i]]--;
            if(mp1[b[i]]==0){
                mp1.erase(b[i]);
            }
        }
        else{
            mp2[b[i]]++;
        }
    }

    
    ll ans=0;
    map<ll,ll> mp3,mp4;
    for(auto x: mp1){
        ll num = x.first;
        int dig = countDig(num);
        if(dig>1){
            mp3[dig] +=x.second; 
            ans+=x.second;
        }
        else{
            mp3[num] += x.second;
        }
    }

    for(auto x: mp2){
        ll num = x.first;
        int dig = countDig(num);
        if(dig>1){
            mp4[dig] +=x.second; 
            ans+=x.second;
        }
        else{
            mp4[num] += x.second;
        }
    }
    
    for(auto x: mp3){
        if(mp4.find( x.first)!= mp4.end()){
            ll mini =  min(x.second , mp4[x.first]);
            mp3[x.first]-=mini;
            mp4[x.first]-=mini;
        }
    }
    for(auto x: mp3){
        if(x.first>1){
            ans+=x.second;
        }
    }

    for(auto x: mp4){
        if(x.first>1){
            ans+=x.second;
        }
    }
    cout<<ans<<"\n";
    // if equals then take them out
    //anything >10 will have to be reduced at least once
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