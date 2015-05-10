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
#include <stack>
#include <list>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;



int main(){
    int tc;
    cin>>tc;
    
    while(tc--){
        
        int n,k;
        cin>>n>>k;
        
        int cost[k+1];
        int dp[k+1];
        int pack[k+1];
        
        for(int i=1;i<=k;i++){
            cin>>cost[i];
            if(cost[i]==-1)
            {    dp[i]=1000000;
                pack[i]=+1000000;
                cost[i]=1000000;
            }
        }
        
        dp[0]=0;pack[0]=0;
        
        for(int i=1;i<k+1;i++){
            int mini=100000;
            for(int j=0;j<i;j++){
                
                if((pack[j]+1)<=n && (dp[j]+cost[i-j])<mini){
                    pack[i]=pack[j]+1;
                    dp[i]=dp[j]+cost[i-j];
                    mini=dp[i];
                }
            }
        }
        
        if(dp[k]>100000)cout<<-1;
        else cout<<dp[k];
        
        cout<<endl;
    }}
