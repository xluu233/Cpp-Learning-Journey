#include <iostream>
#include <vector>


void bubbleSort(std::vector<int> &vec){
    int  size = vec.size();
    for (int i = 0; i < size; ++i) {
        for (int j = i+1; j < size;j++) {
            if (vec[i] > vec[j]){
                std::swap(vec[i],vec[j]);
            }
        }
    }
}


void printVec(std::vector<int>& vec){
    for (auto i : vec){
        std::cout << i <<std::endl;
    }
    std::cout << "========================================" <<std::endl;
}

int main(){
    std::vector<int> vec = {1,24,59,-1,0,99,100,-50,-100,200,200,123};
    printVec(vec);

    bubbleSort(vec);
    printVec(vec);


    return 0;
}