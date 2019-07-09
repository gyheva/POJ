#include<bits/stdc++.h>
using namespace std;
struct node{
    int v;
    int id;
}re[1001];
int v[1001],pa[1001],son[1001][1001],ns[1001],f[1001];
bool cmp(node a,node b){
    return a.v>b.v;
}
int main(){
    while(true){
        cin>>n>>r;
        if(!n&&!r) break;
        for(int i=1;i<=n;i++){
            cin>>re[i].v;
            re[i].id=i;
        }
        sort(re+1,re+n+1,cmp);
        for(int i=1;i<n;i++){
            cin>>p>>s;
            pa[s]=p;
            ns[p]++;
            son[p][ns[p]]=s;
        }
        for(ct=1;ct<=n;ct++){
            for(i=1;i<=n;i++){
                if(pa[re[i].id]==0||f[pa[i]]==1){
                    sum+=ct*re[i].v;
                    f[re[i].id]=1;
                }
            }
        }
    }
}
