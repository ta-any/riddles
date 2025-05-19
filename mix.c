#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STRING_FOREACH(ch, str) \
    for (char *(ch) = (str); *(ch) != '\0'; ++(ch))
    
#define ALPHABET_SIZE 26    

char get_str(char *str){
  int count_ALPHABET[ALPHABET_SIZE] = {0};
  STRING_FOREACH(c, str) {
      if (islower(*c))
        count_ALPHABET[*c - 'a']++;
  }
  
  for(int i = 0; i < ALPHABET_SIZE; i++){
    printf("%d ", count_ALPHABET[i]);
  }
  
}


void mix(char *first_str, char *second_str)
{

  get_str(first_str);
}


int main(void)
{
    char *s1 = "my&friend&Paul has heavy hats! &";
    char *s2 = "my friend John has many many friends &";
    // mix(s1, s2) --> "2:nnnnn/1:aaaa/1:hhh/2:mmm/2:yyy/2:dd/2:ff/2:ii/2:rr/=:ee/=:ss"
    
    mix(s1, s2);

}

// https://www.codewars.com/kata/5629db57620258aa9d000014
