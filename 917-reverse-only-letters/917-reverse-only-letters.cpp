class Solution {
public:
    string reverseOnlyLetters(string a) {
        char temp='a';
        int j=a.size();
        int i=0;
        while(i<j){
           
            if((a[i]>=65 && a[i]<=90) || (a[i]>=97&&a[i]<=122)){
                for(j;;j--){
                    if((a[j]>=65 && a[j]<=90) || (a[j]>=97&&a[j]<=122)){
                        break;
                    }
                } 
                    temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                    j--;
                }
                
            i++;
            
        }
        return a;
    }
};