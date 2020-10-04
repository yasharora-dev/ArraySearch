//
//  DutchNationalFlagProblem.hpp
//  ArraySearch
//
//  Created by Yash Arora on 13/09/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#ifndef DutchNationalFlagProblem_hpp
#define DutchNationalFlagProblem_hpp

#include <stdio.h>
#include <vector>
using namespace std;

class DutchNationalFlagProblem{
public:
    void static SortFlags(vector<int> &flags);
    void static SortFlags_CountSort(vector<int> &flags);
    void static Test_SortFlags();
    
};
#endif /* DutchNationalFlagProblem_hpp */
