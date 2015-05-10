///

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








int main(){
    
    int n;
    scanf("%d",&n);
    
    int f[n+2];
    int sum[n+2];
    int dp[n+2];
    
    
    sum[0]=0; sum[n+1]=0;
    
    for(int i=1;i<=n;i++){
        scanf("%d",&f[i]);
        sum[i]=sum[i-1]+f[i];
        dp[i]=0;
    }
    
    
    
    int m;
    scanf("%d",&m);
    
    int b[m+2],d[m+2];
    
    
    for(int i=1;i<=m;i++){
        scanf("%d",&b[i]);
        scanf("%d",&d[i]);
        
        
    }
    
    
    
    int me[m+2];
    me[0]=0;
    
    int cnt=1;
    
    
    for(int i=1;i<=n;i++){
        
        if(cnt>m)break;
        
        if(i<b[cnt])continue;
        
        if(i==b[cnt] && i-d[cnt]>=me[cnt-1]){me[cnt]=i; cnt++;continue;}
        
        if(i-d[cnt]>=me[cnt-1]){me[cnt]=i;cnt++;continue;}
        
        
        
    }
    
    
    
    dp[0]=0;
    int sc=1;
    
    for(int i=me[1];i<=n;i++){
        
        
        if(i==me[sc]){dp[i]=dp[i-d[sc]]-sum[i-d[sc]]+sum[i];}
        else if(i>me[sc] && i-d[sc]+1<=b[sc]){ dp[i]=max(dp[i-1],dp[i-d[sc]]-sum[i-d[sc]]+sum[i]);}
        else if(i>me[sc])dp[i]=dp[i-1];
        
        if(i+1==me[sc+1])sc++;
        
    }
    
    
    printf("%d",dp[n]);
    printf("\n");
    
    
}


/*
 
 
 11
 1 1 6 4 4 1 1 3 10 1 1
 3
 2 5
 6 3
 10 2
 
 */

