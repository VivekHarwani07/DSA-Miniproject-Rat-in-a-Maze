#include<bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int n, vector<vector<int>> &maze, vector<vector<int>> &visited)
{
    if( (x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && maze[x][y] == 1)
    {
        return true;
    }
    return false;
}


void solve(vector<vector<int>> &maze, int n, vector<string> &ans, 
            int x, int y, vector<vector<int>> &visited, string path)
{
    // Base Case
    if( x == n-1 && y == n-1)
    {
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    // we have 4 choice - D, L, R, U

    // for Down
    int newx = x+1;
    int newy = y;
    if(isSafe(newx, newy, n, maze, visited))
    {
        path.push_back('D');
        solve(maze, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // for Left
    newx = x;
    newy = y-1;
    if(isSafe(newx, newy, n, maze, visited))
    {
        path.push_back('L');
        solve(maze, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // for Right
    newx = x;
    newy = y+1;
    if(isSafe(newx, newy, n, maze, visited))
    {
        path.push_back('R');
        solve(maze, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // for Up
    newx = x-1;
    newy = y;
    if(isSafe(newx, newy, n, maze, visited))
    {
        path.push_back('U');
        solve(maze, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    visited[x][y] = 0;
}


vector<string> findPath(vector<vector<int>> &maze, int n)
{
    vector<string> ans;

    if(maze[0][0] == 0)
    {
        return ans;
    }

    int srcx = 0;
    int srcy = 0;

    vector<vector<int>> visited = maze;

    //Initialising with 0
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            visited[i][j] = 0;


    string path = "";

    solve(maze, n, ans, srcx, srcy, visited, path);

    return ans;
}


int main()
{
    int n = 4;

    vector<vector<int>> maze{{1,0,0,0},
                             {1,1,1,1},
                             {1,1,1,0},
                             {0,1,1,1}};

    // vector<vector<int>> maze{{1,1,1,1},
    //                          {1,0,0,1},
    //                          {1,0,1,1},
    //                          {1,1,1,1}};

    cout<<"The Current Maze is: "<<endl;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout<<maze[i][j]<<" ";
        cout<<endl;
    }

    cout<<endl<<"D - Down\nL - Left\nR - Right\nU - Up"<<endl;

    cout<<endl<<"All the paths which can be used are: "<<endl;
        
    vector<string> allPaths =  findPath(maze, n);

    for(int i = 0; i < allPaths.size(); i++)
        cout<<allPaths[i]<<endl;

    return 0;
}