#include <iostream>
#include <climits>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

#include "vertex.cpp"

using namespace std;

class Graph
{
    private:
    
        // Variable that tells when a graph is directed or undirected
        bool directed;
        
        // Stores all of the vertices associated with this graph as a list
        vector<Vertex*> vertices;
        
        /*_________________________________________________________________________________________________________________________________//
    	 *
    	 *													GET_VERTEX METHOD
    	 *
    	 * _______________________________________________________________________________________________________________________________
    	 *
    	 *														PARAMETERS: 
    	 *												Char: label_to_search_for
    	 *
    	 * _______________________________________________________________________________________________________________________________
    	 *
    	 *													   FUNCTIONALITY:
     	 *						
    	 *
    	 *________________________________________________________________________________________________________________________________*/
    
        // Method to return a POINTER to a specific vertex if it exists in the graph
        Vertex* getVertex(char label)
        {
            
            // While i is less than the size of the vector
            for (int i = 0; i < vertices.size(); i++)
            {
                
                // if the label in this location is the label we are looking for
                if (vertices[i]->getLabel() == label)
                {
                    
                    // return that label
                    return vertices[i];
                }
            }
            // Else, the label was not found
            return nullptr;
        }
        
        /*_________________________________________________________________________________________________________________________________//
    	 *
    	 *													 CLEAR_MARKS METHOD
    	 *
    	 * _______________________________________________________________________________________________________________________________
    	 *
    	 *														PARAMETERS: 
    	 *													       VOID	
    	 *
    	 * _______________________________________________________________________________________________________________________________
    	 *
    	 *													   FUNCTIONALITY:
     	 *					    Iterates through all vertices in graph to remove all marks from each individual NODE
    	 *
    	 *________________________________________________________________________________________________________________________________*/
    
        void clearMarks()
        {
            
            // Iterate through all vertices of the graph
            for (int i = 0; i < vertices.size(); i++)
            {
                
                // Clear the marks of the current NODE
                vertices[i]->clearMark();
            }
        }
        
        /*_________________________________________________________________________________________________________________________________//
    	 *
    	 *										dfs_HELPER METHOD (DEPTH_FIRST_SEARCH_HELPER)
    	 *
    	 * _______________________________________________________________________________________________________________________________
    	 *
    	 *														PARAMETERS: 
    	 *												Vertex pointer: Node_you_came_from
    	 *                                              Vertex pointer: Node_you_wanna_go_to
    	 *
    	 * _______________________________________________________________________________________________________________________________
    	 *
    	 *													   FUNCTIONALITY:
     	 *	"Helps" depth first search. Travels as far through the graph as it can, printing the path to a node the first time it reaches that node
    	 *
    	 *________________________________________________________________________________________________________________________________*/
    
        void dfsHelper(Vertex* from, Vertex* to)
        {
            
            // If to points to a node, print the node and its number of neighbors
            if (to)
            {
                cout << to->getLabel() << endl;
                cout << to->getNumNeighbors() << endl;
            }
            
            // If from points to a node, print the node and the node it is connected to
            if (from)
            {
                cout << from->getLabel() << " - " << to->getLabel() << endl;
            }
            
            // Set to as marked because it has already been visited once before
            to->setMark();
            
            // Visit all neighbors of to
            for (int i = 0; i < to->getNumNeighbors(); i++)
            {
                
                // Look at the i-th neighbor of the current node pointed to by to
                Vertex* neighbor = to->getNeighbor(i);
                
                // If that neighbor is not marked, call this method recursively by passing to as arg1 and its i-th neighbor as arg2
                if (!neighbor->isMarked()) 
                {
                    dfsHelper(to, neighbor);
                }
            }
        }
        
        /*_________________________________________________________________________________________________________________________________//
    	 *
    	 *										TOP_SORT_HELPER METHOD (Topological sort helper)
    	 *
    	 * _______________________________________________________________________________________________________________________________
    	 *
    	 *														PARAMETERS: 
    	 *										    Vertex Pointer: Vertex_to_go_to
    	 *
    	 * _______________________________________________________________________________________________________________________________
    	 *
    	 *													   FUNCTIONALITY:
     	 *						
    	 *
    	 *________________________________________________________________________________________________________________________________*/
    
        void topSortHelper(Vertex* to)
        {
            // Set the node as marked
            to->setMark();
            
            // While that node has neighbors
            for (int i = 0; i < to->getNumNeighbors(); i++)
            {
                // Look at the current (i-th) neighbor
                Vertex* neighbor = to->getNeighbor(i);
                
                // If that neighbor has not been visited before
                if (!neighbor->isMarked())
                {
                    // Go to that neighbor
                    topSortHelper(neighbor);
                }
            }
            
            // If it made it here, print the node that got here
            cout << to->getLabel() << " ";
        }

