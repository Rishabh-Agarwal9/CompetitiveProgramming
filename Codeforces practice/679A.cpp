#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
typedef set<string> ss;
typedef vector<int> vi;
typedef map<int, char> msi;
typedef pair<int, int> pa;
typedef long long int ll;
vector<int> primes ={ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
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
    for(int i=0;i<4;i++){
        int num = primes[i]*primes[i];
        cout<<num<<endl;
        string res;
        cin>>res;
        if(res=="yes"){
            cout<<"composite"<<endl;
            return;
        }
    }
    int n = primes.size();
    int count=0;
    for(int i =0;i<n;i++){
        int num = primes[i];
        cout<<num<<endl;
        string res;
        cin>>res;
        if(res=="yes"){
            count++;
        }
    }
    if(count>=2){
        cout<<"composite"<<endl;

    }
    else{
        cout<<"prime"<<endl;

    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    
    return 0;
}