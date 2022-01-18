#include <iostream>
#include <climits>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>
#include <string>
#include <fstream>

#include "vertex.cpp"

using namespace std;

// This is the Graph class that uses an adjacency matrix for its implementation.
// Finished on 11/10/21 by Logan Brennaman

// Since this isn't usually how I'd code my class, here's a list of this class's methods in order of their appearance
/*

lines: 70 - 79
    private:
        // Fields
        bool directed;                      // Boolean to tell if the graph is directed (1) or undirected (0)
        vector<Vertex*> vertices;           // The list of vertices/nodes stored in the graph
        pair<bool, int>** edgelist;         // This is the adjacency matrix. A bool denotes an edge, the int is the weight of the edge (PROJECT GOAL 0)
lines: 80 - 180
        // Methods
        int getVertex(char)                 // Returns the index of where the given vertex is in vertices. Returns -1 if not found
        void clearMarks()                   // Clear the marks of all vertices in the graph
        void dfsHelper(Vertex*, Vertex*)    // Method to help depth first search (is really what does the work)
        void topSortHelper(Vertex*)         // Method to help topSort (Again, really is what does all the work)
lines: 181 - 233
    public:
        Graph(bool)                         // CONSTRUCTOR: initializes a graph as directed or undirected
        Graph(string, bool)                 // CONSTRUCTOR: reads from file to initialize graph as directed or undirected (PROJECT GOAL 1)
lines: 234 - 362
        bool addVertex(char)                // Adds the given label as a vertex in the graph
        bool addEdge(char, char)            // Create an edge between the two vertices in the graph with a DEFAULT WEIGHT OF 1
        bool addEdge(char, char, int)       // Create an edge between the two vertices in the graph with a specified weight
lines: 363 - 695
        void dfs()                          // Perform depth first search
        void topologicalSort(char)          // Perform topological sort, starting at the given vertex
        void bfs()                          // Perform breadth first search
        void dijkstrasAlg(char)             // Perform dijkstrasAlgorithm, starting at the given vertex
        void prim()                         // Perform Prim's algorithm
        void printN()                       // Print all vertices, their number of neighbors, and who they are
        void printGraph(bool)               // Print the graph, with, or without weights
lines: 696 - 747
        int getNumNeighbors(int)            // Get the number of neighbors for the current vertex
        int getNeighbor(int, int)           // For the given vertex (int parameter #1), get its i-th neighbor (specified by int parameter #2)
        int getNeighborWeight(int, int)     // For the given vertex, get the weight of the edge associated with its i-th neighbor
lines: 748 - 868
        int getInDegree(char)                       // Get the in degree associated with the given vertex
        int getOutDegree(char)                      // Get the out degree associated with the given vertex
        vector<Vertex*> getMaxInDegree(int&)        // Get the largest in degree in the whole graph (or multiple if there is a tie)
        vector<Vertex*> getMaxOutDegree(int&)       // Get the largest out degree in the whole graph (or multiple if there is a tie)
        void pMAX()                                 // Print the maxInDegree and maxOutDegree
lines: 869 - 950
        vector<Vertex*> getNeighborhood(char, int)  // Return the neighborhood specified by the parameters
        void printNei(char, int)                    // Print the neighborhood returned from using getNeighborhood with the specified parameters
lines: 951 - 991
        vector<Vertex*> getLargestConnectedComponent()  // Return the largest connected component in the graph
        void pVECTOR(vector<Vertex*>)                   // Given a set of vertices, print them

*/

class Graph
{
    private:

        // Variable that tells when a graph is directed or undirected
        bool directed;

        // Stores all of the vertices associated with this graph as a list
        vector<Vertex*> vertices;

        // Stores all edges in the graph
        pair<bool, int>** edgelist;

        // Method to return the index of a specific vertex if it exists in the graph's list of vertices
        int getVertex(char label)
        {

            // While i is less than the size of the vector
            for (int i = 0; i < vertices.size(); i++)
            {

                // if the label in this location is the label we are looking for
                if (vertices[i]->getLabel() == label)
                {

                    // return that label
                    return i;
                }
            }

            // Else, the label was not found
            // -1 will show that the index is out of bounds
            // BE CAREFUL HERE, CAN CAUSE OUT OF BOUNDS ISSUES IF NOT CODED FOR
            return -1;
        }

