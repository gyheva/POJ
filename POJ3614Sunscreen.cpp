#include<bits/stdc++.h>
using namespace std;
int i,j,ans,coc,m,n,maxi,v[3000],num[3000];
struct cow{
    int mini,maxi;
}a[3000];
bool cmp(cow x, cow y){
    return x.mini>y.mini;
}
int main(){
    cin>>m>>n;
    for(i=1;i<=m;i++) cin>>a[i].mini>>a[i].maxi;
    sort(a+1,a+m+1,cmp);
    for(i=1;i<=n;i++) cin>>v[i]>>num[i];
    for(i=1;i<=m;i++){
        maxi=0;
        coc=0;
        for(j=1;j<=n;j++){
            if(v[j]>=a[i].mini&&v[j]<=a[i].maxi&&num[j]&&v[j]>maxi){
                maxi=v[j];
                coc=j;
            }
            //cout<<v[j]<<" "<<num[j]<<" "<<a[i].mini<<" "<<a[i].maxi<<" "<<maxi<<" "<<endl;

        }
        if(coc!=0){
            num[coc]--;
            ans++;
        }
    }
    cout<<ans;
}
