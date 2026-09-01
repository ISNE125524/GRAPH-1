#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <list>
using namespace std;

class Node {
public:
    char label;

    Node(char l) {
        label = l;
    }
};

class Edge {
public:
    Node *from;
    Node *to;
    int weight;

    Edge(Node *f, Node *t, int w) {
        from = f;
        to = t;
        weight = w;
    }
};

class Graph {
public:
    static const int SIZE = 9;

    list<Node> nodes;
    list<Edge> edges;

    Graph(int input[SIZE][SIZE]) {

        Node *nodeIndex[SIZE];

        for (int i = 0; i < SIZE; i++) {
            nodes.push_back(Node('A' + i));
            nodeIndex[i] = &nodes.back();
        }

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {

                if (input[i][j] != 0) {
                    edges.push_back(
                        Edge(nodeIndex[i],
                             nodeIndex[j],
                             input[i][j])
                    );
                }
            }
        }
    }

    void showNodes() {

        cout << "Nodes: ";

        for (list<Node>::iterator i = nodes.begin();
             i != nodes.end();
             i++) {

            cout << i->label << " ";
        }

        cout << endl;
    }

    void showEdges() {

        cout << "Edges:" << endl;

        for (list<Edge>::iterator i = edges.begin();
             i != edges.end();
             i++) {

            cout << i->from->label
                 << " -> "
                 << i->to->label
                 << " weight "
                 << i->weight
                 << endl;
        }
    }

    bool isMultigraph() {

        for (list<Edge>::iterator i = edges.begin();
             i != edges.end();
             i++) {

            list<Edge>::iterator j = i;
            j++;

            for (; j != edges.end(); j++) {

                if (i->from == j->from &&
                    i->to == j->to) {

                    return true;
                }
            }
        }

        return false;
    }

    bool isPseudograph() {

        for (list<Edge>::iterator i = edges.begin();
             i != edges.end();
             i++) {

            if (i->from == i->to) {
                return true;
            }
        }

        return false;
    }

    bool isDigraph() {

        for (list<Edge>::iterator i = edges.begin();
             i != edges.end();
             i++) {

            bool reverseFound = false;

            for (list<Edge>::iterator j = edges.begin();
                 j != edges.end();
                 j++) {

                if (i->from == j->to &&
                    i->to == j->from &&
                    i->weight == j->weight) {

                    reverseFound = true;
                }
            }

            if (reverseFound == false) {
                return true;
            }
        }

        return false;
    }

    bool isWeighted() {

        for (list<Edge>::iterator i = edges.begin();
             i != edges.end();
             i++) {

            if (i->weight != 1) {
                return true;
            }
        }

        return false;
    }

    bool isComplete() {

        for (list<Node>::iterator i = nodes.begin();
             i != nodes.end();
             i++) {

            list<Node>::iterator j = i;
            j++;

            for (; j != nodes.end(); j++) {

                bool connected = false;

                for (list<Edge>::iterator e = edges.begin();
                     e != edges.end();
                     e++) {

                    if ((e->from == &(*i) &&
                         e->to == &(*j)) ||

                        (e->from == &(*j) &&
                         e->to == &(*i))) {

                        connected = true;
                    }
                }

                if (connected == false) {
                    return false;
                }
            }
        }

        return true;
    }

    bool isDisjointed() {

        for (list<Node>::iterator i = nodes.begin();
             i != nodes.end();
             i++) {

            bool connected = false;

            for (list<Edge>::iterator e = edges.begin();
                 e != edges.end();
                 e++) {

                if (e->from == &(*i) ||
                    e->to == &(*i)) {

                    connected = true;
                }
            }

            if (connected == false) {
                return true;
            }
        }

        return false;
    }
};

#endif