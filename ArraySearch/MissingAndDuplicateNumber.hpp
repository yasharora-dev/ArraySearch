//
//  MissingAndDuplicateNumber.hpp
//  ArraySearch
//
//  Created by Yash Arora on 13/09/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#ifndef MissingAndDuplicateNumber_hpp
#define MissingAndDuplicateNumber_hpp

#include <stdio.h>
#include<vector>
using namespace std;

class MissingAndDuplicateNumber{
  
public:
    static void findMissingAndReapeatingNum_Sum(vector<int> &arr,int n, int &missing, int &duplicate);
    static void findMissingAndReapeatingNum_XOR(vector<int> &arr,int n, int &missing, int &duplicate);
    static void Test_findMissingAndReapeatingNum();
};
#endif /* MissingAndDuplicateNumber_hpp */
