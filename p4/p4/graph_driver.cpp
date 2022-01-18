#include "graph.cpp"

int main() {


// Testing for step 1

	// TESTING FILE IN GRAPH (GRAPH 5)
	Graph g5("mine.graph", true);
	g5.printGraph(true);
	cout << "IN: " << g5.getInDegree('A') << endl;
	cout << "OUT: " << g5.getOutDegree('A') << endl;
	g5.pMAX();
	g5.printNei('H', 2);
	g5.pVECTOR(g5.getLargestConnectedComponent());
	cout << endl;


// Testing everything for step 0

	// TESTING GRAPH 1

	Graph g(false);
	g.addVertex('A');
	g.addVertex('B');
	g.addVertex('C');
	g.addVertex('D');
	g.addVertex('E');
	g.addVertex('F');


	g.addEdge('A', 'C');
	g.addEdge('A', 'E');
	g.addEdge('B', 'C');
	g.addEdge('B', 'F');
	g.addEdge('C', 'D');
	g.addEdge('C', 'F');
	g.addEdge('D', 'F');
	g.addEdge('E', 'F');
	g.printGraph(true);
	cout << endl << endl << endl;
	g.printN();
	cout << "\n\n\n";

	g.dfs();
	cout << endl;
	g.topologicalSort('A');
	cout << endl;
	g.bfs();
	cout << endl;
	g.dijkstrasAlg('A');
	cout << endl;
	g.prim();
	cout << endl;
	cout << "IN: " << g.getInDegree('A') << endl;
	cout << "OUT: " << g.getOutDegree('A') << endl;
	g.pMAX();
	g.printNei('A', 2);
	g.pVECTOR(g.getLargestConnectedComponent());
	cout << endl;
	
	// TESTING GRAPH 2

	Graph g2(true);
	g2.addVertex('1');
	g2.addVertex('2');
	g2.addVertex('3');
	g2.addVertex('4');
	g2.addVertex('5');
	g2.addVertex('6');
	g2.addVertex('7');

	g2.addEdge('1', '2');
	g2.addEdge('1', '3');
	g2.addEdge('2', '5');
	g2.addEdge('2', '6');
	g2.addEdge('2', '4');
	g2.addEdge('3', '4');
	g2.addEdge('4', '5');
	g2.addEdge('5', '7');
	g2.printGraph(true);
	cout << "\n\n\n";
	g2.printN();
	cout << "\n\n\n";
	g2.dfs();
	cout << endl;
	g2.topologicalSort('1');
	cout << endl;
	g2.bfs();
	cout << endl;
	g2.dijkstrasAlg('1');
	cout << endl;
	g2.prim();
	cout << endl;
	cout << "IN: " << g2.getInDegree('1') << endl;
	cout << "OUT: " << g2.getOutDegree('1') << endl;
	g2.pMAX();
	g2.printNei('1', 2);
	g2.pVECTOR(g2.getLargestConnectedComponent());
	cout << endl;

	// TESTING GRAPH 3

	cout << "\n\n\n";
	Graph g3(true);
	g3.addVertex('A');
	g3.addVertex('B');
	g3.addVertex('C');
	g3.addVertex('D');
	g3.addVertex('E');

	g3.addEdge('A', 'B', 10);
	g3.addEdge('A', 'C', 3);
	g3.addEdge('A', 'D', 20);
	g3.addEdge('B', 'D', 5);
	g3.addEdge('C', 'B', 2);
	g3.addEdge('C', 'E', 15);
	g3.addEdge('D', 'E', 11);

	g3.printGraph(true);
	cout << "\n\n\n";
	g3.printN();
	cout << "\n\n\n";

	g3.dfs();
	cout << endl;
	g3.topologicalSort('A');
	cout << endl;
	g3.bfs();
	cout << endl;
	g3.dijkstrasAlg('A');
	cout << endl;
	g3.prim();
	cout << endl;
	cout << "IN: " << g3.getInDegree('A') << endl;
	cout << "OUT: " << g3.getOutDegree('A') << endl;
	g3.pMAX();
	g3.printNei('A', 2);
	g3.pVECTOR(g3.getLargestConnectedComponent());
	cout << endl;
	
	// TESTING GRAPH 4

	cout << "\n\n\n";
	Graph g4(false);
	g4.addVertex('A');
	g4.addVertex('B');
	g4.addVertex('C');
	g4.addVertex('D');
	g4.addVertex('E');
	g4.addVertex('F');

	g4.addEdge('A', 'C', 7);
	g4.addEdge('A', 'E', 9);
	g4.addEdge('B', 'C', 5);
	g4.addEdge('B', 'F', 6);
	g4.addEdge('C', 'D', 1);
	g4.addEdge('C', 'F', 2);
	g4.addEdge('D', 'F', 2);
	g4.addEdge('E', 'F', 1);
	g4.printGraph(true);
	cout << "\n\n\n";
	g4.printN();
	cout << "\n\n\n";

	g4.dfs();
	cout << endl;
	g4.topologicalSort('A');
	cout << endl;
	g4.bfs();
	cout << endl;
	g4.dijkstrasAlg('A');
	cout << endl;
	g4.prim();
	cout << endl;
	cout << "IN: " << g4.getInDegree('A') << endl;
	cout << "OUT: " << g4.getOutDegree('A') << endl;
	g4.pMAX();
	g4.printNei('A', 2);
	g4.pVECTOR(g4.getLargestConnectedComponent());
	cout << endl;
	

}
