class Solution {
  public:
    int rectanglesInCircle(int r) {
        // code here
        int count =0;
        for(int i =1;i<2*r;i++)
        {
            for(int j=1;j<2*r;j++)
            {
                 if((i*i+j*j)<=(4*r*r)) //Checking whether the rectangle area is lesser than the circle area so it can fit
                {
                    count++;    
                }
                
            }
        }
        
        return (count);
    }
};