# Dijkstra's

In this project, I have implemented Dijkstra's algorithm to build the routing table of a given source node in the network, which is 0 for this project. Along with this, I have also shown the minimum path tree for each node from node 0.

dijkstras.cpp
  
This file first reads the data from a text file called Adj.txt from which it gets the number of nodes and its adjacency matrix. It then performs Dijkstra's algorithm using this adjacency matrix and outputs the cost to reach each node and its next hop. After this, the minimum path tree for each node from 0 is also shown. The path is shown according to the node number rather than sequence of the node followed by the path to reach the destination  node.
  
Adj.txt
  
This file contains the number of nodes in the first line and the adjacency matrix for the all the nodes in the network, separated by a newline(\n).
