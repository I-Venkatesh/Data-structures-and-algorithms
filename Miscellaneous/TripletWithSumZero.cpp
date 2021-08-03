int findTriplets(int arr[], int n)
    {
        sort(arr,arr+n);
        bool ok=false;
        for(int i=0;i<n;i++)
        {
            int sum1=arr[i];
            int j=i+1,k=n-1;
            while(j<k)
            {
                if(sum1+arr[j]+arr[k]==0)
                {
                    ok=true;
                    break;
                }
                else if(sum1+arr[j]+arr[k]<0)
                {
                    j++;
                }
                else{
                    k--;
                }
            }
            if(ok)
            {
                break;
            }
        }
        if(ok)
        {
            return 1;
        }
        else{
            return 0;
        }
    }