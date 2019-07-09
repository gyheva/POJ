#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n,i,id,k,j,sm,lg,num,med;
int main(){
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>id>>k;
        vector<int> ans;
        priority_queue<int> mini;
        priority_queue<int,vector<int>,greater<int> > maxi;
        cin>>num;
        med=num;
        ans.push_back(num);
        if(k>=2){
            cin>>num;
            if(med<num){
                mini.push(med);
                maxi.push(num);
            }
            else{
                mini.push(num);
                maxi.push(med);
            }
        }

        for(j=3;j<=k;j++){
            cin>>num;
            if(j%2==1){
                sm=mini.top();
                lg=maxi.top();
                if(num<sm){
                    mini.pop();
                    mini.push(num);
                    med=sm;
                }
                else if(num>lg){
                    maxi.pop();
                    maxi.push(num);
                    med=lg;
                }
                else med=num;
                ans.push_back(med);
            }

            else{
                if(num<med){
                    mini.push(num);
                    maxi.push(med);
                }
                else{
                    mini.push(med);
                    maxi.push(num);
                }
            }
        }
        cout<<id<<" "<<ans.size()<<endl;
        for(j=0;j<ans.size();j++){
            cout<<ans[j]<<" ";
            if((j+1)%10==0) cout<<endl;
        }
        cout<<endl;
    }
}
