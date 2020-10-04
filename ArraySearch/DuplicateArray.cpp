//
//  DuplicateArray.cpp
//  ArraySearch
//
//  Created by Yash Arora on 12/09/20.
//  Copyright © 2020 Yash Arora. All rights reserved.
//

#include "DuplicateArray.h"
#include <iostream>

using namespace std;

//solution is to consider the numbers in the array as linked list next ptr and apply fast slow two pointer
//method, floyd algo or tortoise algo for detection and removal of loop into linked list

//e.g. 1->3->4->2->5->4
//so here a loop or cycle is formed and the fast and slow will meet inside the loop
// now as the distance tarvelled between fast and slow pointer is x if x is the distance as slow has covered
// also as this tdistance is multiple of the length of the cycle
// so moving the slow pointer from start of linked list i.e. 0 and fast pointer now in same speed as slow from
//intersection point, both pointers will meet at the start of loop i.e. duplicate number

int DuplicateArray::findDuplicate(const vector<int> &arr)
{
    
    int slow = arr[0];
    int fast = arr[0];
    
    do{
    
        slow = arr[slow];
        fast = arr[arr[fast]];
    }while(slow!=fast);
    
    slow=arr[0]; //set slow to start
    //and move both fast and slow at same speed and whenever they meet it will be the
    // starting of the cycle and that will be our duplicate
    
    while(slow!=fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}

//question is to find the a duplicate in the array which occurs atleast more than one time
//and the numbers in the array are in the range 1 to n in an array of size n+1
// also there can be missing numbers fro the range 1 to n and that will be filled by the duplicate
//https://www.youtube.com/watch?v=32Ll35mhWg0
void DuplicateArray::Test_findDuplicate()
{
    vector<int> arr1 { 1,3,4,2,2};
    vector<int> arr2 { 1,4,7,8,6,6,6,6,5};
    
    cout<<findDuplicate(arr1)<<endl;
    cout<<findDuplicate(arr2)<<endl;
    
    
}
