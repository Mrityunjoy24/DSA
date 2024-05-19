#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        int maxLevel = -1, minLevel = INT_MAX;
        queue<pair<TreeNode *, int>> queue;
        unordered_map<int, vector<int>> map;

        queue.push({root, 0});

        while (queue.size() > 0)
        {
            pair front = queue.front();
            queue.pop();

            TreeNode* temp = front.first;
            int level = front.second;

            maxLevel = max(maxLevel, level);
            minLevel = min(minLevel, level);

            map[level].push_back(temp->val);

            if (temp->left)
            {
                queue.push({temp->left, level - 1});
            }

            if (temp->right)
            {
                queue.push({temp->right, level + 1});
            }
        }

        vector<vector<int>> ans;
        for (int i = minLevel; i <= maxLevel; i++)
        {
            ans.push_back(map[i]);
        }
        return ans;
    }
};

int main()
{
    return 0;
}

/* Read input from STDIN. Print your output to STDOUT*/
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <bits/stdc++.h>
using namespace std;

vector<int> dir{-1,0,1,0,-1};
int dfs(vector<vector<char>> &mat,int x,int y,int fcount,int c, vector<vector<int>> &vis){
    if(fcount==c){
        return 0;
    }

    vis[x][y] = 1;
    int ans=0;
    if(mat[x][y]=='B'){
        ans;
    }
    else if(mat[x][y]=='F'){
        fcount++;
    }

    int val= 1000000;
    for(int i=0;i<4;i++){
        int dx = x+dir[i];
        int dy = y+dir[i+1];

        if(dx>=0 &&dy>=0 &&dx<mat.size() && dy<mat[0].size()&&vis[dx][dy]==0&&mat[dx][dy]!='O'){
            val = min(val,dfs(mat,dx,dy,fcount,c,vis));
        }
    }

    vis[x][y] = 0;
    
    return ans+val;
}

int main(int argc, char *a[])
{
    //Write code here
    int n,m;
    cin>>n>>m;
    int c=0;
    vector<vector<char>> mat(n,vector<char>(m));
    // vector<vector<int>> vis(n,vector<int>(m,0)),dp(n,vector<int>(m,100000);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
            if(mat[i][j] == 'F')
                c++;
        }
    }

    queue<vector<int> > q;
    int ans = 1000000;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            vector<vector<int>> vis(n,vector<int>(m,0));
            if(mat[i][j]!='O'){
                int k = dfs(mat,i,j,0,c,vis);
                ans = min(ans,k);
            }
        }
    }

    if(ans==1000000)
        ans=-1;
    cout<< ans;
    return 0;
}

// 6 5
// FBFFO
// OBBFO
// OOBFO
// OOBBO
// BBBBB
// OOOOF

// 4

// Free Tickets (100 Marks)
// Once in a while, there comes movies for which the people go crazy. It is such a crazy time. The 

// two movies - Barbie and Oppenheimer are breaking the records of sales. The ticket prices are really high and even then the shows are going housefull. In fact, cinema houses are scheduling the shows in the midnight and early morning to meet the demand. Looking at the craze, Mr. X has created a game for the fans where they have a chance to win free tickets for the movie of their choice.


// Game:

// There is a N*M matrix where each cell of the matrix is represented by either F (Flag) or B (Barbie) or O (Oppenheimer).


// How To WIN?

// A participant will win the game by fetching all the flags in the matrix.


// Rules:

// A participant present at cell (i, j) can move in any of the cells: (i-1, j), (i+1, j). (i, j+1), (i, j-1) i.e., left, right, top and down.

// If a participant moves to a cell marked with B, he/she will fall in a pit and to get back in the game they will have to pay one coin.

// If a participant moves to a cell marked with O, there will be a blast and the participant will be eliminated.

// The cells marked with F consist of the flag. These are the safe places in the matrix and can be visited by the participant without any restriction.

// To start the game, a participant can choose any cell of his/her choice.


