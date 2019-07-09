//status: TLE
//solution: sort by st time + use priority to maintain ×îºóÖµ
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdlib>
#include<string.h>
using namespace std;
long int i,j,minino,curno,p[60000],n,ans[60000],cur,coc;
struct cow{
    long int st,en,k;
}a[60000];
bool cmp(cow x, cow y){
    if(x.en!=y.en) return x.en<y.en;
    else return x.st<y.st;
}
int main(){
    while(cin>>n){
    for(i=1;i<=n;i++) cin>>a[i].st>>a[i].en,a[i].k=i;
    sort(a+1,a+n+1,cmp);
    //for(i=1;i<=n;i++) cout<<a[i].st<<" "<<a[i].en<<endl;
    memset(p,0,sizeof(p));
    curno=1;
    minino=1;
    p[1]=0;
    for(i=1;i<=n;i++){
        cur=0;
        coc=0;
        for(j=1;j<curno;j++){
            if(p[j]<a[i].st&&p[j]>cur){
                cur=p[j];
                coc=j;
            }
        }
        if(coc!=0){
            ans[a[i].k]=coc;
            p[coc]=a[i].en;
        }
        else{
            ans[a[i].k]=curno;
            p[curno]=a[i].en;
            curno++;
        }
    }
    cout<<curno-1<<endl;
    for(i=1;i<=n;i++) cout<<ans[i]<<endl;
    }
}
