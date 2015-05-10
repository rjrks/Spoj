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



bool primecheck(long long k){
    long long temp=sqrt(k);
    if(k==2)return true;
    if(k==1)return false;
    for(long long i=2;i<=temp;i++){
        if(k%i==0)return false;
    }
    
    return true;
}


int main(){
    
    for(int i=0;i<10;i++){
        
        int k[101];
        int n[101];
        int t[101];
        int diff[101];
        for(int j=0;j<101;j++){k[j]=0;n[j]=0;t[j]=0;diff[j]=0;}
        
        string in1, in2;
        cin>>in1>>in2;
        int l1=in1.length();
        int l2=in2.length();
        for(int i=0;i<in1.length();i++){
            t[i]=in1[l1-i-1]-'0';
        }
        for(int i=0;i<in2.length();i++){
            diff[i]=in2[l2-1-i]-'0';
        }
        
        // INPUT COMPLETE ****************
        
        
        for(int i=0;i<l1;i++){
            if(t[i]>=diff[i])n[i]=t[i]-diff[i];
            else{
                t[i+1]--;
                n[i]=t[i]+10-diff[i];
            }
        }
        int nstart=0;
        
        for(int i=l1;i>=0;i--){
            if(n[i]!=0){nstart=i; break;}
            
        }
        
        //division by 2
        for(int i=nstart;i>=0;i--){
            
            
            if(n[i]%2==0)n[i]=n[i]/2;
            
            else {
                n[i]=n[i]/2;
                n[i-1]=10+n[i-1];
            }
        }
        
        for(int i=nstart;i>=0;i--){
            if(n[i]!=0){nstart=i; break;}
            
        }
        
        
        
        
        int index=max(l1,nstart+1)+1;
        
        
        for(int i=0;i<index;i++){
            if((n[i]+diff[i]+k[i])<10)k[i]+=n[i]+diff[i];
            
            else {
                k[i+1]++;
                k[i]=(k[i]+n[i]+diff[i])%10;
                
            }
        }
        
        int kstart;
        for(int i=index;i>=0;i--){
            if(k[i]!=0){kstart=i; break;}
            
        }
        
        
        
        for(int i=kstart;i>=0;i--)cout<<k[i];
        cout<<endl;
        for(int i=nstart;i>=0;i--)cout<<n[i];
        cout<<endl;
        
        
    }
    
    
    
}