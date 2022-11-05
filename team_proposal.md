## Leading Question 

It’s annoying to miss a class or an appointment due to one’s unfamiliarity with the bus routes in Champaign-Urbana. To avoid such situations, finding the fastest route of public transportation is the most accessible solution. Therefore, we want to implement an algorithm that tells the fastest possible routes for the buses to take, when the user imports the information needed. 

## Dataset Acquisition

From the official site of local public transportation. Once we have the bus stop and corresponding bus line, we can create a CSV file to store that data and initialize a grid-based map using the data from that file. 

## Data Format

Graph, Vector, and Queue. We will store the data (the name of stops, their distances to the next stop) of each bus stop in various nodes, and connect them with weighted edges in both directions, meaning the bus in the same line can move in both directions. The vector will be used in the BFS algorithm.

## Data Correction

We will first calculate the distance between the client's current location and the nearest bus stop. If the distance calculated above is more than 2 KMs, we will recommend the client take a taxi or drive to the destination. Meanwhile, if the client’s current location is out of the map we created, we will output an error.

## Data Storage

We will store our data from the CSV file in a set of nodes, and form a graph with corresponding edges between each node. According to the Algorithm we listed below, we estimate the space complexity we will reach is O(N) (N means the number of stations in the CSV file)

## Algorithm 

We will use the BFS algorithm to search for the shortest path on bus routes provided between two places. The input CSV file should include all the information on bus routes, for each line it represents one route number, followed by the order of bus stops it goes through. The file should also include the information that represents the location of each bus stop or the distance between bus stops, to calculate the distances through our algorithm. We will utilize the input file to create a graph in which each node represents a bus stop and each directed edge represents the path that a bus can travel. 

The function of our algorithm would output the choices of bus and a path of bus stops that represents the fastest way to travel between two places. 

Both the time complexity and space complexity would be approximately O(V^2) where V is the number of nodes. 

## Timeline

**Week 1 **

Decide the project and the leading question we want to solve.

**Week 2 **

Collect all the possible or required data, the CSV file of the bus routes, and the station location coordination.

**Week 3 **

Finish the construction function of the graph, that is the map (midterm goal)

**Week 4 **

Finish the function of finding the shortest route.

**Week 5 **

Prepare for the presentation, and the slides.