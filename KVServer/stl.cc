#include "vector"
#include "iostream"
#include "mutex"
#include "vector"
#include "helper.h"
#include "unistd.h"
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include "unordered_map"
#include "utility"
#include <iterator>
#include <set>
std::unordered_map<std::string,std::pair<int,std::string>> keyFeqValue;
#include "thread"
#include <iterator>
#include <set>
std::set<std::pair<int,std::string>> feqKeq;

int main()
{
    {
//    feqKeq.insert({1,"ok1"});
//    feqKeq.insert({10,"ok10"});
//    feqKeq.insert({11,"ok11"});
//    feqKeq.insert({5,"ok5"});
//    feqKeq.insert({2,"ok2"});
//    auto it =feqKeq.find({1,"ok1"});
//    feqKeq.erase(it);
//    for (auto itr = feqKeq.begin(); itr != feqKeq.end(); itr++)
//    {
//        std::cout << itr->first<<" "<<itr->second<< std::endl;
//    }
    }
    {
        keyFeqValue["hnSA"] = {1, "hba"};
        keyFeqValue["h"] = {1, "hba"};
        keyFeqValue["h1"] = {1, "hba"};
        keyFeqValue["n"] = {1, "hba"};
        keyFeqValue.erase("n");
        auto it = keyFeqValue.find("n");
        if (it == keyFeqValue.end())
            std::cout << "NOT found";
        else
            std::cout << "Found";
    }
}