//convex hull construction
//implementation of Graham's Scan Algorithm

// #include<bits/stdc++.h>
// using namespace std;

struct point{
    double x,y;
    bool isEqual(point const& t) const{
        return x == t.x && y == t.y;
    }
};

int orientation(point a, point b, point c){
    double v = a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y);
    //shoelace formula (area of triangle using coordinates)
    if(v < 0) return -1; //clockwise turn
    if(v > 0) return 1;  //counter-clockwise turn
    return 0;            //collinear
}

bool isClockwise(point a, point b, point c, bool includeCollinear){
    int x = orientation(a,b,c);
    return (x<0 || (includeCollinear && x==0));
}

bool collinear(point a, point b, point c){
    return orientation(a,b,c) == 0;
}

void convexHull(vector<point>& a, bool includeCollinear = false){
    if(a.empty()) return;

    point p0 = *min_element(a.begin(), a.end(), [](point a, point b){
        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
    });

    sort(a.begin(), a.end(), [&p0](const point& p1, point& p2){
        int o = orientation(p0,p1,p2);
        if(o==0){
            return (p0.x-p1.x)*(p0.x-p1.x) + (p0.y-p1.y)*(p0.y-p1.y)
                  <(p0.x-p2.x)*(p0.x-p2.x) + (p0.y-p2.y)*(p0.y-p2.y);
        }
        return o<0;
    });

    if(includeCollinear){
        int i=(int)a.size() -1;
        while(i>=0 && collinear(p0, a[i], a.back())) i--;
        reverse(a.begin()+i+1, a.end());
    }

    vector<point> st;
    for(int i=0; i<(int)a.size(); i++){
        while(st.size()>1 && !isClockwise(st[st.size()-2],st.back(),a[i],includeCollinear))
            st.pop_back();
        st.push_back(a[i]);
    }

    if(!includeCollinear && st.size() == 2 && st[0].isEqual(st[1]))
        st.pop_back();
    
    a=st;
}
