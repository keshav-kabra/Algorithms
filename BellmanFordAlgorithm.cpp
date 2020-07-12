// program for implementing bellman ford algorithm

#include<iostream>
using std::cout , std::endl;
#define INFINITE 10000000;

struct edge
{
    int src;
    int weight;
    int des;
};
struct graph{
   int totalvertices;
   int totaledges;
   int edgeindex;
   edge *edges; 
};

graph* creategraph(int totalvertices , int totaledges)
{
    graph *g = new graph(); 
    g->totaledges = totaledges;
    g->totalvertices = totalvertices;
    g->edges = new edge[totaledges];  //we will use 0th index also
    g->edgeindex = -1;
    return g;
}

void addedge(graph *g , int src , int des , int weight)
{
    g->edges[++g->edgeindex].src = src; 
    g->edges[g->edgeindex].des = des;
    g->edges[g->edgeindex].weight = weight;
}

void printDistances(int *distance , int size)
{
   for(int i=1;i<size;i++)
   cout<<distance[i]<<endl;
}
void Bellmanford(graph *g , int src)
{
    int *dist = new int[g->totalvertices+1];

    //set every distance as infinite
    for(int i=1;i<g->totalvertices+1;i++)   //(1  ->  <6 ) runs for index 1 to 5
    dist[i] = INFINITE;

    dist[src] = 0;

    for(int i=1;i<g->totalvertices;i++) //(1 -> <5)  runs for index 1 to 4 i.e n-1
    {
        for(int j=0;j<=g->edgeindex;j++) 
        {
            //1.for every edge check the least distance
            int u = g->edges[j].src;
            int v = g->edges[j].des;
            int weight  = g->edges[j].weight;

            if(dist[u] + weight < dist[v])
            dist[v] = dist[u] + weight;

        }
    }

    for(int j=0;j<=g->edgeindex;j++)
    {
        int u = g->edges[j].src;
            int v = g->edges[j].des;
            int weight  = g->edges[j].weight;

            if(dist[u] + weight < dist[v])
            {
                cout<<"this contains a negative edge cycle ...!!";
                return;
            }
    }


    printDistances(dist , g->totalvertices+1);
}

void printgraph(graph *g)
{
    for(int i=1;i<=g->edgeindex;i++)
    {
        cout<<"src "<<g->edges[i].src<<" des"<<g->edges[i].des<<" weight"<<g->edges[i].weight<<endl;
    }
}
main()
{

    //lets see our graph..!!
    //1.create first ..
    graph *g = creategraph(5,6);
    addedge(g, 1, 2, 2);
    addedge(g, 1, 5, 4);
    addedge(g, 2, 5, 1);
    addedge(g, 2, 3, 2);
    addedge(g, 3, 4, 2);
    addedge(g, 5, 4, 4);

    printgraph(g);

    
    Bellmanford(g , 3);
    
}