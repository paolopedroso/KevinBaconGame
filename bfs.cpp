#include <cstdlib>
#include "bfs.h"
#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Define the addEdge function to connect two actors with a movie
void Graph::addEdge(const string& actor1, const string& actor2, const string& movie) {
    adj[actor1][actor2].insert(movie); // Insert movie into adjacency list for actor1 to actor2
    adj[actor2][actor1].insert(movie); // Insert movie into adjacency list for actor2 to actor1
}

// Define the BFS function to find the shortest path between two actors
string Graph::bfs(const string& start, const string& goal) {
    if (adj.find(start) == adj.end() || adj.find(goal) == adj.end())
        return "Not present"; // Check if either actor is not in the graph

    queue<string> q; // BFS queue
    unordered_map<string, pair<string, string>> parent; // Map to store parent and movie
    unordered_set<string> visited; // Set to track visited actors

    q.push(start); // Start BFS from the start actor
    visited.insert(start); // Mark start as visited
    parent[start] = {"", ""}; // Start actor has no parent

    while (!q.empty()) {
        string current = q.front(); // Get the front actor from the queue
        q.pop();

        if (current == goal) {
            // Construct the path by backtracking from goal to start
            string path = "";
            string step = goal;
            while (step != start) {
                string par = parent[step].first;
                string mov = parent[step].second;
                if (!path.empty()) {
                    path = " -(" + mov + ")- " + step + path;
                } else {
                    path = " -(" + mov + ")- " + step;
                }
                step = par;
            }
            return start + path; // Include start in the path
        }

        for (const auto& neighbor : adj[current]) {
            if (visited.find(neighbor.first) == visited.end()) {
                visited.insert(neighbor.first); // Mark neighbor as visited
                // Sort the movies and pick the lexicographically smallest one
                vector<string> movies(neighbor.second.begin(), neighbor.second.end());
                sort(movies.begin(), movies.end());
                parent[neighbor.first] = {current, movies[0]}; // Store parent and the smallest movie
                q.push(neighbor.first); // Push neighbor to the queue
            }
        }
    }

    return "Not present"; // If no path is found
}

// Define isActorPresent function to check if an actor is in the graph
bool Graph::isActorPresent(const string& actor) const {
    return adj.find(actor) != adj.end(); // Return true if the actor is found in the adjacency list, otherwise false
}
