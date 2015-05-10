
//  main.cpp


#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <queue>

using namespace std;

string input="";               //input string
int bracket_close[250];         //stores the index of the closing bracket for every ( bracket


//checks whether input is an operator or not
bool op(char a){
    
    if(a=='*' || a=='/' || a=='+' || a=='-')return true;
    else return false;
}






//finds main operator
char find_main_op(int start, int end){
    char ans='0';           //default value null
    int i=start;
    int flag=0;
    while(i<=end && flag==0){
        
        
        
        
        
        if(op(input[i])){if(input[i]=='+' || input[i]=='-'){flag=1;}     ans=input[i]; }
        
        
        else if(input[i]=='('){i=bracket_close[i];}
        i++;
    }
    
    
    
    return ans;    //upper two digits represents lmain_op_left
    
    //  return 0;
}

//ends




//return true when brackets can be removed
bool priority(char op_s, char main_op, char op_e){
    
    
    
    if(main_op=='+' || main_op=='-' ){
        if((op_s=='0' || op_s=='+') && (op_e=='0' || op_e=='+' || op_e=='-'))return true;
    }
    
    else if(main_op=='/' || main_op=='*' ){
        if(op_s=='*' || op_s=='0' || op_s=='+' || op_s=='-')return true;
        
    }
    
    else if(main_op=='0')return true;
    
    else {return false; }          //else return false
    
    return false;
    
}

//priority fnc ends


char main_op_left='0';
int temp;

int check(int start,int end,int* bci, char op_s, char op_e){                 //bci bracket close index
    
    main_op_left='0';
    
    //op_s starting operator before bracket
    //op_e ending operator after bracket
    
    for(int i=start;i<=end;i++){
        
        int jmp=0;
        int flag=0;
        
        if(input[i]=='('){
            if(op(input[bci[i]+1])&& i<=end)op_e=input[bci[i]+1];
            else op_e='0';                                 //null
            if(op(input[i-1]) && i>=start) op_s=input[i-1];
            else op_s='0';
            flag=1;
            
            jmp= check(i+1,bci[i]-1,bci,op_s,op_e);
            
            temp=find_main_op(i+1,bci[i]-1);
            if(temp=='0'){main_op_left='0';}
            else{
                main_op_left=temp;
            }
            if(priority(op_s, main_op_left, op_e)){
                
                input[i]=' '; input[bci[i]]=' ';
            }
            
            
            
        }
        
        if(flag)i=jmp;
    }
    
    return end+1;
}








int main(){
    
    int n;
    
    
    cin>>n;
    
    for(int i=0;i<n;i++){
        string in;
        cin>>in;
        
        input=in;       //input global variable no need to pass string in the function
        
        
        std::stack<int> bracket;
        
        
        //(a+b+(c+d))  bracket_close[]={10,x,x,x,x,8}
        
        
        int size1=in.length();       //length iof string;
        
        //calculation of bracket_close begins
        for(int i=0;i<size1;i++){
            if(in[i]=='(')bracket.push(i);
            else if(in[i]==')'){ bracket_close[bracket.top()]=i; bracket.pop();}
            
            
        }
        //calcuation of bracket_close ends
        
        
        check(0,size1,bracket_close,'0','0');
        
        
        //test case    (a+(b*c))
        //test case    (a*((b*c)+c))
        //test cases 8 (a+(b*c)) ((a+b)*c) (a*(b*c)) (a*(b/c)*d) ((a/(b/c))/d) ((x)) (a+b)-(c-d)-(e/f) (a+b)+(c-d)-(e+f)
        
        
        for(int i=0;i<in.length();i++){
            if(input[i]!=' '){cout<<input[i];}
            
            
        }
        cout<<endl;
        
    }    // testcases for loop ends
    // ((((((c))))))   1 ((a-(c-d*(-e))+(-f/(-g))+(-h*(g/i))+j*(-l)))
    
}