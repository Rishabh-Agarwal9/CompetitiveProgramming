#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
typedef set<string> ss;
typedef vector<int> vs;
typedef map<int, char> msi;
typedef pair<int, int> pa;
typedef long long int ll;

ll func(ll x, ll y){
    ll ans =1;
    while(y>0){
        if(y%2==1){
            ans = ans *x;
            y--;
        }
        else{
            x=x*x;
            y/=2;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<func(3,7);
    return 0;
}