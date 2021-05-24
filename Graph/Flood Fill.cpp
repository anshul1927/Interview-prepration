// https://leetcode.com/problems/flood-fill/
// lc 733

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        if (newColor != image[sr][sc])
            floodFillRec(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }

    void floodFillRec(vector<vector<int>> &image, int sr, int sc, int newColor, int basecolor)
    {
        int row = image.size();
        int col = image[0].size();

        if (sr < 0 || sr >= row || sc < 0 || sc >= col || image[sr][sc] != basecolor)
        {
            return;
        }

        image[sr][sc] = newColor;

        floodFillRec(image, sr + 1, sc, newColor, basecolor);
        floodFillRec(image, sr, sc + 1, newColor, basecolor);
        floodFillRec(image, sr - 1, sc, newColor, basecolor);
        floodFillRec(image, sr, sc - 1, newColor, basecolor);
    }
};