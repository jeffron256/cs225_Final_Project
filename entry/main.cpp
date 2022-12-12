#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <array>

#include "../src/mapMaker.h"
#include "../src/shortestPath.h"

using std::cout;
using std::endl;

int main(void)
{
    std::array<char, 30> str1, str2;
    std::string str_one, str_two;
    Graph g = init("../data/bus_stop_info_weekday.csv");
    std::vector<Vertex> vertices = g.getVertices();

    printf("Hi! Welcome to use the MTD bus route FINDER(Ver4.0) made by group SMARTPOINTER\n");
    printf("Please enter your current BUS stop:\n");

    str_one = type_name(g, str1);

    printf("Your current BUS stop is %s\n", str1.data());
    printf("Now please enter your destination stop:\n");

    str_two = type_name(g, str2);
    
    printf("Your destination BUS stop is %s\n", str2.data());

    if (str_one == str_two) {
        printf("You cannot have a route between two same BUS stop!\n");
        return 1;
    }

    printf("You have finished entering your stop.\n");
    cout << "Your current stop is " << str_one << ", and Your destination stop is " << str_two << "." << endl;

    std::vector<Vertex> v = dijkstra(g, str_one, str_two);
    std::vector<Vertex> v2 = BFS(g, str_one, str_two);
    double time = time_needed(g, v);
    double time_2 = time_needed(g, v);

    printf("Your route have been created, CHECK IT OUT!!\n");

    if (v.size() == 1) {
        printf("Unfortunately, currently there is no any route between your entered two bus stops.");
        return 1;
    }

    printf("You route with least stops is:\n");

    for (auto i : v2) {
        if (i == v.back()) {
            cout << i << endl;
        } else {
            cout << i << "  ->  ";
        }
    }

    printf("And would approximately take about %f mins.\n", time_2);

    printf("You route with least time is:\n");

    for (auto i : v) {
        if (i == v.back()) {
            cout << i << endl;
        } else {
            cout << i << "  ->  ";
        }
    }

    printf("And would approximately take about %f mins.\n\n", time);

    printf("The top five BUS stops that are passed most frequently by different buses\n");
    auto m4 = Betw(g);
    vector<pair<string, int>> A;

    for (auto& it : m4) {
        A.push_back(it);
    }

    sort(A.begin(), A.end(), cmp);

    for (int i = 0; i < 5; i++) {
        cout << A[i].first << " " << A[i].second << endl;
    } 

    return 0;
}