        // This method clears all marks from vertices
        void clearMarks()
        {

            // Iterate through all vertices of the graph
            for (int i = 0; i < vertices.size(); i++)
            {

                // Clear the marks of the current NODE
                vertices[i]->clearMark();
            }
        }

        // This method helps depth first search
        void dfsHelper(Vertex* from, Vertex* to)
        {

            // If to points to a node, print the node and its number of neighbors
            int toi = getVertex(to->getLabel());
            if (to)
            {
                cout << to->getLabel() << endl;
                cout << getNumNeighbors(toi) << endl;
            }

            // If from points to a node, print the node and the node it is connected to
            if (from)
            {
                cout << from->getLabel() << " - " << to->getLabel() << endl;
            }

            // Set to as marked because it has already been visited once before
            to->setMark();

            // Visit all neighbors of to

            for (int i = 1; i < getNumNeighbors(toi) + 1; i++)
            {

                // Look at the i-th neighbor of the current node pointed to by to
                int ithIndex = getNeighbor(toi, i);
                Vertex* neighbor = vertices[ithIndex];

                // If that neighbor is not marked, call this method recursively by passing to as arg1 and its i-th neighbor as arg2
                if (!neighbor->isMarked())
                {
                    dfsHelper(to, neighbor);
                }
            }
        }

