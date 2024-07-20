class Solution
{
    public:

    int missingNumber(int arr[], int n) 
    { 
        for(int i=0;i<n;i++)
        {
            int index = arr[i] -1;
            while(0 <= index && index <= n-1 && arr[i] != arr[index])
            {
                swap(arr[i], arr[index]);
                index = arr[i] -1;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(arr[i] != i+1)
                return i+1;
        }
        
        return n+1;
    } 
};

