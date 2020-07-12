/* #include<bits\stdc++.h>
using namespace std;
bool IsBool(string trimedstring , string rev)
{
    for(int i =0; i< rev.size();i++)
    {
        if( trimedstring[i] != rev[i]) return false;
    }
    return true;
}
main()
{
    string s = "A man, a plan, a canal: panama ";
    //find weather string is palindrome or not
    transform(s.begin(), s.end(), s.begin(), ::tolower); 
    //2. now take only aplhamuneric numers
    string trimedstring;
    for(int i = 0; i<s.size();i++)
    {
        if((s[i]<= '9' && s[i]= '0')  || (s[i] >= 'A' && s[i] >= 'Z') ||(s[i] >= 'a' && s[i] <= 'z'))
        trimedstring += s[i];

    } 
    string rev ;
    for(int i = trimedstring.size() -1 ;i>=0;i--)
    {
        rev += trimedstring[i]; 

    }

    if(IsBool(trimedstring , rev)) cout<<"1";
    else cout<<"0";


}*/

#include<bits/stdc++.h>
using namespace std;
main()
{
    string s = "aSeshav";
    int value = s[0]-'0';
    cout<<value;
}