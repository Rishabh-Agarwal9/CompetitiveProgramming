#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef set<string> ss;
typedef vector<int> vs;
typedef map<int, char> msi;
typedef pair<int, int> pa;
typedef long long int ll;

class DisjointSet{
    vector<int> rank, parent,Size;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        Size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUPar(int u){
        if(u==parent[u]) return u;
        return parent[u]=findUPar(parent[u]);
    }
    void unionByRank(int u, int v){
        int pu=findUPar(u);
        int pv=findUPar(v);
        if(pu==pv) return;
        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else if(rank[pu]>rank[pv]){
            parent[pv]=pu;
        }
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }

    void unionBySize(int u, int v){
        int pu=findUPar(u);
        int pv=findUPar(v);
        if(pu==pv) return;
        if(Size[pu]<Size[pv]){
            parent[pu]=pv;
            Size[pv]+=Size[pu];
        }
        else{
            parent[pv]=pu;
            Size[pu]+=Size[pv];
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    DisjointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    if(ds.findUPar(3)==ds.findUPar(7)) cout<<"yes";
    else cout<<"no";
    
    ds.unionBySize(3,7);
    if(ds.findUPar(3)==ds.findUPar(7)) cout<<"yes";
    else cout<<"no"; 


    return 0;
}