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


bool comp(const std::pair<ll, ll>& n1, const std::pair<ll, ll>& n2){
    return n1.first>n2.first;
}




int main(){
    
    
    
    int tc;
    scanf("%d",&tc);
    
    while(tc--){
    
        std::pair<ll, ll>mypair[10001];

        
    int n;
    scanf("%d",&n);
    
    
    
    for(int i=0;i<n;i++){
    ll x,y;
    
        
        scanf("%lld",&x);
        scanf("%lld",&y);
        
        mypair[i].first=y-x;
         mypair[i].second=min(x,y);
        
        
        
    }
    
    sort(mypair, mypair+n, comp);
    
    ll ans=0;
    
    for(int i=0;i<n;i=i+2){
        
        ans=ans^mypair[i].second;
        
        
        
    }

    
    if(ans==0)printf("No");
    else printf("Yes");
    
    printf("\n");
    
        
    }
}

/*
 
 TESTCASES
 
 3
 5
 1 0
 1 2
 2 5
 4 2
 4 4

 5
 101 0
 10 2
 60 530
 412 20
 422 48
 
 6
 1 0
 10 2
 6 53
 4 20
 402 41
 80 23
 
 

 
 
 */



