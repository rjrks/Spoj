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
    
    int n;
    while(1){
        
        scanf("%d",&n);
        if(n==0)break;
        int c1=1;
        std::stack<int>stk;
        
        for(int i=1;i<=n;i++){
            
            int curr;
            scanf("%d",&curr);
            
            stk.push(curr);
            
            if(curr==c1){c1++; stk.pop();}
            
            while(!stk.empty()){
                
                if(stk.top()==c1){
                    c1++;stk.pop();
                }
                else break;
            }
            
        }
        
         if(stk.empty())printf("yes\n");
         else printf("no\n");
    }
}