#include<iostream>
#include<bits/stdc++.h>
using namespace std;
main()
{
    int n=0 ;
    cout<<" \nno of times to perform ";
    cin>>n;
    vector<string> s;
    cin.ignore();
    for(int i=0;i<n;i++)
    {

        string line , firstword , secondword;
        int index= 0  , arr_index = -1;
        cout<<"enter the string of task";
        getline(cin,line);

        for(int i=0;i<line.length();i++)
        {
            if(line[i] == ' ') break;
            firstword += line[i];
            index++; 
            
        }
        int length_of_lastword = line.length() - index - 1;
        secondword = line.substr(index+1 , length_of_lastword);
        cout<<"first word is "<<firstword<<endl;
        if(firstword == "add") 
        {
            s.push_back(secondword);
            
        } 

        
        else if(firstword == "find")
        {
            
            for(int i =0;i<=s.size();i++)
            {
                
                string element = s[i];
                if(element.substr(0,length_of_lastword) == secondword) 
                cout<<element<<"\t";


            }
            

        }
        else
        {
            cout<<"wrong choice entered";
            break;
        }
        



    }
}