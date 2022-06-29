#include <queue>
#include <iostream>
#include <cassert>
using namespace std;

class Coord
{
public:
    Coord(int rr, int cc) : m_row(rr), m_col(cc) {}
    int r() const { return m_row; }
    int c() const { return m_col; }
private:
    int m_row;
    int m_col;
};

bool pathExists(char maze[][10], int sr, int sc, int er, int ec)
{
    queue<Coord> coordQueue;
    Coord start(sr, sc);
    coordQueue.push(start);
    maze[sr][sc] = '*';

    while (!coordQueue.empty()) {
        Coord current = coordQueue.front();
        coordQueue.pop();
        int r = current.r();
        int c = current.c();
        if (r == er && c == ec) return true;
        if (r == er && c == ec) return true;

        if (maze[r][c - 1] == '.')
        {
            coordQueue.push(Coord(r, c - 1));
            maze[r][c - 1] = '*';
        }

        if (maze[r - 1][c] == '.')
        {
            coordQueue.push(Coord(r - 1, c));
            maze[r - 1][c] = '*';
        }

        if (maze[r][c + 1] == '.')
        {
            coordQueue.push(Coord(r, c + 1));
            maze[r][c + 1] = '*';
        }

        if (maze[r + 1][c] == '.')
        {
            coordQueue.push(Coord(r + 1, c));
            maze[r + 1][c] = '*';
        }

    }
    return false;
}
