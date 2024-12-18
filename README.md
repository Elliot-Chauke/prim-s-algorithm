C++ program determines the Minimum Spanning Tree (MST)
for Company XFibre to install fiber cables in a neighborhood, 
minimizing the overall cost. 
It uses Prim's Algorithm with an Adjacency Matrix representation for graph data. 
The program has a time complexity of O(n²) and is designed for simplicity and efficiency.

Uses an adjacency matrix to represent paths and their associated costs.

Constructs the MST by iteratively adding the least expensive edge.
Guarantees optimal paths for fiber installation while respecting constraints.
Input and Output:

Input: Graph details (number of vertices, edges, and their weights) provided in a text file.
Output: Displays the MST edges and their total cost.
File Requirements:
Input file: Located at c:\data\fiberdata.txt.
Format:
Number_of_Vertices Number_of_Edges  
StartVertex EndVertex Weight  

Example:

5 7  
1 2 3  
1 3 2  
2 3 4  
2 4 6  
3 4 5  
3 5 8  
4 5 7  

Usage
Ensure the input file is correctly formatted and placed at c:\data\fiberdata.txt.
Compile and run the program using a C++ compiler.
View the MST and total cost in the console output.
