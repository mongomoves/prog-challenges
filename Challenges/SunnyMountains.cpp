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

double distance(Point p1, Point p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double pytho(int a, int b)
{
    return sqrt((a * a) + (b * b)); 
}

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

            double opposite = points[i].y - points[i - 1].y;
            double adjacent = points[i - 1].x - points[i].x;

            double angleA = atan(opposite / adjacent) * 180 / PI;

            double sideA = points[i].y - maxY;

            double hypo = (sideA/sin(angleA * 3.14159265 / 180)) * sin(90 * 3.14159265 / 180);
            length += hypo;

            
            maxY = points[i].y;
        }
        
        std::cout << length << "\n";
        points.clear();
    }
    return 0;
}