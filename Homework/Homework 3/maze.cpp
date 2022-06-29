//
//  maze.cpp
//  homework 3
//
//  Created by James Fu on 5/3/22.
//

bool pathExists(char maze[][10], int sr, int sc, int er, int ec);

bool pathExists(char maze[][10], int sr, int sc, int er, int ec)
// Return true if there is a path from (sr,sc) to (er,ec)
// through the maze; return false otherwise
{
    if(sr == er && sc == ec) return true;
    
    // start location
    maze[sr][sc] = 'V';
    
    // west
    if(maze[sr][sc-1] == '.')
    {
        if(pathExists(maze, sr, sc-1, er, ec)) {
            return true;
        }
    }
    // north
    if(maze[sr-1][sc] == '.')
    {
        if(pathExists(maze, sr-1, sr, er, ec)) {
            return true;
        }
    }
    //east
    if(maze[sr][sc+1] == '.')
    {
        if(pathExists(maze, sr, sc+1, er, ec)) {
            return true;
        }
    }
    // south
    if(maze[sr+1][sc] == '.')
    {
        if(pathExists(maze, sr+1, sc, er, ec)) {
            return true;
        }
    }
    return false;
}
