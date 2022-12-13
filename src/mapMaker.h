#pragma once
#include <map>
#include <sstream>

#include "../lib/graph.h"
#include "../lib/edge.h"
#include "utils.h"

using std::vector;
using std::map;
using std::stringstream;

/**
 * Accounting for removing the brackets, that is, the parenthesis and content inside it, in given string
 * 
 * @param s The input string
 * @return The input string after removed the parenthesis and content inside it
*/
std::string trim_Brackets(std::string s); 

/**
 * Takes a filename and read the content in this file. Output a 2D vector filled vectors in the form of StopA, time interval, StopB
 * 
 * @param filename file ready to be read
 * @return A 2D vector filled vectors in the form of StopA, time interval, StopB
*/
std::vector<std::vector<std::string>> file_to_Vec(std::string filename);

/**
 * Receving a 2D vector and A empty map, which will make a graph based on vector and fill map with vertex as the key
 * and corrosponding busline as the value
 * 
 * @param stopinfo 2-D vector obtained by the function file_to_Vec, each vector<string> includes a busline, a stop A, 
 *                 time interval between A and B, and a stop B
 * @param m  Mapping each bus stop to a vector containing all buslines pass through it
 * @return a completed graph which vertices are bus stops and edges are time intervals
*/
Graph makeGraph(std::vector<std::vector<std::string>> stopinfo, std::map<std::string, std::vector<string>> &m);

/**
 * A function assembled the functionality of both file_to_Vec and makeGraph, which will output a completed
 * weighted and directed graph
 * 
 * @param filename file ready to be read
 * @return A completed weighted and directed graph read data from filename
*/
Graph init(std::string filename);

/**
 * Overloaded version of method above, additionally take a empty m and fill with vertex as key and
 * corrosponding buslines as the value
 * 
 * @param filename file ready to be read
 * @return A completed weighted and directed graph read data from filename
*/
Graph init(std::string filename, std::map<std::string, std::vector<string>> &m);