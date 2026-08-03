class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> ds; 
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        ds[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(ds.count(key)==0) return "";
        const auto &v = ds[key];
        int start=0,end=v.size()-1;
        string ans="";
        while(start<=end){
            int mid=end+(start-end)/2;
            if(v[mid].first == timestamp) return v[mid].second;
            else if(v[mid].first < timestamp) {
                ans=v[mid].second;
                start=mid+1;
            }else end=mid-1;
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */