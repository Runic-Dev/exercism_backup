#include "hexadecimal.h"

namespace hexadecimal {
    int convert(string input){
        int result = 0;
        int weight = 1;
        for(size_t i = 1; i <= input.length(); i++){
            int idx = input.length() - i;
            char c = input[idx];
            
            if(isdigit(c)){
                result += weight * (c - 48);
                weight *= 16;
            }
            if(isalpha(c)){
                c = tolower(c);
                if(c < 87 or c > 102) return 0;
                result += weight * (c - 87);
                weight *= 16;
            }
        }
        return result;
    }
}  // namespace hexadecimal
