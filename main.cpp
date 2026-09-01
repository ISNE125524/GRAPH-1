#include <iostream>
#include "graph1.h"
using namespace std;

int main() {

    int matrix[9][9] = {
        {0, 2, 1, 7, 0, 0, 0, 0, 0},
        {2, 0, 5, 5, 0, 0, 0, 0, 0},
        {1, 5, 0, 4, 0, 9, 0, 0, 0},
        {7, 5, 4, 0, 8, 0, 0, 0, 0},
        {0, 0, 0, 8, 0, 3, 7, 0, 0},
        {0, 0, 9, 0, 3, 0, 5, 10, 0},
        {0, 0, 0, 0, 7, 5, 0, 11, 6},
        {0, 0, 0, 0, 0, 10, 11, 0, 3},
        {0, 0, 0, 0, 0, 0, 6, 3, 0}
    };

    Graph graph(matrix);

    graph.showNodes();
    graph.showEdges();

    cout << boolalpha << endl;

    cout << "Multigraph: "
         << graph.isMultigraph() << endl;

    cout << "Pseudograph: "
         << graph.isPseudograph() << endl;

    cout << "Digraph: "
         << graph.isDigraph() << endl;

    cout << "Weighted graph: "
         << graph.isWeighted() << endl;

    cout << "Complete graph: "
         << graph.isComplete() << endl;

    cout << "Disjointed graph: "
         << graph.isDisjointed() << endl;

    return 0;
}