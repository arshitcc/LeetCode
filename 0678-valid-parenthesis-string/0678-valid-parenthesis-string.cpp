class Solution {
public:
    bool checkValidString(string s) {
        
        
        // Method 2 : 83/83
        stack<int> open;
        stack<int> star;
        
        for(int i=0; i<s.size(); i++){
            
            if(s[i]=='(') open.push(i);
            else if(s[i]=='*') star.push(i);
            else {
                if(open.size()) open.pop();  // 1st priority - ( 
                else if(star.size()) star.pop(); // 2nd priority - *
                else{
                    return false;
                }
            }
        }
        
        while(open.size()){
            if(star.size()==0) return false;
            else if(star.top() < open.top()) return false;  // * came before (
            else {  // * is after ( => pair-up
                star.pop();
                open.pop();
            }
        }
        
        return true;
    
        
//         // Method 1 : 74/83 , => "(()(())()())*((()(())))*()(*)()()(*((()((*(*))))()*()(()((()(*((()))*(((())(())))*))(()*))(()*)"
        
//         int close = 0;
//         int laterstar = 0;
    
//         for(int i=0; i<s.size(); i++ ){
//             if( s[i] == ')') close++;
//             if( s[i] == '*') laterstar++;
//         }
        
//         int star = 0;
//         int openUsed = 0;
        
//         for(int i=0; i<s.size(); i++){
            
//             if(s[i]=='(' and close>0){
//                 close--;
//                 openUsed++;
//             }
//             else if(s[i]==')' and openUsed>0) openUsed--;
//             else if(s[i]=='*') {
//                 laterstar--;
//                 star++;
//             }
//             else if(s[i]=='(' and close==0){
//                 cout<<"Check1"<<endl;
//                 if(laterstar==0) return false;
//                 else laterstar--;
//             }
//             else if(s[i]==')' and openUsed==0){
//                 cout<<"check2"<<endl;
//                 if(star==0) return false;
//                 else star--;
//             }
    
//         }
        
//         return true;
    }
};