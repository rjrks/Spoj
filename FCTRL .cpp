//
//  main.cpp
//  amazon
//
//  Created by Rohan on 30/08/14.
//  Copyright (c) 2014 Rohan. All rights reserved.
//


#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <queue>

using namespace std;

int fact[200];

int  mul(int num, int count){
    
    int carry[200];
    
    
    for(int i=0; i<=(2+count);i++)carry[i]=0;
    
    for(int i=0;i<count;i++){
        
        int temp=fact[i]*num;
        fact[i]=temp%10;                    //units digit
        int temp1=temp%100;
        carry[i+1]+=(temp1-fact[i])/10;             //tens digit  added to carry
        carry[i+2]+=temp/100;                   //hundres digit
        
        
    }
    int count_temp=1;
    
    for(int i=0;i<=(2+count);i++)
    {
        
        int temp=(fact[i]+carry[i]);
        fact[i]=temp%10;
        
        carry[i+1]+=(temp-fact[i])/10;              //carry can be of more than one digit
        
        if(fact[i]!=0)count_temp=i;              //calculAtes the no. of digits of the no.
    }
    return count_temp+1;;
}








int main(){
    
    int test_cases;
    cin>>test_cases;
    
    for(int i=0;i<test_cases;i++){
        int n;
        cin>>n;
        for(int i=0;i<200;i++){fact[i]=0;}
        
        int count;
        
        
        fact[0]=1; count=1;
        
        
        
        for(int i=1;i<=n;i++){
            
            int temp;
            temp=mul(i, count);
            count=temp;
            
        }
        
        for(int i=count-1;i>=0;i--)cout<<fact[i];
        cout<<endl;
    }
    //test_cases loop ends
    
    
}