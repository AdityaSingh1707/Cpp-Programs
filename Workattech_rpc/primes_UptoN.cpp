#include<bits/stdc++.h>
using namespace std;

bool check_prime(int n)
{
	int flag = 0;
	
	for(int i = 2;i <= n/2; i++)
	{
		if(n % i == 0)
		{
			flag++;
			break;
		}
	}
	
	if(flag != 0)
	{
		return false;
	}

	return true;	
}

vector<int> primesUptoN(int n) 
{
	vector<int>res;
	if(n == 0 || n == 1)
	{
		return res;
	}
	else
	{
		for(int i = 2;i <= n;i++)
		{
			if(check_prime(i) == true)
			{
				res.push_back(i);
			}
		}
	}
	return res;
}

int main()
{
    int n;
    vector<int>store;
    cout << "Enter the number:";
    cin >> n;
    store = primesUptoN(n);

    for(int i = 0;i < store.size();i++)
    {
        cout << store[i] << " ";
    }
    return 0;
}
