class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        double k = celsius + 273.15;
        double f = celsius *1.80 +32.00;

        return {k,f};
    }
};