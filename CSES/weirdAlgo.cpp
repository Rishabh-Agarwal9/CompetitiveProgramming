#include<bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    cin>>n;
    if(n==1){
        cout<<1;
        return 0;
    } 

    while(n>1){
        cout<<n<<" ";
        if(n%2==0) n/=2;
        else n=n*3+1;
    }
    cout<<1;
    return 0;
}