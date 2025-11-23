class Solution {
    public:
        int numOfSubarrays(vector<int>& arr) {
            const int MOD = 1e9 + 7;
            long long count = 0; // Dùng long long tránh tràn số
            long long pre_sum = 0; // Prefix sum tích lũy
            int even_count = 1; // Đếm số prefix sum chẵn (khởi tạo 1 vì tổng 0 là chẵn)
            int odd_count = 0;  // Đếm số prefix sum lẻ
            
            for(int i = 0; i < arr.size(); i++) {
                pre_sum += arr[i]; // Cập nhật prefix sum
                if(pre_sum % 2 == 0) { // Nếu prefix sum chẵn
                    count += odd_count; // Cộng số prefix sum lẻ trước đó
                    even_count++; // Tăng đếm chẵn
                } else { // Nếu prefix sum lẻ
                    count += even_count; // Cộng số prefix sum chẵn trước đó
                    odd_count++; // Tăng đếm lẻ
                }
                count %= MOD;
            }
            
            return count;
        }
    };