#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2) {
    std::set<T> result;
    if (s1.size() < s2.size()) {
        for (const T& item : s1) {
            if (s2.find(item) != s2.end()) {
                result.insert(item);
            }
        }
    } 
    else 
    {
        for (const T& item : s2) {
            if (s1.find(item) != s1.end()) {
                result.insert(item);
            }
        }
    }
    return result;
}

template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
    std::set<T> result = s1;
    result.insert(s2.begin(), s2.end());
    return result;
}


/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(const std::string& src);


std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s);

// Removes any trailing whitespace
std::string &rtrim(std::string &s);

// Removes leading and trailing whitespace
std::string &trim(std::string &s);
#endif
