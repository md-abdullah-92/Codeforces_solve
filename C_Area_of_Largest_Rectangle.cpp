#include <bits/stdc++.h>
using namespace std;

int  r,c;
int matrix[205][205];

int calculateMaxHistogram(int row[])
{
	stack<int> st;
	int topval;
	int maxArea = 0;
	int area = 0;
	int i = 0;

	while (i < c) {
		if (st.empty() || row[st.top()] <= row[i])
			st.push(i++);
		else {
			topval = row[st.top()];
			st.pop();
			area = topval * i;

			if (!st.empty())
				area = topval * (i - st.top() - 1);

			maxArea = max(area, maxArea);
		}
	}

	while (!st.empty()) {
		topval = row[st.top()];
		st.pop();
		area = topval * i;

		if (!st.empty())
			area = topval * (i - st.top() - 1);

		maxArea = max(area, maxArea);
	}

	return maxArea;
}

int calculateMaxRectangle()
{
	int result = calculateMaxHistogram(matrix[0]);

	for (int i = 1; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (matrix[i][j])
				matrix[i][j] += matrix[i - 1][j];
		}
		result = max(result, calculateMaxHistogram(matrix[i]));
	}

	return result;
}

int main()
{
  cin>>r>>c;
  for(int i=0;i<r;i++){
	for(int j=0;j<c;j++){
		cin>>matrix[i][j];
	}
  }
  cout<<calculateMaxRectangle()<<endl;

	return 0;
}
