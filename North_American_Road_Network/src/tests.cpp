#include <iostream>
#include "Utils.h"
#include "Graph.h"


int tests() {
    
    //NOTE: Enough names for 15 vertices-- if more than 15 vertices for simulation, you will need more names
    vector<string> list = {"chicago", "new_york", "madison", "evanston", "urbana", "nashville", "tampa", "miami", "dallas", "austin", "houston",
        "atlanta", "san_francisco", "los_angeles", "san_diego", "seattle"
    };  
    map<int, string> cityMap;
    int city_count = 0;

    for(size_t num = 0; num < list.size(); num++) { //Constructs map with a city name associated with a number 0-length for mapping purposes 
        cityMap.insert({city_count, list.at(num)});
        city_count++;
    }

    for(auto itr = cityMap.begin(); itr != cityMap.end(); itr++) {  //prints cities mapped to their number
        cout<< "Number: " << itr->first << "   City: " << itr->second << endl;
    }

    //GRAPH 1
    int vertices = 5;
    Graph g1(vertices);
    g1.addEdge(0, 1, 10); //node 1, node 2, edge weight
    g1.addEdge(0, 2, 3);
    g1.addEdge(1, 2, 4);
    g1.addEdge(2, 3, 8);
    g1.addEdge(1, 3, 2);
    g1.addEdge(2, 4, 5);
    g1.addEdge(3, 4, 7);
    
    int src = 2, dest = 3;
    cout << "Testing BFS 1: "<<endl;
    cout<< "Should print: 3"<<endl;
    g1.findShortestPathBFS(src, dest);

    //GRAPH 2
    int vertices2 = 10;
    Graph g2(vertices2);
    g2.addEdge(0, 1, 4);
    g2.addEdge(0, 7, 8);
    g2.addEdge(1, 7, 11);
    g2.addEdge(7, 8, 7);
    g2.addEdge(7, 6, 1);
    g2.addEdge(1, 2, 8);
    g2.addEdge(2, 8, 2);
    g2.addEdge(8, 6, 6);
    g2.addEdge(6, 5, 2);
    g2.addEdge(2, 3, 7);
    g2.addEdge(2, 5, 4);
    g2.addEdge(3, 4, 9);
    g2.addEdge(3, 5, 14);
    g2.addEdge(5, 4, 10);
    g2.addEdge(4, 9, 3);
    
    int s = 1, d = 3;
    cout << "Testing BFS 2: "<<endl;
    cout<< "Should print: 2 3"<<endl;
    g2.findShortestPathBFS(s, d);
        
    //Uncomment below to test BFS for every node in the graph (do NOT do this for the full dataset)
    // for(int i = 0; i < vertices; i++) {    //change to vertices2 for for loops if testing graph 2
    //     src = i;
    //     for(int j = 0; j < vertices;j++) {
    //         dest = j;
    //         g1.findShortestPathBFS(src, dest);    //change to g2 if testing graph 2
    //         cout<< " ";
    //     }
    //     cout << endl;
    // }

    //Testing Dijkstra 1 
    cout << "Testing Dijkstra: \n" << endl;

    cout << "Graph 1: " << endl;
    vector<int> dijkstraVector; 
    cout<<"The path with the shortest distance starting at " << src << " and ending at " << dest << " is: " << endl;
    dijkstraVector = g1.dijkstra(src, dest);
    cout << "Should have printed: 3 <- 1 <- 2 with a distance of 6" << endl;
    cout<< "Matching vector test: " << endl;
    for(size_t i = 0; i < dijkstraVector.size(); i++) {
        cout << dijkstraVector[i] << endl;
    }
   

    cout << "Graph 2: " << endl;
    vector<int> dijkstraVector2; 
    cout<<"The path with the shortest distance starting at " << src << " and ending at " << dest << " is: " << endl;
    dijkstraVector2 = g2.dijkstra(s, d);
    cout << "Should have printed: 3 <- 2 <- 1 with a distance of 15" << endl;
    cout<< "Matching vector test: " << endl;
    for(size_t i = 0; i < dijkstraVector2.size(); i++) {
        cout << dijkstraVector2[i] << endl;
    }

    //Uncomment below to test Dijkstra's for every node in the graph (do NOT do this for the full dataset)
    // for(int i = 0; i < vertices; i++) {    //change to vertices2 for for loops if testing graph 2
    //     src = i;
    //     for(int j = 0; j < vertices;j++) {
    //         dest = j; 
    //         cout<<"The path with the shortest distance starting at " << src << " and ending at " << dest << " is: " << endl;
    //         dijkstraVector = g1.dijkstra(src, dest);    //change to g2 if testing graph 2
    //         cout<< " ";
    //     }
    //     cout << endl;
    // }
   

    //Testing map of cities with distances 
    cout << "Testing map of cities with distances: " << endl;   //<- possibly move this entire thing to a utils file if there are more functions like it 
    map<string, int> newMap = mapDistanceGraph(dijkstraVector, cityMap);
    printDistanceMap(newMap);



    //Tests for nearby cities to your location (given that distance is less than certain threshold) map<string, int> (vector<int> v, map<int, string> m)
    cout << "Printing Nearby Cities: " << endl;
    double range = 3.0;
    vector<int> nearbyVector = nearbyCities(dijkstraVector, range);
    for(size_t nearby = 0; nearby < nearbyVector.size(); nearby++) {
        string str = cityMap.find(nearby)->second;
        cout << str << endl;
    }



    //Test for adjacency matrix
    cout << "Testing Adjacency Matrix: " << endl;
    g1.printAdjencyMatrix();



    return 0;        
}