// The game can be played in pairs where one person can guide the other to move to a particular cell. Moreover, to help the participants, the map of the matrix is shown at the start so that they can plan a strategy and win the game.


// Olive is really excited about the game and wants to win it to get the free tickets. But her partner, Popeye, has gone to far lands for some important work. Olive is asking you for help to win the game. She is determined to play the game optimally. When the map is shown, she will remember the cells she needs to move to fetch all the flags. She needs your help to determine the minimum number of coins she would need to get back in the game if she falls in the Barbie pit. Help Olive win the game.


// /* Read input from STDIN. Print your output to STDOUT*/
// #include <bits/stdc++.h>
// #include <math.h>
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <assert.h>
// #include <limits.h>
// #include <stdbool.h>
// using namespace std;

// unordered_set<int> set1;
    
// // bool comparator(vector<int> v1,vector<int> v2){
// //     if(set.find(v1))
// // }

// int component(int n, vector<int> &comp){
//     if(n==comp[n])
//     return n;

//     comp[n] = component(comp[n],comp);
//     return comp[n];
// }

// int main(int argc, char *a[])
// {
//     //Write code here
//     int n,t,r;
//     cin>>n>>t>>r;

//     vector<int> rel(r),weights(t);
//     vector<vector<int>> edges(t,vector<int>(3));
//     for(int i=0;i<r;i++){
//         cin>>rel[i];
//         set1.insert(rel[i]);
//     }

//     vector<vector<vector<int>>> graph(n+1);
//     int ans=1;
//     for(int i=0;i<t;i++){
//         cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
//         graph[edges[i][0]].push_back({edges[i][1],edges[i][2]});
//         graph[edges[i][1]].push_back({edges[i][0],edges[i][2]});    
//     }


//     vector<int> dis(n+1,INT_MAX);
//     int start=-1;
//     // for(int i=1;i<=n;i++){
//     //     if(set1.find(i)==set1.end()){
//     //         start=
//     //     }
//     // }
// //     sort(edges.begin(),edges.end());
// //     // sort(edges.begin(),edges.end(), comparator);
// //     for(int i=0;i<t;i++){

// //         int c1 = component(edges[i][0],comp);
// //         int c2 = component(edges[i][1],comp);

// //         if(c1!=c2){
// //             ans+=edges[i][2];
// //             comp[max(c1,c2)] = min(c1,c2);
// //         }
// //    }

//     cout<<ans<<endl;;

//     return 0;
// }

// Humans have been destroying nature for a long time now. The course of rivers are changed, forests are destroyed, mountains are cut and buildings are constructed in the hilly areas. As a result, there is an imbalance in nature and it gets difficult for humans when nature takes matters in hand. There is loss of life and property and what not. The recent heavy rains and floods are an example of it. Roads, bridges, buildings and cars washed away in floods. Hundreds of people are injured and are fighting for life, trying to recover from this devastation.


// To help out the distressed people, N camps have been set up by the NDRF team, the military and the local police. Each camp is assigned an integer from 1 to N (inclusive). These camps are the places where the teams reside, have equipment, necessary things and much more. There are T bidirectional tracks between these camps and any camp is reachable from any camp. The length of the track between two tracks is present along the track and is represented by L. A pair of camps is said to be directly accessible if there is a direct track between the two. Out of these N, there are R relief camps which are big in size to adhere to the injured people.


// Doctors are out in the field and providing help as much as possible. The team of doctors have to leave their camp in the morning, visit each relief camp everyday and come back to their own camp in the evening time. The problem is that they are not able to figure out which camp they should reside in, such that they had to travel the minimum distance. The team can reside in any camp except the relief camp. You have to help the team to figure out the optimal camp for them by figuring out the minimum distance they would be covering everyday.


// Example:

// Number of camps, N = 6

// Number of tracks between camps, T = 7

// Number of relief camps = 2

// Relief camps = [ 4, 6 ]


// Consider the given graph as the pictorial representation.
