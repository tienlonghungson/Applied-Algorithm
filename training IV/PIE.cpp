#include<iostream>

using namespace std;

const double ERROR = 1e-6;
const double M_PI = 3.141592653;
int N, F;
double volumn[10000], maxVol=0;

double cal_volumn(int radius){
    return (M_PI*radius*radius);
}

int count_pie(double vol){
    int count=0;
    for (int i=0;i<N;++i){
        count += (int)(volumn[i]/vol);
    }
    return count;
}

void find_suitable_volumn(){
    double left=0, right = maxVol;
    double mid;
    while((right-left)>ERROR){
        mid =(left+right)/2;
        if (count_pie(mid)>=F+1) {
            left = mid;
        } else {
            right = mid;
        }
    }
    printf("%.6lf\n",mid);
}

int main(){
    int numTest, radius;
    cin>> numTest;
    for (int i=0;i<numTest;++i){
        cin>>N>>F;
        for (int j=0;j<N;++j){
            cin>> radius;
            volumn[j] = cal_volumn(radius);
            maxVol = max(maxVol, volumn[j]);
        }
        find_suitable_volumn();
    }
    return 0;
}
