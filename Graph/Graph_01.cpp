// /* Day-01 of learning Graphs in C++ by taught Apna-College (Shradha Khapra).
//    Graph is a network of Nodes 
// */

// // Implementation of Graph using Adjacency List

// // #include<iostream>
// // #include<vector>
// // #include<list>
// // using namespace std;
// // // creating Graph class from scratch
// // class Graph {
// //     int V; // Number of varices of the graph
// //     list<int>* l; // dynamic list (doubly-linkedlist) to store the neighbors of the graph of size V
// // public:
// // // constructor
// //     Graph(int V) {
// //         this->V = V; // putting the value of V into the parameterized constructor Graph 
// //         l = new list<int> [V]; // creating list of size V
// //     }
    
// //     // function/method to add edges 
// //     void addEdge(int u, int v){
// //         l[u].push_back(v);
// //         l[v].push_back(u);
// //     }

// //     // function to pring graph
// //     void print(){
// //         for(int u=0;u<V;u++){
// //             list<int> neighbors = l[u];
// //             cout<<u<<" : ";
// //             for(int v: neighbors){
// //                 cout<<v<<" ";
// //             }
// //             cout<<"\n";
// //         }
// //     }
// // };



// // int main(){
// //     Graph graph(5); // creating graph 
// //     graph.addEdge(0,1);// adding edges
// //     graph.addEdge(1,2);// adding edges
// //     graph.addEdge(1,3);// adding edges
// //     graph.addEdge(2,3);// adding edges
// //     graph.addEdge(2,4);// adding edges
    
// //     graph.print();// calling print function
// //     return 0;
// // };

// /* 
// output = 0 : 1
//          1 : 0 2 3
//          2 : 1 3 4
//          3 : 1 2
//          4 : 2  
// */


// // Breath-First-Search (BFS) in Graph
// // #include<iostream>
// // #include<vector>
// // #include<list>
// // #include<queue>
// // using namespace std;
// // // creating Graph class from scratch
// // class Graph {
// //     int V; // Number of varices of the graph
// //     list<int>* l; // dynamic list (doubly-linkedlist) to store the neighbors of the graph of size V
// // public:
// // // constructor
// //     Graph(int V) {
// //         this->V = V; // putting the value of V into the parameterized constructor Graph 
// //         l = new list<int> [V]; // creating list of size V
// //     }
    
// //     // function/method to add edges 
// //     void addEdge(int u, int v){
// //         l[u].push_back(v);
// //         l[v].push_back(u);
// //     }

// //     // function to pring graph
// //     void print(){
// //         for(int u=0;u<V;u++){
// //             list<int> neighbors = l[u];
// //             cout<<u<<" : ";
// //             for(int v: neighbors){
// //                 cout<<v<<" ";
// //             }
// //             cout<<"\n";
// //         }
// //     }

// //     void BFS(){
// //         queue<int> q;
// //         vector<bool> vis(V,false);
// //         q.push(0);
// //         vis[0]=true;

// //         while(q.size()>0){
// //             int u = q.front();
// //             q.pop();
// //             cout<<u<<" ";
// //             list<int> neighbors = l[u];
// //             for(int v:neighbors){
// //                 if(!vis[v]){
// //                     vis[v]= true;
// //                     q.push(v);
// //                 }
            
// //             }
// //         }
// //         cout<<"\n";
// //     }
// // };



// // int main(){
// //     Graph graph(7);      // creating graph 
// //     graph.addEdge(0,1);  // adding edges
// //     graph.addEdge(0,2);  // adding edges
// //     graph.addEdge(1,3);  // adding edges
// //     graph.addEdge(2,4);  // adding edges
// //     graph.addEdge(3,5);  // adding edges
// //     graph.addEdge(4,5);  // adding edges
// //     graph.addEdge(5,6);  // adding edges
    
// //     //graph.print(); calling print function
// //     graph.BFS();
// //     return 0;
// // };

// // /*
// //     output = 0 1 2 3 4 5 6
// // */







// // creating va graph using adjacency list in C++
// #include<iostream>
// #include<list>
// using namespace std;

// class Graph {
//     int v;
//     list<int>* l;
//     public:
//         Graph(int v) {
//         this->v=v;
//         this->l= new list<int>[v];
//         }


//         void addEdge(int u,int v){
//             l[u].push_back(v);
//             l[v].push_back(u);
//         }

