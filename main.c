#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[4][4];
    int i,j,turn=0,w,play=1,c,d,l,m,e,o,u,z,q,h,k;
    char b[10]="akshay",g[10]="sumit";
    printf("enter name of first player :");
    scanf("%[^\n]",&b);
    fflush(stdin);
    printf("enter name of second player :");
    gets(g);
    do
    {
        turn=0;
        play=1;
        for(z=0; z<4; z++)
        {
            for(q=0; q<4; q++)
            {
                if(z==0)
                {
                    a[z][q]='X';
                }
                else if(z==3)
                {
                    a[z][q]='O';
                }
                else
                {
                    a[z][q]=' ';
                }
            }
        }
        printf("\n\t%s is playing with 'X'\n\t%s is playing with 'O'",b,g);

        do
        {
            turn++;
            for(u=0; u<4; u++)
            {
                printf("\n-----------------");
                printf("\n| %c | %c | %c | %c |",a[u][0],a[u][1],a[u][2],a[u][3]);
                if(u==3)
                    printf("\n----------------");
            }
            if(turn%2==0)
            {
                printf("\nwrite the co-ordinates of the 'O' which you want to move :");
                scanf("%d",&l);
                scanf("%d",&m);
                l--;
                m--;
                if(a[l][m]=='O')
                {
up:
                    printf("enter the coordinates where you want to play :");
                    scanf("%d",&e);
                    scanf("%d",&o);
                    e--;
                    o--;
                    if(a[e][o]==' ')
                    {
                        if(((e==(l-1))&&(o==m))||((e==(l+1))&&(o==m))||((o==(m-1))&&(e==l))||((o==(m+1))&&(e==l)))
                        {
                            a[e][o]='O';
                            a[l][m]=' ';
                        }
                        else if((e==(l-2))&&(o==m)&&(a[l-1][m]=='X'))
                        {
                            a[e][o]='O';
                            a[l][m]=' ';
                            a[l-1][m]=' ';
                        }
                        else if ((e==(l+2))&&(o==m)&&(a[l+1][m]=='X'))
                        {
                            a[e][o]='O';
                            a[l][m]=' ';
                            a[l+1][m]=' ';
                        }
                        else if((o==(m-2))&&(e==l)&&a[l][m-1]=='X')
                        {
                            a[e][o]='O';
                            a[l][m]=' ';
                            a[l][m-1]=' ';
                        }
                        else if ((o==(m+2))&&(e==l)&&(a[l][m+1]=='X'))
                        {
                            a[e][o]='O';
                            a[l][m]=' ';
                            a[l][m+1]=' ';
                        }
                        else
                        {
                            printf("\nyou cant play there\ntry again");
                            goto up;
                        }
                    }
                    else
                    {
                        printf("\nyou cant play there\ntry again");
                        goto up;
                    }
                }
                else
                {
                    printf("\n worng input there is no 'O' at these coordinates");
                    turn--;
                }
            }
            else if(turn%2!=0)
            {
                printf("\nwrite the co-ordinates of the 'X' which you want to move :");
                scanf("%d",&l);
                scanf("%d",&m);
                l--;
                m--;
                if(a[l][m]=='X')
                {
down:
                    printf("enter the coordinates where you want to play :");
                    scanf("%d",&e);
                    scanf("%d",&o);
                    e--;
                    o--;
                    if(a[e][o]==' ')
                    {
                        if(((e==(l-1))&&(o==m))||((e==(l+1))&&(o==m))||((o==(m-1))&&(e==l))||((o==(m+1))&&(e==l)))
                        {
                            a[e][o]='X';
                            a[l][m]=' ';
                        }
                        else if((e==(l-2))&&(o==m)&&(a[l-1][m]=='O'))
                        {
                            a[e][o]='X';
                            a[l][m]=' ';
                            a[l-1][m]=' ';
                        }
                        else if ((e==(l+2))&&(o==m)&&(a[l+1][m]=='O'))
                        {
                            a[e][o]='X';
                            a[l][m]=' ';
                            a[l+1][m]=' ';
                        }
                        else if((o==(m-2))&&(e==l)&&a[l][m-1]=='O')
                        {
                            a[e][o]='X';
                            a[l][m]=' ';
                            a[l][m-1]=' ';
                        }
                        else if ((o==(m+2))&&(e==l)&&(a[l][m+1]=='O'))
                        {
                            a[e][o]='X';
                            a[l][m]=' ';
                            a[l][m+1]=' ';
                        }
                        else
                        {
                            printf("\nyou cant play there\ntry again");
                            goto down;
                        }
                    }
                    else
                    {
                        printf("\nyou cant play there\ntry again");
                        goto down;
                    }
                }
                else
                {
                    printf("\n worng input there is no 'X' at these coordinates");
                    turn--;
                }
            }
            c=0;
            d=0;
            for(i=0; i<4; i++)
            {
                for(j=0; j<4; j++)
                {
                    if(a[i][j]!='X')
                    {
                        c++;
                        if(c==16)
                        {
                            for(u=0; u<4; u++)
                            {
                                printf("\n-----------------");
                                printf("\n| %c | %c | %c | %c |",a[u][0],a[u][1],a[u][2],a[u][3]);
                                if(u==3)
                                    printf("\n----------------");
                                printf("\n%s has won",g);
                                play=0;
                            }
                        }
                    }
                    if(a[i][j]!='O')
                    {
                        d++;
                        if(d==16)
                        {
                            for(u=0; u<4; u++)
                            {
                                printf("\n-----------------");
                                printf("\n| %c | %c | %c | %c |",a[u][0],a[u][1],a[u][2],a[u][3]);
                                if(u==3)
                                    printf("\n----------------");
                            }
                            printf("\n%s has won",b);
                            play=0;
                        }
                    }
                }
            }
        }
        while(play>0);

        printf("\n\nto play again press 1  :");
        scanf("%d",&w);
    }
    while(w==1);
    return 0;
}