        // This method helps topological sort
        void topSortHelper(Vertex* to)
        {
            // Set the node as marked
            to->setMark();

            // While that node has neighbors
            int toi = getVertex(to->getLabel());
            for (int i = 1; i < getNumNeighbors(toi) + 1; i++)
            {
                // Look at the current (i-th) neighbor
                int ithIndex = getNeighbor(toi, i);
                Vertex* neighbor = vertices[ithIndex];

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

        // Create a directed or undirected graph
        Graph(bool directed)
        {
            this->directed = directed;
        }

        // GOAL 1 OF PROJECT
        // CONSTRUCTOR TO TAKE IN A FILENAME AND BOOLEAN
        // Reads from a file and creates a graph
        // Read in "Vertices" until "Edges" is read
        // When reading Vertices, use the addVertex method
        // When reading Edges, use the addEdge (weighted) method
        Graph(string filename, bool directed)
        {
            // First, set directed so the methods know how to properly react
            this->directed = directed;

            // Keep track of whether to use addVertex or addEdge
            string function = "";

            // Manage file properly
            string line;            // This will be the line read from the file
            ifstream myFile;        // This is the file stream
            myFile.open(filename);  // Open the file
            if (myFile.is_open())   // Only open if a file could be found
            {
                while (getline(myFile, line)) // Read in all contents of the file (until null)
                {
                    if (line == "Vertices" || line == "Edges")
                    {
                        function = line;
                    }
                    if (function == "Vertices" && line != "Vertices" && line != "Edges")
                    {
                        // When reading in vertices
                        // Simply say addVertex(line[0])
                        addVertex(line[0]);
                    }
                    if (function == "Edges" && line != "Edges")
                    {
                        // When reading in edges
                        // Index 0 is v1
                        // Index 2 is v2
                        // Index 4+ is weight
                        addEdge(line[0], line[2], stoi(line.substr(4, line.size() - 4)));
                    }
                }
                myFile.close(); // Ensure that the file is properly closed at the end
            }
        }

        // Add a vertex to the graph
        bool addVertex(char label)
        {

            // If the label already exists, don't add this label
            int index = getVertex(label);
            if (index != -1)
            {
                return false;
            }

            // Otherwise, create a new vertex using the given label
            Vertex* newV = new Vertex(label);

            // Add the vertex to the end of the vector
            vertices.push_back(newV);

            // initialize edgelist if it is not already initialized
            if (vertices.size() == 1)
            {
                edgelist = new pair<bool, int>*[1];
                edgelist[0] = new pair<bool, int>[1];
            }

            // If vertices has grown to 2 or above, edgelist must be recreated
            if (vertices.size() >= 2)
            {
                pair<bool, int>** temp = new pair<bool, int>*[vertices.size()];
                for (int i = 0; i < vertices.size(); i++)
                {
                    temp[i] = new pair<bool, int>[vertices.size()];
                }

                // Store the edges into temp
                for (int i = 0; i < vertices.size() - 1; i++)
                {
                    for (int j = 0; j < vertices.size() - 1; j++)
                    {
                        temp[i][j].first = edgelist[i][j].first;
                        temp[i][j].second = edgelist[i][j].second;
                    }
                }

                edgelist = temp;
            }

            // The process succeeded in adding a new NODE. Return true to show this
            return true;
        }

        // Add an edge between two nodes with a default weight of 1
        bool addEdge(char label1, char label2)
        {

            // Find the vertex containing label one
            int v1 = getVertex(label1);

            // Find the vertex containing label two
            int v2 = getVertex(label2);

            // If either of the vertexes does not exist, an edge cannot be added. Return false
            if (!vertices[v1] || !vertices[v2])
            {
                return false;
            }

            // Create a new edge between the first label and the second label with a default weight of 1
            // To create an edge between the first label and the second label, their indeces need to be used
            // Create an edge in edgelist[index_of_label1][index_of_label2]
            // Set the .first, the bool of the pair, to true to indicate an edge between label1 and label2
            edgelist[v1][v2].first = true;

            // Their .second is set to 1 by default
            edgelist[v1][v2].second = 1;

            // If that graph is not directed, this needs to be done the other way as well for an undirected graph
            if (!directed) {

                // Add the edge going in the opposite direction
                edgelist[v2][v1].first = true;

                // Their .second is set to 1 by default
                edgelist[v2][v1].second = 1;

            }

            // It made it here successfully, so a vertex was added. Return true to show this
            return true;
        }

        // Add an edge between two nodes with a weight
        bool addEdge(char label1, char label2, int edgeWeight)
        {
            // Find the vertex containing label one
            int v1 = getVertex(label1);

            // Find the vertex containing label two
            int v2 = getVertex(label2);

            // If either of the vertexes does not exist, an edge cannot be added. Return false
            if (!vertices[v1] || !vertices[v2])
            {
                return false;
            }

            // Create a new edge between the first label and the second label with a default weight of 1
            // To create an edge between the first label and the second label, their indeces need to be used
            // Create an edge in edgelist[index_of_label1][index_of_label2]
            // Set the .first, the bool of the pair, to true to indicate an edge between label1 and label2
            edgelist[v1][v2].first = true;

            // Their .second is set to 1 by default
            edgelist[v1][v2].second = edgeWeight;

            // If that graph is not directed, this needs to be done the other way as well for an undirected graph
            if (!directed) {

                // Add the edge going in the opposite direction
                edgelist[v2][v1].first = true;

                // Their .second is set to 1 by default
                edgelist[v2][v1].second = edgeWeight;

            }

            // It made it here successfully, so a vertex was added. Return true to show this
            return true;
        }

        // Depth first search
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

        // Topological sort
        void topologicalSort(char label)
        {
            // Ensure that marks are cleared when starting this method
            clearMarks();

            // Use the helper to perform this method
            // Get the index of the vertex first
            int index = getVertex(label);
            topSortHelper(vertices[index]);

            // Print a new line
            cout << endl;

            // Ensure that marks are cleared
            clearMarks();
        }

        // Breadth first search
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
                int voi = getVertex(v->getLabel());
                for (int i = 1; i < getNumNeighbors(voi) + 1; i++) {

                    // Look at the current (i-th) neighbor
                    int ithIndex = getNeighbor(voi, i);
                    Vertex* neighbor = vertices[ithIndex];

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

        // Dijkstra's Algorithm
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

            // get the current index of the sourcelabel
            int current = getVertex(sourceLabel);

            // If no starting place was provided, the operation cannot be performed. Return from the method
            if (!vertices[current])
            {
                return;
            }

            // The distance from the current node is 0
            distances[vertices[current]] = 0;

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
                int coi = getVertex(current->getLabel());
                int numNeighbors = getNumNeighbors(coi);

                for (int i = 1; i < numNeighbors + 1; i++)
                {
                    // if the distance from the source vertex to the current one
                    // PLUS the distance from the current one to the neighbor that
                    // we're looking at right now is less than the value of that
                    // neighbor in the map, update that neighbor's map value to this
                    // sum

                    int ithIndex = getNeighbor(coi, i);
                    Vertex* neighbor = vertices[ithIndex];
                    int sourceToCurrent = distances[current];
                    int currentToNeighbor = getNeighborWeight(coi, i);

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

        // Prim's algorithm
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
                int coi = getVertex(current->getLabel());
    			int numNeighbors = getNumNeighbors(coi);
    			for (int i = 1; i < numNeighbors + 1; i++)
    			{
    			    // If the current's neighbor is less than what is stored,
    			    // Get the current neighbor weight
    			    int weight = getNeighborWeight(coi, i);

    			    // Get the vertex that is current's ith neighbor
    			    int ind = getNeighbor(coi, i);
    				if (weight < distances[vertices[ind]].first)
    				{
    				    // Change it by changing the pair
    					distances[vertices[ind]] = make_pair(weight, current);
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

        // Print all vertices, its number of neighbors, and who they are
    	void printN()
    	{
    	    for (int i = 0; i < vertices.size(); i++)
    	    {
    	        cout << "Vertex: " << vertices[i]->getLabel() << " has " << getNumNeighbors(i) << " Neigbors" << endl;
    	        cout << "Neighbors: ";
    	        for (int j = 1; j < getNumNeighbors(i) + 1; j++)
    	        {
    	            cout << vertices[getNeighbor(i, j)]->getLabel();
    	        }
    	        cout << endl;
    	    }
    	}

        // Print the graph vertices and the edges between them
    	void printGraph(bool withWeights)
    	{
    	    if (!withWeights)
    	    {
    	        cout << "  ";
    	        for (int i = 0; i < vertices.size(); i++)
    	        {
    	            cout << vertices[i]->getLabel() << " ";
    	        }
    	        cout << endl;

    	        // Now for the nodes they connect to
    	        for (int i = 0; i < vertices.size(); i++)
    	        {
    	            cout << vertices[i]->getLabel() << " ";
    	            for (int j = 0; j < vertices.size(); j++)
    	            {
    	                cout << edgelist[i][j].first << " ";
    	            }
    	            cout << endl;
    	        }
    	    }
    	    else
    	    {
    	        cout << "    ";
    	        for (int i = 0; i < vertices.size(); i++)
    	        {
    	            cout << vertices[i]->getLabel() << "     ";
    	        }
    	        cout << endl;

    	        // Now for the nodes they connect to
    	        for (int i = 0; i < vertices.size(); i++)
    	        {
    	            cout << vertices[i]->getLabel() << " ";
    	            for (int j = 0; j < vertices.size(); j++)
    	            {
    	                cout << "<" << edgelist[i][j].first << "," << edgelist[i][j].second << ">" << " ";
    	            }
    	            cout << endl;
    	        }
    	    }
    	}

    	// Get the number of neighbors for the current node (provided by vertices[index])
    	int getNumNeighbors(int index)
    	{
    	    // For this row, iterate through its columns and count the number of trues
    	    int trueCount = 0;
    	    for (int col = 0; col < vertices.size(); col++)
    	    {
    	        if (edgelist[index][col].first == true)
    	        {
    	            trueCount++;
    	        }
    	    }
    	    return trueCount;
    	}

    	// Return the index of the ith neighbor for the current node
    	int getNeighbor(int index, int ith)
    	{
    	    // Make sure that there is actually an ith neighbor
    	    if (getNumNeighbors(index) < ith)
    	    {
    	        // Show that there is not an ith neighbor
    	        return -1;
    	    }

    	    // Count trues, stop when ith true is hit
    	    int trueCount = 0;
    	    for (int col = 0; col < vertices.size(); col++)
    	    {
    	        if (edgelist[index][col].first == true)
    	        {
    	            trueCount++;
    	            if (trueCount == ith)
    	            {
    	                return col;
    	            }
    	        }
    	    }

    	    // This is here as a fall back or else the compiler yells
    	    return trueCount;
    	}

    	// Return the weight of the ith neighbor of the current index
    	int getNeighborWeight(int index, int ith)
    	{
    	    int vei = getNeighbor(index, ith);

    	    // Using the index of the ith neighbor, return the weight of that edge (edgelist[index][vei].second)
    	    return edgelist[index][vei].second;
    	}

    	// STEP 2 (called 3 in pdf) OF PROJECT BELOW
    	// Return the in degree of a certain node of the graph
    	int getInDegree(char vertexLabel)
    	{
    	    // Given a vertex to find the in degree, that vertex's index is vei
            int vei = getVertex(vertexLabel);

            // If it is undirected, just return getNumNeighbors(index)
            if (!directed)
            {
                return getNumNeighbors(vei);
            }

            // Iterate through vertices, if (when i != vei) edgelist[i][vei] == true, return the number of times true was hit
            int trueCount = 0;
            for (int i = 0; i < vertices.size(); i++)
            {
                if (edgelist[i][vei].first == true && i != vei)
                {
                    trueCount++;
                }
            }

            return trueCount;
    	}

    	// Return the out degree of a certain node of the graph
        int getOutDegree(char vertexLabel)
        {
            // Find that index's position in vertices
            int index = getVertex(vertexLabel);
    	    return getNumNeighbors(index);
        }

        // Return a POINTER to the vertex with the biggest IN degree or more if there is a tie
        vector<Vertex*> getMaxInDegree(int& maxDegree)
        {
            // Create a vector, push the node with the MAX to the front.
            vector<Vertex*> v;

            // Keep track of the biggest number
            int biggest = 0;

            // Iterate through vertices
            for (int i = 0; i < vertices.size(); i++)
            {
                // If the degree of this index is bigger than the biggest number, change biggest
                if (getInDegree(vertices[i]->getLabel()) >= biggest)
                {
                    biggest = getInDegree(vertices[i]->getLabel());
                }
            }

            // Now that the biggest is known, iterate through again and add all vertices whose degree is equal to the bigges to vector
            for (int i = 0; i < vertices.size(); i++)
            {
                // If the degree of this index is bigger than the biggest number, change biggest
                if (getInDegree(vertices[i]->getLabel()) == biggest)
                {
                    v.push_back(vertices[i]);
                }
            }

            maxDegree = biggest;

            return v;
        }

        // Return a POINTER to the vertex with the biggest OUT degree or more if there is a tie
        vector<Vertex*> getMaxOutDegree(int& maxDegree)
        {
            // Create a vector, push the node with the MAX to the front.
            vector<Vertex*> v;

            // Keep track of the biggest number
            int biggest = 0;

            // Iterate through vertices
            for (int i = 0; i < vertices.size(); i++)
            {
                // If the degree of this index is bigger than the biggest number, change biggest
                if (getOutDegree(vertices[i]->getLabel()) >= biggest)
                {
                    biggest = getOutDegree(vertices[i]->getLabel());
                }
            }

            // Now that the biggest is known, iterate through again and add all vertices whose degree is equal to the bigges to vector
            for (int i = 0; i < vertices.size(); i++)
            {
                // If the degree of this index is bigger than the biggest number, change biggest
                if (getOutDegree(vertices[i]->getLabel()) == biggest)
                {
                    v.push_back(vertices[i]);
                }
            }

            maxDegree = biggest;

            return v;
        }

        // Method to print the max in degree and the max out degree
        void pMAX()
        {
            int maxDegree = 0;
            vector<Vertex*> print;
            print = getMaxInDegree(maxDegree);
            for (int i = 0; i < print.size(); i++)
            {
                cout << print[i]->getLabel() << endl;
                cout << "InMax: " << maxDegree << endl;
            }
            print = getMaxOutDegree(maxDegree);
            for (int i = 0; i < print.size(); i++)
            {
                cout << print[i]->getLabel() << endl;
                cout << "OutMax: " << maxDegree << endl;
            }
        }

        // PART 4 OF PROJECT
        // getNeighborhood method that returns a vector of pointers to all the vertices in the neighborhood of the size (+1 [counts the start])
        vector<Vertex*> getNeighborhood(char vertexLabel, int neighborhoodSize)
        {
            // Initialize a vector of Vertex POINTERS
            vector<Vertex*> ve;

            // Iterate through all nodes that this vertex points to
            // Clear marks as a safety measure
            clearMarks();

            // Create a queue to store vertices
            queue<Vertex*> q;

            // Start at the index of the label
            int ind = getVertex(vertexLabel);
            q.push(vertices[ind]);

            // Add the starting place to the vector
            ve.push_back(vertices[ind]);

            // Set that vertice as visited (marked)
            vertices[ind]->setMark();

            // While that queue is not empty, iterate through its edges
            while (!q.empty()) {

                // Retrieve the vertice at the front of the queue
                Vertex* v = q.front();

                // Pop that vertice out of the queue to get rid of it
                q.pop();

                // For as many neighbors as there are in that vertice, iterate through the list of neighbors
                int voi = getVertex(v->getLabel());
                for (int i = 1; i < getNumNeighbors(voi) + 1; i++) {

                    // Look at the current (i-th) neighbor
                    int ithIndex = getNeighbor(voi, i);
                    Vertex* neighbor = vertices[ithIndex];

                    // If that neighbor is not marked,
                    if (!neighbor->isMarked()) {

                        // Add that neighbor to the vector
                        // Only add if the current size of the vector is less than or equal to neighborhoodSize
                        if (ve.size() <= neighborhoodSize)
                        {
                            ve.push_back(neighbor);
                        }

                        // Mark that neighbor
                        neighbor->setMark();

                        // Add that neighbor to the queue
                        q.push(neighbor);
                    }
                }

            }

            // Clear marks after finishing
            clearMarks();

            // Return vector
            return ve;
        }

        // Method to print out the list of vectors gathered by getNeighborhood(label, size)
        void printNei(char label, int size)
        {
            vector<Vertex*> vec = getNeighborhood(label, size);

            // For each of the vertices in the vector, use its index from vertices to print it
            for (int i = 0; i < vec.size(); i++)
            {
                int index = getVertex(vec[i]->getLabel());
                cout << vertices[index]->getLabel();
            }
            cout << endl;
        }

        // PART 5 of the PROJECT
        // Returns the largest connected component in the graph
        vector<Vertex*> getLargestConnectedComponent()
        {
            // Initialize a vector to store the component when found
            vector<Vertex*> vec;

            // Iterate through all vertices in graph in search of the INDEX of the vertice with the largest connected component
            int biggestComponentSize = 0;
            int index = 0;
            for (int i = 0; i < vertices.size(); i++)
            {
                // Whichever vertice returns the largest neighborhood is the largest connected component
                // If it is equal, it could be reset but doesn't have to be
                if ((getNeighborhood(vertices[i]->getLabel(), vertices.size())).size() > biggestComponentSize)
                {
                    biggestComponentSize = (getNeighborhood(vertices[i]->getLabel(), vertices.size())).size();
                    index = i;
                }
            }

            // Now that the biggest component's index is known, add the whole component to the vector
            vec = (getNeighborhood(vertices[index]->getLabel(), vertices.size()));

            // Return the connected component
            return vec;
        }

        // Method to print a vector of Vertice POINTERS
        void pVECTOR(vector<Vertex*> vec)
        {
            for (int i = 0; i < vec.size(); i++)
            {
                // Get the index of the vertice and print the corresponding vertices[index]
                int index = getVertex(vec[i]->getLabel());
                cout << vertices[index]->getLabel() << " ";
            }
            cout << endl;
        }
};