    public:
    
        /*_________________________________________________________________________________________________________________________________//
    	 *
    	 *													DIRECTED CONSTRUCTOR
    	 *
    	 * _______________________________________________________________________________________________________________________________
    	 *
    	 *														PARAMETERS: 
    	 *												BOOL: IS_THIS_GRAPH_DIRECTED
    	 *
    	 * _______________________________________________________________________________________________________________________________
    	 *
    	 *													   FUNCTIONALITY:
     	 *						Given a boolean parameter, a graph is initialized as directed (1) or undirected (0)
    	 *
    	 *________________________________________________________________________________________________________________________________*/
    	 
        Graph(bool directed)
        {
            this->directed = directed;
        }
    
        /*_________________________________________________________________________________________________________________________________//
    	 *
    	 *													ADD_VERTEX METHOD
    	 *
    	 * _______________________________________________________________________________________________________________________________
    	 *
    	 *														PARAMETERS: 
    	 *													Char: label_to_add
    	 *
    	 * _______________________________________________________________________________________________________________________________
    	 *
    	 *													   FUNCTIONALITY:
     	 *		Given a label to add to the graph, if a vertex does not already exist with the given label, add a new vertex to the graph
    	 *
    	 *________________________________________________________________________________________________________________________________*/
    	 
        bool addVertex(char label)
        {
            
            // If the label already exists, don't add this label
            if (getVertex(label))
            {
                return false;
            }
            
            // Otherwise, create a new vertex using the given label
            Vertex* newV = new Vertex(label);
            
            // Add the vertex to the end of the vector
            vertices.push_back(newV);
            
            // The process succeeded in adding a new NODE. Return true to show this
            return true;
        }
        
        /*_________________________________________________________________________________________________________________________________//
    	 *
    	 *													  ADD_EDGE METHOD 1
    	 *
    	 * _______________________________________________________________________________________________________________________________
    	 *
    	 *														PARAMETERS: 
    	 *												Char: label_of_first_node
    	 *                                              Char: label_of_second_node
    	 *
    	 * _______________________________________________________________________________________________________________________________
    	 *
    	 *													   FUNCTIONALITY:
     	 *	Given the labels of two nodes, create an edge between those nodes with a weight of 1 (directivity depends on BOOL DIRECTED)
    	 *
    	 *________________________________________________________________________________________________________________________________*/
    
        bool addEdge(char label1, char label2)
        {
            
            // Find the vertex containing label one
            Vertex* v1 = getVertex(label1);
            
            // Find the vertex containing label two
            Vertex* v2 = getVertex(label2);
            
            // If either of the vertexes does not exist, an edge cannot be added. Return false
            if (!v1 || !v2)
            {  
                return false;
            }
            
            // Create a new edge between the first label and the second label with a default weight of 1
            v1->addNeighbor(v2);
            
            // If that graph is not directed, this needs to be done the other way as well for an undirected graph
            if (!directed) {
                
                // Add the edge going in the opposite direction
                v2->addNeighbor(v1);
            }
            
            // It made it here successfully, so a vertex was added. Return true to show this
            return true;
        }
        
        /*_________________________________________________________________________________________________________________________________//
    	 *
    	 *													  ADD_EDGE METHOD 2
    	 *
    	 * _______________________________________________________________________________________________________________________________
    	 *
    	 *														PARAMETERS: 
    	 *												Char: label_of_first_node
    	 *                                              Char: label_of_second_node
    	 *                                           Integer: weight_of_the_edge
    	 *
    	 * _______________________________________________________________________________________________________________________________
    	 *
    	 *													   FUNCTIONALITY:
     	 *	Given the labels of two nodes, create an edge between those nodes with a specified weight (directivity depends on BOOL DIRECTED)
    	 *
    	 *________________________________________________________________________________________________________________________________*/
    
        bool addEdge(char label1, char label2, int edgeWeight)
        {
            // Find the vertex containing label one
            Vertex* v1 = getVertex(label1);
            
            // Find the vertex containing label two
            Vertex* v2 = getVertex(label2);
            
            // If either of the vertexes does not exist, an edge cannot be added. Return false
            if (!v1 || !v2)
            {  
                return false;
            }
            
            // Create an edge between the first label and the second label with the specified weight
            v1->addNeighbor(v2, edgeWeight);
            
            // If the graph is undirected, this must be done once again but in the opposite direction
            if (!directed) {
                
                // Create an edge between the second label and the first label with the specified weight
                v2->addNeighbor(v1, edgeWeight);
            }
            
            // An edge was successfully added if it made it here. Return true to show this
            return true;
        }
        
