#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void printVec(std::vector<T>& vec){
    for (auto &i : vec){
        std::cout << i << "\t";
    }
    std::cout << std::endl;
    std::cout << "========================================" << std::endl;
}

/*--------------------------------- 实现一 -------------------------*/
int partition(std::vector<int> &vector,int start,int end){
    int pivot = vector[end];
    int i = start-1;
    for (int j = start; j < end; ++j) {
        if (vector[j] < pivot){
            i++;
            std::swap(vector[i],vector[j]);
        }
    }
    swap(vector[end],vector[i+1]);
    return i+1;
}


void quickSort(std::vector<int> &vector,int start,int end){
    if (start < end){
        int middle = partition(vector,start,end);
//        std::cout << "middle" << middle << endl;
        quickSort(vector,start,middle-1);
        quickSort(vector,middle+1,end);
    }
}


/*--------------------------------- 实现二 -------------------------*/
int partition2(std::vector<int>& vector,int start,int end){
    int pivot = vector[start];
    int i = start + 1;
    int j = end;
    while (true){
        while (i < end && vector[i] < pivot) i++;
        while (j > start && vector[j] > pivot) j--;
        if (i >= j) break;
        std::swap(vector[i],vector[j]);
        i++;
        j--;
    }
    std::swap(vector[start],vector[j]);
    return j;
}

void quickSort2(std::vector<int> &vector,int start,int end){
    if (start <= end){
        int middle = partition(vector,start,end);
//        std::cout << "middle" << middle << endl;
        quickSort(vector,start,middle-1);
        quickSort(vector,middle+1,end);
    }
}

int main(){
    std::vector<int> vec = {34,101,255,1,24,59,-1,0,99,100,-50,-100,200,200,123};
    std::vector<int> vec2(vec);
    std::vector<int> vec3(vec);
//    printVec(vec);
//    printVec(vec2);
//    printVec(vec3);

    quickSort(vec,0,vec.size()-1);
    printVec(vec);

    quickSort2(vec2,0,vec.size()-1);
    printVec(vec2);




    return 0;
}
