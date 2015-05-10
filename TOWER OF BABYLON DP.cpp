
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
#include <algorithm>

using namespace std;



struct triple {
    
    int x,y,z;
};

struct compare{
    
    bool operator()(triple p,triple q){
        
        if(p.x<q.x)return true;
        else return false;
    }
    
    
}comp;


int main(){
    
    while(1){
        int n;
        cin>>n;
        if(n==0)break;
        
        triple cord[95];
        
        
        
        //step 1
        
        for(int i=0;i<n;i++){
            
            int in[3];      //x,y,z cordinates
            cin>>in[0]>>in[1]>>in[2];
            std::sort(in,in+3);
            
            
            cord[3*i].x=in[0];  cord[3*i].y=in[2];   cord[3*i].z=in[1];
            cord[3*i+1].x=in[0];  cord[3*i+1].y=in[1];   cord[3*i+1].z=in[2];
            
            
            cord[3*i+2].x=in[1];  cord[3*i+2].y=in[2];   cord[3*i+2].z=in[0];
            
            
        }
        
        sort(cord, cord+3*n,comp);
        
        
        
        
        
        
        int dp[90], maxdp;
        
        dp[0]=cord[0].z; maxdp=dp[0];
        
        for(int i=1;i<3*n;i++){
            
            dp[i]=cord[i].z;
            
            int xtemp=cord[i].x;
            int ytemp=cord[i].y;
            int maxi=0;
            for(int j=i-1;j>=0;j--){
                
                if(xtemp>cord[j].x && ytemp>cord[j].y)
                {//cout<<"yo";
                    maxi=max(dp[j], maxi);
                }
                
                
                
            }
            
            dp[i]+=maxi;         maxdp=max(maxdp, dp[i]);
            
            
        }
        
        
        cout<<maxdp<<endl;
        
    }
    
    
}