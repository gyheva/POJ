#include<bits/stdc++.h>
using namespace std;
int i,j,m,n,k,maxi,a[510][510],sum[510][510],cur;
int main(){
    cin>>n;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            sum[i][j]=sum[i][j-1]+a[i][j];
        }
    }
    for(i=1;i<=n;i++){
        for(j=i;j<=n;j++){
            cur=0;
            for(k=1;k<=n;k++){
                cur+=sum[k][j]-sum[k][i-1];
                maxi=max(maxi,cur);
                cur=max(cur,0);
            }
        }
    }
    /*
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            for(k=i-1;k>=0;k--){
                for(m=j-1;m>=0;m--){
                    maxi=max(maxi,sum[i][j]-sum[k][j]-sum[i][m]+sum[k][m]);
                }
            }
        }
    }
    */
    cout<<maxi;
}
