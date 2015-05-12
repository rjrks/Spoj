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


string ip()
{
    string i="";
    int temp=getchar_unlocked();
    while(temp<'0'||temp>'9')
        temp=getchar_unlocked();
    while(temp>='0'&&temp<='9')
    {
        i+=(char)temp;
        temp=getchar_unlocked();
    }
    return i;
}


int main()
{
    
    int tc;
    scanf("%d",&tc);
    
    while(tc--){

    int n,i;
    string m,j;
    
    scanf("%d",&n);
    m=ip();
    scanf("%d",&i);
    j=ip();
    
    int mt=m[m.length()-1]-'0';
    int jt=j[j.length()-1]-'0';
        
        if(n%2==0 || mt%2==0){
            printf("Impossible.\n");
            continue;
        }
        
        if((i%2==0 && jt%2==0) || (i%2!=0 && jt%2!=0))printf("Possible.\n");
        else  printf("Impossible.\n");
    
    }
    
    
}