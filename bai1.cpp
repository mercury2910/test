#include<iostream>
#include<vector>
#include<math.h>
#include<stack>

using namespace std;

int countStop(int totalDistance, int maxDistanceFullTank, vector<int> stopPoint)
{
    if(stopPoint[stopPoint.size() - 1]+ maxDistanceFullTank < totalDistance) return -1;
    vector<int>  q;
    unsigned int index=0;
    int min=0;
    int res=maxDistanceFullTank;
    while(res<totalDistance){
        while(index<stopPoint.size() && stopPoint[index]<= res){
            q.push_back(stopPoint[index]);
            index++;
        }
        if(q.empty()){
            return -1;
        }
        res=q[q.size()-1]+ maxDistanceFullTank;
        q.pop_back();
        min++;
    }
    return min;
}

int main(){
    vector<int> stopPoint;
    int arr[] = {2,5, 7, 9, 11};
    stopPoint.insert(stopPoint.end(), arr, arr+5);
    cout << countStop(15, 4, stopPoint);
}