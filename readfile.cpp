#include<bits/stdc++.h>
using namespace std;
int main()
{
    string information , information2;
    string word, line;
    //program for file handling
    ofstream output ;
    ifstream input;
    //open file
    input.open("test.txt");
    while(!input.eof())
    {
        input>>word;
        getline(input , line);
        information2 += "\n"+line; 
        information += "\n"+word;

    }
    cout<<information;
    cout<<"\n"<<information2;
    cout<<"working";
    return 0;
}