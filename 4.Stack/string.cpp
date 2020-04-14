/////////////////151. Reverse Words in a String

class Solution {
public:
    string reverseWords(string s) {
        
        //reverse the whole string 
        
        reverse(s.begin(), s.end());
        
        
        int size = s.size();
        int index =0;
        
        for(int start =0; start <size; ++ start){
            
            if (s[start] != ' '){
                
                //go to begining of thw word 
                if (index != 0){
                    s[index++] = ' ';
                }
                
                //go to end of the word
                int end = start;
                
                
                while(end < size && s[end] != ' '){
                    s[index++] = s[end++];
                }
                
                //reverse the word
                reverse(s.begin() + index - (end - start), s.begin() + index);
                // move to the next word
                start = end;
            }
        }
        s.erase(s.begin() + index, s.end());
        return s;
    }
};