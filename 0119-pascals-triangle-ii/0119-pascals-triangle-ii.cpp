class Solution {
public:
    vector<int> getRow(int rowIndex) {
         vector<int> row(1, 1);
        
        for(int i = 1; i <= rowIndex; i++)
        {
            vector<int> newRow(i+1, 1);
            
            for(int j = 1; j < i; j++)
                newRow[j] = row[j]+row[j-1];
            
            row = newRow; 
        }
        
        return row;    
    }
};