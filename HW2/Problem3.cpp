//Dabin Jang, djang12@bu.edu

#include "Problem3.h"
#include <vector>
#include <iostream>

using namespace std;

void MaxDecSeq(int *nums, int len)
{
    //create a vector of vectors of decreasing sequences
    vector<vector<int> > maxdec(len, vector<int>());

    maxdec[0].push_back(*(nums)); // set the first vector of maxdec have only nums 0th element

    for (int i = 1; i < len; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (maxdec[j].size() > maxdec[i].size() && (*(nums + j) > *(nums + i)))
            {
                maxdec[i] = maxdec[j]; // set next vector equal to previous if and only if the previous element is larger than the current (in nums)
                                       // and the previous vector is bigger in size than the previous
            }
        }
        maxdec[i].push_back(*(nums + i));
    }

    //find the vector with the largest size, and then print the one with the most elements
    int *temp = new int(0);
    for (int i = 0; i < len; i++)
    {
        if (maxdec[*temp].size() < maxdec[i].size())
        {
            *temp = i;
        }
    }

    for (int i = 0; i < maxdec[*temp].size(); i++)
    {
        cout << maxdec[*temp].at(i) << " ";
    }
    cout << endl;

    delete temp;
}
