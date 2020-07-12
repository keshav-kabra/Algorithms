#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    int  index = 0 , n=0 , k=0;
    cout<<"enter the number of times to perform the operation";
    cin>>n;
    vector<string> v;
    stack<string> s;
    while(k<n)
    {
        string line ;
        cout<<"\nenter the task ";
        getline(cin,line);
        string firstword , lastword;
        cout<<"inpput line is "<<line<<endl;
        //find first space
        for(int i=0;i<line.length();i++)
        {
            if(line[i] ==' ') break; 
            firstword += line[i];
            index++;
        }
        for(int i=index+1;i<line.length();i++)
        {
            lastword += line[i];

        }
        int length_of_lastword = line.length() - index -1;
        if(firstword == "add") 
        {
            v.push_back(lastword);
        }
        else 
        {
            for(int i=0;i<v.size();i++)
            {
                string element = v[i];
                cout<<"element checking is "<<element<<"\n";
                cout<<"elements sub string is"<<element.substr(0,length_of_lastword -1)<<"\n";
                if(element.substr(0,length_of_lastword -1) == lastword) 
                s.push(element);
 
            }
            while(!s.empty())
            {
                cout<<s.top()<<"\t";
                s.pop();
            }

        }

        k++;  
    }

    

    return 0;
}
