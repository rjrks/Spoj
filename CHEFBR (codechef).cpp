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



ll max(ll a, ll b){
    if(a>b)return a;
    else return b;
    
    
    
}






int main(){
    
    
    ll const mod=1000000007;
    
    int n;
    scanf("%d",&n);
    
    ll a[102];
    
    std::map<ll, list<int> >mymap;
    
    
    for(int i=1;i<=n;i++){scanf("%lld",&a[i]); if(a[i]<0){ mymap[a[i]].push_back(i);  }       }
    
    
    ll dp[102][102];
    
    for(int i=0;i<=n;i++){
        
        for(int j=0;j<i &&j<n;j++){
            
            dp[i][j]=0;
        }
    }
    
    dp[0][0]=0;
    
    
    
    for(int j=1;j<=n;j++){
        
        for(int i=1;i<=n && i<=j;i++){
            
            if(i==j){dp[i][i]=1; continue;}
            
            if(a[j]<0){dp[i][j]=dp[i][j-1];continue;}
            
            // here end>0
            
            if(mymap.find(-a[j])==mymap.end()){dp[i][j]=dp[i][j-1];continue;}
            
            std::list<int>::iterator it;
            
            dp[i][j]=0;
            
            for(it=mymap[-a[j]].begin();it!=mymap[-a[j]].end();++it)
            {
                int ind=*it;
                if(ind>j || ind<i)continue;
                
                dp[i][j]=(dp[i][j]+(max(dp[ind+1][j-1],1)*max(1,dp[i][ind-1]))%mod)%mod;
            }
            dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
            
            
        }
        
        
    }
    if(dp[1][n]<0)dp[1][n]+=mod;
    printf("%lld",dp[1][n]);
    printf("\n");
    
    
}

/*
 7
 6 -3 1 2 -3  -2 3
 
 6
 -1 2 3 1 -1 1
 
 
 */

