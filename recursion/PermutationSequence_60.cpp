//Brute force - recursion 
class Solution {
    void generatePermutations(string& s, string& current, vector<bool>& visited, vector<string>& result) {
        if (current.length() == s.length()) {
            result.push_back(current);
            return;
        }
        
        for (int i = 0; i < s.length(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                current.push_back(s[i]);
                generatePermutations(s, current, visited, result);
                current.pop_back();
                visited[i] = false;
            }
        }
    }
    
public:
    string getPermutation(int n, int k) {
        string s = "";
        for (int i = 1; i <= n; i++) {
            s += to_string(i);
        }
        
        vector<string> result;
        string current = "";
        vector<bool> visited(n, false);
        
        generatePermutations(s, current, visited, result);
        
        return result[k - 1];
    }
};



//Optimal solution - using factorials O(n^2)
class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> numbers;
        
        for (int i = 1; i < n; i++) {
            fact = fact * i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        
        string ans = "";
        k = k - 1;
        
        while (true) {
            ans = ans + to_string(numbers[k / fact]);
            numbers.erase(numbers.begin() + k / fact);
            
            if (numbers.size() == 0) {
                break;
            }
            
            k = k % fact;
            fact = fact / numbers.size();
        }
        
        return ans;
    }
};