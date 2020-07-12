// program for implementing bellman ford algorithm

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
using std::cout , std::endl;
#define INFINITE 9000000000000000000; //long long takes 19 digit max keyword

struct edge
{
    long long src;
    long long weight;
    long long des;
};
struct graph{
   long long totalvertices;
   long long totaledges;
   long long edgeindex;
   edge *edges; 
};

graph* creategraph(long long totalvertices , long long totaledges)
{
    graph *g = new graph(); 
    g->totaledges = totaledges;
    g->totalvertices = totalvertices;
    g->edges = new edge[totaledges];  //we will use 0th index also
    g->edgeindex = -1;
    return g;
}

void addedge(graph *g , long long src , long long des , long long weight)
{
    g->edges[++g->edgeindex].src = src; 
    g->edges[g->edgeindex].des = des;
    g->edges[g->edgeindex].weight = weight;
}

bool bellmonford_checker(graph *g , long long src)
{
    long long *dist = new long long[g->totalvertices+1];

    //set every distance as infinite
    for(long long i=1;i<g->totalvertices+1;i++)   //(1  ->  <6 ) runs for index 1 to 5
    dist[i] = INFINITE;

    dist[src] = 0;

    for(long long i=1;i<g->totalvertices;i++) //(1 -> <5)  runs for index 1 to 4 i.e n-1
    {
        for(long long j=0;j<=g->edgeindex;j++) 
        {
            //1.for every edge check the least distance
            long long u = g->edges[j].src;
            long long v = g->edges[j].des;
            long long weight  = g->edges[j].weight;

            if(dist[u] + weight < dist[v])
            dist[v] = dist[u] + weight;

        }
    }

    for(long long j=0;j<=g->edgeindex;j++)
    {
        long long u = g->edges[j].src;
            long long v = g->edges[j].des;
            long long weight  = g->edges[j].weight;

            if(dist[u] + weight < dist[v])
            {
                cout<<"this contains a negative edge cycle ...!!";
                return true;
            }
    }

    return false;


}

void printDistances(long long *distance , long long size)
{
   for(long long i=1;i<size;i++)
   cout<<distance[i]<<endl;
}
void Bellmanford(graph *g , long long src , long long **distance)
{
    long long *dist = new long long[g->totalvertices+1];

    //set every distance as infinite
    for(long long i=1;i<g->totalvertices+1;i++)   //(1  ->  <6 ) runs for index 1 to 5
    dist[i] = INFINITE;

    dist[src] = 0;

    for(long long i=1;i<g->totalvertices;i++) //(1 -> <5)  runs for index 1 to 4 i.e n-1
    {
        for(long long j=0;j<=g->edgeindex;j++) 
        {
            //1.for every edge check the least distance
            long long u = g->edges[j].src;
            long long v = g->edges[j].des;
            long long weight  = g->edges[j].weight;

            if(dist[u] + weight < dist[v])
            dist[v] = dist[u] + weight;

        }
    }

    for(long long j=0;j<=g->edgeindex;j++)
    {
        long long u = g->edges[j].src;
            long long v = g->edges[j].des;
            long long weight  = g->edges[j].weight;

            if(dist[u] + weight < dist[v])
            {
                cout<<"this contains a negative edge cycle ...!!";
                return;
            }
    }


    // printDistances(dist , g->totalvertices+1);

    for(int i=1;i<g->totalvertices+1;i++)
    distance[src][i] = dist[i];
}

void printgraph(graph *g)
{
    for(long long i=1;i<=g->edgeindex;i++)
    {
        cout<<"src "<<g->edges[i].src<<" des"<<g->edges[i].des<<" weight"<<g->edges[i].weight<<endl;
    }
}


void readgraph(graph *g)
{
    string line;
    ifstream input;
    input.open("g3.txt");
    bool run = true;

    while(getline(input , line))
    {
        if(run) run = false;
        else
        {
            stringstream ss(line);
            long long src , des , weight;
            ss>>src;
            ss>>des;
            ss>>weight;
            addedge(g ,src , des , weight );

        }
    }
    input.close();

}
main()
{
    long long shortestdistance = INFINITE;


    long long totalvertices , totaledges;
    string line;
    ifstream input;
    input.open("g3.txt");
    bool run = true;
    while(run)
    {
        getline(input , line);
        stringstream ss(line);
        ss>>totalvertices;
        ss>>totaledges;
        run = false;
    }
    input.close();

    //lets see our graph..!!
    //1.create first ..
    // graph *g = creategraph(5,6);
    // addedge(g, 1, 2, 2);
    // addedge(g, 1, 5, 4);
    // addedge(g, 2, 5, 1);
    // addedge(g, 2, 3, 2);
    // addedge(g, 3, 4, 2);
    // addedge(g, 5, 4, 4);

    graph *g = creategraph(totalvertices , totaledges);

    // create 2-d array dynamically
    long long **distance = new long long*[g->totalvertices+1];
    for(int i =0;i <g->totalvertices+1;i++)
    distance[i] = new long long[g->totalvertices+1]; 


    //read graph 
    readgraph(g);

    // printgraph(g);

    //check for negative cycles
    if(bellmonford_checker(g , 1))
    cout<<" yes negative cycle "<<endl;
    else 
    {
        cout<<"no negative cycle.."<<endl;

        for(long long src = 1; src<g->totalvertices+1; src++)   
        Bellmanford(g , src , distance);
    

        for(int i=1;i<g->totalvertices+1;i++)
        {
            for(int j=1;j<g->totalvertices+1;j++)
            {
                if(shortestdistance > distance[i][j])
                shortestdistance = distance[i][j];
            }
            
        }
        cout<<"shortest distance is "<<shortestdistance<<endl;
    }
}