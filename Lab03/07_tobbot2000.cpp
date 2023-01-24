/*
    Task	: 07_tobbot2000
    Author	: Worakorn K.
    School	: Kasetsart University
    Language: C++
    Created	: 28 December 2022 [00:16]
    Algo	:
    Status	:
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string command;
    getline(cin, command);
    char facing = 'N';
    for (int i = 0; i < command.length(); i++)
    {
        char ch = command[i];
        if (ch == 'N')
        { // go North
            if (facing == 'N')
            {
                cout << "F";
            }
            else if (facing == 'W')
            {
                facing = 'N';
                cout << "RF";
            }
            else if (facing == 'S')
            {
                facing = 'N'; // check here
                cout << "RRF";
            }
            else if (facing == 'E')
            {
                facing = 'N';
                cout << "RRRF";
            }
        }
        else if (ch == 'E')
        { // go East
            if (facing == 'N')
            {
                facing = 'E';
                cout << "RF";
            }
            else if (facing == 'E')
            {
                cout << "F";
            }
            else if (facing == 'S')
            {
                facing = 'E';
                cout << "RRRF";
            }
            else if (facing == 'W')
            {
                facing = 'E'; // check here
                cout << "RRF";
            }
        }
        else if (ch == 'W')
        { // go West
            if (facing == 'N')
            {
                facing = 'W';
                cout << "RRRF";
            }
            else if (facing == 'E')
            {
                facing = 'W'; // check here
                cout << "RRF";
            }
            else if (facing == 'S')
            {
                facing = 'W';
                cout << "RF";
            }
            else if (facing == 'W')
            {
                cout << "F";
            }
        }
        else if (ch == 'S')
        { // go South
            if (facing == 'N')
            {
                facing = 'S'; // check here
                cout << "RRF";
            }
            else if (facing == 'E')
            {
                facing = 'S';
                cout << "RF";
            }
            else if (facing == 'S')
            {
                facing = 'S';
                cout << "F";
            }
            else if (facing == 'W')
            {
                facing = 'S';
                cout << "RRRF";
            }
        }
        else if (ch == 'Z')
        { // Assume Reset
            facing = 'N';
            cout << "Z";
        }
    }

    return 0;
}