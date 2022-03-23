class Solution
{
public:
    int wordsTyping(vector<string> &sentence, int rows, int cols)
    {
        string str = "";
        for (string &s : sentence)
        {
            str += s + " ";
        }
        int n = str.length();
        int start = 0;
        for (int i = 0; i < rows; i++)
        {
            start = start + cols;
            if (str[start % n] == ' ')
                start++;
            else
            {
                while (start > 0 && str[(start - 1) % n] != ' ')
                    start--;
            }
        }
        return start / n;
    }
};