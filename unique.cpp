/*******************************************************************************
 * Name        : unique.cpp
 * Author      : Armaan Khatri
 * Date        : 9/30/2023
 * Description : Determining uniqueness of chars with int as bit vector.
 * Pledge      : I pledge my honor that I have abided by the stevens honor system. 
 ******************************************************************************/
#include <iostream>
#include <cctype>

using namespace std;

bool is_all_lowercase(const string &s)
{
	unsigned int i = 0;
    unsigned int checker = 0xFFFFFFFF; // Initialize all bits to 1
    
    while (i < s.size()) {
        unsigned int bitMask = 1 << (s[i] - 'a');
        if ((checker & bitMask) == 0) {
            std::cout << "Error: String must contain only lowercase letters." << std::endl;
            return false;
        }
        ++i;
    }
    
    
    return true;
    //is_all_lowercase function checks if a function has all lowercase leters
    //by iterating through each later and calulcates the bitmask using bitwise operations
}

bool all_unique_letters(const string &s) {
    // TODO: returns true if all letters in string are unique, that is
    // no duplicates are found; false otherwise.

    // You MUST use only single unsigned integers and work with bitwise
    // and bitshifting operators only.  Using any other kind of solution
    // will automatically result in a grade of ZERO for the whole assignment.
     unsigned int bit = 0;
    int size = s.length();
    int i = 0;

    while (i < size) {
        unsigned int setter = 1 << (s[i] - 'a');
        int isVisited = bit & setter;

        if (isVisited) {
            return false;
        }

        bit = bit | setter;
        i++;
    }

    return true;
    // the all_unique_letters function determines if all the letters in the 
    //string are unique(no duplicates) using bitwise operations to track 
    //the count of the letters in the string and if a duplicate is found it returns false. 
}

int main(int argc, char * const argv[]) {
    // TODO: reads and parses command line arguments.
    // Calls other functions to produce correct output.
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <string>" << std::endl;
        return 1;
    }

    const char* input = argv[1];

    bool isLowerCase = true;
    bool hasDuplicateLetters = false;

    for (int i = 0; input[i] != '\0'; ++i) {
        if (input[i] < 'a' || input[i] > 'z') {
            isLowerCase = false;
            break;
        }
    }

    if (!isLowerCase) {
        std::cerr << "Error: String must contain only lowercase letters." << std::endl;
    } else {
        unsigned int checker = 0;
        for (int i = 0; input[i] != '\0'; ++i) {
            int bit = input[i] - 'a';
            unsigned int bitMask = 1 << bit;
            if ((checker & bitMask) > 0) {
                hasDuplicateLetters = true;
                break;
            }
            checker |= bitMask;
        }

        if (hasDuplicateLetters) {
            std::cerr << "Duplicate letters found." << std::endl;
        } else {
            std::cout << "All letters are unique." << std::endl;
        }
    }

    return 0;
    // the main method calls of the previously created methods anc checks 
    // if its unique(no duplicates) and all lowercase and prints the messages at the end. 
}

