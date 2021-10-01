
/*
 * https://www.geeksforgeeks.org/snake-ladder-problem-2/
 *
 * Snake and ladder: This is a directed graph problem and uses BFS.
 * Time complexity: O(n)
 */

#include <iostream>
#include <queue>

using namespace std;

// An entry used in BFS

struct queueEntry {
    int v; // vertex number
    int dist; // Distance of this vertex from source
};


int getMinDiceThrow(int move[], int N) {

    vector<bool> visited(N, false);
    queue<queueEntry> q; // BFS uses queue FIFO.

    visited[0] = true;
    queueEntry s = {0, 0}; // distance of 0'th vertex is also 0.
    q.push(s);

    queueEntry qe;
    while (!q.empty()) {
        qe = q.front();
        int v = qe.v;

        // we are at the destination
        if (v == N - 1) {
            break;
        }
        q.pop();

        for(int i = v+1; i <= (v+6) && i < N; i++) {
            if (!visited[i]) {

                queueEntry a;
                a.dist = qe.dist + 1;
                visited[i] = true;

                if (move[i] != -1) {
                    a.v = move[i];
                } else {
                    a.v = i;
                }
                q.push(a);
            }
        }
    }
    return qe.dist;
}


int main()
{
    int N = 30;
    int move[N];
    for (int i = 0; i < N; i++) {
        move[i] = -1;
    }

    // ladders
    move[2] = 21;
    move[4] = 7;
    move[10] = 25;
    move[19] = 28;

    // snakes
    move[26] = 0;
    move[20] = 8;
    move[16] = 3;
    move[18] = 6;

    cout << "Min Dice throws required is " << getMinDiceThrow(move, N) << endl;
    return 0;
}
