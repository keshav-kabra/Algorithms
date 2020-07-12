// program for finding scc in a directed graph
#include<bits/stdc++.h>
using namespace std;
long long t =0 ;
long long s=0 ;
struct vertex
{
    long long label;
    long long finishing_time;
    vector<long long> edges;
    vector<long long> rev_edges;
    // vector<long long> squashed;
};
struct edge
{
    long long start;
    long long end;

};
struct graph
{
    long long vertex_count;
    vector<vertex> vertices = vector<vertex>();
    vector<edge> edges;
};
graph g , rev_g;
stack<long long> new_stack;
bool discovered_vertex[900000];
bool visited_global[900000];


void Read_edges()
{
    //set discovered vertices to be false
    for(int i=0;i<900000;i++) discovered_vertex[i] = false;
     string line;
     g.vertex_count =0;
    //for determining the size of the vertex and edges 
    int max = 0;
    
    //now read into graph from the file
    ifstream input;
    input.open("test.txt");
    while(getline(input , line))
    {
        
        //if vertex already not exist
        vertex v ;
        int vertexnum = 0 , edgenum = 0;
        
        stringstream ss(line);
        ss>>vertexnum;

        int exist = 0;
        v.label = vertexnum;
        if(v.label > max)  //check if that index
        {
                max = v.label;
                g.vertices.resize(max+1);
                
        }
                //add at v.label position
        if(discovered_vertex[v.label] == false) 
        {
            discovered_vertex[v.label] = true;
            g.vertices.at(v.label) = v;
            g.vertex_count++;
        }

            
        //push the edge into respective vertex;
        ss>>edgenum;
        g.vertices[vertexnum].edges.push_back(edgenum);
        }
}

// bool *visited_global = (bool*)malloc((g.vertex_count)*sizeof(bool));
void dfs_traversal(long long vertex)
{
    //write a recursive dfs traversal function
    visited_global[vertex] = true;
    for(long long i =0 ;i<g.vertices[vertex].edges.size();i++)
    {
        long long vertex_edge = g.vertices[vertex].edges[i];
        if(visited_global[vertex_edge] == false)
        {
            visited_global[vertex_edge] = true;
            dfs_traversal(vertex_edge);
        }
    }
    t++;
    new_stack.push(vertex);
    g.vertices[vertex].finishing_time = t;
    
    
    
}

void dfs_loop()
{
    for(long long i=0;i<g.vertex_count;i++) visited_global[i] = false;
    t=0;
    for(long long i=g.vertex_count;i>0;i--)
    {
        long long vertex = g.vertices[i].label;
        if(visited_global[vertex] == false)
        {
            visited_global[vertex] = true;
            dfs_traversal(vertex);
        }
    }
    
}

void reverse_edges()
{
    //1.reverse edges
    for(long long i=1;i<=g.vertex_count;i++)
    {
        long long vertex = g.vertices[i].label;
        
        for(long long j=0;j<g.vertices[i].edges.size();j++)
        {
            long long cur_edge = g.vertices[i].edges[j];
            g.vertices[cur_edge].rev_edges.push_back(vertex);

        }


    }
    
}
void dfs_traversal_two(long long vertex)
{
    //write a recursive dfs traversal function
    visited_global[vertex] = true;
    for(long long i =0 ;i<g.vertices[vertex].rev_edges.size();i++)
    {
        
        long long vertex_edge = g.vertices[vertex].rev_edges[i];
        if(visited_global[vertex_edge] == false)
        {
            s++;
            visited_global[vertex_edge] = true;
            dfs_traversal_two(vertex_edge);
        }
    }
    
}

void compute_scc()
{
    long long count = 0;
    
    for(int i=1;i<=g.vertex_count;i++) visited_global[i] = false;
    while(!new_stack.empty())
    {
        long long vertex = new_stack.top();new_stack.pop();
        if(visited_global[vertex] == false)
        {
            s++;
            visited_global[vertex] = true;

            dfs_traversal_two(vertex);
            count++;
            cout<<"\nsize of "<<count<<" scc is "<<s;
            
        }
        s=0;

    }
    cout<<"\nthe graph has "<<count<<" strongly connected components";

}

void find_scc()
{
    Read_edges();
    dfs_loop() ;   // dfs_traversal(g , g.vertices[1].label );
    reverse_edges();
    compute_scc();
}

int main()
{
    find_scc();
    return 0;
}















