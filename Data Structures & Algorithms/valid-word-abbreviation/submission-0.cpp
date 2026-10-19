class Solution {
   public:
    bool validWordAbbreviation(const string& word, const string& abbr) {
        int wn = word.length(), an = abbr.length();
        int i = 0, j = 0;
        while (i < an && j < wn) {
            if (abbr[i] == word[j]) {
                i++;
                j++;
            } else if (abbr[i] > '0' && abbr[i] <= '9') {
                int k = i;
                while (k < an && abbr[k] >= '0' && abbr[k] <= '9') {
                    k++;
                }
                j += stoi(abbr.substr(i, k - i));
                i = k;
            } else
                return false;
        }
        if (i == an && j == wn) return true;
        return false;
    }
};