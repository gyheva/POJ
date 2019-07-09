#include<iostream>
#include<vector>
using namespace std;
long long a,b,i,ans,t,d,m;
typedef pair<long long,long long> pa;
vector<pa> que;
vector<pa>::iterator it;
long long po(long long a, long long b){
    long long ans=1;
    for(;b;b>>=1){
        if(b&1){
            ans*=a;
            ans%=9901;
        }
        a*=a;
        a%=9901;
    }
    return ans;
}
long long sum(long long p,long long c){
    if(c==0) return 1;
    if(c==1) return 1+p;
    long long num=1;
    if(c%2==1){
        num=(1+po(p,(c+1)/2))*sum(p,(c-1)/2);
    }
    else{
        num=(1+po(p,c/2))*sum(p,c/2-1)+po(p,c);
    }
    num%=9901;
    return num;
}
int main(){
    cin>>a>>b;
    t=1;
    for(i=2;a!=1;i++){
        m=0;
        while(a%i==0){
            m++;
            a/=i;
        }
        pa x;
        x.first=i;
        x.second=m;
        if(m!=0) que.push_back(x);
    }
    ans=1;
    for(it=que.begin();it!=que.end();it++){
        long long i=it->first,pw=it->second;
        ans*=sum(i,b*pw)%9901;
        ans%=9901;
        //cout<<i<<" "<<pw<<endl;
        //cout<<sum<<" "<<pp<<" "<<ans<<endl;
    }
    cout<<ans;
}
