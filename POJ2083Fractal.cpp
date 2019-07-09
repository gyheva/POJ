#include<bits/stdc++.h>
using namespace std;
int a[1000][1000],m[10],n,i,j;
void dg(int k,int xl,int xr,int yl,int yr){
    if(k==1) {a[xl][yl]=1; return;}
    dg(k-1,xl,(xr-xl+1)/3+xl-1,yl,(yr-yl+1)/3+yl-1);//左上
    dg(k-1,xl,(xr-xl+1)/3+xl-1,2*(yr-yl+1)/3+yl,yr);//左下
    dg(k-1,(xr-xl+1)/3+xl,2*(xr-xl+1)/3+xl-1,(yr-yl+1)/3+yl,2*(yr-yl+1)/3+yl-1);//中间
    dg(k-1,2*(xr-xl+1)/3+xl,xr,yl,(yr-yl+1)/3+yl-1);//右上
    dg(k-1,2*(xr-xl+1)/3+xl,xr,2*(yr-yl+1)/3+yl,yr);//右下
}
int main(){
    m[0]=1;
    for(int i=1;i<=10;i++){
        m[i]=m[i-1]*3;
    }
    while(true){
        cin>>n;
        memset(a,0,sizeof(a));
        if(n==-1) break;
        dg(n,1,m[n-1],1,m[n-1]);
        for(int i=1;i<=m[n-1];i++){
            for(int j=1;j<=m[n-1];j++){
                if(a[i][j]) cout<<"X";
                else cout<<" ";
            }
            cout<<endl;
        }
        cout<<"-"<<endl;
    }
}
