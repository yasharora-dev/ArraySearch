//
//  main.cpp
//  ArraySearch
//
//  Created by Yash Arora on 12/09/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#include <iostream>
#include "DuplicateArray.h"
#include "DutchNationalFlagProblem.hpp"
#include "MissingAndDuplicateNumber.hpp"

int main(int argc, const char * argv[]) {
    
    //question is to find the a duplicate in the array which occurs atleast more than one time
    //and the numbers in the array are in the range 1 to n in an array of size n+1
    // also there can be missing numbers fro the range 1 to n and that will be filled by the duplicate
    DuplicateArray::Test_findDuplicate();
    
    
    DutchNationalFlagProblem::Test_SortFlags();
    
    
    MissingAndDuplicateNumber::Test_findMissingAndReapeatingNum();
    return 0;
}
