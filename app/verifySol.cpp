#include <unordered_map>
#include <string>
#include "verifySol.hpp"
using namespace std;

int numberGenerator(string s, const std::unordered_map<char, unsigned> & map){
    //translate a string to a number based on the given map
    string num_holder;
    string final;
    for(auto &ch : s){ 
        num_holder = to_string(map.find(ch)->second); //find the unsigned int in the map and change it to a string
        final+=num_holder; //concatenate to the end of the final number
    }
    return stoi(final); //translate from string to int
}

bool verifySolution(std::string s1, std::string s2, std::string s3, const std::unordered_map<char, unsigned> & mapping)
{   

    int translated_s1 = numberGenerator(s1,mapping); //translate each string
    int translated_s2 = numberGenerator(s2,mapping);
    int translated_s3 = numberGenerator(s3,mapping);
    return translated_s1+translated_s2==translated_s3; //return string 1 and string 2 equate to string 3
    
}

