#include<bits/stdc++.h>
using namespace std;
struct p{
	long long wid,hei;
};
long long i,n,j,ans,sw,h,a[100001];
stack<p> rec;
int main(){
    while(true){
        ans=0;
        memset(a,0,sizeof(a));
        cin>>n;
        if(n==0) break;
        for(i=1;i<=n;i++) cin>>a[i];
        p temp;
        temp.hei=a[1];
        temp.wid=1;
        rec.push(temp);
        for(i=2;i<=n;i++){
            h=rec.top().hei;
            if(a[i]>h){
                temp.wid=1;
                temp.hei=a[i];
                rec.push(temp);
            }
            else{
                sw=0;
                h=rec.top().hei;
                while(h>=a[i]&&!rec.empty()){
                    sw+=rec.top().wid;
                    ans=max(ans,sw*rec.top().hei);
                    rec.pop();
                    if(!rec.empty()) h=rec.top().hei;
                }
                temp.wid=sw+1;
                temp.hei=a[i];
                rec.push(temp);
            }
        }
        sw=0;
        while(!rec.empty()){
            sw+=rec.top().wid;
            ans=max(ans,sw*rec.top().hei);
            rec.pop();
        }
        cout<<ans<<endl;
    }

}
