#include<bits/stdc++.h>
using namespace std;
double n,a[100010],b[100010],sum[100010];
int i,R;
int main(){
    cin>>n>>R;
    for(i=1;i<=n;i++) cin>>a[i];
    double eps=1e-5;
    double l=-1e6,r=1e6;
    while(r-l>eps){
        double mid=(l+r)/2;
        double minv=1e6,maxn=-1e6;
        for(i=1;i<=n;i++) b[i]=a[i]-mid;
        for(i=1;i<=n;i++) sum[i]=sum[i-1]+b[i];
        for(i=R;i<=n;i++){
            minv=min(minv,sum[i-R]);
            maxn=max(maxn,sum[i]-minv);
        }
        if(maxn>=0) l=mid;
        else r=mid;
    }
    cout<<int(r*1000)<<endl;
}
