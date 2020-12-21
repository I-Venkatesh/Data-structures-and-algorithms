void sort012(int a[], int n)
{
    // coode here
    int one=0,two=0,zero=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==2)
        {
            two++;
        }
        else if(a[i]==1)
        {
            one++;
        }
        else
        {
            zero++;
        }
    }
    int i=0;
    while(zero>0)
    {
        a[i]=0;
        zero--;
        i++;
    }
    while(one>0)
    {
        a[i]=1;
        one--;
        i++;
    }
    while(two>0)
    {
        a[i]=2;
        two--;
        i++;
    }
    
}