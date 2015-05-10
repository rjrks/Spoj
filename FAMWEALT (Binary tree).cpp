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
    int x,y;
    float w;
    
    scanf("%d",&x);
    scanf("%d",&y);
    scanf("%f",&w);

    int i=x;
    double w1=w;
    
    
    while(i!=1){
        
        int t=i/2;
        
        if(i%2==0 && t%2!=0)w1=2*w1;        //p=M C=F
        else if(i%2==0 && t%2==0)w1=2*w1;   //P=M C=M
        else if(i%2!=0 && t%2!=0)w1=4*w1;   //P=F C=F
        else if(i%2!=0 && t%2==0)w1=2*w1;   //P=F C=M
        
        i=t;
        
    }
    
    i=y;
    float ca=1;
    while(i!=1){
        
        int t=i/2;
        
        if(i%2==0 && t%2!=0)ca=2*ca;
        else if(i%2==0 && t%2==0)ca=2*ca;
        else if(i%2!=0 && t%2!=0)ca=4*ca;
        else if(i%2!=0 && t%2==0)ca=2*ca;
        
        i=t;
    }
    
  
    printf("%f\n",w1/ca);

    }
}

/*
 5961 3974

 7778 164
 2 1
 100 100
 0 0



*/