//         void print() {
//             for(int i=0;i<v;i++){
//                 cout<<i<<" : ";
//                 for(int j:l[i]){
//                     cout<<j<<" ";
//                 }
//                 cout<<"\n";
//             }
//         }

//         ~Graph() {
//             delete[] l; // Free dynamically allocated memory for the adjacency list
//         }

//         // Destructor to clean up the dynamically allocated memory
//         // Note: The destructor is important to avoid memory leaks, especially in larger applications.a1
//         // If you have other resources to clean up, you can add them here as well.a1

        
        

        
        


//     };


// int main(){
//     Graph graph(5);
//     graph.addEdge(0,1);
//     graph.addEdge(1,2);
//     graph.addEdge(1,3); 
//     graph.addEdge(2,3);
//     graph.addEdge(2,4);
    
//     graph.print();
//     // Output:
//     // 0 : 1
//     // 1 : 0 2 3
//     // 2 : 1 3 4
//     // 3 : 1 2
//     // 4 : 2


//     return 0;
// }









// /* Day-01 of learning Graphs in C++ by taught Apna-College (Shradha Khapra).
//    Graph is a network of Nodes 
// */

// // Implementation of Graph using Adjacency List

// // #include<iostream>
// // #include<vector>
// // #include<list>
// // using namespace std;
// // // creating Graph class from scratch
// // class Graph {
// //     int V; // Number of varices of the graph
// //     list<int>* l; // dynamic list (doubly-linkedlist) to store the neighbors of the graph of size V
// // public:
// // // constructor
// //     Graph(int V) {
// //         this->V = V; // putting the value of V into the parameterized constructor Graph 
// //         l = new list<int> [V]; // creating list of size V
// //     }
    
// //     // function/method to add edges 
// //     void addEdge(int u, int v){
// //         l[u].push_back(v);
// //         l[v].push_back(u);
// //     }

// //     // function to pring graph
// //     void print(){
// //         for(int u=0;u<V;u++){
// //             list<int> neighbors = l[u];
// //             cout<<u<<" : ";
// //             for(int v: neighbors){
// //                 cout<<v<<" ";
// //             }
// //             cout<<"\n";
// //         }
// //     }
// // };



// // int main(){
// //     Graph graph(5); // creating graph 
// //     graph.addEdge(0,1);// adding edges
// //     graph.addEdge(1,2);// adding edges
// //     graph.addEdge(1,3);// adding edges
// //     graph.addEdge(2,3);// adding edges
// //     graph.addEdge(2,4);// adding edges
    
// //     graph.print();// calling print function
// //     return 0;
// // };

// /* 
// output = 0 : 1
//          1 : 0 2 3
//          2 : 1 3 4
//          3 : 1 2
//          4 : 2  
// */


// // Breath-First-Search (BFS) in Graph
// // #include<iostream>
// // #include<vector>
// // #include<list>
// // #include<queue>
// // using namespace std;
// // // creating Graph class from scratch
// // class Graph {
// //     int V; // Number of varices of the graph
// //     list<int>* l; // dynamic list (doubly-linkedlist) to store the neighbors of the graph of size V
// // public:
// // // constructor
// //     Graph(int V) {
// //         this->V = V; // putting the value of V into the parameterized constructor Graph 
// //         l = new list<int> [V]; // creating list of size V
// //     }
    
// //     // function/method to add edges 
// //     void addEdge(int u, int v){
// //         l[u].push_back(v);
// //         l[v].push_back(u);
// //     }

// //     // function to pring graph
// //     void print(){
// //         for(int u=0;u<V;u++){
// //             list<int> neighbors = l[u];
// //             cout<<u<<" : ";
// //             for(int v: neighbors){
// //                 cout<<v<<" ";
// //             }
// //             cout<<"\n";
// //         }
// //     }

// //     void BFS(){
// //         queue<int> q;
// //         vector<bool> vis(V,false);
// //         q.push(0);
// //         vis[0]=true;

// //         while(q.size()>0){
// //             int u = q.front();
// //             q.pop();
// //             cout<<u<<" ";
// //             list<int> neighbors = l[u];
// //             for(int v:neighbors){
// //                 if(!vis[v]){
// //                     vis[v]= true;
// //                     q.push(v);
// //                 }
            
// //             }
// //         }
// //         cout<<"\n";
// //     }
// // };



