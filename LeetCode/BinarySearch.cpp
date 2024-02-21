//
// Created by xlu on 2023/4/6.
//
#include <iostream>
#include <vector>

using namespace std;

//递归实现
int BinarySearch(vector<int> vector, int value, int low, int high){
    if (low > high)
        return -1;
    int mid = low + (high-low)/2;
    if (vector[mid] == value)
        return mid;
    else if (vector[mid] < value)
        return BinarySearch(vector,value,mid+1,high);
    else
        return BinarySearch(vector,value,low,mid-1);
}


//非递归实现
int BinarySearch2(vector<int> vector, int value, int low, int high){
    if (vector.size() <= 0)
        return -1;
    while (low <= high){
        int mid = low + (high-low)/2;
        if (vector[mid] == value){
            return mid;
        } else if (vector[mid] < value){
            low = mid+1;
        } else{
            high = mid-1;
        }
    }
    return -1;
}




int main(){

}