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





int main(){
    
    int tc;
    scanf("%d",&tc);
    
    while(tc--){
    
     int p,m;
     scanf("%d",&p);
     scanf("%d",&m);
     int a[p+1];
     for(int i=1;i<=p;i++){
         scanf("%d",&a[i]);
     }
    
    int sum[p+1];
    sum[1]=a[1]; sum[0]=0;a[0]=0;
    for(int i=2;i<=p;i++){
        
        sum[i]=a[i]+sum[i-1];
    }
    
    int lptr=1,rptr=1;
    int ans=0;
    int maxi=0;
    while(lptr<=p && rptr<=p){
        
        if(lptr==rptr){
            
            if(a[lptr]<=m){
            
                if(maxi<1){
                    maxi=1;ans=a[lptr];
                }
                
                else if(maxi==1)ans=min(ans, a[lptr]);
        
                rptr++;
            }
            else {lptr++; rptr++;}
            continue;
        }
        
        if(sum[rptr]-sum[lptr-1]<=m){
            
            if(maxi<rptr-lptr+1){
            
                maxi=rptr-lptr+1;
                ans=sum[rptr]-sum[lptr-1];
                
            }
            
            else if(maxi==rptr-lptr+1){
                ans=min(ans, sum[rptr]-sum[lptr-1]);
            }
            
            
            rptr++;
        }
        else lptr++;
        
    }
    
    
    cout<<ans<<" "<<maxi<<endl;
}}

// 1 5 1 rrgrr
// 1 6 3 abcaab
// 5 3 rgggr
// 5 6 aaaav