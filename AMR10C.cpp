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
#include <list>
#include <stack>
using namespace std;
typedef long long ll;


int prime[169];

void pre(){
    
    bool vis[1001];
    for(int i=1;i<=1000;i++){vis[i]=false;}
    
    int cnt=0;
    for(int i=2;i<=1000;i++){
        
        if(vis[i]==true)continue;
        for(int j=2*i;j<=1000;j=j+i){
            
            vis[j]=true;
            
            
        }
        cnt++;
     
        
    }
    int t=1;
    
    for(int i=2;i<=1000;i++){
        
        if(vis[i]==false){prime[t]=i; t++;}
    }
    
}







int main(){
    
    pre();
   // cout<<prime[169];
    //cout<<prime[78498];
    
    int tc;
    scanf("%d",&tc);
    while(tc--){
    
    
    int n;
    scanf("%d",&n);
    
    int maxi=-1;
    for(int i=1;i<=168;i++){
        if(n==1)break;
        int pow=0;
        
        while(true){
            if(n==1)break;
            if(n%prime[i]==0){
                n/=prime[i];
                pow++;
                
            }
            else break;
            
        }
        
        
        maxi=max(maxi, pow);
    }
    
    //    if(maxi==0)maxi++;
    printf("%d\n",maxi);
    
    
    
    }
    }

/*
 
 
 1
 
 
 
 */