        /*_________________________________________________________________________________________________________________________________//
    	 *
    	 *											  dfs METHOD (Depth First Search)
    	 *
    	 * _______________________________________________________________________________________________________________________________
    	 *
    	 *														PARAMETERS: 
    	 *														   VOID
    	 *
    	 * _______________________________________________________________________________________________________________________________
    	 *
    	 *													   FUNCTIONALITY:
     	 *	Depth first search: Travels as far through the graph as it can, printing the path to a node the first time it reaches that node
     	 *  Note that for the above description: an edge from one node to the other is only printed once
    	 *
    	 *________________________________________________________________________________________________________________________________*/
    
        void dfs()
        {
            
            // In case marks haven't been cleared for some reason, clear them
            clearMarks();
            
            // Iterate through all vertices in the graph
            for (int i = 0; i < vertices.size(); i++)
            {
                // If a vertice is not marked already marked, use dfsHelper to try and travel to other nodes
                if (!vertices[i]->isMarked())
                {
                    // Travel to other nodes in the specified order
                    dfsHelper(nullptr, vertices[i]);
                }
            }
            
            // Clear marks after finishing
            clearMarks();
        }
        
        /*_________________________________________________________________________________________________________________________________//
    	 *
    	 *												 TOPOLOGICAL_SORT METHOD
    	 *
    	 * _______________________________________________________________________________________________________________________________
    	 *
    	 *														PARAMETERS: 
    	 *												Char: label_to_start_from		
    	 *
    	 * _______________________________________________________________________________________________________________________________
    	 *
    	 *													   FUNCTIONALITY:
     	 *						Travel through edges for as long as possible, then print them out in a recursive manor
    	 *
    	 *________________________________________________________________________________________________________________________________*/
    
        void topologicalSort(char label)
        {
            // Ensure that marks are cleared when starting this method
            clearMarks();
            
            // Use the helper to perform this method
            topSortHelper(getVertex(label));
            
            // Print a new line
            cout << endl;
            
            // Ensure that marks are cleared
            clearMarks();
        }
        
        /*_________________________________________________________________________________________________________________________________//
    	 *
    	 *												bfs METHOD (Breadth First Search)
    	 *
    	 * _______________________________________________________________________________________________________________________________
    	 *
    	 *														PARAMETERS: 
    	 *														   VOID
    	 *
    	 * _______________________________________________________________________________________________________________________________
    	 *
    	 *													   FUNCTIONALITY:
     	 *			Breadth first search: find as many paths to different nodes as possible before going to another node to do the same
     	 *          Note that for the above description: an edge from one node to the other is only printed once
    	 *
    	 *________________________________________________________________________________________________________________________________*/
    
        void bfs()
        {
            // Clear marks as a safety measure
            clearMarks();
            
            // Create a queue to store vertices
            queue<Vertex*> q;
            
            // Add the first vertice to the queue
            q.push(vertices[0]);
            
            // Set that vertice as visited (marked)
            vertices[0]->setMark();
            
            // While that queue is not empty, iterate through its edges
            while (!q.empty()) {
                
                // Retrieve the vertice at the front of the queue
                Vertex* v = q.front();
                
                // Pop that vertice out of the queue to get rid of it
                q.pop();
                
                // Print the name of that vertice
                cout << v->getLabel() << " " << endl;
                
                // For as many neighbors as there are in that vertice, iterate through the list of neighbors
                for (int i = 0; i < v->getNumNeighbors(); i++) {
                    
                    // Look at the current (i-th) neighbor
                    Vertex* neighbor = v->getNeighbor(i);
                    
                    // If that neighbor is not marked, 
                    if (!neighbor->isMarked()) {
                        
                        // Mark that neighbor
                        neighbor->setMark();
                        
                        // Add that neighbor to the queue
                        q.push(neighbor);
                    }
                }
            }
            
            // Clear marks after finishing
            clearMarks();
        }
        
        /*_________________________________________________________________________________________________________________________________//
    	 *
    	 *										DIJKSTRAS_ALG METHOD (DIJKSTRAS ALGORITHM)
    	 *
    	 * _______________________________________________________________________________________________________________________________
    	 *
    	 *														PARAMETERS: 
    	 *												Char: label_of_starting_vertex
    	 *
    	 * _______________________________________________________________________________________________________________________________
    	 *
    	 *													   FUNCTIONALITY:
     	 *						        Dijkstra's algorithm: finds a minimal spanning tree of the graph
    	 *
    	 *________________________________________________________________________________________________________________________________*/
    
