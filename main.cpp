/*Sum Query Segment Tree*/
#include <iostream>

using namespace std;

void SegmentTree(int array[], int tree[], int low, int high, int position){
    if(low==high){
        tree[position] = array[low];
        return;
    }
    int mid = (low+high)/2;
    SegmentTree(array, tree, low, mid, 2*position+1);
    SegmentTree(array, tree, mid+1, high, 2*position+2);
    tree[position] = tree[2*position+1]+tree[2*position+2];
}

int sumQuery(int tree[], int qlow, int qhigh, int low, int high, int position){
    if(qlow==low && qhigh==high){
        return tree[position];
    }
    int sum = 0, mid = (low+high)/2;
    if(qlow <= mid){
        sum += sumQuery(tree, qlow, min(qhigh, mid), low, mid, 2*position+1);
    }
    if(qhigh >= mid+1){
        sum += sumQuery(tree, max(mid+1, qlow), min(qhigh, high), mid+1, high, 2*position+2);
    }
    return sum;
}

int updateSum(int tree[], int index, int low, int high, int position, int value){
    if(low==high && low==index){
        return (tree[position] = value);
    }
    int mid = (low+high)/2;
    if(index < mid+1){
        updateSum(tree, index, low, mid, 2*position+1, value);
    }
    else{
        updateSum(tree, index, mid+1, high, 2*position+2, value);
    }
    tree[position] = tree[2*position+1]+tree[2*position+2];
}

int main(){



    return 0;
}