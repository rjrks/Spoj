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
using namespace std;



int main(){
    
    long long num;
    cin>>num;
    if(num>1){
        long long  num1[60];
        long long num0[60];
        long long num10[60];
        
        for(int k=0;k<60;k++){num1[k]=0;num0[k]=0;num10[k]=0;}
        
        
        for(long long i=0;i<num;i++){
            
            long long in;
            cin>>in;
            for(int j=0;j<20;j++){
                int x=((in>>j)&1);
                if(x==1)num1[j]=1+num1[j];
                else num0[j]=1+num0[j];
            }
            
            
        }
        
        
        
        
        for(int k=0;k<20;k++)num10[k]=num1[k]*num0[k];
        
        long long out[60];
        
        
        
        for(int i=0;i<60;i++){
            
            long long temp;
            temp=num10[i];
            out[i]=temp&1;
            
            for(int k=i+1;k<60;k++){
                temp=temp>>1;
                num10[k]=(temp&1) + num10[k];
                
            }
            
        }
        
        long long ans=0;
        long long mult=1;
        for(int i=0;i<60;i++){
            
            ans=ans+mult*out[i];
            mult=mult*2;
            
        }
        cout<<ans;
        
    }
    else {
        long in;
        cin>>in;
        cout<<in;
    }
    
    
    
}