class Solution {
public:
    int romanToInt(string s) {
      int n=0;
        int m=1000,d=500,c=100,l=50,x=10,v=5,i=1;
        for(int j=0;s[j]!='\0';j++){
            if(s[j]=='M')
                n=n+1000;
             
            if(s[j]=='D'){
                if(value(s[j])<value(s[j+1])){
                    n=n-500;
                }else
                    n=n+500;
            }
             if(s[j]=='L'){
                if(value(s[j])<value(s[j+1])){
                    n=n-50;
                }else
                    n=n+50;
            }
             if(s[j]=='X'){
                if(value(s[j])<value(s[j+1])){
                    n=n-10;
                }else
                    n=n+10;
            }
             if(s[j]=='V'){
                if(value(s[j])<value(s[j+1])){
                    n=n-5;
                }else
                    n=n+5;
            }
             if(s[j]=='C'){
                if(value(s[j])<value(s[j+1])){
                    n=n-100;
                }else
                    n=n+100;
            }
            
            if(s[j]=='I'){
                if(value(s[j])<value(s[j+1])){
                    n=n-1;
                }else
                    n=n+1;
            }
                
           
        }
        return n;
    }
    int value(char c){
        switch(c){
            case 'I':
                return 1;
                break;
            case 'V':
                return 5;
                break;
            case 'X':
                return 10;
                break;
            case 'L':
                return 50;
                break;
            case 'C':
                return 100;
                break;
            case 'D':
                return 500;
                break;
            case 'M':
                return 1000;
                break;
        }
        return -1;
    }
};