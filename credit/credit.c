#include<stdio.h>
#include<cs50.h>
void getcard(void);           //to get card number
int length, cardid, count;
long long n;
int main(void)
{
    getcard();  //To get input which is positive and has permissible length
    //calculate checksum
    long long c = 1; 
    int c_sum = 0, d = 0;
    do                               //to find the sum starting with second last
    {
        c *= 100;
        d = 2 * ((n % c) / (c / 10));
        if (d > 9)                   //to add product's digits
        {
            d = (d / 10) + (d % 10);
        }
        c_sum += d;
    }
    while (c < n);
    c = 10, count = 0;
    do                               //to find the sum of remaining
    {
        if (count == 0)
        {
            d = (n % c);
        }
        else
        {
            c *= 100;
            d = ((n % c) / (c / 10));
            if (d > 9)                  //to add product's digits
            {
                d = (d / 10) + (d % 10);
            }
        }
        c_sum += d;
        count++;
    }
    while (c < n);
    if (c_sum % 10 == 0)      //to see if the card is valid
    {
        switch (cardid)     //if valid, then to determine the type of card
        {
            case 4:
            {
                if (length == 16 || length == 13)   //to make sure it is a visa card
                {
                    printf("VISA\n");    
                }
                else 
                {
                    printf("INVALID\n");
                }
                break;
            }
            case 34:
            case 37:
            {
                if (length == 15)        //to make sure it is a amex card
                {
                    printf("AMEX\n");                    
                }
                else 
                {
                    printf("INVALID\n");
                }                
                break;
            }
            case 51:
            case 52:
            case 53:
            case 54:
            case 55:
            {
                if (length == 16)        //to make sure it is a master card
                {
                    printf("MASTERCARD\n");                    
                }
                else 
                {
                    printf("INVALID\n");
                }                
                break;
            }
            default:
            {
                printf("INVALID\n");
            }
        }        
    }
    else
    {
        printf("INVALID\n");
    }      
}

void getcard(void)
{
    do
    {
        length = 0;
        n = get_long_long("Number: ");
        //to get the no of digits present
        long long j = n;
        while (j != 0)
        {
            j /= 10;
            length++;
        }
    }
    while (n < 0);
    long long f = 1;           //to store the first two digits of the card
    for (int d = 0; d < (length - 2); d++)
    {
        f *= 10;
    }
    cardid = n / f;
    if ((cardid / 10) == 4)    //incase of VISA just 4 is enough 
    { 
        cardid = 4;
    }
}
