#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct e{
	int a,b;
	e(int x,int y):a(x),b(y){}
	friend bool operator<(e l,e r){return l.b>r.b;}
};
int main(){
	int a,b,h,t,p,s=0;
	cin>>b>>a;
	priority_queue<e> c;
	vector<bool>m(b,0);
	vector<e>*g=new vector<e>[b];
	for(int i=0;i<a;++i){
		cin>>h>>t>>p;
		g[h-1].push_back(e(t-1,p));
		g[t-1].push_back(e(h-1,p));
	}
	m[0]=1;
	for(int i=0,n=0;i<b-1;++i){
		for(int j=0;j<g[n].size();++j)if(!m[g[n][j].a])c.push(g[n][j]);
		while(m[c.top().a])c.pop();
		n=c.top().a;
		m[n]=1;
		s+=c.top().b;
		c.pop();
	}
	cout<<s<<endl;
	return 0;
}