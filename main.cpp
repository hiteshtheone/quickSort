//
//  main.cpp
//  quickSort
//
//  Created by hambarkh on 28/03/15.
//  Copyright (c) 2015 Akola. All rights reserved.
//

#include <iostream>
//#include <stdlib.h>

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
    for (i=0; i<10; i++) {
        //srand(time(NULL));
        int random = rand();
   //     cout << random%10 << "\t" << random << endl;
    }
    cout << endl;
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
    
    if (l >= r || l >r ) {
        return;
    }
    countQ++;
    srand((unsigned int)time(NULL));
    int pivotPos = rand()%(r-l) + l;
    int pivot = a[pivotPos];
    cout << "Pivot = "<< pivot << " Pivot pos = "<< pivotPos /*<< " l = " << l << " r =  " << r */<<endl;
    int j,i=l;
    bool pivotLower=false;
    for (j=l; j<r; j++) {
        if (j == pivotPos) {
            continue;
        }
        if (i == pivotPos) {
            i++;
            pivotLower =true;
            //continue;
        }
        if (a[j] < pivot) {
            swapQ(j, i++);
            //i++;
        }
    }
    if (!pivotLower) {
        swapQ(pivotPos, i);
        partitionQ(l, i);
        partitionQ(i+1, r);
    }
    else{
        swapQ(pivotPos, i-1);
        partitionQ(l, i-1);
        partitionQ(i, r);
    }
    
    
}