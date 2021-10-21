#include <bits/stdc++.h>

using namespace std;

mutex m;
 
class CacheLRU {

    list<pair<string, string>> cache;
    unordered_map<string, list<pair<string, string>>::iterator> cacheMap;
    int cache_size;
 
    public:
        CacheLRU(int);
        pair<string, string> get_value(string);
        void put_key_value(string, string);
        void delete_key_value(string);
        void display();

};

CacheLRU::CacheLRU(int n)
{
    cache_size = n;
}

pair<string, string> CacheLRU::get_value(string key)
{
    lock_guard<mutex> lock(m);

    string fetched_value = "";

    if (cacheMap.find(key) == cacheMap.end()) {
        // cache entry not found. find it from file.
        fetched_value = "hello";

        // check if the cache is full
        if (cache.size() == cache_size) {
            // deleting the least recently used entry which is stored at the last
            pair<string, string> last = cache.back();
            cache.pop_back();

            // deleting the map entry
            cacheMap.erase(last.first);
        }

    } else {
        fetched_value = (*cacheMap[key]).second;
        cache.erase(cacheMap[key]);
    }
 
    // putting the recently accessed key-value pair at the front
    pair<string, string> key_val(key, fetched_value);
    cache.push_front(key_val);
    cacheMap[key] = cache.begin();

    return key_val;
}
 
void CacheLRU::put_key_value(string key, string value)
{
    lock_guard<mutex> lock(m);

    pair<string, string> key_val(key, value);

    // check if the cache is full
    if (cache.size() == cache_size) {
        // deleting the least recently used entry which is stored at the last
        pair<string, string> last = cache.back();
        cache.pop_back();

        // deleting the map entry
        cacheMap.erase(last.first);
    }
 
    // putting the recently accessed key-value pair at the front
    cache.push_front(key_val);
    cacheMap[key] = cache.begin();

    // Store the key-value pair in a file


}

void CacheLRU::delete_key_value(string key)
{
    lock_guard<mutex> lock(m);
    if (cacheMap.find(key) != cacheMap.end()) {
        cache.erase(cacheMap[key]);
        cacheMap.erase(key);
    } 

    // delete key-value entry from the file
 
}
 
// Function to display contents of cacheLRU
void CacheLRU::display()
{
    for (auto it = cache.begin(); it != cache.end(); it++)
        cout << (*it).first << ":" << (*it).second << '\n';
 
}

int main()
{
    CacheLRU my_cache(10);
    
    my_cache.put_key_value("hello", "world");
    my_cache.put_key_value("nvs", "abhishek");

    cout << my_cache.get_value("hello").second << endl;

    my_cache.display();

    my_cache.delete_key_value("hello");
    
    my_cache.display();
 
    return 0;
}