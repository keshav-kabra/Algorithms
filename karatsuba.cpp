#include<cmath>
#include<iostream>
#include<cstring>
using namespace std;
string add(string num1 , string num2)
{
    int carry=0;
    int sum = 0;
    string answer ;
    
    int length = max(num1.size() , num2.size());
    while(num1.size()<length) num1.insert(0,"0");
    while(num2.size()<length) num2.insert(0,"0");
    //perform add
    for(int i = length-1; i >= 0; i--)
    {
        sum = (num1[i]-'0')+(num2[i]-'0')+carry;
        carry = sum/10;
        answer.insert(0,to_string( (sum%10)));
    }
    if(carry)  answer.insert(0 ,to_string(carry));
   
    return answer;

}
string subtract(string num1 , string num2)
{
    int length = max(num1.size() ,num2.size()); //return total number of characters in the string
    while(num1.size()<length) num1.insert(0,"0");
    while(num2.size()<length) num2.insert(0,"0");
    int borrow = 0, firstnumber=0;
    string answer;
    //subtract form end index 
    for(int i= length -1 ; i>=0;i--)
    {
        if (borrow == 1) 
        {
            firstnumber  = (num1[i]-'0') - 1;
            borrow = 0; 
        }
        else firstnumber = num1[i]-'0';
        if(firstnumber< num2[i]-'0') 
        {

            firstnumber = firstnumber + 10;
            borrow = 1;
            
        }
        int sub = firstnumber - (num2[i]-'0');
        answer.insert(0 , to_string(sub));

    }
    return answer;
}
string multi(string x , string y )

{
    int length = max(x.size() , y.size());
    while(x.size() < length) x.insert(0, "0");    
    while(y.size() < length) y.insert(0, "0");
    if(length==1) 
    {
        return to_string((x[0]-'0')*(y[0]-'0'));
    }
    string a ,b  ,c ,d ;
    a = x.substr(0, length/2);
    b =  x.substr(length/2, length - (length/2) );
    c = y.substr(0, length/2);
    d =  y.substr(length/2, length - (length/2));
    //find no of zeros to add
    string zeros = "1"; 
    
    string ac = (multi(a,c))  ; 
    // string ad =  (multi(a,d)) ;
    // string bc =  (multi(b,c)) ;
    string bd =  multi(b,d);
    string add1 =add(a, b);
    string add2 =add(c, d);
    string md = multi(add1 , add2); 
    string ad_bc = subtract( md , add(ac, bd));
    // cout<<"\n"<<ac<<" "<<bd<<" "<<ad_bc<<" "<<md<<" "<<add1<<" "<<add2;
    for(int i = 0; i < 2*(length-length/2);i++) ac.append("0");
    for(int i = 0; i < length-length/2; i++)
    {
        // ad.append("0");
        // bc.append("0");
        ad_bc.append("0");
    }

    //now we need to create a function for addition 
    string answer =     add(add(ac,bd), ad_bc);
    return answer;

    
    

}
main()
{
    
    string answer = multi("1234", "5678");
    cout<<"\n"<<answer;
}
