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
int n;
vector<int> vect;

bool check(int x){
    vector<int> temp = vect;
    for(int i=1;i<=x;i++){
        int num = x-i+1;
        int ind = temp.size()-1;
        while(ind>=0 && temp[ind]>num){
            temp.pop_back();
            ind--;
        }
        if(temp.empty()){
            return false;
        }
        temp.pop_back();
        if(temp.empty()){
            if(i==x)
                return true;
            else    
                return false;
        }

        int ele = temp[0];
        temp.erase(temp.begin());
        ele +=num;
        temp.push_back(ele);
        sort(temp.begin(), temp.end());
    }

    return true;
}
void solve(){
    cin>>n;
    vect.resize(n);
    for(int i=0;i<n;i++){
        cin>>vect[i];
    }

    sort(vect.begin(), vect.end());
    int l =0;
    int r = n;
    while(l+1<r){
        int mid = (l+r)/2;
        if(check(mid)){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    if(check(r)){
        cout<<r<<"\n";
        return;
    }
    cout<<l<<"\n";

    // k max = countOnes;
    //can go for a n square solution here
    // alice needs a 1 in the array to finish the game
    // if bob removes all 1 then alice loses for sure
    /// if bob cannot remove all 1s, even then it is possible that alice loses 
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