#include<bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int> &arr, int key) 
{
    // add your logic here
	vector<int>a;
	for(int i = 0;i < arr.size();i++)
	{
		if(arr[i] ==  key)
		{
			a.push_back(i);
			break;
		}
	}
	for(int j = arr.size()-1;j >= 0;j--)
	{
		if(arr[j] ==  key)
		{
			a.push_back(j);
			break;
		}
	}
	return a;
}

int main()
{
    vector<int>a,store;
    int n;
    for(int i = 0;i < 5;i++)
    {
        cin >> n;
        a.push_back(n);
    }
    store = searchRange(a,3);
    for(int j = 0;j < store.size();j++)
    {
        cout << store[j];
    }
    return 0;
}
