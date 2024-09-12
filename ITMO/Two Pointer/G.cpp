#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll gcd (ll a, ll b) {
    return b ? gcd (b, a % b) : a;
}
class StackOps{
    public:
    stack<ll> s,gcdS;

    void push(ll num){
        s.push(num);

        ll gcd = num;
        if(!gcdS.empty()){
            gcd = __gcd(gcdS.top(), gcd);
        }
        gcdS.push(gcd);
    }
    bool empty(){
        return s.empty();
    }
    void pop(){
        s.pop();
        gcdS.pop();

    }

    ll gcdVal(){
        return gcdS.top();
    }
    ll top(){
        return s.top();
    }
};
StackOps s1,s2;

ll getGcd(){
    if(s1.empty()){
        return s2.gcdVal();
    }
    else if(s2.empty()){
        return s1.gcdVal();
    }
    return __gcd(s1.gcdVal(),s2.gcdVal());
}
void solve(){
    ll  n;
    cin>>n;
    vector<ll> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll l=0, r=0;
    ll ans = LLONG_MAX;
    while(r<n){
        if(a[r]==1){
            cout<<1<<"\n";
            return;
        }
        s2.push(a[r]);  
        while(getGcd()==1){
            ans = min(ans, r-l+1);
            if(s1.empty()){
                while(!s2.empty()){
                    s1.push(s2.top());
                    s2.pop();
                }
            }
            l++;
            s1.pop();
        }
        r++;
    }
    if(ans==LLONG_MAX) cout<<-1<<"\n";
    else
        cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();    
    return 0;
}