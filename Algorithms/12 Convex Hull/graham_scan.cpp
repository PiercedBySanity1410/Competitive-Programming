#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

// Global point used for sorting points with reference to the first point
Point p0;

// Returns the second top element of the stack
Point nextToTop(stack<Point> &S) {
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}

// Swaps two points
void swap(Point &p1, Point &p2) {
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

// Returns square of distance between two points
int distSq(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) +
           (p1.y - p2.y) * (p1.y - p2.y);
}

// Returns orientation of the triplet (p, q, r)
// 0 --> Collinear, 1 --> Clockwise, 2 --> Counterclockwise
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;              // Collinear
    return (val > 0) ? 1 : 2;            // Clockwise or counterclockwise
}

// Used by qsort to sort points with respect to the first point (p0)
int compare(const void *vp1, const void *vp2) {
    Point *p1 = (Point *)vp1;
    Point *p2 = (Point *)vp2;

    int o = orientation(p0, *p1, *p2);
    if (o == 0)
        return (distSq(p0, *p2) >= distSq(p0, *p1)) ? -1 : 1;

    return (o == 2) ? -1 : 1;
}

// Prints the convex hull of a set of n points
void convexHull(Point points[], int n) {
    // Find the bottom-most point (or leftmost in case of tie)
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++) {
        int y = points[i].y;
        if ((y < ymin) || (y == ymin && points[i].x < points[min].x))
            ymin = points[i].y, min = i;
    }

    // Place the bottom-most point at first position
    swap(points[0], points[min]);

    // Sort the remaining points with respect to the first point
    p0 = points[0];
    qsort(&points[1], n - 1, sizeof(Point), compare);

    // Remove points with same angle with p0 except the farthest
    int m = 1;
    for (int i = 1; i < n; i++) {
        while (i < n - 1 && orientation(p0, points[i], points[i + 1]) == 0)
            i++;
        points[m++] = points[i];
    }

    // Convex hull not possible with less than 3 points
    if (m < 3) return;

    // Create a stack and push first three points
    stack<Point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);

    // Process the remaining points
    for (int i = 3; i < m; i++) {
        // Remove top while the angle formed by points[i] and top two elements is not counterclockwise
        while (S.size() > 1 && orientation(nextToTop(S), S.top(), points[i]) != 2)
            S.pop();
        S.push(points[i]);
    }

    // Print the convex hull
    while (!S.empty()) {
        Point p = S.top();
        cout << "(" << p.x << ", " << p.y << ")" << endl;
        S.pop();
    }
}

// Driver code
int main() {
    Point points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1},
                      {3, 0}, {0, 0}, {3, 3}};
    int n = sizeof(points) / sizeof(points[0]);
    convexHull(points, n);
    return 0;
}
