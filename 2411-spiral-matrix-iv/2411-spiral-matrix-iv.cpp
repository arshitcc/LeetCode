/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        
        vector<vector<int>> ans(m, vector<int>(n,-1));

        int minrow = 0;
        int mincol = 0;
        int maxrow = m-1;
        int maxcol = n-1;

        ListNode* temp = head;
        while(temp and minrow<=maxrow and mincol<=maxcol){

            for(int i=mincol; temp and i<=maxcol; i++){
                ans[minrow][i] = temp->val;
                temp = temp->next;
            }
            minrow++;

            for(int i=minrow; temp and i<=maxrow; i++){
                ans[i][maxcol] = temp->val;
                temp = temp->next;
            }
            maxcol--;

            for(int i=maxcol; temp and i>=mincol; i--){
                ans[maxrow][i] = temp->val;
                temp = temp->next;
            }
            maxrow--;

            for(int i=maxrow; temp and i>=minrow; i--){
                ans[i][mincol] = temp->val;
                temp = temp->next;
            }
            mincol++;
        }


        return ans;
    }
};