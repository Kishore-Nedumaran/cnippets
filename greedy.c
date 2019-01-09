#include<stdio.h>
#include<cs50.h>
#include<math.h>
int coins = 0, change, c;
float dollars;
void changer(int d); //to initialize the changer function
int main(void)
{
    do            //to accept positive values only
    {
        dollars = get_float("Change: ");        
    }
    while (dollars < 0);
    change = round(dollars * 100);     //ollars to cents conversion
    for (int i = 0; i < 4; i++)
    {
        if (i == 0)        //to set the change value
        {
            c = 25;
        } 
        else if (i == 1)
        {
            c = 10;
        } 
        else if (i == 2)
        {
            c = 5;
        } 
        else if (i == 3)
        {
            c = 1;
        }
        if (change >= c && change != 0)
        {
            changer(c);    //calls changer function
        }
        else
        {
            continue;
        }
    }
    
    printf("%i\n", coins);    //finally prints the no. of coins
}
void changer(int d)
{
    if (change >= d)
    {
        int e = change / d;
        coins += e;            //increase no. of coins
        change -= e * d;       //reduce the balance amount
    }
}
