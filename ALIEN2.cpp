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
#include <cmath>



using namespace std;



int main(){
    
    
    int n,k;
    cin>>n>>k;
    
    //station 1 --> A
    //station 2---> B
    
    int p[3][n+1];
    
    for(int i=1;i<=2;i++){
        for(int j=1;j<=n;j++){
            
            cin>>p[i][j];
        }
    }
    
    
    int dp[3][n+1];
    
    dp[1][0]=0;
    dp[2][0]=0;
    
    int index=n;
    for(int i=1;i<=n;i++){
        
        
        dp[1][i]=min(dp[1][i-1]+p[1][i],dp[2][i-1]+p[2][i]+p[1][i]);
        
        dp[2][i]=min(dp[2][i-1]+p[2][i],dp[1][i-1]+p[1][i]+p[2][i]);
        
        
        if(dp[1][i]>k && dp[2][i]>k){index=i-1;break;}
        
    }
    
    
    
    cout<<index<<" "<<min(dp[1][index],dp[2][index])<<endl;
    
    
    
    
}

