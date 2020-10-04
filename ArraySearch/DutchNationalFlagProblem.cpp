//
//  DutchNationalFlagProblem.cpp
//  ArraySearch
//
//  Created by Yash Arora on 13/09/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#include "DutchNationalFlagProblem.hpp"
#include <iostream>

enum  flags { red,blue,yellow};

void DutchNationalFlagProblem::SortFlags_CountSort(vector<int> &flags)
{
    int ones=0,zeroes=0,twos=0;
    
    for(int flag: flags)
    {
        switch(flag)
        {
            case 0:
                zeroes++;
                break;
            case 1:
                ones++;
                break;
            case 2:
                twos++;
                break;
            default:
                break;
        }
    }
    

    for(int index=0;index<zeroes;index++)
    {
        flags[index]=0;
    }
    for(int index=0;index<ones;index++)
    {
        flags[zeroes + index]=1;
    }
    for(int index=0;index<twos;index++)
    {
        flags[zeroes + ones + index]=2;
    }
}

//the idea is to store the 0's in range 0..low-1
// store 2's in high +1 ...end
// and in between this store 1 i.e. low...high

// for 0: swap mid and low..mid++ low++
// for 2: swap mid and high.. high--;
// for 1: mid++;

// do this until mid <=high

void DutchNationalFlagProblem::SortFlags(vector<int> &flags)
{
    
    int low = 0,mid=1;
    int high = flags.size()-1;
    
    while(mid <=high)
    {
        switch (flags[mid]) {
            case 0:
                std::swap(flags[low],flags[mid]);
                //mid++;
                low++;
                break;
            case 1:
                mid++;
                break;
            case 2:
                std::swap(flags[mid],flags[high]);
                high--;
                break;
            default:
                break;
        }
    }
}
void DutchNationalFlagProblem::Test_SortFlags()
{
    //here red=0 blue=1 and yellow=2 is used to represent flags
    
    vector<int> flagsArr1 { red,blue,blue,red,blue,yellow,blue,yellow,red,red,red,blue};
    vector<int> flagsArr2 (flagsArr1);
    
    cout<<"Input Unsorted Array: "<<endl;
    for(auto flag: flagsArr1)
    {
        switch (flag)
        {
            case red:
                cout<<"red , ";
                break;
            case blue:
                cout<<"blue , ";
                break;
            case yellow:
                cout<<"yellow , ";
                break;
        }
    }
    cout<<endl;
    
    SortFlags_CountSort(flagsArr1);
    cout<<"Sorted Array using count sort: "<<endl;
    for(auto flag: flagsArr1)
    {
        switch (flag)
        {
            case red:
                cout<<"red , ";
                break;
            case blue:
                cout<<"blue , ";
                break;
            case yellow:
                cout<<"yellow , ";
                break;
        }
    }
    cout<<endl;
    
    SortFlags(flagsArr2);
    cout<<"Sorted Array using Dutch National Problem Algo : "<<endl;
    for(auto flag: flagsArr2)
    {
        switch (flag)
        {
            case red:
                cout<<"red , ";
                break;
            case blue:
                cout<<"blue , ";
                break;
            case yellow:
                cout<<"yellow , ";
                break;
        }
    }
    cout<<endl;
}

