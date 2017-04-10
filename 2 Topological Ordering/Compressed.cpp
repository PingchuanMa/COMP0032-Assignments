#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef set<int>::iterator p;
int main(){
	int a,b,c,d;
	cin>>a>>b;
	vector<vector<bool> >e(a,vector<bool>(a,0));
	set<int>f;
	vector<int>g(a,0);
	vector<int>h(a,0);
	bool l=1;
	vector<int>m;
	for(int i=0;i<a;++i)f.insert(i);
	for(int i=0;i<b;++i){cin>>c>>d;e[c-1][d-1]=1;++g[d-1];++h[c-1];}
	while(!f.empty()&&l){
		l = 0;
		for(p r=f.begin();r!=f.end();++r)
			if(g[*r]==0){
				l=1;
                for (p s=f.begin();s!=f.end();++s)if(e[*r][*s]){e[*r][*s]=0;--g[*s];--h[*r];}
				m.push_back(*r);
				f.erase(r);
				break;
			}
	}
	if(!l){
		m.clear();
		bool o=0;
		vector<bool>n(a,0);
		while(!o){
			o=1;
			for(p r=f.begin();r!=f.end();++r)
				if(h[*r]==0){
					o=0;
					for(p s=f.begin();s!=f.end();++s)if(e[*s][*r]){e[*s][*r]=0;--h[*s];--g[*r];}
					f.erase(r);
					break;
				}
		}
		int s=*f.begin();
		n[s]=1;
		while(1){
			for(p r=f.begin();r!=f.end();++r)if(e[s][*r]){s=*r;break;}
			if(n[s]==1)break;
			else n[s]=1;
		}
		m.push_back(s);
		while(1){
			for(p r=f.begin();r!=f.end();++r)if(e[s][*r]){s=*r;break;}
			m.push_back(s);
			if (s==m[0])break;
		}
	}
	cout<<(l?"YES":"NO")<<endl;
	for(int i=0;i<m.size();++i){
		cout<<m[i]+1;
		if(i!=m.size()-1)cout<<',';
	}
	cout<<endl;
	return 0;
}