// // int main(){
// //     Graph graph(7);      // creating graph 
// //     graph.addEdge(0,1);  // adding edges
// //     graph.addEdge(0,2);  // adding edges
// //     graph.addEdge(1,3);  // adding edges
// //     graph.addEdge(2,4);  // adding edges
// //     graph.addEdge(3,5);  // adding edges
// //     graph.addEdge(4,5);  // adding edges
// //     graph.addEdge(5,6);  // adding edges
    
// //     //graph.print(); calling print function
// //     graph.BFS();
// //     return 0;
// // };

// // /*
// //     output = 0 1 2 3 4 5 6
// // */







// // creating va graph using adjacency list in C++
// #include<iostream>
// #include<list>
// using namespace std;

// class Graph {
//     int v;
//     list<int>* l;
//     public:
//         Graph(int v) {
//         this->v=v;
//         this->l= new list<int>[v];
//         }


//         void addEdge(int u,int v){
//             l[u].push_back(v);
//             l[v].push_back(u);
//         }

//         void print() {
//             for(int i=0;i<v;i++){
//                 cout<<i<<" : ";
//                 for(int j:l[i]){
//                     cout<<j<<" ";
//                 }
//                 cout<<"\n";
//             }
//         }

//         ~Graph() {
//             delete[] l; // Free dynamically allocated memory for the adjacency list
//         }

//         // Destructor to clean up the dynamically allocated memory
//         // Note: The destructor is important to avoid memory leaks, especially in larger applications.a1
//         // If you have other resources to clean up, you can add them here as well.a1

        
        

        
        








#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
    GRAPH STRUCTURE (Undirected, Unweighted):

            0
           / \
          1   2
           \   \
            3---4
             \ /
              5
              |
              6

    Edges:
    0 - 1, 0 - 2
    1 - 3
    2 - 4
    3 - 4, 3 - 5
    4 - 5
    5 - 6

    BFS Traversal from node 0: 0 1 2 3 4 5 6  
    DFS Traversal from node 0: 0 1 3 5 6 4 2
*/

// Edge class with source, destination, and weight
class Edge {
public:
    int src, dest, weight;

    // Constructor using 'this' keyword
    Edge(int src, int dest, int weight) {
        this->src = src;
        this->dest = dest;
        this->weight = weight;
    }
};

// Create the graph as an adjacency list
void createGraph(vector<Edge> graph[], int V) {
    for (int i = 0; i < V; i++) {
        graph[i] = vector<Edge>();
    }

    // Add bidirectional edges
    graph[0].push_back(Edge(0, 1, 1));
    graph[0].push_back(Edge(0, 2, 1));

    graph[1].push_back(Edge(1, 0, 1));
    graph[1].push_back(Edge(1, 3, 1));

    graph[2].push_back(Edge(2, 0, 1));
    graph[2].push_back(Edge(2, 4, 1));

    graph[3].push_back(Edge(3, 1, 1));
    graph[3].push_back(Edge(3, 5, 1));
    graph[3].push_back(Edge(3, 4, 1));

    graph[4].push_back(Edge(4, 3, 1));
    graph[4].push_back(Edge(4, 5, 1));

    graph[5].push_back(Edge(5, 3, 1));
    graph[5].push_back(Edge(5, 6, 1));
    graph[5].push_back(Edge(5, 4, 1));
}

// BFS Traversal
void BFS_Traversal(vector<Edge> graph[], int V) {
    vector<bool> visited(V, false);
    queue<int> q;

    q.push(0); // Start from vertex 0

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (!visited[curr]) {
            visited[curr] = true;
            cout << curr << " ";

            for (Edge e : graph[curr]) {
                if (!visited[e.dest]) {
                    q.push(e.dest);
                }
            }
        }
    }
    cout << endl;
}

// DFS Helper (Recursive)
void DFS_Helper(int curr, vector<Edge> graph[], vector<bool>& visited) {
    visited[curr] = true;
    cout << curr << " ";

    for (Edge e : graph[curr]) {
        if (!visited[e.dest]) {
            DFS_Helper(e.dest, graph, visited);
        }
    }
}

// DFS Traversal
void DFS_Traversal(vector<Edge> graph[], int V) {
    vector<bool> visited(V, false);
    DFS_Helper(0, graph, visited);
    cout << endl;
}

// Main Function
int main() {
    int V = 7;
    vector<Edge> graph[V];

    createGraph(graph, V);

    cout << "BFS Traversal of the graph: ";
    BFS_Traversal(graph, V);

    cout << "DFS Traversal of the graph: ";
    DFS_Traversal(graph, V);

    return 0;
}
