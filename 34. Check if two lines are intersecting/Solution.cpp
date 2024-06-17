class Solution {
  public:
  
    struct Point
    {
        int x;
        int y;
        Point (int a, int b)
        {
            x=a;
            y=b;
        }
    };
    
    // checking to see if point a lies between point b and point C
    bool onSegment(Point a, Point b, Point c)
    {
        if(a.x <= max(b.x,c.x) && a.x>=min(b.x,c.x) && a.y <=max(b.y,c.y) && a.y >= min (b.y,c.y))
        {
            return true;
        }
        else 
        return false;
    }
    
     int orientation (Point a, Point b, Point c)
     {
        long value =  (long)(b.y-a.y)*(c.x-b.x) - (long)(c.y -b.y)*(b.x-a.x);
        if (value == 0)
        {
            return 0;
        }
        
        if(value > 0)
        {
            return 1;
        }
        else
        {
            return -1;
        }
     }
    
    string doIntersect(int p1[], int q1[], int p2[], int q2[]) {
        
        // code here
        Point P1 =  Point(p1[0],p1[1]);
        Point Q1 =  Point(q1[0],q1[1]);
        Point P2 =  Point(p2[0],p2[1]);
        Point Q2 =  Point(q2[0],q2[1]);
        
        int o1 = orientation(P1, Q1, P2); 
    int o2 = orientation(P1, Q1, Q2); 
    int o3 = orientation(P2, Q2, P1); 
    int o4 = orientation(P2, Q2, Q1); 
  
  //cout<<"o1: "<<o1<<" o2: "<<o2<<" o3: "<<o3<<" o4: "<<o4<<endl;
    // General case 
    if (o1 != o2 && o3 != o4) 
        return "true"; 
  
    // Special Cases 
    // p1, q1 and p2 are collinear and p2 lies on segment p1q1 
    if (o1 == 0 && onSegment(P2, P1, Q1)) return "true"; 
  
    // p1, q1 and q2 are collinear and q2 lies on segment p1q1 
    if (o2 == 0 && onSegment(Q2, P1, Q1)) return "true"; 
  
    // p2, q2 and p1 are collinear and p1 lies on segment p2q2 
    if (o3 == 0 && onSegment(P1, P2, Q2)) return "true"; 
  
     // p2, q2 and q1 are collinear and q1 lies on segment p2q2 
    if (o4 == 0 && onSegment(Q1, P2, Q2)) return "true"; 
  
    return "false";
           
        
    }
};
