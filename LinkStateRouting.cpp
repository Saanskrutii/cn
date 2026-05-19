#include <iostream>
using namespace std;

#define MAX 10
#define INF 9999

int main() {

    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    int cost[MAX][MAX];
    int dist[MAX];
    int visited[MAX];

    cout << "Enter cost matrix:\n";

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    int source = 0;

    // Initialize
    for(int i = 0; i < n; i++) {
        dist[i] = cost[source][i];
        visited[i] = 0;
    }

    dist[source] = 0;
    visited[source] = 1;

    // Dijkstra Algorithm
    for(int count = 1; count < n; count++) {

        int min = INF;
        int nextNode;

        for(int i = 0; i < n; i++) {

            if(dist[i] < min && !visited[i]) {
                min = dist[i];
                nextNode = i;
            }
        }

        visited[nextNode] = 1;

        for(int i = 0; i < n; i++) {

            if(!visited[i]) {

                if(min + cost[nextNode][i] < dist[i]) {
                    dist[i] = min + cost[nextNode][i];
                }
            }
        }
    }

    cout << "\nShortest Distance from Node 0:\n";

    for(int i = 0; i < n; i++) {
        cout << "Node " << i << " = " << dist[i] << endl;
    }

    return 0;
}