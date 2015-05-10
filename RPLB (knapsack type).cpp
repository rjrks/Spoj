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
#include <math.h>
#include <map>
#include <list>
#include <stack>


//no. of prime less than 10^6 are 78498
using namespace std;







int main(){
    
    int tc;
    cin>>tc;
    for(int l=1;l<=tc;l++){
        
        int n,k;
        
        cin>>n>>k;
        
        int dp[n+1][k+1];
        
        int a[n+1];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<=k;i++){
            if(a[0]<=i)dp[0][i]=a[0];
            else dp[0][i]=0;
            
            
        }
        
        
        for(int i=1;i<n;i++){
            
            for(int j=1;j<=k;j++){
                
                if(a[i]>j)dp[i][j]=dp[i-1][j];
                else if(a[i]<j){
                    if(i<2)dp[i][j]=max(dp[i-1][j],a[i]);
                    else dp[i][j]=max(dp[i-1][j],a[i]+dp[i-2][j-a[i]]);
                }
                else dp[i][j]=a[i];
                
                
            }
        }
        
        
        cout<<"Scenario #"<<l<<": "<<dp[n-1][k]<<endl;
        // 6 10 1 3  4 5  1  4
        
    }
}
