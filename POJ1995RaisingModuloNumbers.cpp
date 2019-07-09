#include<bits/stdc++.h>
using namespace std;
long long n,i,p,m,a,b,j,ans;
long long mul(long long a,long long b,long long p){
    long long ans;
    if(p==1) ans=0;
    else ans=1;
    for(;b;b>>=1){
        if(b&1) ans = ans*a%p;
        a = a*a%p;
    }
    return ans;
}
int main(){
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>p>>m;
        ans=0;
        for(j=1;j<=m;j++){
            cin>>a>>b;
            ans+=mul(a,b,p);
            ans%=p;
        }
        cout<<ans<<endl;
    }
}