        void dijkstrasAlg(char sourceLabel)
        {
            // Ensure that marks are cleared
            clearMarks();
    
            // create an unordered_map where the first thing in each pair
            // is the Vertex* and the second thing is the int that
            // represents the length of the shortest known path from
            // the source vertex to this one
            unordered_map<Vertex*, int> distances;
            int count = 0;
    
            // in this map, initialize all of the values to infinity
            for (int i = 0; i < vertices.size(); i++) 
            {
                distances.insert(make_pair(vertices[i], INT_MAX));
            }
    
            // then set the one for the source vertex to zero
            Vertex* current = getVertex(sourceLabel);
            
            // If no starting place was provided, the operation cannot be performed. Return from the method
            if (!current)
            {
                return;
            }
            
            // The distance from the current node is 0
            distances[current] = 0;
    
            // Look at each vertice in the list
            while (count < vertices.size())
            {
                
                // find the unmarked vertex that goes with the smallest
                // value in the map
                
                int smallest = INT_MAX;
                Vertex* current = nullptr;
    
                // For each pair in distances,
                for (auto& it : distances)
                {
                    // If its distance is smaller than the smallest AND it is not marked
                    if (it.second < smallest && !it.first->isMarked())
                    {
                        // The smallest value is now the distance from this node
                        smallest = it.second;
                        
                        // The current node is now this node
                        current = it.first;
                    }
                }
    
                // loop over all of the neighbors of this current vertex
                int numNeighbors = current->getNumNeighbors();
                
                for (int i = 0; i < numNeighbors; i++)
                {
                    // if the distance from the source vertex to the current one
                    // PLUS the distance from the current one to the neighbor that
                    // we're looking at right now is less than the value of that
                    // neighbor in the map, update that neighbor's map value to this
                    // sum
                    
                    Vertex* neighbor = current->getNeighbor(i);
                    int sourceToCurrent = distances[current];
                    int currentToNeighbor = current->getNeighborWeight(i);
                    
                    if (sourceToCurrent + currentToNeighbor < distances[neighbor])
                    {
                        distances[neighbor] = sourceToCurrent + currentToNeighbor;
                    }
                }
                
                // Set the current node as marked and increment count
                current->setMark();
                count++;
            } // while there are still unmarked vertices
    
            // display results
            for (auto& it : distances)
            {
    			cout << it.first->getLabel() << ": " << it.second << endl;
            }
    
            // Clear marks for safety
            clearMarks();
        }
        
        /*_________________________________________________________________________________________________________________________________//
    	 *
    	 *												Prim METHOD (Prim's algorithm)
    	 *
    	 * _______________________________________________________________________________________________________________________________
    	 *
    	 *														PARAMETERS: 
    	 *														   VOID
    	 *
    	 * _______________________________________________________________________________________________________________________________
    	 *
    	 *													   FUNCTIONALITY:
     	 *						Returns a minimal spanning tree for the graph using Prim's algorithm
    	 *
    	 *________________________________________________________________________________________________________________________________*/
    
    	void prim()
    	{
    
            // Start by ensuring all marks are cleared
    		clearMarks();
    
    		// empty graph
    		if (!vertices.size())
    		{
    		    return;
    		}
    
            // Create an unordered map to store the distances between nodes
            unordered_map<Vertex*, pair<int, Vertex*> > distances;
            int count = 0;
    
            // in this map, initialize all of the values to infinity
            for (int i = 0; i < vertices.size(); i++)
            {
                distances.insert(make_pair(vertices[i], make_pair(INT_MAX, nullptr)));
            }
    
            // then pick any vertex to current from 
            Vertex* current = vertices[0]; 
    
            // While there are still nodes to visit
    		while (count < vertices.size()-1)
    		{
    		    // Set the current's pair to an empty node
    			distances[current] = make_pair(0, nullptr);
    			
    			// Mark it as visited
    			current->setMark();
    			
    			// Increment count
    			count++;
    
                // do this while the current node has neighbors
    			int numNeighbors = current->getNumNeighbors();
    			for (int i=0; i<numNeighbors; i++)
    			{
    			    // If the current's neighbor is less than what is stored,
    				if (current->getNeighborWeight(i) < distances[current->getNeighbor(i)].first)
    				{
    				    // Change it by changing the pair
    					distances[current->getNeighbor(i)] = make_pair(current->getNeighborWeight(i), current);
    				}
    			}
    
    			int smallest = INT_MAX;
    			Vertex* next = nullptr;
    			Vertex* from = nullptr;
    
                // Look through all values stored in distances
    			for (auto& it : distances)
    			{
    			    // If the pair's distance is less than the current smallest value AND the node is not marked,
    				if (it.second.first < smallest && !it.first->isMarked())
    				{
    				    // Set the smallest to the smallest value
    					smallest = it.second.first;
    					
    					// The node it is going to look at next needs to be set to next
    					next = it.first;
    					
    					// The node it is going to have come from is set to from
    					from = it.second.second;
    				}
    			}
    			
    			// Print the node that it came from and the node it is going to
    			cout << from->getLabel() << " - " << next->getLabel() << endl;
    			
    			// Move current to the next node
    			current = next;
    		}
            
            // Ensure that marks are cleared at the end
    		clearMarks();
    	}
};
