

#include <iostream>
using namespace std;
#include <math.h>       /* sqrt */


#include <math.h>
#include <stack>          // std::stack
#include <queue>
#include <string>
#include <stdlib.h>



int main(){
    int n;
    cin>>n;
    
    for(int t=0;t<n;t++){
        string in,s;
        
        cin>>in;
        s=in;
        int length=in.size();
        bool carry=true;
        int car=1;
        
        
        int i,j;
        
        // _ _ _ _ _ _ _ | _ _ _ _ _ _ _
        //        <----i   j--->
        
        if(length%2==0){i=length/2-1; j=length/2;}      //i and j are strarting points
        else {i=length/2;j=i;}
        
        while(j<length){
            
            if(in[i]<in[j]){carry=true; break;}
            
            else if(in[i]>in[j]){carry=false; break;}
            
            i--;j++;
        }
        
        if(length%2==0){i=length/2-1; j=length/2;}      //i and j are strarting points
        else {i=length/2;j=i;}
        
        //adding carry
        if(carry){
            
            while(i>=0 && car!=0){
                int temp1,temp2;
                temp1=in[i]-'0';
                
                temp2=(temp1+car)%10;
                in[i]=temp2+'0';
                
                car=(temp1+car)/10;
                
                i--;
                
            }
        }
        
        
        //checking carry is there in msb and printing it if present
        i=0;
        if(car && carry){cout<<car; i=1;}       //carry is present and is equal to 1
        
        //cout<<i;
        
        //printing the palindrome
        int mid;
        if(length%2==0) mid=length/2;
        else mid=length/2 +1;
        
        for(;i<length;i++){
            
            if(i>=mid)cout<<in[length-1-i];
            else cout<<in[i];
        }
        if(car && carry)cout<<car;   //printing the last carry
        
        
        cout<<endl;
    }
    
    
}


