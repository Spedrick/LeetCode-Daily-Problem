class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int ans = -1, c = 1;
        int n1 = sentence.length(), n2 = searchWord.length();

        for (int i = 0; i < n1; i++) {
            string nexstr = "";
            
            while (i < n1 && sentence[i] != ' ') {
                nexstr += sentence[i];
                i++;
            }

            if (nexstr.length() >= n2 && nexstr.substr(0, n2) == searchWord) return c;

            c++;
        }

        return -1;
    }
};