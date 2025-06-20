/*        (5)
      0--------1
        (1) /   \   (3)
           /     \
          2-------3
           \  (1)
     (2)    \
             4
 */

 // This code defines a simple graph structure using an adjacency list representation.
 // we are using one array of ArrayList which contains an edge . each edge has 3 properties , one src , dist and weight

import java.util.*;
import java.io.*;
import java.math.*;

 public class Graph {
    static class Edge {
        int src;
        int dest;
        int weight;

        // Constructor to initialize the edge
        // src: source vertex, dest: destination vertex, weight: weight of the edge
        // This constructor initializes the edge with the given source, destination, and weight.
        // It is used to create an edge in the graph with the specified properties.
        // The src and dest represent the vertices connected by the edge, and weight represents the cost or distance associated with that edge.
        
        public Edge(int src, int dest, int weight) {
            this.src = src;
            this.dest = dest;
            this.weight = weight;
            }   
        }
        public static void createGraph(ArrayList<Edge>[] graph) {
        // Initialize the adjacency list for each vertex
            for (int i = 0; i < graph.length; i++) {
                graph[i] = new ArrayList<>();
            }
            // Add edges to the graph 
            // 0-vertex
            graph[0].add(new Edge(0, 1, 1));
            graph[0].add(new Edge(0, 2, 1));
            // 1-vertex
            graph[1].add(new Edge(1, 0, 1));
            graph[1].add(new Edge(1, 3, 1));
            // 2-vertex
            graph[2].add(new Edge(2, 0, 1));
            graph[2].add(new Edge(2, 4, 1));
            // 3-vertex
            graph[3].add(new Edge(3, 1, 1));
            graph[3].add(new Edge(3, 5, 1));
            graph[3].add(new Edge(3, 4, 1));
            // 4-vertex
            graph[4].add(new Edge(4, 3, 1));
            graph[4].add(new Edge(4, 5, 1));
            // 5-vertex
            graph[5].add(new Edge(5, 3, 1));
            graph[5].add(new Edge(5, 6, 1));
            graph[5].add(new Edge(5, 4, 1));

            }



            //BFS Traversal
            public static void BFS_Traversal(ArrayList<Edge>[] graph) {     
                Queue<Integer> queue = new LinkedList<>();
                boolean[] visited = new boolean[graph.length];
                queue.add(0); // Start BFS from vertex 0

                while(!queue.isEmpty()){
                    int current = queue.remove();
                    if(!visited[current]) {
                        visited[current] = true; // Mark the current vertex as visited
                        System.out.print(current + " "); // Print the current vertex

                        // Traverse all edges from the current vertex
                        for(Edge edge : graph[current]) {
                            if(!visited[edge.dest]) {
                                queue.add(edge.dest); // Add unvisited destination to the queue
                            }
                        }
                    }
                }
            } 




            public static void DFS_Traversal(ArrayList<Edge>[] graph) { 
                   
            }
    public static void main(String[] args) {
       
   /*      
            1-------3 -------5------6
          /         \        /
        /            \      /
       0             \     /     
        \             \   /
         \             \ /   
          2-------------4

    */
             int V = 7; // Number of vertices
             ArrayList<Edge> [] graph = new ArrayList[V];
             createGraph(graph);

            System.out.println("BFS Traversal of the graph:");
            BFS_Traversal(graph);
            System.out.println();

    // for(int j=0;j<graph.length;j++){
    //     for(int i=0;i<graph[j].size();i++) {
    //         Edge e = graph[j].get(i);
    //         System.out.println("Edge from " + e.src + " to " + e.dest + " with weight " + e.weight);
    //         }
    //         System.out.println("-----------------");
    //     }
    }
}






import java.util.ArrayList;

// Edge class with source, destination, and weight
class Edge {
    int src, dest, wt;

    public Edge(int src, int dest, int wt) {
        this.src = src;
        this.dest = dest;
        this.wt = wt;
    }
}

public class Graph {
    // Function to create the graph
    public static void createGraph(ArrayList<Edge>[] graph) {
        // Initialize the array of ArrayLists
        for (int i = 0; i < graph.length; i++) {
            graph[i] = new ArrayList<>();
        }

        // Original edges
        graph[0].add(new Edge(0, 1, 5));
        graph[0].add(new Edge(0, 2, 3));
        graph[1].add(new Edge(1, 3, 6));
        graph[2].add(new Edge(2, 3, 7));
        graph[3].add(new Edge(3, 4, 4));
        graph[4].add(new Edge(4, 0, 2));

        // Additional edges
        graph[1].add(new Edge(1, 2, 1));
        graph[2].add(new Edge(2, 4, 8));
        graph[4].add(new Edge(4, 1, 9));
    }

    // Function to print the graph
    public static void printGraph(ArrayList<Edge>[] graph) {
        for (int i = 0; i < graph.length; i++) {
            for (Edge e : graph[i]) {
                System.out.println("From " + e.src + " to " + e.dest + " with weight " + e.wt);
            }
        }
    }

    public static void main(String[] args) {
        int V = 5; // Number of vertices
        ArrayList<Edge>[] graph = new ArrayList[V];

        createGraph(graph);
        printGraph(graph);
    }
}

/*
    GRAPH STRUCTURE (Directed & Weighted):

            (0)
           /   \
         5/     \3
         /       \
       (1) -----> (2)
        | 1        | \
       6|         7|  \8
        |          |   \
       (3) ------> (4)
             4      ↑
                   9|
                   (1)

    Nodes: 0, 1, 2, 3, 4
    Directed Edges with Weights:
    0 -> 1 (5), 0 -> 2 (3)
    1 -> 3 (6), 1 -> 2 (1)
    2 -> 3 (7), 2 -> 4 (8)
    3 -> 4 (4)
    4 -> 0 (2), 4 -> 1 (9)
*/







--------------------------------------------------------------





      import java.util.*;

public class GraphDFS {
    static class Graph {
        int V;
        ArrayList<ArrayList<Integer>> adj;

        // Constructor
        Graph(int V) {
            this.V = V;
            adj = new ArrayList<>();
            for (int i = 0; i < V; i++)
                adj.add(new ArrayList<>());
        }

        // Add edge
        void addEdge(int u, int v) {
            adj.get(u).add(v);
            adj.get(v).add(u); // Omit this if it's a directed graph
        }

        // DFS Utility
        void dfsUtil(int v, boolean[] visited) {
            visited[v] = true;
            System.out.print(v + " ");

            for (int neighbor : adj.get(v)) {
                if (!visited[neighbor])
                    dfsUtil(neighbor, visited);
            }
        }

        // DFS from a given start node
        void dfs(int start) {
            boolean[] visited = new boolean[V];
            System.out.print("DFS traversal starting from node " + start + ": ");
            dfsUtil(start, visited);
            System.out.println();
        }
    }

    // Main
    public static void main(String[] args) {
        Graph g = new Graph(5);
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 3);
        g.addEdge(1, 4);

        /*
         Graph visualization:

             0
            / \
           1   2
          / \
         3   4

        Output of DFS from node 0: 0 1 3 4 2
        */

        g.dfs(0);
    }
}
