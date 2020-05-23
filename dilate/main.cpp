//
// Created by dylan on 27-3-2020.
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;






int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<vector<int>> image = {{1, 0, 0, 0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 1, 0, 0, 0},
                                  {0, 0, 0, 0, 1, 0, 0, 0},
                                  {0, 0, 0, 0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0, 0, 0, 1}};

    for (size_t i=3; i<image[0].size() - 3; i++){
        for (size_t j=3; j<image[1].size() - 3; j++){
            if (image[i][j] == 1){
                if (i>0 && image[i-1][j]==0) image[i-1][j] = 2;
                if (j>0 && image[i][j-1]==0) image[i][j-1] = 2;
                if (i+1<image[0].size() && image[i+1][j]==0) image[i+1][j] = 2;
                if (j+1<image[1].size() && image[i][j+1]==0) image[i][j+1] = 2;
            }
        }
    }
    for (size_t i=2; i<image[0].size() - 2; i++){
        for (size_t j=2; j<image[1].size() - 2; j++){
            if (image[i][j] == 2){
                image[i][j] = 1;
            }
        }
    }

    for (size_t i=0; i<image[0].size(); i++){
        for (size_t j=0; j<image[1].size(); j++){
            std::cout << image[i][j] << " | ";
        }
        std::cout << std::endl;
    }
    return 0;
}