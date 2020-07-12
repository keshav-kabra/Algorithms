//program for 0/1 knapsack problem using dynamic programming
// total weight = 8
//total ojects = 4
#include<iostream>
#include<fstream>
#include<sstream>
#include<bits/stdc++.h>
using namespace std;

void readfile(int *profit , int *weight)
{
    int index = 0;
    bool first = true;
    ifstream input ;
    input.open("_knapsack1.txt");
    string line;
    while(getline(input , line))
    {
        if(first) first = false;
        else
        {
            stringstream ss(line);
            ss>>profit[++index];
            ss>>weight[index];        
        }
    }

}
main()
{
    //define two arrays
    // int weight[5] = {0,2,3,4,5};
    // int profit[5]= {0,1,2,5,6};
    int totalweight=0 , totalobjects = 0;
    ifstream input;
    string line;
    input.open("_knapsack1.txt");
    getline(input , line);
    stringstream ss(line);

    ss>>totalweight;
    ss>>totalobjects;
    input.close();
    int *weight = new int[totalobjects +1];
    int *profit = new int[totalobjects +1];

    //we start from 1 so initialize the 0 index as 0
    profit[0] = weight[0] = 0; 
    readfile(profit , weight);

  
    int **k = new int*[totalobjects+1];
    for(int i=0; i<totalobjects+1;i++)
    {
        k[i] = new int[totalweight+1];
    }

    //write algorithm
    for(int i=0;i<totalobjects+1;i++)
    {
        for(int w=0;w<totalweight +1;w++)
        {
            if(i==0 || w ==0)
            {
                k[i][w] = 0;  
            }
            else if (weight[i] <= w) //weight of ith object is less than allowed weight thn
            k[i][w] = max( k[i-1][w] , profit[i] + k[i-1][w -weight[i]]);

            else
            k[i][w] = k[i-1][w];
            

        }
    }
    // for(int i=0;i<totalobjects+1;i++)
    // {
    //     for(int j=0;j<totalweight+1;j++)
    //     { 
    //         cout<<k[i][j]<<"\t";
    //     }
    //     cout<<endl;
    // }
    cout<<k[totalobjects][totalweight];
}