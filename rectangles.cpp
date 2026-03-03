#include <cstdio>
#include <vector>

using namespace std;

class Rectangles {
    int case_count = 0;
public: 
    void checkIntersection(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int Ax1 = bottomLeft[0][0];
        int Ay1 = bottomLeft[0][1];
        int Ax2 = topRight[0][0];
        int Ay2 = topRight[0][1];

        int Bx1 = bottomLeft[1][0];
        int By1 = bottomLeft[1][1];
        int Bx2 = topRight[1][0];
        int By2 = topRight[1][1];

        case_count += 1;

        if ((Ax2 < Bx1) || (Bx2 < Ax1) ||
            (Ay2 < By1) || (By2 < Ay1)) {
            printf("Case %d: Rectangles don't intersect\n", case_count);
            printf("-----------------------\n");
            return;
        }

        bool touchVertical = (Ax2 == Bx1) || (Bx2 == Ax1);
        bool touchHorizontal = (Ay1 == By2) || (Ay2 == By1);
        bool overlapVertical = (Ay1 < By2) && (Ay2 > By1);
        bool overlapHorizontal = (Bx1 < Ax2) && (Ax1 < Bx2); 
        
        if ((Ax1 >= Bx1) && (Ax2 <= Bx2) && 
            (Ay1 >= By1) && (Ay2 <= By2))
            printf("Case %d: A is inside B\n", case_count);
        else if ((Bx1 >= Ax1) && (Bx2 <= Ax2) &&
                 (By1 >= Ay1) && (By2 <= Ay2))
            printf("Case %d: B is inside A\n", case_count);
        else if (touchVertical && overlapVertical)
            printf("Case %d: Rectangles are adjacent on the Y axis\n", case_count);
        else if (touchHorizontal && overlapHorizontal)
            printf("Case %d: Rectangles are adjacent on the X axis\n", case_count);
        else if (touchVertical || touchHorizontal)
            printf("Case %d: Rectangles touch on the vertices\n", case_count);
        else
            printf("Case %d: Rectangles intersect\n", case_count);
        printf("-----------------------\n");
    }
};

int main() {
    Rectangles* rec = new Rectangles();

    // case 1> no intersection
    vector<vector<int>> bottomLeft{{1,1}, {4, 2}};
    vector<vector<int>> topRight{{3,3}, {6, 5}};
    rec->checkIntersection(bottomLeft, topRight);
    bottomLeft.clear();
    topRight.clear();

    // case 2> intersection
    bottomLeft.push_back({1,1});
    bottomLeft.push_back({2, 2});
    topRight.push_back({3,3});
    topRight.push_back({4, 5});
    rec->checkIntersection(bottomLeft, topRight);
    bottomLeft.clear();
    topRight.clear();

    // case 3> contaiment
    bottomLeft.push_back({1,1});
    bottomLeft.push_back({2, 2});
    topRight.push_back({6,5});
    topRight.push_back({4, 3});
    rec->checkIntersection(bottomLeft, topRight);
    bottomLeft.clear();
    topRight.clear();

    // case 4> adjacent partial
    bottomLeft.push_back({1,1});
    bottomLeft.push_back({2,3});
    topRight.push_back({3,3});
    topRight.push_back({5,5});
    rec->checkIntersection(bottomLeft, topRight);
    bottomLeft.clear();
    topRight.clear();

    // case 5> adjacent partial
    bottomLeft.push_back({1,1});
    bottomLeft.push_back({3,2});
    topRight.push_back({3,3});
    topRight.push_back({5,6});
    rec->checkIntersection(bottomLeft, topRight);
    bottomLeft.clear();
    topRight.clear();

    // case 6> no intersection 
    bottomLeft.push_back({2,1});
    bottomLeft.push_back({2,4});
    topRight.push_back({4,3});
    topRight.push_back({4,8});
    rec->checkIntersection(bottomLeft, topRight);
    bottomLeft.clear();
    topRight.clear();

    // case 7> adjacent on vertices
    bottomLeft.push_back({1,1});
    bottomLeft.push_back({3,2});
    topRight.push_back({3,2});
    topRight.push_back({5,6});
    rec->checkIntersection(bottomLeft, topRight);
    bottomLeft.clear();
    topRight.clear();

    // case 8> no intersection
    bottomLeft.push_back({1,1});
    bottomLeft.push_back({3,3});
    topRight.push_back({3,2});
    topRight.push_back({5,5});
    rec->checkIntersection(bottomLeft, topRight);
    bottomLeft.clear();
    topRight.clear();

    // case 9> containment 
    bottomLeft.push_back({2,1});
    bottomLeft.push_back({1,1});
    topRight.push_back({3,4});
    topRight.push_back({4,4});
    rec->checkIntersection(bottomLeft, topRight);
    bottomLeft.clear();
    topRight.clear();

    // case 10> intersection 
    bottomLeft.push_back({3,1});
    bottomLeft.push_back({1,2});
    topRight.push_back({5,3});
    topRight.push_back({6,4});
    rec->checkIntersection(bottomLeft, topRight);
    bottomLeft.clear();
    topRight.clear();

    // case 11> containment 
    bottomLeft.push_back({1,1});
    bottomLeft.push_back({1,1});
    topRight.push_back({3,3});
    topRight.push_back({3,3});
    rec->checkIntersection(bottomLeft, topRight);
    bottomLeft.clear();
    topRight.clear();

    // case 12> Proper Adjacent 
    bottomLeft.push_back({1,1});
    bottomLeft.push_back({3,1});
    topRight.push_back({3,3});
    topRight.push_back({5,3});
    rec->checkIntersection(bottomLeft, topRight);

    delete rec;
    return 0;
}
