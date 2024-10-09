class Solution {
public:
    int compress(vector<char>& chars) {
        int count = 1;
        char curr = chars[0];

        for(int i=1;i<chars.size();i++){
            if(chars[i] == curr ) {
                count++;
                continue;
            }

            if(count > 1){

                int j = count;
                while(j > 1){
                    chars.erase(chars.begin() + i - 1);
                    i--;
                    j--;
                }

                vector<char> a;
                while(count > 0){
                    int rem = count % 10;
                    a.push_back('0' + rem);
                    count /= 10;
                }
                for(int j = a.size()-1; j >= 0 ;j--){
                    chars.insert(chars.begin() + i , a[j]);
                    i++;
                }       

            }
            
            count = 1;
            curr = chars[i];
        }

        if(count > 1){

            int j = count;
            while(j > 1){
                chars.erase(chars.end() - 1);
                j--;
            }

            vector<char> a;
            while(count > 0){
                int rem = count % 10;
                a.push_back('0' + rem);
                count /= 10;
            }
            for(int j = a.size()-1; j >= 0 ;j--){
                chars.insert(chars.end() , a[j]);
            }
        }

            

        return chars.size();
    }
};