/*
    ID: 920
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>

#define PI 3.14159265;

struct Point {
    int x; 
    int y;
    Point(int x, int y) : x(x), y(y) {};
};

int main()
{
    int cases, maxY;
    double length;
    std::cout << std::fixed;
    std::cout << std::setprecision(2);    
    std::vector<Point> points;
    std::cin >> cases;
    while(cases--)
    {
        int peaks;
        std::cin >> peaks;
        for(int i = 0; i < peaks; i++)
        {
            int x, y;
            std::cin >> x >> y;
            points.push_back(Point(x,y));
        }
        std::sort(points.begin(), points.end(), [](Point p1, Point p2){ return p1.x > p2.x; });
        maxY = 0;
        length = 0;
        for(size_t i = 1; i < points.size(); i++)
        {
            if(points[i].y < maxY) continue;
            //The two sides of the big triangle we need
            double opposite = points[i].y - points[i - 1].y;
            double adjacent = points[i - 1].x - points[i].x;
            //First find the angle for both big and small triangle
            double angleA = atan(opposite / adjacent) * 180 / PI;
            //Get the hypotenuse for the small triangle
            double hypo = ((points[i].y - maxY)/sin(angleA * 3.14159265 / 180)) * sin(90 * 3.14159265 / 180);
            length += hypo;   
            maxY = points[i].y;
        }
        std::cout << length << "\n";
        points.clear();
    }
    return 0;
}