#include <stdio.h>
#include <string.h>

int main()
{
    int n, i, j=0, k, c=0;
    char word[101];
    char cnt[101]={0};

    scanf("%d", &n);

    for(i=0;i<n;i++)
    {
        scanf("%s", word);
        
        while(word[j]!='\0')
        {
            for(k=j+1;word[k]!='\0';k++)
            {
                if(word[j]==word[k])
                {
                    if(k!=j+1)
                    {
                        if(word[k]!=word[k-1])
                        {   
                            cnt[i]=1;
                            break;
                        }
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            if(cnt[i]==1)
            {
                c++;
                break;
            }
            j++;
        }
        j=0;
    }

    printf("%d", n-c);

    return 0;
}