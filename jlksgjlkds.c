# include <stdio.h>
int main()
{
    int n,m,t,a[1000000 + 10];
    while (scanf ("%d%d",&n,&m)!=EOF)
    {

        for(int i=0;i<n;i++)
          scanf ("%d",a+i);
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - 1 - i; j++)
                if (a[j] < a[j + 1])
                {
                    t = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = t;
                }
        for (int i=0;i < m - 1;i++)
            printf ("%d ",a[i]);
        printf("%d\n",a[m - 1]);
    }
    return 0;
}
