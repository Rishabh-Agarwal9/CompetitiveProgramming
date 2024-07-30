#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<bool> vect(n+1,false);
    int i=n-1;
    while(i--){
        int x;
        cin>>x;
        vect[x] = true;

    }

    for(int i=1;i<=n;i++ ){
        if(!vect[i]) cout<<i;
    }
    return 0;
}


// always use "\n" for new line and not endl
