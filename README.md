# Evaluating Postfix Operations
This program evaluates
postfix expressions using a stack.
The program was designed by Dr. Carlos Arias, who wrote the files 'evaluator.h', 'makefile', and 'main.cpp'. 
'evaluator.cpp' was programmed by Cypress Payne for the Data Structures II (CSC2431)

## Design

The design is a function with the following prototype: `double Evaluate(const string& postfix, bool& error);`.

The function takes in a parameter `postfix` that contains a string with a postfix arithmetic
expression. The expression will have only integers (each can have several digits)
and it can have the following operators: +, -, *, / and ^. The other parameter is used
to check whether the postfix operation was correctly formatted, therefore if `Evaluate` finds
an error, it will set the `error` variable to `true` and return `-1`. If everything goes well
the function will set `error` to `false` and return the result of the expression.

### Examples

Postfix Expression | Infix Expression | Result
-------------------|------------------|-------
`2 5 +`            | `2 + 5`          | `7`
`4 5 * 2 +`        | `4 * 5 + 2`      | `22`
`5 1 + 3 *`        | `(5 + 1) * 3`    | `18`
`1 4 + 10 4 - *`   | `(1  + 4) * (10 - 4)` | `30`
`3 2 ^ 5 -`        | `3 ^ 2 - 5`      | `4`


## Files
* `makefile`
* `main.cpp` this file holds the main function, contains unit tests, and outputs how much of the unit tests 'evaluator.cpp' passed
* `evaluator.h`
* `evaluator.cpp` this file defines the function `Evaluate`. 

The Evaluate function can also work with Real numbers. For example, the Evaluate function can take and calculate `2.7172 0.5 ^`.
