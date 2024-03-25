#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();
    int quarters = 0, dimes = 0, nickels = 0, pennies = 0;
    // Calculate the number of quarters to give the customer
    if (cents >= 25)
    {
        quarters = calculate_quarters(cents);
        cents = cents - quarters * 25;
        printf("quarters: %i\n", quarters);
    }
    // Calculate the number of dimes to give the customer
    if (cents >= 10)
    {
        dimes = calculate_dimes(cents);
        cents = cents - dimes * 10;
        printf("dimes: %i\n", dimes);
    }
    // Calculate the number of nickels to give the customer
    if (cents >= 5)
    {
        nickels = calculate_nickels(cents);
        cents = cents - nickels * 5;
        printf("nickels: %i\n", nickels);
    }
    // Calculate the number of pennies to give the customer
    if (cents != 0)
    {
        pennies = calculate_pennies(cents);
        cents = cents - pennies * 1;
        printf("pennies: %i\n", pennies);
    }
    // Sum coins
    int coins = quarters + dimes + nickels + pennies;
    // Print total number of coins to give the customer
    printf("total number of coins to give the customer: %i\n", coins);
    printf("\n");
}

int get_cents(void)
{
    // TODO
    int cents;
    do
    {
        cents = get_int("how many cents you want to own: ");
    }
    while (cents < 0);
    return cents;
}

int calculate_quarters(int cents)
{
    // TODO
    int count = 0;
    while (cents >= 25)
    {
        int quarters = 1;
        count++;
        cents = cents - quarters * 25;
    }
    return count;
}

int calculate_dimes(int cents)
{
    // TODO
    int count = 0;
    while (cents >= 10)
    {
        int dimes = 1;
        count++;
        cents = cents - dimes * 10;
    }
    return count;
}

int calculate_nickels(int cents)
{
    // TODO
    int count = 0;
    while (cents >= 5)
    {
        int nickels = 1;
        count++;
        cents = cents - nickels * 5;
    }
    return count;
}

int calculate_pennies(int cents)
{
    // TODO
    return cents;
}
// calculating the length of num_cart.
int length(long long num_cart)
{
  int l = 0;
  while ((char)num_cart[l] != '\0')
  {
    l++;
  }
  printf("%i\n", l);
  return l;
}
//
bool calculate_checsum(long long num_cart, int l)
{
  //
  //the sum of the digits that we are multiplied by 2
  //
  int tot_nbrs_last_sec = 0;
  int t, k = 0;
  if (l % 2 == 0)
  {
  for (int j = 0; j < l ; j = j + 2)
  {
    t = l/2;
    char char_array_last_sec[t];
    int nbrs_array_last_sec[t], nbrs_multi_2[t];
    char_array_last_sec[k] = (char)num_cart[j];
    nbrs_array_last_sec[k] = (int)char_array_last_sec[k];
    printf("%i\n", (char)num_cart[j]);
    nbrs_multi_2[k] = nbrs_array_last_sec[k]*2;
    if (nbrs_multi_2[k] >= 10)
    {
      tot_nbrs_last_sec = tot_nbrs_last_sec + nbrs_multi_2[k] % 10 + 1;
    }
    else
    {
      tot_nbrs_last_sec = tot_nbrs_last_sec + nbrs_multi_2[k];
    }
    k++;
  }
  }
  else
  {
    for (int j = 1; j < l ; j = j + 2)
    {
      t = l/2;
      char char_array_last_sec[t];
      int nbrs_array_last_sec[t], nbrs_multi_2[t];
      char_array_last_sec[k] = (char)num_cart[j];
      nbrs_array_last_sec[k] = (int)char_array_last_sec[k];
      printf("%i\n", (char)num_cart[j]);
      nbrs_multi_2[k] = nbrs_array_last_sec[k]*2;
      if (nbrs_multi_2[k] >= 10)
      {
        tot_nbrs_last_sec = tot_nbrs_last_sec + nbrs_multi_2[k] % 10 + 1;
      }
      else
      {
        tot_nbrs_last_sec = tot_nbrs_last_sec + nbrs_multi_2[k];
      }
      k++;
    }
  }
  //
  //the sum of the digits that weren’t multiplied by 2.
  //
  int tot_nbrs_last_first = 0;
  for (int j = l - 1; j >= 0 ; j = j - 2)
  {
    int m = 0;
    char char_array_last_first[l/2];
    int nbrs_array_last_first[l/2];
    char_array_last_first[m] = (char)num_cart[j];
    nbrs_array_last_first[m] = (int)char_array_last_first[m];
    tot_nbrs_last_first = tot_nbrs_last_first + nbrs_array_last_first[m];
    m++;
  }
  printf("%i\n", tot_nbrs_last_sec + tot_nbrs_last_first);
  printf("%i\n", tot_nbrs_last_sec );
  printf("%i\n", tot_nbrs_last_first);
  //printf("%i\n", MAX_INT);
  if ((tot_nbrs_last_sec + tot_nbrs_last_first) % 10 == 0)
  {
    return false;
  }
  else
    return true;
}