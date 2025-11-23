class Solution {
    public:
        string defangIPaddr(string address) {
            string ans = "";
            for(int i = 0; i < address.size() - 1; i++){
                if(address[i + 1] == '.'){
                    ans.push_back(address[i]);
                    ans.push_back('[');
                }else if(address[i] == '.'){
                    ans.push_back('.');
                    ans.push_back(']');
                }else{
                    ans.push_back(address[i]);
                }
            }
            ans.push_back(address[address.size() - 1]);
            return ans;
        }
    };