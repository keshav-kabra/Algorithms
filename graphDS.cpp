//we want to create a graph data structure here
#include<bits/stdc++.h>
using namespace std;
struct vertex
{
    int label;
    vector<int> edges;
    // vector<int> squashed;
};
struct edge
{
    int start;
    int end;

};
struct graph
{
    int vertex_count;
    vector<vertex> vertices = vector<vertex>();
    vector<edge> edges;
};
graph g ;
void print(graph g )
{
    //frirst print all the vertices and then in the inner loop print the edges
    // for(vector<vertex>::iterator i =g.vertices.begin();i<g.vertices.end() ;i++)
    // {

    //     cout<<i->label<<"-->";
    //     for(vector<int>::iterator j = i->edges.begin();j<i->edges.end();j++)
    //     {
    //         cout<<*j<<"\t";
    //     }
    //     cout<<"\n";
    // }
    for(int i =1;i<g.vertices.size();i++)
    {
        cout<<g.vertices[i].label<<"-->";
        for(int j=0;j<g.vertices[i].edges.size();j++)
        {
            cout<<g.vertices[i].edges[j]<<"\t";
        }
        cout<<"\n";
    }
}
void read_graph()
{

    string line;
    int vertexnum ;
    //create object of the class
     g.vertex_count =0;
    //for determining the size of the vertex and edges 
    int maxVertex=0;
    //now read into graph from the file
    ifstream input;
    input.open("test.txt");
    while(getline(input , line))
    {
        
        vertex v;
        stringstream ss(line);
        ss>>vertexnum;
        v.label = vertexnum;
        int edgenum=0;
        while(ss>>edgenum)
        {
            v.edges.push_back(edgenum);
            
        }
        // g.vertices.push_back(v);
        if(v.label > maxVertex) 
        {
            maxVertex = v.label;
            g.vertices.resize(maxVertex+1);
            
        }
        g.vertices.at(v.label) = v;
        g.vertex_count++;


    }
    

}


//write  a function for bfs and dfs traversal
int* Bfs_traversal(int first_vertex , graph g)
{
    int *l = (int*)malloc((g.vertex_count)*sizeof(int));
    bool visited[g.vertex_count];
    for(int i=0;i<g.vertex_count;i++) visited[g.vertices[i].label] = false;
    queue<int> q;
    //push first variable in the queue
    q.push(first_vertex);
    visited[first_vertex] = true;
    while(!q.empty())
    {
        int poped_element = q.front();q.pop();

        // cout<<poped_element<<"\t";
        l[poped_element] = poped_element; 
        for(int i=0;i< g.vertices[poped_element].edges.size();i++) 
        {
            int vertex_edge = g.vertices[poped_element].edges[i];
            if(visited[vertex_edge] == false)
            {
                q.push(vertex_edge);
                
                visited[vertex_edge] = true;

            }

        }


        
         

    }  
    return l;  

}

void graph_connectivity(graph g)
{
    bool visited[g.vertex_count];
    for(int i=1;i<g.vertex_count;i++) visited[i] = false;
    int count=0;
    
    //run loop for i=0 to n and inside loop
    for(int i =1; i<=g.vertex_count;i++)
    {
        if(visited[i] == false)
        {
            visited[i] = true;
            int *l = Bfs_traversal(g.vertices[i].label , g);
            for(int i=1;i<=g.vertex_count;i++)   if(l[i] > 0) visited[i] = true;       
            count++;
        }
    }
    cout<<"\ngraph is divided into "<<count<<" parts";
}
void dfsutil(graph g , bool visited[] , int first_vertex)
{
    visited[first_vertex] = true;
    cout<<first_vertex<<"\t";
    for(int i =0 ;i<g.vertices[first_vertex].edges.size();i++)
    {
        int vertex_edge = g.vertices[first_vertex].edges[i];
        if(visited[vertex_edge] == false)
        {
            visited[vertex_edge] = true;
            dfsutil(g , visited , vertex_edge);
        }
    }
    return;

}

void dfs_traversal(graph g ,int first_vertex)
{
    //write a recursive dfs traversal function
    bool visited[g.vertex_count];
    cout<<"vertices:";
    for(int i=0;i<g.vertex_count;i++) visited[g.vertices[i].label] = false;
    dfsutil( g , visited , first_vertex);
}

int main()
{
    
    read_graph();
    // print(g);
    // Bfs_traversal(g.vertices[1].label , g);
    // graph_connectivity(g);
    dfs_traversal(g , g.vertices[1].label );

    return 0;
}



















// if(edgenum>vertexnum)
            // {
            //     edge e;
            //     e.start = vertexnum;
            //     e.end = edgenum;
            //     g.edges.push_back(e);

            // }