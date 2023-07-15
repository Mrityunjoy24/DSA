#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);

string rtrim(const string &);

vector<string> split(const string &);

/*

* Complete the 'getMinLeavesToRemove' function below.

*

* The function is expected to return an INTEGER.

* The function accepts following parameters:

* 1. WEIGHTED_INTEGER_GRAPH tree

* 2. INTEGER_ARRAY arr

*/

/*

* For the weighted graph, <name>:

*

* 1. The number of nodes is <name>_nodes.

* 2. The number of edges is <name>_edges.

* 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].

*

*/

int getMinLeavesToRemove(int tree_nodes, vector<int> tree_from, vector<int> tree_to, vector<int> tree_weight, vector<int> arr)
{
}

int main()
{

    ofstream fout(getenv("OUTPUT_PATH"));

    string tree_nodes_edges_temp;

    getline(cin, tree_nodes_edges_temp);

    vector<string> tree_nodes_edges = split(rtrim(tree_nodes_edges_temp));

    int tree_nodes = stoi(tree_nodes_edges[0]);

    int tree_edges = stoi(tree_nodes_edges[1]);

    vector<int> tree_from(tree_edges);

    vector<int> tree_to(tree_edges);

    vector<int> tree_weight(tree_edges);

    for (int i = 0; i < tree_edges; i++)
    {

        string tree_from_to_weight_temp;

        getline(cin, tree_from_to_weight_temp);

        vector<string> tree_from_to_weight = split(rtrim(tree_from_to_weight_temp));

        int tree_from_temp = stoi(tree_from_to_weight[0]);

        int tree_to_temp = stoi(tree_from_to_weight[1]);

        int tree_weight_temp = stoi(tree_from_to_weight[2]);

        tree_from[i] = tree_from_temp;

        tree_to[i] = tree_to_temp;

        tree_weight[i] = tree_weight_temp;
    }

    string arr_count_temp;

    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++)
    {

        string arr_item_temp;

        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }

    int result = getMinLeavesToRemove(tree_nodes, tree_from, tree_to, tree_weight, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{

    string s(str);

    s.erase(

        s.begin(),

        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))

    );

    return s;
}

string rtrim(const string &str)
{

    string s(str);

    s.erase(

        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),

        s.end()

    );

    return s;
}

vector<string> split(const string &str)
{

    vector<string> tokens;

    string::size_type start = 0;

    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {

        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}