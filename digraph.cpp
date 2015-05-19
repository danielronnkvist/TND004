/*********************************************
* file:	~\tnd004\lab\lab4a\digraph.cpp       *
* remark: mplementation of directed graphs   *
* file for students                          *
**********************************************/


#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

#include "digraph.h"
#include "queue.h"

const int INFINITY = 9999;

// -- CONSTRUCTORS

Digraph::Digraph(int n)
{
    assert(n >= 1);
    array = new List[n + 1];
    dist  = new int [n + 1];
    path  = new int [n + 1];
    done  = new bool[n + 1];
    size  = n;
}

// -- DESTRUCTOR

Digraph::~Digraph()
{
    delete[] array;
    delete[] dist;
    delete[] path;
    delete[] done;
}

// -- MEMBER FUNCTIONS

// insert directed edge (u, v) with weight w
// update weight w if edge (u, v) is present
void Digraph::insertEdge(int u, int v, int w)
{
    assert(u >= 1 && u <= size);
    assert(v >= 1 && v <= size);
    array[u].insert(v, w);
}

// remove directed edge (u, v)
void Digraph::removeEdge(int u, int v)
{
    assert(u >= 1 && u <= size);
    assert(v >= 1 && v <= size);
    array[u].remove(v);
}

// unweighted single source shortest paths
void Digraph::uwsssp(int s)
{
    if (s < 1 || s > size)
    {
         cout << "\nERROR: expected source s in range 1.." << size << " !" << endl;
         return;
    }

    Queue<int> Q;

    for (int i = 0; i <= size; i++)
    {
        dist[i] = -1;
        path[i] = 0;
    }

    dist[s] = 0;

    Q.enqueue(s);
    while (!Q.isEmpty())
    {
        int v = Q.getFront();
        Q.dequeue();
        List vertex = array[v];
        Node* node;
        for(node = vertex.getFirst(); node != nullptr; node = vertex.getNext())
        {
            int u= node->vertex;
            if(dist[u] == -1)
            {
                dist[u] = dist[v] + 1;
                path[u] = v;
                Q.enqueue(u);
            }

        }

    }
}

// positive weighted single source shortest pats
void Digraph::pwsssp(int s)
{
    if (s < 1 || s > size)
    {
         cout << "\nERROR: expected source s in range 1.." << size << " !" << endl;
         return;
    }

    for (int i = 0; i <= size; i++)
    {
        dist[i] = -1;
        path[i] = 0;
        done[i] = false;
    }

    dist[s] = 0;
    done[s] = true;
    int v = s;
    while (true)
    {
        List vertex = array[v];
        Node* node = vertex.getFirst();
        bool firstRun = true;
        int smallestDist;
        int newIndex = -1;
        for(; node != nullptr; node = vertex.getNext())
        {
            int u = node->vertex;
            int w = node->weight;
            if(!done[u] && ((dist[u] > dist[v] + w) || (dist[v] == -1)))
            {
                if(firstRun)
                {
                    smallestDist = w;
                    firstRun = false;
                }
                dist[u] = dist[v] + w;
                path[u] = v;
                if(dist[u] < smallestDist)
                {
                    smallestDist = dist[u];
                    newIndex = u;
                }
            }

        }
        if(newIndex == -1)
            break;

        done[v] = true;
        v = newIndex;
}

// print graph
void Digraph::printGraph() const
{
    cout << "------------------------------------------------------------------" << endl;
    cout << "vertex  adjacency list                  " << endl;
    cout << "------------------------------------------------------------------" << endl;

    for (int v = 1; v <= size; v++)
    {
        cout << setw(4) << v << " : ";
        array[v].print();
    }

    cout << "------------------------------------------------------------------" << endl;
}

// print shortest path tree for s
void Digraph::printTree() const
{
    cout << "----------------------" << endl;
    cout << "vertex    dist    path" << endl;
    cout << "----------------------" << endl;

    for (int v = 1; v <= size; v++)
    {
        cout << setw(4) << v << " :" << setw(8) << dist[v] << setw(8) << path[v] << endl;
    }

    cout << "----------------------" << endl;
}

// print shortest path from s to t
void Digraph::printPath(int t) const
{
    if (t < 1 || t > size)
    {
         cout << "\nERROR: expected target t in range 1.." << size << " !" << endl;
         return;
    }

    // *** TODO ***
}
