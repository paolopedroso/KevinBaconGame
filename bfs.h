#ifndef BFS_H
#define BFS_H

#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>

using namespace std;

class Graph {
public:
    void addEdge(const string& actor1, const string& actor2, const string& movie);
    string bfs(const string& start, const string& goal);
    bool isActorPresent(const string& actor) const;

private:
    unordered_map<string, unordered_map<string, set<string>>> adj;
};

#endif // BFS_H
