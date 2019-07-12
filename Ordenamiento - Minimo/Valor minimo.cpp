#include<iostream>
#include<stack>
#include<fstream>
#include<vector>

using namespace std;
struct nodo
{
	int l,r,index;
};
int find(int arr[],int i)
{
	while(1)
	{
		if(arr[i]==i)
			return i;
		i=arr[i];
	}
}
int main()
{
	ifstream in("consult.txt");
	int arr[]={6,7,1,4,3,2};
	int arr1[]={0,1,2,3,4,5};
	int n;
	in>>n;
	vector<nodo> consul[6];
	vector<int> resulta;
	
	for(int i=0;i<n;i++)
	{
		int l,r;
		in>>l>>r;
		nodo temp={l,r,i};
		consul[r].push_back(temp);
		

	}
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<consul[i].size();j++)
		{
			cout<<"Left: "<<consul[i][j].l<<" Right:  "<<consul[i][j].r<<" Index: "<<consul[i][j].index<<endl;
		}
	}
	
	stack<int> sck;
	for(int i=0;i<n;i++)
	{
		while(!sck.empty() && arr[sck.top()]>arr[i])
		{
				arr1[sck.top()]=i;
				sck.pop();
		}
		sck.push(i);
		if(consul[i].size()>0)
		{
			for(int j=0;j<consul[i].size();j++)
				cout<<find(arr1,consul[i][j].l)<<endl;
		}
	}	
}

