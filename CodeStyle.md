# Coding Style #
Maintain consistency between formatting, identifier names, and casing.

## Macro Definitions and enum identifiers ##
Rules for things following '#define', enum identifiers, or some sort of static constant array or value.

### Rules ###
- All letters are capitalized.
- "Words" are seperated with underscoreds (_).
- ".h" protection is written as `_[FILENAME]_H_`.
- Enumeration identifiers of the same type should begin with the same word.

### Examples ###
- ```
  #define HELLO_WORLD "Hello World"
``` all caps, separated with underscore.
- ```
  #define enum {ENTITY_TYPE_NONE = 0, ENTITY_TYPE_PLAYER };
``` preceded with the same words since.
- ```
  const int PRIMES[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
``` not macros, but still const.

## Classes ##
Rules for class and struct declarations and definitions

### Rules ###
- Class and Struct names use sentence casing.
- They are not to be consistently precded with the same letter or word.
- Access specifiers are not to have space above or below them and should be one tab back.
- Member variables are to use sentence casing.
- Member variables should not be preceded with repeated tokesn such as `m_*` or `my*`
- Methods are to use camel casing.
- Code for one line inline methods declared at class definition should be on the same line as where the signature of the method is defined.

### Example ###
```
class CBad {  //prefaced with C *WRONG*
public:
  int myVar; //camel case, prefaced with my *WRONG*
  
public:  //leaves space above *WRONG*
  void HelloWorld(); //sentence case *WRONG*
};

class CorrectExample {  //Sentence case *GOOD*
public:
  int VarEx;  //Sentence case *GOOD*
public:   //no space above or below *GOOD*
  void doNothing();  //camel case *GOOD*
};
```

## Syntax ##
Rules for syntax within any function

### Rules ###
- Left curly brackets belong at the end of the syntax element they belong to.
- Space separating arithmetic operators (except between constants), assignment operators, or comparison operators.
- No space separating member access operators, or scope resolution operators.
- No space separating index operators.
- No space separtating function call argument list.
- No space preceding comma, one space succeeding comma.
- No space prefixing or postfixing incremental operators.
- Space separating logical operators.
- Space after `?` in conditional operator, no space around `:` in conditional operator.
- Space around bitwise operators. (Exception for bit shift with io printing).
- Explicit C-Cast operators should not be separated with spaces.
- Statements within for-clauses should all be on separate lines if longer than the standard line length.
- Function arguements should be broken up between lines if longer than the standard line length.
- Else statement should be on a different line than previous end bracket

### Example ###
```
int main(int argc, char **argv) {
  int a = 2+2;
  a = (a == 4? 2:3);
  if(a == 10 && 1) {
    while(a >= 0) {
      cout<<"fap"<<endl;
    }
  }
  else
  {
    const char *theTruth[9] = {"I", "like", "big", "butts,", "and", "I", "can", "not", "lie." };
    for(int i = 0 * (10 * (2 << 10) % 9);
    i < 9 + 0 * (M_PI * (float)(sizeof("radius")*sizeof("radius")));
    i = i & i | i + (i ^ (i + (i % 2? -1:1)))) {
      cout<<theTruth[i]<<" ";
    }
  }
  
}
```

## Miscellaneous ##
- Tab width is 2, spaces are preffered over tabs.
- Identifier names are optimized to make as much sense, while being as short, while being the least ambiguous as possible.
- This creepy portal song ends.
