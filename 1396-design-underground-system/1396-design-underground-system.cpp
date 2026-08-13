class UndergroundSystem {
public:
    
    unordered_map<int, pair<string, int>> checkInData;

 
    unordered_map<string, pair<int, int>> travelData;

    UndergroundSystem() {
    }

    void checkIn(int id, string stationName, int t) {
        checkInData[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        string startStation = checkInData[id].first;
        int startTime = checkInData[id].second;

        int travelTime = t - startTime;

        string route = startStation + "#" + stationName;

        travelData[route].first += travelTime;
        travelData[route].second++;

        checkInData.erase(id);
    }

    double getAverageTime(string startStation, string endStation) {
        string route = startStation + "#" + endStation;

        return (double)travelData[route].first /
               travelData[route].second;
    }
};