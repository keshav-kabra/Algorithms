#include<iostream>
#include<unordered_map>
#include<map>
#include<list>
#include<cstring>
using namespace std;

void print_graph(unordered_map<string, list<string>>& vertex )
{
    for(auto itr= vertex.begin();itr!=vertex.end();itr++)
    {
        cout<<"vertex "<<itr->first<<"--->";
        for(auto itr1 = itr->second.begin();itr1!=itr->second.end();itr1++)
        {
            cout<<*(itr1)<<"\t";
        }
        cout<<"\n";
    }
}

string new_person(unordered_map<string , list<string>>& vertex )
{
    string person;
    cout<<"enter the name of new person"<<endl;
    cin>>person;
    cout<<"enter any three friends "<<endl;
    for(int i=0;i<3;i++)  
    {
        string cofriend; 
        cin>>cofriend;
        vertex[person].push_back(cofriend);
    }
    return person;
}

unordered_map<string , list<string>> read_map(unordered_map<string , list<string>>& vertex )
{
    int persons =0 , cofriends =0;
    cout<<"enter the number of friends"<<endl;
    cin>>persons;
    for(int i=0;i<persons;i++)
    {
        string person;
        cout<<"enter the name of the person"<<endl;
        cin>>person;
        cout<<"enter the co friends of the person"<<endl;
        cin>>cofriends;
        for(int j=0;j<cofriends;j++)
        {
            string  cofriend;
            cout<<"enter "<<i+1<<"  cofriend "<<endl;
            cin>>cofriend;
            vertex[person].push_back(cofriend);
        }
    }
    return vertex;
}
map<string , int> friend_suggestor(unordered_map<string ,list<string>>& vertex , string person , map<string , int>& priority)
{

    for(auto itr = vertex[person].begin() ; itr != vertex[person].end();itr++)
    {
        // cout<<*itr<<"\t";
        string cofriend = *itr;
        priority[cofriend]++;
        // now create a map and when we find a string increase its hash value and finally
        for(auto itr1 = vertex[cofriend].begin();itr1 != vertex[cofriend].end();itr1++)
        {
            string co_cofriend = *itr1;
            // cout<<"co_co frined "<<*itr1<<"\t";
            priority[co_cofriend]++;
            
        }
        cout<<"\n";

        
    }
    return priority;
}
void print_suggested_friends(map<string , int>& priority)
{
    cout<<"this function is called";
    auto itr = priority.begin();
    for(;itr != priority.end();itr++)
    {
        cout<<itr->first<<" \t"<<itr->second<<"\n";
        
    }
}
int main()
{
    unordered_map<string, list<string>> vertex;
    map<string , int > priority;
    vertex = read_map(vertex);
    print_graph(vertex);
    string person = new_person(vertex);
    priority = friend_suggestor(vertex , person , priority);
    print_suggested_friends(priority);



}