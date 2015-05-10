
//
//  Created by Rohan on 30/08/14.
//  Copyright (c) 2014 Rohan. All rights reserved.
//

#include <math.h>
#include <iostream>

#include <sstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;



int main(){
    
    int tc;
    cin>>tc;
    for(int i=0;i<tc;i++){
        int h,w;
        cin>>h>>w;
        
        int x[110][110];
        
        
        for(int i=0;i<h;i++){
            
            for(int j=0;j<w;j++){
                
                cin>>x[i][j];
                
            }
        }
        
        int dp[110][110];
        
        for(int i=0;i<w;i++)dp[0][i]=x[0][i];
        for(int i=0;i<h;i++)dp[i][w]=0;
        
        
        for(int i=1;i<h;i++){
            
            for(int j=0;j<w;j++){
                if(j>0)
                    dp[i][j]= x[i][j] + max(dp[i-1][j], max(dp[i-1][j-1], dp[i-1][j+1]));
                else dp[i][j]= x[i][j] + max(dp[i-1][j], dp[i-1][j+1]);
                
            }
        }
        
        
        int maxdp=0;
        for(int i=0;i<w;i++)maxdp=max(maxdp, dp[h-1][i]);
        
        
        cout<<maxdp<<endl;
    }
}