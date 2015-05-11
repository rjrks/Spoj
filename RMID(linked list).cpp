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
    
    
    std::list<int>lst;
    std::list<int>::iterator it;
    std::list<int>::iterator tail;
    std::list<int>::iterator dum;
    
    int cnt=0;
    int in;
    while(scanf("%d",&in)!=EOF){
        
        if(in!=-1 && in!=0){
            
            cnt++;
            
            if(lst.size()==0){
                lst.push_back(in);
                tail=lst.begin();
                ++tail;
            }
            else {
                
                lst.insert(tail, in);
            }
            
            
            if(cnt==1)it=lst.begin();
            else if(cnt%2!=0)++it;
            
            //dum=tail;
            //--dum;
            //cout<<"tail="<<*dum<<"  median="<<*it<<endl;
            
        }
        
        else if(in==-1){
            printf("%d",*it);
            printf("\n");
            cnt--;
            it=lst.erase(it);
            if(cnt%2==0)--it;
            //dum=tail;
            //--dum;
            //cout<<"tail="<<*dum<<"  median="<<*it<<endl;
            
        }
        
        
        else {
            cnt=0;
            tail=lst.begin();
            printf("\n");
        }
        
    }
    
}
