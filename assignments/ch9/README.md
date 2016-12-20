### print all *simple cycles* in a *directed acyclic graph*
[a good ref](http://stackoverflow.com/questions/546655/finding-all-cycles-in-graph)

#### description of my programs
- `ch9_cycle_DG_DFS.cpp` maintain a vector `visited` to record which vertex we've already visited.
- `ch9_cycle_DG_DFS2.cpp` doesn't care whether a vertex is visited when do the recursion.
- In `ch9_cycle_DG_DFS3.cpp`, I tried to maintain two vectors to remember the vertexes and paths that are visited. But this algorithm turned out a failure.

#### (bad) option1 : using DFS
- remember to use a `flag` to record whether cycles exist
- use a **"stack"** (actually `std::deque` because we have to loop on it) to record vertex in current recurssion.
- when we find a cycle, we shouldn't print the whole stack: The simple cycle consists of the elements on the stack starting with the identified successor(which we found duplicate) and ending with the top of the stack.
- **difficulty** is:  if we maintain a vector `visited` to record which vertex we've already visited, we can avoid re-visiting. But we will miss some cycles in the graph. 

An example is  :
```bash
digraph G {
    5 -> 6 -> 0 -> 1 -> 2;
    2 -> 3, 4;
    3, 4 -> 5;
    5 -> 6;
    6 -> 7;
    7 -> 6;
}
```
There are 3 loops: `0-1-2-3-5-6-0`, `0-1-2-4-5-6-0` and `6-7-6`.

#### some possible choices to be researched
- DAG: directed acyclic graph
- strongly connected components
- use Tarjan's algorithm to find the set of strongly connected components.
- minimal spanning tree (MST)
- for `undirected graph`, the algorithm is different.
