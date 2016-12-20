/**
 * algo to print all cycyles in a directed graph, using DFS.
 */

#include <iostream>
#include <algorithm>
#include <list>
#include <deque>
#include <vector>
#include <cassert>

void print_cycle(std::deque<int> &d, int start);

class Graph
{
  public:
    Graph(int nv); // Constructor
    void addEdge(int v, int w); // to add an edge to graph
    void find_cyclic(); // returns true if there is a cycle in this graph

  private:
    int count;//#TODO

    int nv; // No. of vertices
    std::list<int> *adj; // Pointer to an array containing adjacency lists
    void find_cycle_slave(int v, bool &flag, std::vector<bool> &visited_e,
            std::vector<bool> &visited_v, std::deque<int> &r_stack); // used by find_cyclic()
};

Graph::Graph(int nv)
{
    this->count = 0;//#TODO

    this->nv = nv;
    adj = new std::list<int>[nv];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

// Returns true if the graph contains a cycle, else false.
void Graph::find_cyclic()
{
    // Mark all the vertices as not visited and not part of recursion
    // stack
    bool flag = false;
    std::vector<bool> visited_v(nv, false);
    std::vector<bool> visited_e(nv*nv, false);
    std::deque<int> r_stack;

    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for(int vertex = 0; vertex < nv; ++vertex)
        if (!visited_v[vertex]) {
            visited_v[vertex] = true;
            find_cycle_slave(vertex, flag, visited_e, visited_v, r_stack);
        }

    if (!flag) std::cout << "no circles!" << std::endl;
}

void Graph::find_cycle_slave(int v, bool &flag, std::vector<bool> &visited_e,
        std::vector<bool> &visited_v, std::deque<int> &r_stack) {
    std::cout << "slave visiting: " << v << "==============" << std::endl;

    // Mark the current node as visited and part of recursion stack
    visited_v[v] = true;
    count++; std::cout <<"count: "<< count << std::endl; assert(count < 20);//#TODO
    //for (auto itr : visited_v) {std::cout << itr << ',';}
    //std::cout << "\n capacity: " << visited_v.size() << std::endl;
    r_stack.push_back(v);

    // Recur for all the vertices adjacent to this vertex
    for (int &i : adj[v])
    {
        std::cout << "    visiting "
            << v << "'s adjacent " << i << std::endl;

        if (!visited_v[i]) {
            visited_e[v*nv + i] = true;
            find_cycle_slave(i, flag, visited_e, visited_v, r_stack);
        }
        else {
            bool in_stack =
                !(std::find(std::begin(r_stack), std::end(r_stack), i)
                 == std::end(r_stack));
            if (in_stack) {
                flag = true;
                print_cycle(r_stack, i);
            }
            else if (!visited_e[v*nv + i]){
                visited_e[v*nv + i] = true;
                find_cycle_slave(i, flag, visited_e, visited_v, r_stack);
            }
            else {
                std::cout << '[' << v << "] is visited, "
                    << "and [" << v << "->" << i << "] is also visited,"
                    << "but " << i << " is not in stack!" << std::endl;
            }
        }
    }

    r_stack.pop_back();
}

void print_cycle(std::deque<int> &d, int start) {
    bool loop = false;
    std::cout << "-------------[Find a circle]: ";
    for (int &k : d) {
        if (k == start) loop = true;

        if (loop) {
            std::cout << k << ", ";
        }
    }
    std::cout << start << ";" << std::endl;
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(9);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 0);
    g.addEdge(5, 7);
    g.addEdge(7, 8);
    g.addEdge(8, 7);
    std::cout << "Construction of graph completed." << std::endl;

    g.find_cyclic();

    return 0;
}
