#include <bits/stdc++.h>
using namespace std;
int polygonArea(){
    int area = 0;
    int N = lengthof(p);
    //We will triangulate the polygon
    //into triangles with points p[0],p[i],p[i+1]
    for(int i = 1; i+1<N; i++){
        int x1 = p[i][0] - p[0][0];
        int y1 = p[i][1] - p[0][1];
        int x2 = p[i+1][0] - p[0][0];
        int y2 = p[i+1][1] - p[0][1];
        int cross = x1*y2 - x2*y1;
        area += cross;
    }
    return abs(area/2.0);
}
int dot(int A[2], int B[2], int C[2]){
    int AB[2];
    int BC[2];
    AB[0] = B[0]-A[0];
    AB[1] = B[1]-A[1];
    BC[0] = C[0]-B[0];
    BC[1] = C[1]-B[1];
    int dot = AB[0] * BC[0] + AB[1] * BC[1];
    return dot;
}
//Compute the cross product AB x AC
int cross(int A[2], int B[2], int C[2]){
    int AB[2];
    int AC[2];
    AB[0] = B[0]-A[0];
    AB[1] = B[1]-A[1];
    AC[0] = C[0]-A[0];
    AC[1] = C[1]-A[1];
    int cross = AB[0] * AC[1] - AB[1] * AC[0];
    return cross;
}
    //Compute the distance from A to B
double distance(int A[2], int B[2]){
    int d1 = A[0] - B[0];
    int d2 = A[1] - B[1];
    return sqrt(d1*d1+d2*d2);
}
//Compute the distance from AB to C
//if isSegment is true, AB is a segment, not a line.
double linePointDist(int A[2], int B[2], int C[2], bool isSegment){
    double dist = cross(A,B,C) / distance(A,B);
    if(isSegment){
        int dot1 = dot(A,B,C);
        if(dot1 > 0)return distance(B,C);
        int dot2 = dot(B,A,C);
        if(dot2 > 0)return distance(A,C);
    }
    return abs(dist);
}
int point_of_intersection(int A1,int B1,int C1,int A2,int B2,int C2){
    /*
    A1x + B1y = C1
    A2x + B2y = C2*/
    double det = A1*B2 - A2*B1;
    if(det == 0){
        //Lines are parallel
    }
    else{
        double x = (B2*C1 - B1*C2)/det;
        double y = (A1*C2 - A2*C1)/det;
    }
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
