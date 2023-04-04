#include <fstream>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
using StreetSegmentIdx = int;using IntersectionIdx = int;using StreetIdx = int;
struct StreetSegmentInfo{
    StreetSegmentIdx seg_id;
    IntersectionIdx from, to;
    double length;
    double time;
    StreetIdx street_id;
};
// struct StreetSegmentInfo {
//     IntersectionIdx from, to;  // intersection ID this segment runs from/to
//     bool oneWay;        // if true, then can only travel in from->to direction
//     float speedLimit;        // in m/s
//     StreetIdx streetID;     // index of street this segment belongs to
//     double travel_time;//NOT 
// };
struct LatLon{
    double lat;
    double lon;
    double longitude(){return lon;}
    double latitude(){return lat;}
};

template<typename T>
vector<T> readVectorFromFile(const std::string& filename) {
    std::ifstream infile(filename, std::ios::binary);
    if (!infile.is_open()) {
        std::cerr << "Error: could not open file " << filename << " for reading\n"; exit(1);
    }
    size_t size; infile.read(reinterpret_cast<char*>(&size), sizeof(size));
    std::vector<T> vec(size); infile.read(reinterpret_cast<char*>(&vec[0]), size * sizeof(T));
    infile.close();
    return vec;
}

vector <StreetSegmentInfo> seg_info_list;
vector <LatLon> intersectionPosition_list;
void loadStreetsDatabasePickle(string city){
    seg_info_list = readVectorFromFile<StreetSegmentInfo>(city+"_streetSegs.pickle");
    intersectionPosition_list = readVectorFromFile<LatLon>(city+"_intersectionPosition.pickle");
}

LatLon getIntersectionPosition(IntersectionIdx intersectionIdx){ return intersectionPosition_list[intersectionIdx]; }
int getNumIntersections(){ return intersectionPosition_list.size(); }
// int getNumIntersectionStreetSegment(IntersectionIdx intersectionIdx);
// StreetSegmentIdx getIntersectionStreetSegment(IntersectionIdx intersectionIdx, int segmentNumber); 
// StreetSegmentInfo getStreetSegmentInfo(StreetSegmentIdx streetSegmentIdx);
// int getNumStreetSegments();

int main(){
    loadStreetsDatabasePickle("toronto_canada");

    //example usage:
    cout<<intersectionPosition_list.size();
    for(int i=0; i<getNumIntersections();i++){
        LatLon cur = getIntersectionPosition(i);
        cout<<"intersection"<<i<<": "<<cur.latitude()<<" "<<cur.longitude()<<endl;
    }

    // example usage with direct access to vector
    // for(const auto &[lat, lon]: intersectionPosition_list) {
    //     cout<<lat<<" "<<lon<<endl;
    // }    

    for(const auto &[seg_id, from, to, length, time, street_id]: seg_info_list) {
        cout<<"seg"<<seg_id<<": "<<from<<" "<<to<<" "<<length<<" "<<time<<" "<<street_id<<endl;
    }

    return 0;
}