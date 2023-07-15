// C++ program to show segment tree operations like construction, query
// and update
#include <bits/stdc++.h>
using namespace std;

// A utility function to get the middle index from corner indexes.
int getMid(int s, int e)
{
    return s + (e - s) / 2;
}

/* A recursive function to get the sum of values in the given range
    of the array. The following are parameters for this function.

    st --> Pointer to segment tree
    si --> Index of current node in the segment tree. Initially
            0 is passed as root is always at index 0
    ss & se --> Starting and ending indexes of the segment represented
                by current node, i.e., st[si]
    qs & qe --> Starting and ending indexes of query range */
int getSumUtil(vector<int> &tree, int start, int end, int queryStart, int queryEnd, int si)
{
    // If segment of this node is a part of given range, then return
    // the sum of the segment
    if (queryStart <= start && queryEnd >= end)
        return tree[si];

    // If segment of this node is outside the given range
    if (end < queryStart || start > queryEnd)
        return 0;

    // If a part of this segment overlaps with the given range
    int mid = getMid(start, end);
    return getSumUtil(tree, start, mid, queryStart, queryEnd, 2 * si + 1) +
           getSumUtil(tree, mid + 1, end, queryStart, queryEnd, 2 * si + 2);
}

/* A recursive function to update the nodes which have the given
index in their range. The following are parameters
    st, si, ss and se are same as getSumUtil()
    i --> index of the element to be updated. This index is
            in the input array.
diff --> Value to be added to all nodes which have i in range */

void updateValueUtil(vector<int> &tree, int start, int end, int i, int diff, int index)
{
    // Base Case: If the input index lies outside the range of
    // this segment
    if (i < start || i > end)
        return;

    // If the input index is in range of this node, then update
    // the value of the node and its children
    tree[index] = tree[index] + diff;
    if (end != start)
    {
        int mid = getMid(start, end);
        updateValueUtil(tree, start, mid, i, diff, 2 * index + 1);
        updateValueUtil(tree, mid + 1, end, i, diff, 2 * index + 2);
    }
}

// The function to update a value in input array and segment tree.
// It uses updateValueUtil() to update the value in segment tree
void updateValue(vector<int> &arr, vector<int> &tree, int n, int i, int new_val)
{
    // Check for erroneous input index
    if (i < 0 || i > n - 1)
    {
        cout << "Invalid Input";
        return;
    }

    // Get the difference between new value and old value
    int diff = new_val - arr[i];

    // Update the value in array
    arr[i] = new_val;

    // Update the values of nodes in segment tree
    updateValueUtil(tree, 0, n - 1, i, diff, 0);
}

// Return sum of elements in range from index qs (query start)
// to qe (query end). It mainly uses getSumUtil()
int getSum(vector<int> &tree, int n, int start, int end)
{
    // Check for erroneous input values
    if (start < 0 || end > n - 1 || start > end)
    {
        cout << "Invalid Input";
        return -1;
    }

    return getSumUtil(tree, 0, n - 1, start, end, 0);
}

// A recursive function that constructs Segment Tree for array[ss..se].
// si is index of current node in segment tree st
int constructSTUtil(vector<int> arr, int start, int end, vector<int> &tree, int index)
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (start == end)
    {
        tree[index] = arr[start];
        return arr[start];
    }

    // If there are more than one elements, then recur for left and
    // right subtrees and store the sum of values in this node
    int mid = getMid(start, end);

    tree[index] = constructSTUtil(arr, start, mid, tree, index * 2 + 1) +
                  constructSTUtil(arr, mid + 1, end, tree, index * 2 + 2);
    return tree[index];
}

/* Function to construct segment tree from given array. This function
allocates memory for segment tree and calls constructSTUtil() to
fill the allocated memory */
vector<int> constructST(vector<int> arr, int n)
{
    // Allocate memory for the segment tree

    // Height of segment tree
    int height = (int)(ceil(log2(n)));

    // Maximum size of segment tree
    int max_size = 2 * (int)pow(2, height) - 1;

    // Allocate memory
    vector<int> tree(max_size, -1);
    // Fill the allocated memory st
    constructSTUtil(arr, 0, n - 1, tree, 0);

    // Return the constructed segment tree
    return tree;
}

// Driver program to test above functions
int main()
{
    int ar[] = {1, 3, 5, 7, 9, 11};
    vector<int> arr(ar, ar + 6);
    int n = arr.size();
    // Build segment tree from given array
    vector<int> tree = constructST(arr, n);

    // Print sum of values in array from index 1 to 3
    cout << "Sum of values in given range = " << getSum(tree, n, 1, 3) << endl;

    // Update: set arr[1] = 10 and update corresponding
    // segment tree nodes
    updateValue(arr, tree, n, 1, 10);

    // Find sum after the value is updated
    cout << "Updated sum of values in given range = "
         << getSum(tree, n, 1, 3) << endl;
    return 0;
}
// This code is contributed by rathbhupendra
