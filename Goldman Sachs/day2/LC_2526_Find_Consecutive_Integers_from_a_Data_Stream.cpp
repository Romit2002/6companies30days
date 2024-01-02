class DataStream {
public:
    vector<int>dq;
    int v=0;
    int K=0;
    DataStream(int value, int k) {
        K=k;
        v=value;
    }
    
    bool consec(int num) {
        if(num==v){
            dq.push_back(num);
        }
        else{
            dq.clear();
        }
        if(dq.size()<K){
            return 0;
        }
        else{
            return 1;
        }

    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */