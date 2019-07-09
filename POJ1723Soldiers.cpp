#include<bits/stdc++.h>
using namespace std;
long long n,i,a[10010],b[10010],x[10010],mid,ans;
int main(){
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i]>>b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    mid=b[(n+1)/2];
    for(i=1;i<=n;i++) ans+=abs(mid-b[i]);
    for(i=1;i<=n;i++) x[i]=a[i]-(i-1);
    sort(x+1,x+n+1);
    mid=x[(n+1)/2];
    for(i=1;i<=n;i++) ans+=abs(mid-x[i]);
    cout<<ans;
}
