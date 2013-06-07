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
