#include "helper.h"
#include "iostream"
#include <fstream>
struct conf print()
{
    struct conf a;

    std::string myText;

    // Read from the text file
    std::ifstream MyReadFile("config.txt");

    // Use a while loop together with the getline() function to read the file line by line
    while (getline (MyReadFile, myText)) {
        // Output the text from the file
        if(myText.substr(0,14)=="LISTENING_PORT")
        {
            a.port=std::stoi(myText.substr(15,31));
        }
        if(myText.substr(0,22)=="CACHE_REPLACEMENT_TYPE")
        {
            a.cache_replacement=myText.substr(23,27);
        }
        if(myText.substr(0,10)=="CACHE_SIZE")
        {
            a.cache_size=std::stoi(myText.substr(11,31));
        }
        if(myText.substr(0,16)=="THREAD_POOL_SIZE")
        {
            a.thread_pool=std::stoi(myText.substr(17,25));
        }
    }

    // Close the file
    MyReadFile.close();
    return a;
}