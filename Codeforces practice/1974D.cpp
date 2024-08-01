#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
typedef set<string> ss;
typedef vector<int> vi;
typedef map<int, char> msi;
typedef pair<int, int> pa;
typedef long long int ll;

void print(vi &a){
    for(auto x : a){
        cout << x << " ";
    }
    cout << "\n";
}
void print(int &a){
    cout << a << " ";
}
void print(string &s){
    cout << s << " ";
}
void print(pair<int,int> &p){
    cout << p.first << " " << p.second << "\n";
}

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int S=0,N=0,E=0,W=0;

    for(int i=0;i<n;i++){
        if(s[i]=='S'){
            S++;
        }
        if(s[i]=='N'){
            N++;
        }
        if(s[i]=='E'){
            E++;
        }
        if(s[i]=='W'){
            W++;
        }
    }
    int diff1 = abs(N-S);
    int diff2 = abs(W-E);
    if(diff1%2==1||diff2%2==1){
        cout<<"NO"<<"\n";
        return;
    }
    // n s e w 
    vector<int> vect(4,0);

    int div = N/2;
    if(div*2!=N) div++;
    vect[0]=div;

    div = S/2;
    if(div*2!=S) div++;
    vect[1]=div;

    div = E/2;
    if(div*2!=E) div++;
    vect[2]=div;

    div = W/2;
    if(div*2!=W) div++;
    vect[3]=div;

    string ans;
    bool flag = false;
    bool flag2 = false; 
    unordered_set<int> st;
    for(int i=0;i<n;i++){
        if(s[i]=='N'){
            if(vect[0]){
                ans.push_back('R');
                st.insert(1);
                vect[0]--;
            }
            else{
                st.insert(0);

                ans.push_back('H');
            }
        }
        if(s[i]=='S'){
            if(vect[1]){
                ans.push_back('R');
                st.insert(1);

                vect[1]--;
            }
            else{
                st.insert(0);

                ans.push_back('H');
            }
        }
        if(s[i]=='E'){
            if(vect[2]){
                ans.push_back('H');
                st.insert(0);

                vect[2]--;
            }
            else{
                ans.push_back('R');
                st.insert(1);

            }
        }
        if(s[i]=='W'){
            if(vect[3]){
                ans.push_back('H');
                st.insert(0);

                vect[3]--;
            }
            else{
                ans.push_back('R');
                st.insert(1);

            }
        }
    }
    if(st.size()==2){
        cout<<ans<<"\n";
    }
    else{
        cout<<"NO"<<"\n";
    }
    

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