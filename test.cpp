//all pairs shortes path problem...
/* 	1. run bellmanford n times (mn*n)
	2. use floyd warshol algorith(n^3)
	3. use jhonson algorithm (mnlogn)

	we will use bellman ford for n times and then floyd warshol 

	..jhonson algorithm after we do dijktras algorithm properly with heaps
 */

#include<bits/stdc++.h>
using namespace std;
struct edge
{
	long long src;
	long long des;
	long long weight;
};
struct graph
{
	edge *edges;
	int edgeindex;
	long long totalvertex;
	long long totaledges; 

};

graph* creategraph(long long totalvertices , long long totaledges)
{
	graph *g = new graph();
	g->edgeindex = -1;
	g->edges = new edge[totaledges];
	g->totalvertex = totalvertices;
	return g;

}

void addedge(graph *g , long long src , long long des , long long weight)
{
	++g->edgeindex;  //increment the value of index
	g->edges[g->edgeindex].src = src;
	g->edges[g->edgeindex].des = des; 
	g->edges[g->edgeindex].weight = weight;
}

void printgraph(graph g)
{
	for(int i=0;i<=g.edgeindex;i++)
	{
		cout<<"src "<<g.edges[i].src<<" des"<<g.edges[i].des<<" weight"<<g.edges[i].weight<<endl;
	}
}

void Bellmonfordcheaker(graph *g ,long long src )
{
	long long *distance = new long long[g->totalvertex+1];
	for(int i=1;i<g->totalvertex+1;i++)
	distance[i] = LLONG_MAX;

	

	distance[src] = 0;

	for(int i=1;i<g->totalvertex;i++)
	{
		for(int j =0 ;j<=g->edgeindex;j++)
		{
			long long u = g->edges[j].src;
			long long v = g->edges[j].des;
			long long weight = g->edges[j].weight;

			if(distance[v] > distance[u] + weight)
			distance[v] = distance[u]+weight;
		}
	}

	for(int j = 0;j<=g->edgeindex;j++)
	{
		long long u = g->edges[j].src;
			long long v = g->edges[j].des;
			long long weight = g->edges[j].weight;

			if(distance[v] > distance[u] + weight)
			{
				cout<<"graph has negative edge cycle";
				return;
			}
				
	}

	for(int i = 1;i<g->totalvertex+1;i++)
	{
		cout<<distance[i]<<endl;
	}



}

void all_pair_shortest_path(graph *g)
{
	//define two d array 
	// long long **distance = new long long*[g->totalvertex+1];  // total vertex = 5 
	// for(int i = 0;i<g->totalvertex+1;i++) //0 - 5
	// {
	// 		distance[i] = new long long[g->totalvertex+1];
	// }

	long long distance[6][6];


	//initialize every thing to infinite
	for(int i=1;i<g->totalvertex+1;i++)
	{

		for(int j= 1;j<g->totalvertex+1;j++)
		{
			distance[i][j] = LLONG_MAX;
		}
	}


	

	//initialize every src of src to 0
	for(int i=1;i<g->totalvertex+1;i++)
	distance[i][i] = 0;	


	//print the 2-d array
	for(int i=1;i<g->totalvertex+1;i++)
	{

		for(int j= 1;j<g->totalvertex+1;j++)
		{
			cout<<distance[i][j]<<"\t";
		}
		cout<<endl;
	}

	for(int src = 1 ; src < g->totalvertex+1 ; src++)
	{
		cout<<"value of src "<<src<<endl;
		for(int i = 1;i<g->totalvertex;i++)
		{
			for(int j = 0;j<= g->edgeindex;j++)
			{
				long long u = g->edges[j].src;
				long long v = g->edges[j].des;
				long long weight = g->edges[j].weight;

				if( distance[src][u]+ weight < distance[src][v] )
				{
					cout<<"true for vertex v "<<distance[src][v]<<" and vertex u "<<distance[src][u]<<"  and weight "<<weight<< endl;
					distance[src][v] =  distance[src][u]+ weight;
				}
			}
		}

		//print the 2-d array
	for(int i=1;i<g->totalvertex+1;i++)
	{

		for(int j= 1;j<g->totalvertex+1;j++)
		{
			cout<<distance[i][j]<<"\t";
		}
		cout<<endl;
	}
		
		
	}

	//print the 2-d array
	for(int i=1;i<g->totalvertex+1;i++)
	{

		for(int j= 1;j<g->totalvertex+1;j++)
		{
			cout<<distance[i][j]<<"\t";
		}
		cout<<endl;
	}
	
}

int main()
{
	graph *g = creategraph(5,6);
    addedge(g, 1, 2, 2);
	addedge(g , 1,5,4);
    addedge(g, 2, 5, 1);
    addedge(g, 2, 3, 2);
    addedge(g, 3, 4, 2);
    addedge(g, 5, 4, 4);
    // printgraph(*g);
	// Bellmonfordcheaker(g, 1);
	
	all_pair_shortest_path(g);
	return 0;
}
