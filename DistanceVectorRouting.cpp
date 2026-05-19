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

    cout << "Enter cost matrix:\n";

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    int source = 0;

    // Initialize distance
    for(int i = 0; i < n; i++) {
        dist[i] = cost[source][i];
    }

    // Bellman Ford Logic
    for(int k = 0; k < n - 1; k++) {

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < n; j++) {

                if(dist[j] > dist[i] + cost[i][j]) {

                    dist[j] = dist[i] + cost[i][j];
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