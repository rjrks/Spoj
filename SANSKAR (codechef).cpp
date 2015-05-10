//

//  Created by Rohan on 30/08/14.

//  Copyright (c) 2014 Rohan. All rights reserved.

//



#include <math.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <list>
#include <stack>
#include <algorithm>




using namespace std;
typedef long long ll;



bool visited[25]={false};
ll a[25];
ll sum;
bool fnd=false;





void dfs(vector<list<int> >& g, int i, ll tget, int n){
    
    if(visited[i] || fnd){return;}
    
    
    
    if(!fnd)visited[i]=true;
    sum+=a[i];
    
    if(sum==tget){fnd=true;sum=0; return;}
    else if(sum>tget){sum=sum-a[i]; visited[i]=false; return;}
    
    //stk.push(i);
    
    
    
    std::list<int>::iterator it;
    
    for(it=g[i].begin();it!=g[i].end();++it){if(i==n-1)return; dfs(g, *it, tget, n);}
    
    
    //   ll temp=stk.top();
    // stk.pop();
    
    sum=sum-a[i];
    if(!fnd)visited[i]=false;
    
    
    
}









int main(){
    
    int tc;
    scanf("%d",&tc);
    
    
    
    while(tc--){
        
        bool flg1=true;
        vector<list<int> >graph(25);
        
        
        int n;
        int k;
        
        int mod=0;
        
        scanf("%d",&n);
        scanf("%d",&k);
        ll sumt=0;
        
        
        
        
        for(int i=0;i<n;i++){
            scanf("%lld",&a[i]);
            sumt+=a[i];
            
            mod=(mod+a[i]%k)%k;
            
            
            if(a[i]!=0)flg1=false;  //if all inputs are zero return true
            
        }
        
        
        std::sort(a, a+n);
        
        int start=0;
        for(int i=0;i<n;i++)if(a[i]!=0){start=i;break;}
        
        if(n<k){printf("no \n"); continue;}
        else if(flg1){printf("yes \n"); continue;}
        else if(mod!=0){printf("no \n"); continue;}
        
        
        ll tget=sumt/k;
        
        for(int i=start;i<n-1;i++){
            
            for(int j=n-1;j>i;j--){
                
                if(j==i)continue;
                graph[i].push_back(j);
                
            }
        }
        
        
        fnd=false;
        //  std::list<int>::iterator it;
        
        int count=0;
        
        for(int i=start;i<n;i++){
            //   cout<<visited[i]<<endl;
            
            if(count>k)break;
            if(visited[i])continue;
            
            fnd=false;
            sum=0;
            dfs(graph,i,tget,n);
            
            
            if(!fnd)break;
            
            count++;
            
            
        }
        
        if(fnd && count==k)printf("yes \n");
        else printf("no \n");
        
        
        
        for(int i=0;i<n;i++)visited[i]=false;
        
        
    }
    
    
}
