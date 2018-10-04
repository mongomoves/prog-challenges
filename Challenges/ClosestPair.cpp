/**
 *  ID: 10245
 * 
 *  Shitty n^2 solution but it works. 
 */


#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
#include <float.h>

struct Point {
    double x;
    double y;
};

double dist(Point p1, Point p2)
{    
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y) * (p1.y- p2.y));
}

double brute(std::vector<Point> points, int pairs)
{
    double min = DBL_MAX;
    for(int i = 0; i < pairs; i++)
    {
        for(int j = i + 1; j < pairs; j++)
        {
            double d = dist(points.at(i), points.at(j));
            if(d < min) min = d;
        }
    }
    return min;
}

int main()
{
    int pairs;
    std::cout << std::fixed << std::setprecision(4);
    std::vector<Point> points;
    while(std::cin >> pairs)
    {
        if(!pairs) return 0;
        for(int i = 0; i < pairs; i++)
        {
            Point p;
            std::cin >> p.x >> p.y;
            points.push_back(p);
        }
        double d = brute(points, pairs);
        if(d < 10000) std::cout << d << "\n";
        else std::cout << "INFINITY\n";
        points.clear();
    }
    return 0;
}