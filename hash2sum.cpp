#include<bits/stdc++.h>
using namespace std;
#define MAX_SLOT 524287

struct chain_node
{
    long long value;
    chain_node *next;
};
long long hashfunction(long long key)
{
    long long index = 0;
    key = key /10000;
    if(key < 0) key *= (-1);
    index = key % MAX_SLOT;
    return index;
}
void chaining(chain_node **arr , long long num , long long hashindex)
{
    //create new node
    chain_node *newnode = new chain_node();
    newnode ->value = num;
    newnode->next = arr[hashindex];
    arr[hashindex] = newnode;


}

int search(chain_node *temp , long long num_to_find , long long num)
{
    while(temp != NULL)
    {
        if(temp ->value == num_to_find && temp ->value != num)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;

}
main()
{
    cout<<"working";
    long long static count=0;
    // chain_node *a[MAX_SLOT];
    // chain_node *b[MAX_SLOT];

    chain_node **a = (chain_node**)malloc(MAX_SLOT * sizeof(chain_node));
    chain_node **b = (chain_node**)malloc(MAX_SLOT * sizeof(chain_node));
    for(int i=0;i<MAX_SLOT;i++) a[i] = b[i] = NULL;

    long long num= 0;
    //read file
    ifstream input , input2;
    input.open("prob-2sum.txt");
    cout<<"running";
    while(!input.eof())
    {
        input>>num;
        long long hashindex = hashfunction(num);
        if(num>0) chaining (a , num , hashindex);

        else chaining(b , num , hashindex);

    }
    cout<<"file reading done ... !!"<<endl;
    input.close();
    int newcount = 0;
    for(int t = -10000;t<=10000;t++)
    {
        cout<<"value of t "<<t<<endl;
        input2.open("prob-2sum.txt");
        while(!input2.eof())
        {
            input2>>num;
            long long num_to_find = t - num;
            long long hashindex = hashfunction(num_to_find);
            chain_node *temp = NULL;
            if(num_to_find > 0)
            {
                if(a[hashindex] == NULL) continue;
                temp = a[hashindex];
            }
            else
            {
                if(b[hashindex] == NULL) continue; 
                temp = b[hashindex];
            }
            count += search(temp , num_to_find , num);
            if(count > newcount)
            {
                cout<<"count found"<<endl;
                newcount = count ;
                break;
            } 
            
        }
        input2.close();

    }
    

    cout<<"count "<<count<<endl;
            
}



 //print the positive arr; 

    // for(int i = 0 ;i<10 ;i++)
    // {
    //     chain_node *temp = a[i];
    //     cout<<"index value "<<i<<" -- >" ;
    //     while(temp != NULL)
    //     {
    //         cout<<temp->value<<"\t";
    //         temp = temp->next;
    //     }
    //     cout<<endl;
    // }





    // for(int t = 465;t<= 500;t++)
    // {
    //     cout<<"value of t "<<t<<endl;
    //     int run = 1;
    //     input2.open("prob-2sum.txt");

    //     while(!input2.eof())
    //     {
    //         input2>>num;
    //         long long num_to_find = t - num;
    //         long long hashindex = hashfunction(num_to_find);
    //         if(num_to_find > 0)
    //         {
    //             if(a[hashindex] == NULL) continue;
    //             else
    //             {
    //                 chain_node *temp = a[hashindex];
    //                 while(temp!= NULL)
    //                 {
    //                     if(temp->value == num_to_find &&temp->value != num)
    //                     {
    //                         cout<<"comming here";
    //                         count++;
    //                         run = 0;
    //                         break;
    //                     }
    //                     temp= temp->next;
    //                 }
    //             }
    //         }
    //         else
    //         {
    //             if(b[hashindex] == NULL) continue;
    //             else
    //             {
    //                 chain_node *temp = b[hashindex];
    //                 while(temp != NULL)
    //                 {
    //                     if(temp->value == num_to_find && temp->value != num) 
    //                     {
    //                         cout<<"comming here";
    //                         count++;
    //                         run = 0;
    //                         break;
    //                     }
    //                     temp = temp->next;
    //                 }
    //             }
            
    //         }
    //         if(run == 0)
    //         {
    //             cout<<"never commin here";
    //             break;
    //         } 
        
            
    //     }
    //     input2.close();
        
    // }