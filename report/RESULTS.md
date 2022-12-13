# Results report

We included several screenshots of the full-scale running of the main algorithms we used in the project in the directory. 

Since we made a graph to store the data, the visualization of our graph can be seen in the images called “Graph visualize”, and since the total amount of combination of vertices and edges are too much to be shown, we included approximately half of them in the images, which should be enough to show the correctness of our graph. 

For our output of BFS and Dijkstra algorithm, we’ve chosen several stops that are separated further away to include as many stops and bus lines within a single route as possible to show the overall correctness of the algorithm. These result are also shown in the screenshots in the same directory, with file names in the format “BFS&Dijkstra”.

The output of Betweenness Centrality for a full-scale run is a list of bus stops and its corresponding visiting frequency represented as an integer. The image showing which can be seen with name “Betweenness” in the same directory as this report. 

We’ve created three test cases for each main algorithm with one easy test, one medium test and one hard test, by utilizing different data sets as inputs and checking whether the results meet what we expected by drawing them out manually.

We did successfully solve our leading question — find the shortest route between two bus stops within the area of UIUC, and determine the stops that are used most frequently within this shortest path to give a clue of which stop might have most passengers entering the bus, so that the one could tend to find a seat prior to that. We’ve provided both the shortest path with least stops for people who don’t want the bus to stop much while they are traveling, and that with least time for people who only need to get to their destination as soon as possible. 

The estimated time we provided should be approximately the most ideal time taken if there is no traffic jam occurring. However, for real-world utilization, for it to be more practical, there are numerous other factors we need to take into consideration, such as the time waiting for the bus to reach the station, and the time lag due to a traffic jam or accident.

link of presentation: https://drive.google.com/file/d/1VF4XXhPpP9WzV_4tkRor6qOMis3EHTtC/view?usp=share_link