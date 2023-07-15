#include <bits/stdc++.h>
using namespace std;

void update(vector<int> &tree, int start, int end, int index, int diff, int treeIndex)
{
    if (index < start || index > end)
        return;

    tree[treeIndex] = tree[treeIndex] + diff;

    if (start != end)
    {
        int mid = (start + end) / 2;
        update(tree, start, mid, index, diff, 2 * treeIndex + 1);
        update(tree, mid + 1, end, index, diff, 2 * treeIndex + 2);
    }
}

int getSum(vector<int> &tree, int start, int end, int queryStart, int queryEnd, int index)
{
    if (queryStart <= start && queryEnd >= end)
    {
        return tree[index];
    }

    if (end < queryStart || start > queryEnd)
    {
        return 0;
    }

    int mid = (start + end) / 2;
    return getSum(tree, start, mid, queryStart, queryEnd, 2 * index + 1) + getSum(tree, mid + 1, end, queryStart, queryEnd, 2 * index + 2);
}

int build(vector<int> &arr, vector<int> &tree, int start, int end, int index)
{
    if (start == end)
    {
        tree[index] = arr[start];
        return arr[start];
    }

    int mid = (start + end) / 2;

    tree[index] = build(arr, tree, start, mid, 2 * index + 1) + build(arr, tree, mid + 1, end, 2 * index + 2);
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
    build(arr, tree, 0, n - 1, 0);

    // getSum query
    cout << getSum(tree, 0, n - 1, 1, 3, 0) << endl;
    cout << getSum(tree, 0, n - 1, 0, 2, 0) << endl;

    // update query
    int newVal = 10;
    int index = 1;
    int diff = newVal - arr[index];
    arr[index] = newVal;
    update(tree, 0, n - 1, index, diff, 0);

    cout << getSum(tree, 0, n - 1, 1, 3, 0) << endl;
    cout << getSum(tree, 0, n - 1, 0, 3, 0) << endl;
    cout << getSum(tree, 0, n - 1, 1, 5, 0) << endl;
    return 0;
}