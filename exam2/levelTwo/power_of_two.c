/*Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:

int	    is_power_of_2(unsigned int n);*/

int	    is_power_of_2(unsigned int n)
{
    if (n == 0)
        return 0;
    return (n & (n - 1)) == 0;
}

/*This function is very fast because it uses bitwise operations, which are much faster than loops or divisions*/

/* exemple of the fun ction using division and modulo*/

int	    is_power_of_2(unsigned int n)
{
    if (n == 0)
        return 0; //same so far for the verification

    while (n % 2 == 0) // let s divide by two as long as we can 
    {
        n = n / 2;
    }
    return n == 1;// if it is one it is a power of two
}