class Solution {
public:
    bool validWordAbbreviation(const string& word, const string& abbr) {
        int i = 0, j = 0;
        int wn = word.length(), an = abbr.length();

        while (i < an && j < wn) {
            if (isalpha(abbr[i])) {
                // If characters don't match, it's invalid
                if (abbr[i] != word[j]) return false;
                i++;
                j++;
            } else if (isdigit(abbr[i])) {
                // Invalid if there's a leading zero
                if (abbr[i] == '0') return false; 
                
                // Parse the number safely
                int num = 0;
                while (i < an && isdigit(abbr[i])) {
                    num = num * 10 + (abbr[i] - '0');
                    i++;
                }
                
                // Jump ahead in the word
                j += num;
                
                // If we jumped past the end of the word, it's invalid
                if (j > wn) return false; 
            }
        }

        // Both pointers must reach the end exactly
        return i == an && j == wn;
    }
};