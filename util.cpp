#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(const std::string& s) {
    std::string result;
    for (char c : s) {
        result += std::tolower(static_cast<unsigned char>(c));
    }
    return result;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
std::set<std::string> keywords;
    std::string keyword;
    
    for (char c : rawWords) {
         
        if (std::isalnum(c)) {
            keyword += c;
        } else {
            if (keyword.length() > 1) {   
                keywords.insert(convToLower(keyword));
            }
            keyword.clear();
        }
    }
    if (keyword.length() > 1) 
    {
        keywords.insert(convToLower(keyword));
    }

    return keywords;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring

std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
