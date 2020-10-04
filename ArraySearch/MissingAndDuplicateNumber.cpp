//
//  MissingAndDuplicateNumber.cpp
//  ArraySearch
//
//  Created by Yash Arora on 13/09/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#include "MissingAndDuplicateNumber.hpp"
#include <iostream>

void MissingAndDuplicateNumber::findMissingAndReapeatingNum_Sum(vector<int> &arr, int n, int &missing, int &duplicate)
{
    int arr_sum =0;

    //1^2 + 2^2 + 3^2 + ....
    long long int arr_square_Sum = 0;
    
    for(int i=0;i<arr.size();i++)
    {
        arr_sum+=arr[i];
        arr_square_Sum += (arr[i]*arr[i]);
    }
    
    int nat_sum = (n*(n+1))/2;
    long long int nat_square_sum = (n*(n+1)*(2*n+1))/6;
    
    int diff =  nat_sum - arr_sum; //X-Y
    int diff_sqaure = (int)(nat_square_sum - arr_square_Sum); // X^2 - Y^2
    
    //now X^2 - Y^2 = (X+Y)*(X-Y)
    int sum = diff_sqaure/diff;
    
    missing = (sum + diff)/2;
    duplicate = sum - missing;
    
}
void MissingAndDuplicateNumber::findMissingAndReapeatingNum_XOR(vector<int> &arr, int n, int &missing, int &duplicate)
{
    int arr_XOR  = arr[0];
    
    for(int i=1;i<arr.size();i++)
        arr_XOR = arr_XOR^arr[i];
    
    int X_XOR_Y = 0;
    for(int i=1;i<=n;i++)
        X_XOR_Y = X_XOR_Y ^ i;
    //we get X^Y
    X_XOR_Y = X_XOR_Y^arr_XOR;
    
    int rightmost_set_bit = X_XOR_Y & (~(X_XOR_Y - 1));
    
    //separate it into two buckets
    int Xbucket = 0;
    int Ybucket =0;
    
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i] & rightmost_set_bit)
            Xbucket = Xbucket^arr[i];
        else
            Ybucket = Ybucket^arr[i];
    }
    
    //now remove extra elements by adding 1to n X and Y set bits into Xbucket and YBucket
    for(int i=1;i<=n;i++)
    {
        if(i & rightmost_set_bit)
            Xbucket = Xbucket ^ i;
        else
            Ybucket = Ybucket ^i;
    }
    
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i] == Xbucket)
        {
            missing = Ybucket;
            duplicate = Xbucket;
            return ;
        }
        else if(arr[i] == Ybucket)
        {
            missing = Xbucket;
            duplicate = Ybucket;
            return;
        }
    }
    
}
void MissingAndDuplicateNumber::Test_findMissingAndReapeatingNum()
{
    vector<int> arr {4,3,6,1,1,2};
    int missing = INT_MAX;
    int duplicate = INT_MAX;
    int n =6;
    cout<<"Missing and duplicate Number using sum and square sum method: "<<endl;
    findMissingAndReapeatingNum_Sum(arr,n, missing, duplicate);
    if(missing!=INT_MAX && duplicate!=INT_MAX)
        cout<<"Missing :"<<missing<<" and Duplicate: "<<duplicate<<endl;
    else
        cout<<"Not found "<<endl;
    
    
    cout<<"Missing and duplicate Number using XOR and separation bucket method: "<<endl;
    findMissingAndReapeatingNum_XOR(arr,n, missing, duplicate);
    if(missing!=INT_MAX && duplicate!=INT_MAX)
        cout<<"Missing :"<<missing<<" and Duplicate: "<<duplicate<<endl;
    else
        cout<<"Not found "<<endl;
    
    
    
}
