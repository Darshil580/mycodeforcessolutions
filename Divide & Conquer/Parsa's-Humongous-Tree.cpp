//Topics DFS, divide and conqure , dp , greedy , recursion

#include <iostream>
#include<vector>
#include<algorithm>
#include <cstdlib>
#define pv(v) for (int i = 0; i < v.size(); ++i) cout<<#v<<"="<<v[i]<<endl;
#define pa(v,size) for (int i = 0; i < size; ++i) cout<<#v<<"="<<v[i]<<endl;
using namespace std;

typedef struct node {
	int left, right;
	vector<int> negboure;
} node;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int delta1(node *v1, node* v2, int a[], int i, int j) {

	if (abs(v1->left - v2->right) > abs(v1->right - v2->left)) {
		a[i] = v1->left;
		a[j] = v2->right;
		return abs(v1->left - v2->right);
	}
	else {
		a[i] = v1->right;
		a[j] = v2->left;
		return abs(v1->right - v2->right);
	}
}

int delta2(int b, node *v2, int j, int a[]) {
	if (abs(b - v2->right) > abs(b - v2->left)) {
		a[j] = v2->right;
		return	(abs(b - v2->right));
	}
	else {
		a[j] = v2->left;
		return	(abs(b - v2->left));
	}
}


long int getbeauty(vector<node>& tree, int vertex, bool visited[], int a[]) {

	if (visited[vertex] == true) {

		return 0;
	}

	long int sum = 0;
	// cout << vertex + 1 << endl;

	visited[vertex] = true;
	for (int i = 0; i < tree[vertex].negboure.size(); ++i)
	{
		int beauty;
		node* temp_negboure = &tree[tree[vertex].negboure[i]];
		if (a[vertex] == 0 && a[tree[vertex].negboure[i]] == 0) {
			beauty = delta1(&tree[vertex], temp_negboure, a, vertex, tree[vertex].negboure[i]);
			// cout << a[vertex] << "-" << a[tree[vertex].negboure[i]] << "=" << beauty << endl;
		}
		else if (a[vertex] != 0 && a[tree[vertex].negboure[i]] == 0 ) {
			beauty = delta2(a[vertex], temp_negboure, tree[vertex].negboure[i], a);
			// cout << a[vertex] << "-" << a[tree[vertex].negboure[i]] << "=" << beauty << endl;
		}
		else {
			beauty = 0;
		}

		if (visited[tree[vertex].negboure[i]] != true) {
			sum += beauty + getbeauty(tree, tree[vertex].negboure[i],  visited, a);
		}
		else {
			sum += beauty;
		}
	}
	return sum;
	// cout << sum << endl;
}



void work() {
	int n;
	cin >> n;
	int a[n] = {0};
	vector<node> tree(n);
	bool visited[n] = {false};
	for (int i = 0; i < n; ++i)
	{
		cin >> tree[i].left;
		cin >> tree[i].right;
	}

	for (int i = 0, j, k; i < n - 1; ++i)
	{
		cin >> j >> k;
		tree[j - 1].negboure.push_back(k - 1);
		tree[k - 1].negboure.push_back(j - 1);
	}
	cout << getbeauty(tree, 0, visited, a);
}

void testcase() {
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		work();
		cout << endl;
	}
}

int main(int argc, char const *argv[])
{
	fastIO();
	testcase();
	return 0;
}