#include <bits/stdc++.h>
using namespace std;
struct point
{
	int x,y;
};
int orientation(point p, point q, point r) 
{ 
    int val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
  
    if (val == 0) return 0;  // colinear 
    return (val > 0)? 1: 2; // clock or counterclock wise 
}
void jarvis(point s[],int n)
{
	if(n<3)
		return ;
	int l=0;
	for(int i=1;i<n;i++)
		if(s[i].x<s[l].x)
			l=i;
	int p=l,q;
	vector<point> v;
	do
		{
			v.push_back(s[p]);
			q=(p+1)%n;
			for(int i=0;i<n;i++)
			{
				if(orientation(s[p],s[i],s[q])==2)
					q=i;
			}
			p=q;
		}while(p!=l);

		for(int i=0;i<v.size();i++)
			cout<<v[i].x<<" "<<v[i].y<<endl;

}
int main()
{
	int n;
	cin>>n;
	point p[n];
	for(int i=0;i<n;i++)
		cin>>p[i].x>>p[i].y;
	jarvis(p,n);
	return 0;
}