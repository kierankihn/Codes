#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MAXN=1e5;
struct Node
{
	int cnt,len;
	Node(){}
};
struct Edge
{
	LL x;
	pair<LL,LL> y;
	LL k;
	Edge(){}
	Edge(LL x_,LL y_,LL y__,LL k_) :x(x_),y(pair<LL,LL>(y_,y__)),k(k_){}
	bool operator<(Edge a){    return x<a.x;}
};
LL n;
LL m;
LL ans;
LL rk[MAXN*2+5];
LL val[MAXN*2+5];
Node node[MAXN*16+5];
Edge edge[MAXN*2+5];
inline LL readLL()
{
	LL res=0,k=1;
	char ch;
	ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			k=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
		res*=10,res+=ch-'0',ch=getchar();
	return k*res;
}
inline void writeLL(LL x)
{
	if(x<0)
		putchar('-'),x=-x;
	if(x>9)
		writeLL(x/10);
	putchar(x%10+'0');
}
void build(LL o,LL l,LL r)
{
	if(l==r)
	{
		node[o].cnt=node[o].len=0;
		return;
	}
	int mid=(l+r)>>1;
	build(o,l,mid);
	build(o,mid+1,r);
	node[o].cnt=node[o].len=0;
}
void updatelen(LL o,LL l,LL r)
{
	if(node[o].cnt)    node[o].len=val[r+1]-val[l];
	else    node[o].len=node[o*2].len+node[o*2+1].len;
}
void update(LL o,LL ql,LL qr,LL l,LL r,LL v)
{
	if(ql<=l && r<=qr)
	{
		node[o].cnt+=v;
		updatelen(o,l,r);
		return;
	}
	LL mid=(l+r)>>1;
	if(mid>=ql)    update(o*2,ql,qr,l,mid,v);
	if(mid<qr)    update(o*2+1,ql,qr,mid+1,r,v);
	updatelen(o,l,r);
}
int main()
{
	n=readLL();
	for(LL i=1;i<=n;i++)
	{
		pair<int,int> x,y;
		x.first=readLL(),y.first=readLL(),x.second=readLL(),y.second=readLL();
		edge[2*i-1]=Edge(x.first,y.first,y.second,1),edge[2*i]=Edge(x.second,y.first,y.second,-1);
		rk[2*i-1]=y.first;
		rk[2*i]=y.second;
	}
	sort(rk+1,rk+2*n+1);
	m=unique(rk+1,rk+2*n+1)-rk-1;
	build(1,1,m);
	for(LL i=1;i<=2*n;i++)
	{
		pair<int,int> newy;
		newy.first=lower_bound(rk+1,rk+m+1,edge[i].y.first)-rk;
		newy.second=lower_bound(rk+1,rk+m+1,edge[i].y.second)-rk;
		val[newy.first]=edge[i].y.first,val[newy.second]=edge[i].y.second;
		edge[i].y=newy;
	}
	sort(edge+1,edge+2*n+1);
	for(LL i=1;i<2*n;i++)
	{
		update(1,edge[i].y.first,edge[i].y.second-1,1,m-1,edge[i].k);
		ans+=node[1].len*(edge[i+1].x-edge[i].x);
	}
	writeLL(ans),putchar('\n');
}
