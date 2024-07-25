# Six Degrees of Kevin Bacon Game: It’s a Small World After All

## Overview
This assignment involves creating a C/C++ program to solve the "Six Degrees of Kevin Bacon" game by parsing movie credit data into a graph and performing shortest path computations to connect actors through their co-acted movies. The program must efficiently handle over 100,000 movies and a similar number of actors to find the shortest connection paths.

## Details
- **Objective:** Design a program that finds the shortest path between two given actors based on their movie collaborations.
- **Data Input:** The dataset (`cleaned_movielist.txt`) contains movie and actor data. Each line lists a movie followed by its actors.
- **Program Input/Output:** For each pair of actors in the input file, the program must output the shortest path between them or indicate if no path exists.
- **Requirements:** Provide a Makefile and executable (`sixdegrees`), Use only C/C++ for all implementations.
- **Data Structures:** Use graph representations, such as adjacency lists, and implement BFS for pathfinding.
- **Testing:** Includes predefined test cases (`simple-input.txt`, `more-input.txt`).

## How to Run

1. **Setup:**
    - Ensure all your code files (`*.c`, `*.cpp`, `*.h`, `*.hpp`) are in the `Sixdegrees` directory.
    - Make sure the dataset file `cleaned_movielist.txt` is available in the same directory.

2. **Compilation:**
    - Use the provided Makefile to compile the program. Run the following command in the terminal:
      ```sh
      make
      ```

3. **Execution:**
    - Run the executable `sixdegrees` with two command line arguments: the input file and the output file.
      ```sh
      ./sixdegrees <input_file> <output_file>
      ```
    - Example:
      ```sh
      ./sixdegrees simple-input.txt simple-output.txt
      ```

4. **Input File Format:**
    - Each line of the input file should contain two actor names separated by a space.
      ```
      ACTOR1 ACTOR2
      ```

5. **Output File Format:**
    - For each line in the input file, the output file will contain the shortest path between the two actors or indicate "Not present" if no path exists.
    - Format for shortest path:
      ```
      ACTOR1 -(MOVIE1)- ACTOR2 -(MOVIE2)- ACTOR3
      ```

## Additional Information
- **Source Data:** The raw data is sourced from [IMDB datasets](https://datasets.imdbws.com/) and [IMDB interfaces](https://www.imdb.com/interfaces/).
This project is a great opportunity to apply your knowledge in graph theory and algorithms, particularly BFS, to a fun and engaging problem!
