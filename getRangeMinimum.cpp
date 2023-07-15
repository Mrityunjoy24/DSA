#include <bits/stdc++.h>
using namespace std;

void update(vector<int> &arr, vector<int> &tree, int start, int end, int index, int value, int treeIndex)
{
    cout << "start: " << start << " end: " << end << " treeIndex: " << treeIndex<< endl;
    if (start == end)
    {
        /*Update leaf node*/
        tree[treeIndex] = value;
        arr[index] = value;
        return;
    }

    int mid = (start + end) / 2;
    /*if index lies in the left child call update() for left child*/

    if (mid >= index)
        update(arr, tree, start, mid, index, value, 2 * treeIndex + 1);
    else
        update(arr, tree, mid + 1, end, index, value, 2 * treeIndex + 2);

    /*after updating the children,update the current node as smallest of its children */
    tree[treeIndex] = min(tree[2 * treeIndex + 1], tree[2 * treeIndex + 2]);
}

int getMinimum(vector<int> &tree, int start, int end, int queryStart, int queryEnd, int index)
{
    if (queryStart <= start && queryEnd >= end)
    {
        return tree[index];
    }

    if (end < queryStart || start > queryEnd)
    {
        return INT_MAX;
    }

    int mid = (start + end) / 2;
    return min(getMinimum(tree, start, mid, queryStart, queryEnd, 2 * index + 1), getMinimum(tree, mid + 1, end, queryStart, queryEnd, 2 * index + 2));
}

int build(vector<int> &arr, int start, int end, vector<int> &tree, int index)
{
    if (start == end)
    {
        tree[index] = arr[start];
        return arr[start];
    }

    int mid = (start + end) / 2;

    tree[index] = min(build(arr, start, mid, tree, 2 * index + 1), build(arr, mid + 1, end, tree, 2 * index + 2));
    return tree[index];
}

int main()
{
    int ar[] = {1, 3, 5, 7, 9, 11};
    vector<int> arr(ar, ar + 6);
    int n = arr.size();

    // build segment tree
    int max_size = 2 * pow(2, ceil(log2(n))) - 1;
    vector<int> tree(max_size, -1);
    build(arr, 0, n - 1, tree, 0);

    // getMinimum query
    // cout << getMinimum(tree, 0, n - 1, 1, 3, 0) << endl;
    // cout << getMinimum(tree, 0, n - 1, 0, 2, 0) << endl;

    // update query
    int newVal = 0;
    int index = 4;
    update(arr, tree, 0, n - 1, index, newVal, 0);

    // cout << getMinimum(tree, 0, n - 1, 0, 0, 0) << endl;
    // cout << getMinimum(tree, 0, n - 1, 1, 1, 0) << endl;
    // cout << getMinimum(tree, 0, n - 1, 2, 2, 0) << endl;
    // cout << getMinimum(tree, 0, n - 1, 3, 3, 0) << endl;
    // cout << getMinimum(tree, 0, n - 1, 0, 2, 0) << endl;
    // cout << getMinimum(tree, 0, n - 1, 3, 5, 0) << endl;

    // for (int i = 0; i < tree.size(); i++)
    // {
    //     cout << i << ":" << tree[i] << " ,";
    // }

    // cout << tree[5] << " " << tree[6] << " ";
    return 0;
}