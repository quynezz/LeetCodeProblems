class NumberContainers {
    private: 
        unordered_map<int,priority_queue<int,vector<int>,greater<>>> mp;
        unordered_map<int,int> m;
    public:
        NumberContainers() {
            
        }
        
        void change(int index, int number) {
            m[index] = number;
            mp[number].push(index);
        }
        
        int find(int number) {
            if(mp.find(number) == mp.end()) return -1;
            auto& heap = mp[number];
            while(!heap.empty()){
                int idx = heap.top(); 
                if(m[idx] == number) return idx;
                heap.pop();
            }
            return -1;
        }
    };
    
    /**
     * Your NumberContainers object will be instantiated and called as such:
     * NumberContainers* obj = new NumberContainers();
     * obj->change(index,number);
     * int param_2 = obj->find(number);
     */