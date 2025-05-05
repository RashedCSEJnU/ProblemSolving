#include <iostream>
#include <vector>

using namespace std;

// Function to recursively calculate the number at position (x, y)
int findNumber(int n, int x, int y)
{
    if (n == 1)
    {
        // Base case: 2x2 matrix
        if (x == 1 && y == 1)
            return 1;
        if (x == 2 && y == 2)
            return 2;
        if (x == 2 && y == 1)
            return 3;
        return 4;
    }

    int size = 1 << (n - 1); // Size of the sub-matrix (2^(n-1) x 2^(n-1))

    // Determine the quadrant
    if (x <= size && y <= size)
    {
        // Top-left sub-matrix
        return findNumber(n - 1, x, y);
    }
    else if (x <= size && y > size)
    {
        // Top-right sub-matrix
        return findNumber(n - 1, x, y - size) + size * size;
    }
    else if (x > size && y <= size)
    {
        // Bottom-left sub-matrix
        return findNumber(n - 1, x - size, y) + 2 * size * size;
    }
    else
    {
        // Bottom-right sub-matrix
        return findNumber(n - 1, x - size, y - size) + 3 * size * size;
    }
}

// Function to recursively find the coordinates of number d
pair<int, int> findCoordinates(int n, int d)
{
    if (n == 1)
    {
        // Base case: 2x2 matrix
        if (d == 1)
            return {1, 1};
        if (d == 2)
            return {2, 2};
        if (d == 3)
            return {2, 1};
        return {1, 2};
    }

    int size = 1 << (n - 1); // Size of the sub-matrix (2^(n-1) x 2^(n-1))

    if (d <= size * size)
    {
        // Top-left sub-matrix
        auto [x, y] = findCoordinates(n - 1, d);
        return {x, y};
    }
    else if (d <= 2 * size * size)
    {
        // Top-right sub-matrix
        auto [x, y] = findCoordinates(n - 1, d - size * size);
        return {x, y + size};
    }
    else if (d <= 3 * size * size)
    {
        // Bottom-left sub-matrix
        auto [x, y] = findCoordinates(n - 1, d - 2 * size * size);
        return {x + size, y};
    }
    else
    {
        // Bottom-right sub-matrix
        auto [x, y] = findCoordinates(n - 1, d - 3 * size * size);
        return {x + size, y + size};
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, q;
        cin >> n >> q;

        while (q--)
        {
            char query_type;
            cin >> query_type;

            if (query_type == '>')
            {
                int x, y;
                cin >> x >> y;
                cout << findNumber(n, x, y) << endl;
            }
            else
            {
                int d;
                cin >> d;
                auto [x, y] = findCoordinates(n, d);
                cout << x << " " << y << endl;
            }
        }
    }

    return 0;
}
