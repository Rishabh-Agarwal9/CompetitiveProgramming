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
class StackOps{
    public:
    stack<ll> s,maxs, mins;

    void push(ll num){
        s.push(num);

        ll mini = num;
        if(!mins.empty()){
            mini = min(mins.top(), mini);
        }
        mins.push(mini);

        ll maxi = num;
        if(!maxs.empty()){
            maxi = max(maxs.top(), maxi);
        }
        maxs.push(maxi);
    }
    bool empty(){
        return s.empty();
    }
    void pop(){
        s.pop();
        maxs.pop();
        mins.pop();
    }

    ll maxVal(){
        return maxs.top();
    }
    ll minVal(){
        return mins.top();
    }
    ll top(){
        return s.top();
    }
};
StackOps s1,s2;

ll getMax(){
    ll maxi =-1;
    if(!s2.empty()){
        maxi = max(maxi , s2.maxVal());
    }

    if(!s1.empty()){
        maxi = max(maxi , s1.maxVal());
    }

    return maxi;
}

ll getMin(){
    ll mini =LLONG_MAX;
    if(!s2.empty()){
        mini = min(mini , s2.minVal());
    }

    if(!s1.empty()){
        mini = min(mini , s1.minVal());
    }

    return mini;
}
void solve(){
    ll  n ,k;
    cin>>n>>k;
    vector<ll> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll l=0, r=0;
    ll ans = 0;
    while(r<n){
        s2.push(a[r]);
        while(getMax() - getMin() >k){
            if(s1.empty()){
                while(!s2.empty()){
                    s1.push(s2.top());
                    s2.pop();
                }
            }
            l++;
            s1.pop();
        }
        ans +=r-l+1;
        r++;
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();    
    return 0;
}