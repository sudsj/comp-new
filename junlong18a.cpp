#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define Debug(x) cout << "> " << #x << " : " << x << "\n";
#define DebugArr(a,n) For(i,0,n) cout << i << " : " << a[i] << "\n";
#define For(i,a,b) for(int i=(a);i<(b);i++)
#define ForD(i,a,b) for(int i=(a);i>(b);i--)
#define tests int t; cin>>t; while(t--)
#define Imax INT_MAX
#define Imin INT_MIN
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
#define sz(a) int((a).size())
#define pb push_back
#define it iterator
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define mod 1000000007
typedef long double ld;
/////////////////////////////////////////////////////////////////////
long double getdist(ld x1, ld y1, ld z1, ld x2, ld y2, ld z2){
	ld distsq = 1.0;
	distsq = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2);
	ld dist = sqrt(distsq);
	return dist;
}
ld errbound = 0.000000001;
ld px,py,pz,qx,qy,qz,cx,cy,cz,r;
ld qtx,qty,qtz,t;
ld btime = 0.0;
ld timelow = 0.0; ld timeup = 1000000000000.0;
ld lineptdist(){
	//assuming line between qt and p
	//point is c
	//projected point is cp;
	ld cpx=px,cpy=py,cpz=pz;
	ld qtpx = qtx-px, qtpy = qty-py, qtpz = qtz-pz;//vector from p to qt
	ld qtpdist = getdist(px,py,pz,qtx,qty,qtz);
	// Debug(qtpdist)
	ld fx = cx-px;ld fy = cy-py;ld fz = cz-pz;
	ld dotprd = fx*qtpx + fy*qtpy + fz*qtpz;
	// Debug(dotprd)
	dotprd = dotprd/qtpdist;//gets projected distance
	dotprd = dotprd/qtpdist;//to make the multiplication by qtp direction vector
	// Debug(dotprd)
	// Debug(cpx)
	cpx += qtpx*dotprd;
	// Debug(cpx)
	// Debug(cpy)
	cpy += qtpy*dotprd;
	// Debug(cpy)
	cpz += qtpz*dotprd;
	// Debug(cpz)
	ld lpdist = getdist(cpx,cpy,cpz,cx,cy,cz);
	return lpdist;
}

ld timetravel(){
	btime = (timeup - timelow)/2;
	btime += timelow;
	qtx = qx+btime*dx;
	qty = qy + btime*dy;
	qtz = qz + btime*dz;
	if(abs( lineptdist() - r ) < errbound )	return btime;
	if(lineptdist() <  r){
		//increase
		timelow = btime;
		return timetravel();
	}else{
		//decrease btime
		timeup = btime;
		return timetravel();
	}
}

int main()
{
    #ifndef ONLINE_JUDGE
 	    freopen("input.txt", "r", stdin);
 	    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    std::cout << std::fixed << std::showpoint;
    std::cout << std::setprecision(9);

    // cout << getdist(1,1,1,2,2,1);
    // t = 0.0;
    tests{
    	btime = 0.0;
    	timelow = 0.0; timeup = 1000000000000.0;
    	cin >> px >> py >> pz >> qx >> qy >> qz >> dx >> dy >> dz >> cx >> cy >> cz >> r;
    	cout << timetravel() << "\n";
    }
 	///   	
    return 0;
}