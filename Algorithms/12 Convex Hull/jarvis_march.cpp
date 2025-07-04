#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x, y;
};

// Returns orientation of triplet (p, q, r):
// 0 --> collinear, 1 --> clockwise, 2 --> counterclockwise
int orientation(const Point& p, const Point& q, const Point& r) {
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

// Prints the convex hull using Jarvis March algorithm (Gift Wrapping)
void convexHull(const vector<Point>& points) {
    int n = points.size();
    if (n < 3) {
        cout << "Convex hull not possible with fewer than 3 points.\n";
        return;
    }

    vector<Point> hull;

    // Find the leftmost point
    int leftmost = 0;
    for (int i = 1; i < n; ++i)
        if (points[i].x < points[leftmost].x)
            leftmost = i;

    int p = leftmost;
    do {
        hull.push_back(points[p]);
        int q = (p + 1) % n;

        for (int i = 0; i < n; ++i)
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;

        p = q;
    } while (p != leftmost);

    // Output convex hull
    cout << "Convex Hull:\n";
    for (const auto& pt : hull)
        cout << "(" << pt.x << ", " << pt.y << ")\n";
}

int main() {
    vector<Point> points = {
        {0, 3}, {2, 2}, {1, 1},
        {2, 1}, {3, 0}, {0, 0}, {3, 3}
    };


    convexHull(points);
    return 0;
}
