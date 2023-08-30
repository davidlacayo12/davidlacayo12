#include "Utils.h"

map<string, int> mapDistanceGraph(vector<int> & v, map<int, string> & m) {  //might move to utils file
    map<string, int> result;
    for(size_t i = 0; i < v.size(); i++) {
        if(m.find(i) != m.end()) {
            result[m.find(i)->second] = v[i];
        }
    }
    return result;
}

void printDistanceMap(map<string, int> & m) {
    for(auto itr = m.begin(); itr != m.end(); ++itr) {
        cout << itr->first << " " << itr->second << endl;
    }
    cout << "\n" << endl;
}

vector<int> nearbyCities(vector<int> v, float maxDistance) {
    vector<int> result;
    for(size_t i = 0; i < v.size(); i++) {
        if(v[i] <= maxDistance) {
            result.push_back(v[i]);
        }
    }
    return result;
}