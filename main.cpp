#include <cstdlib>
#include "bfs.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
    if (argc != 3) {
        cerr << "Usage: ./listwrapper <INPUT_FILE> <OUTPUT_FILE>" << endl;
        return 1;
    }

    ifstream inputFile(argv[1]);
    ifstream movieData("cleaned_movielist.txt"); 
    ofstream outputFile(argv[2]);
    Graph graph;

    if (!movieData) {
        cerr << "Failed to open the movie data file." << endl;
        return 1;
    }

    // Read movie data and build the graph
    string line;
    while (getline(movieData, line)) {
        istringstream iss(line);
        string movie;
        vector<string> actors;
        string actor;

        getline(iss, movie, ' ');  // Assume the first token before a space is the movie title

        while (getline(iss, actor, ' ')) {
            actors.push_back(actor);
        }

        // Add edges between all pairs of actors for this movie
        for (size_t i = 0; i < actors.size(); ++i) {
            for (size_t j = i + 1; j < actors.size(); ++j) {
                graph.addEdge(actors[i], actors[j], movie);
            }
        }
    }
    movieData.close();

    // Process each pair of actors from the input file
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string actor1, actor2;
        if (!(iss >> actor1 >> actor2)) { break; } // error

        if (actor1 == actor2) {
            if (graph.isActorPresent(actor1)) {  // Check if the actor exists in the graph
                outputFile << actor1 << endl;
            } else {
                outputFile << "Not present" << endl;
            }
        } else {
            string path = graph.bfs(actor1, actor2);
            if (path == "Not present") {
                outputFile << "Not present" << endl;
            } else {
                outputFile << path << endl;
            }
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
