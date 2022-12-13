#include <utility>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cassert>
#include <fstream>

#include "../src/mapMaker.h"
#include "../src/shortestPath.h"

/**
 * Imported class and implementations from MP_schedule, altered part of its methods
 * Added several new functions made by ourselves
 * 
 * Thanks the string algorithem this lab offered
 * Dec/12/2022 BY group SMARTPOINTER
*/

/**
 * Takes a filename and reads in all the text from the file
 * Newline characters are also just characters in ASCII
 * 76-98         Z
 * @param filename The name of the file that will fill the string
 * @return A string containing the whole text of the given file
 */
std::string file_to_string(const std::string & filename);

/**
* Functions for the removal of whitespace to the left or right of a string (or both)
*
* @param str The string being processed
* @return The processed string
*/
std::string TrimRight(const std::string & str);
std::string TrimLeft(const std::string & str);
std::string Trim(const std::string & str);

/**
 * Given a string and character, split the string by the character and store in a vector
 * A 'split' string treats the character as a breakpoint and creates a separate item
 * in the output vector for each substring. 
 * 
 * NOTE: The separator character is not included in the substrings.
 * 
 * The total number of substrings created (the length of fields) is returned 
 *  
 * @param str1 The string being split
 * @param sep The separator character
 * @param fields The string vector storing all substrings created by the split
 * @return The number of substrings created
 */
int SplitString(const std::string & str1, char sep, std::vector<std::string> &fields);

/**
 * Comparing the given two pair, which is similar to the overload of opeartor<
 * 
 * @param a The first input
 * @param b The second input
 * @return a < b
*/
bool cmp(std::pair<std::string, int>& a, std::pair<std::string, int>& b);

/**
 *  Accounting for user to type their current bus stop and destination stop
 * 
 * @param g The input graph which account for determing whether user typed a correct BUS stop name
 * @param input A array with max length of 30, ready for user to input their stop name
 * @return A string typed by user
*/
std::string type_name(const Graph& g, std::array<char, 30>& input);