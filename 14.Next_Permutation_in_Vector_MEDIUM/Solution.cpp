vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        int br = -1;
        for(int i = N-2; i>=0;i--)
        {
            if(arr[i]<arr[i+1])
            {
                br=i;
                break;
            }
        }
        
        if(br==-1)
        {
            int i =0,j=N-1;
            while(i<=j)
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                i++;
                j--;
                
            }
            return arr;
        }
        
        bool flag = true;
        int minLarge = br;
        for(int j = br+1;j<N;j++)
        {
            if(arr[j]>arr[br])
            {
                if(flag)
                {
                    minLarge = j;
                    flag=false;
                }
                if(arr[j]<arr[minLarge])
                {
                    minLarge = j;
                }
            }
        }
        
        int temp = arr[minLarge];
        arr[minLarge] = arr[br];
        arr[br]= temp;
        
        int i =br+1,j=N-1;
            while(i<=j)
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                i++;
                j--;
                
            }
        
        return arr;
        
        
    }