class Solution {
public:
    int fib(int n) {
    //    if(n == 1){
    //     return 1;
    //    } else if( n == 0){ 
    //     return 0;
    //    }
    //    return fib(n - 1) + fib(n - 2); 
    if(n <= 1){ 
        return n;
    }
    int f1 = 1, f0 = 0, temp; 
    for(int i = 2; i <= n; i++){ 
        temp = f1 + f0; 
        f0 = f1; 
        f1 = temp;
    }
    return temp;

    }
};