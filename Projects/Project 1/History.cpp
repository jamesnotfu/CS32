#include "History.h"
#include <iostream>
using namespace std;

History::History(int nRows, int nCols)
{
    m_rows = nRows;
    m_cols = nCols;
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            m_grid[i][j] = '.';
        }
    }
}

bool History::record(int r, int c)
{
    if (r < 1 || c < 1 || r > m_rows || c > m_cols)
    {
        return false;
    }
    char& char_grid = m_grid[r - 1][c - 1]; // use char array can't figure out method with int array
    switch (char_grid)
    {
        case '.':
            char_grid = 'A';
            break;
        case 'Z':
            break;
        default:
            char_grid++; // interate to print A-Y
            break;
    }
    return true;
}

void History::display() const
{
    clearScreen();

    for (int i = 0; i < m_rows; i++)
    {
        for (int j = 0; j < m_cols; j++)
            cout << m_grid[i][j];
        cout << endl;
    }
    cout << endl;
}
