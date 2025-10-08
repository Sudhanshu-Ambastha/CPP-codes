#include <iostream>
using namespace std;

#define INF 99999

int get_min_dist_vertex(int V, int dist[], bool processed[]) {
    int u = -1;
    int min_dist = INF;
    
    for (int v = 0; v < V; v++) {
        if (!processed[v] && dist[v] < min_dist) {
            min_dist = dist[v];
            u = v;
        }
    }
    return u;
}

void print_distances(int V, int source, int dist[]) {
    cout << "\nShortest Distances from Source Vertex " << source << ":\n";
    cout << "------------------------------------------\n";
    for (int i = 0; i < V; i++) {
        cout << "To Vertex " << i << ": ";
        if (dist[i] == INF) {
            cout << "Unreachable\n";
        } else {
            cout << dist[i] << "\n";
        }
    }
}

void dijkstra(int V, int** graph, int source) {
    int* dist = new int[V]; 
    bool* processed = new bool[V]; 

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        processed[i] = false;
    }
    
    dist[source] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = get_min_dist_vertex(V, dist, processed);

        if (u == -1) break;

        processed[u] = true;

        for (int v = 0; v < V; v++) {
            if (!processed[v] && graph[u][v] != 0 && 
                dist[u] != INF && (dist[u] + graph[u][v] < dist[v])) {
                
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    print_distances(V, source, dist);
    
    delete[] dist;
    delete[] processed;
}

void cleanup_graph(int V, int** graph) {
    for (int i = 0; i < V; i++) {
        delete[] graph[i];
    }
    delete[] graph;
}

int main() {
    int V;
    cout << "Enter the number of vertices (nodes): ";
    cin >> V;
    
    if (V <= 0) {
        cout << "Invalid number of vertices.\n";
        return 1;
    }

    int** graph = new int*[V];
    for (int i = 0; i < V; i++) {
        graph[i] = new int[V];
    }

    cout << "Enter the adjacency matrix (weights):\n";
    cout << "Enter 0 for no direct edge between nodes.\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << "Weight from " << i << " to " << j << ": ";
            cin >> graph[i][j];
        }
    }

    int source_vertex;
    cout << "Enter the source vertex (0 to " << V - 1 << "): ";
    cin >> source_vertex;

    if (source_vertex < 0 || source_vertex >= V) {
        cout << "Invalid source vertex.\n";
        cleanup_graph(V, graph);
        return 1;
    }
    
    dijkstra(V, graph, source_vertex);
    
    cleanup_graph(V, graph);

    return 0;
}
