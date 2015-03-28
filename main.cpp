//
//  main.cpp
//  quickSort
//
//  Created by hambarkh on 28/03/15.
//  Copyright (c) 2015 Akola. All rights reserved.
//

#include <iostream>

#define N   10
using namespace std;

int a[N]= {5,3,6,2,7,4,1,9,8,10};
int countQ = 0;

void partitionQ(int l, int r);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int i;
    partitionQ(0, N);
    for (i=0; i<N; i++) {
        cout << a[i] << "  " ;
    }
    cout << endl << "CountQ= " << countQ << endl;
    return 0;
}

void swapQ(int p1,int p2)
{
    int temp = a[p1];
    a[p1] = a[p2];
    a[p2] = temp;
}

void partitionQ(int l, int r)
{
    countQ++;
    if (l == r-1 || l >r ) {
        return;
    }
    //int i = rand()%N;
    int pivot = a[l];
    cout << "Pivot = "<< pivot << endl;
    int j,i=l+1;
    for (j=l+1; j<r; j++) {
        if (a[j] < pivot) {
            swapQ(j, i++);
            //i++;
        }
    }
    swapQ(l, i-1);
    partitionQ(l, i-2);
    partitionQ(i, r);
}