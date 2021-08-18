#include <iostream>
#include<vector>
using namespace std;

struct Point
{
	int x, y;
};


void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int operation() {

	int n;
	cin >> n;
	vector<Point> points;
	int x, y;
	cin >> x >> y;
	Point P;
	P.x = x;
	P.y = y;
	points.push_back(P);
	return ;


}

void testcase() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cout << "Case #" << i + 1 << ":" << operation() << endl;
	}
}



int main(int argc, char const *argv[])
{
	int
	fastIO();
	testcase();
	return 0;
}