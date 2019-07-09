#include<bits/stdc++.h>
using namespace std;
long long a[1100],b[1100],x,y,num,ans,integ,i,j,t,n;
double fin,dou;
int main(){
    cin>>t;
    for(int z=1;z<=t;z++){
        cin>>n;
        ans=2*(1e18);
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i];
        }
        for(int i=1;i<=n;i++){
            cin>>x>>y;
            for(int j=1;j<=n;j++){
                num=(a[j]-x)*(a[j]-x)+(b[j]-y)*(b[j]-y);
                ans=min(ans,num);
            }
        }
        printf("%.3llf\n",(double)sqrt(ans));
    }
}
