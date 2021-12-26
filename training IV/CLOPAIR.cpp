#include<iostream>
#include<utility>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;

class Point{
    public :
    pair<int, int> coor;
    int index;
};

Point points[50001];
int N;
int index_first_point, index_second_point;
double min_dis=INT_MAX;

double distance(pair<int, int> coor_1, pair<int, int> coor_2){
    int dx = coor_1.first-coor_2.first;
    int dy = coor_1.second-coor_2.second;
    return sqrt(dx*dx+dy*dy);
}

double clo_pair(int l, int r){
    if (l==r-1) {
        return INT_MAX;
    }
    
    int mid = (l+r)/2;

    double dl = clo_pair(l, mid);
    double dr= clo_pair(mid, r);
    double d = min(dl, dr);
    min_dis = min(min_dis, d);

    Point median_point = points[mid];

    vector<Point> ships; 
    
    for (int j=l;j<r;++j){
        if (abs(points[j].coor.first-median_point.coor.first)<min_dis){
            ships.push_back(points[j]);
        }
    }
    sort(ships.begin(), ships.end(),[=](const Point a,const Point b){
        return (a.coor.second != b.coor.second)?a.coor.second<b.coor.second:a.coor.first<b.coor.first;
    });

    int ships_size= ships.size();
    for (int j=0;j<ships_size;++j){
        for (int i=j+1; i<ships_size&&(abs(ships[i].coor.second-ships[j].coor.second)<min_dis);++i){
            d = distance(ships[i].coor, ships[j].coor);
            if (d<min_dis){
                min_dis = d;
                index_first_point = ships[i].index;
                index_second_point = ships[j].index;
            }
        }
    }

    return min_dis;
}

int main(){
    cin>>N;
    for (int i =0 ;i<N;++i){
        cin>>points[i].coor.first>>points[i].coor.second;
        points[i].index=i;
    }
    sort(points, points+N, [=](const Point a,const Point b){
        return (a.coor.first!=b.coor.first)?a.coor.first<b.coor.first:a.coor.second<b.coor.second;
    });
    double ans = clo_pair(0,N);
    if (index_first_point>index_second_point){
        swap(index_first_point, index_second_point);
    }
    cout<<index_first_point<<" "<<index_second_point;
    printf(" %.6f\n",ans);
    return 0;
}