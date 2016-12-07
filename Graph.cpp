#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>

#include "Graph.hpp"

using namespace std;

Graph::Graph()
{
}

Graph::~Graph()
{
}

void Graph::addEdge(string v1, string v2, int dist)
{
	// add code here
  int i = 0;
  while(vertices[i].name != v1){
    i++;
  }
  int j = 0;
  while(vertices[j].name != v2){
    j++;
  }
  adjVertex* tmpadj = new adjVertex;
  tmpadj->v = &vertices[j];
  tmpadj->distance = dist;
  vertices[i].adj.push_back(*tmpadj);
}

void Graph::addVertex(string n)
{
	// add code here
  vertex* tmp = new vertex;
  tmp->name = n;
  tmp->ID = -1;
  tmp->district = -1;
  tmp->visited = false;
  vertices.push_back(*tmp);
}

void Graph::displayEdges()
{
    for(unsigned i = 0; i < vertices.size(); i++)
	{
        cout << vertices[i].district << ":" <<vertices[i].name << "-->";
        for(unsigned j = 0; j < vertices[i].adj.size(); j++)
		{
            cout << vertices[i].adj[j].v->name;
			cout << " (" << vertices[i].adj[j].distance << " miles)"; 
            if (j != vertices[i].adj.size()-1)
                cout << "***";
        }
        cout << endl;
    }
}

void Graph::assignDistricts()
{
    // Starting district numbers at 1
    int distID = 1;
    

    // For each of the vertices
    for(unsigned i = 0; i < vertices.size(); i++)
    {
        // Only consider a vertex that has not been assigned a district.
        if (vertices[i].district == -1)
        {
            // Run breadth first traversal and assign each node in the network to this district.
            BFTraversalLabel(vertices[i].name,distID);
            distID++;
        }
    }
}

void Graph::BFTraversalLabel(std::string startingCity, int distID)
{
  queue<vertex*> q;
  // Label all as unvisited.
  for(unsigned i = 0; i < vertices.size(); i++)
  {
    vertices[i].visited = false;
  }
  // Find the starting node and enqueue it.
  for(unsigned i = 0; i < vertices.size(); i++)
  {
      if (vertices[i].name == startingCity)
      {
          // set current vertex to be visited.
		      // add code here
        q.push(&vertices[i]);
      }
  }
 // Now do the rest of the search.
 while (q.empty() != true)
 {
      vertex * u = q.front();		// get the next one from the queue
      q.pop();		
      u->visited = true;
      u->district = distID;
				// remove that one from the queue
     for(unsigned i = 0; i<u->adj.size();i++){
        if(!(u->adj[i].v->visited)){
          q.push(u->adj[i].v);
        }
     }
 }

}

vertex * Graph::findVertex(std::string name)
	 // add code here
{
    for(unsigned i = 0; i < vertices.size(); i++)
    {
        if (vertices[i].name == name){
          return &vertices[i];
        }
    }
    return NULL;
}
