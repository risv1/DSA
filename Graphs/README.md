# Graphs

-> Defined as collection of vertices and edges
    G = ( V, E )

-> If edges have direction, called directed graph
   If directed graph has edge connected to itself, called self loop
   If edges connect in both directions, called parallel edges
   Without self loop or parallel edges, called simple graph

-> If edges dont have direction, called undirected graph

-> If there are 2 or more components without connection, called non-connected graph

-> If you can reach all other vertices from any one vertex in a directed graph,
   called strongly connected graph

-> Path is defined as set of vertices between pair of vertices

-> Cycle is defined as path from an initial vertex, travelling around to reach the 
   same vertex

-> A graph in which starting at any point, cannot reach the same vertex, is called
   directed acycylic graph

-> If a directed acyclic graph is arranged linearly, such that edges go only in
   forward direction, called topological ordering of vertices 