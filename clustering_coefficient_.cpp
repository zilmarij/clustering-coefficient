#include <bits/stdc++.h>

using namespace std;

vector<float> clustering_coefficient(vector<vector<int>> G, int n)
{
        
	vector<float> open_tri(n,0.00); vector<float> triangles(n,0.00);  vector<float> CC(n,0.00);

	for(int row_num=0; row_num<n; row_num++)
	{	
      	    	vector<int> row = G[row_num];
		for(int i=0; i<n; i++)
		{
		    if(row[i] == 1)
		   { 
		      for(int j=0;j<n;j++)
		      {
		         if(j>i)
			{  
			   if(row[j] == 1)
			  { 
		             if(G[i][j] == 1)  //closed tri	
			    { 
			       triangles[row_num]++;
			    }
			    else    //open_triangles
			    {	
				open_tri[row_num]++;
			        open_tri[i]++;
			        open_tri[j]++;
			    }	
			  }
			}
		      }			 
		   }
               }		
	    	
	}
        
	for(int i=0;i<n;i++)
	{
	    CC[i] = triangles[i]/(triangles[i]+open_tri[i]);
	}
	return CC;
}

int main()
{
	int n,inp; 
	vector<vector<int>> G; 	
	vector<float> cc;
	

	//Input node count
	cin >> n;
	
	//Input Adj Matrix
	for(int i=0; i<n; i++)
	{
	    vector<int> r; 
	    for(int j=0; j<n; j++)
	   {
		cin >> inp;  
		r.push_back(inp);
	   }
	   G.push_back(r);
	}

	//Call the function
        cc = clustering_coefficient(G,n);

	//print output
	for(int i=0; i<n;i++)
	{
	    printf("%.2f ",cc[i]);
	}
	cout<<endl;

	return 0;


}

