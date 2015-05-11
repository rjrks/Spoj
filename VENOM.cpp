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
#include <map>
#include <set>
#include <algorithm>




using namespace std;





int main()
{
    int tc;
    scanf("%d",&tc);
    
    while(tc--){
    
    int h,p,a;
    
    scanf("%d",&h);
    scanf("%d",&p);
    scanf("%d",&a);
    
    
    if(h<p){
        printf("1\n");
        continue;
    }
        
    int t;
    
    int A=p;
    int B=4*p-4*a;
    int C=4*a+3*p-8*h;
        
    t= (-B + sqrt(B*B-4.0*A*C))/(2.0*A);  //discriminant >0 always as a<p
    
        if(t%2==0)t++;
        
       
        int b1=A*t*t+B*t+C;
        int b2=A*(t+2)*(t+2)+B*(t+2)+C;
        int b3=A*(t-2)*(t-2)+B*(t-2)+C;
        
        
        if(b3>=0)printf("%d",t-2);
        else if(b1>=0)printf("%d",t);
        else if(b2>=0)printf("%d",t+2);
        else printf("%d",t+4);
        
        printf("\n");
        
    
    }
    
}