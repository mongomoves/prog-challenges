/**
 * ID: 10078
 */

#include <iostream>
#include <vector>

struct Point {
    int x;
    int y;
};

double cross(Point &a, Point &b, Point &c)
{
    double bax = a.x - b.x;
    double bay = a.y - b.y;
    double bcx = c.x - b.x;
    double bcy = c.y - b.y;
    return (bax * bcy) - (bay * bcx);
}

int main()
{
    int n;
    std::vector<Point> points;  
    while(std::cin >> n)
    {
        if(!n) return 0;
        for(int i = 0; i < n; i++)
        {
            Point p;
            std::cin >> p.x >> p.y;
            points.push_back(p);
        }
        bool neg = false, pos = false;
        int b, c;
        for(int a = 0; a < n; a++)
        {
            b = (a + 1) % n;
            c = (b + 1) % n;
            double res = cross(points[a], points[b], points[c]);
            if(res < 0) neg = true;
            else if(res > 0) pos = true;
        }
        if(neg && pos) std::cout << "Yes\n";
        else std::cout << "No\n";
        points.clear(); 
    }
    return 0;
}