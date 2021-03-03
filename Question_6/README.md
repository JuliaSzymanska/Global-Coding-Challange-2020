# Question 6 - Encrypting Messages

Data encryption prevents data visibility in the event of its unauthorized access.

Consider the following encryption algorithm to encipher a given string input. Firstly, discard all spaces of the string. Then store all the characters within a matrix, according to the constraints below, to get the encoded string output.

## Constraints
- floor(squareRoot(stringLength)) <= matrixRows <= matrixColumns <=
- ceil(squareRoot(stringLength))
- matrixRows x matrixColumns >= stringLength
- Choose the matrix with the smallest area.
- Print out the characters of the first column, then embed a space before printing out the following column, etc.

## Input format
A string

## Output format
An encrypted string

## Examples
### Example 1

Command line input:
```
coding
```

Output: ``` ci on dg ```

i.e. The string length is 6. The square root of 6 is between 2 and 3. Thus, the string is rewritten as a matrix with 2 rows and 3 columns.
```
cod
ing
```
### Example 2
Command line input:
```
its harder to read code than to write it
```
Output: ``` ideeoi teatwt srdhr htcai aoont rrdte ```

i.e. The string length is 32. The square root of 32 is between 5 and 6. However, 5 x 6 is not >= 32, therefore, the string is rewritten as a matrix with 6 rows and 6 columns.
```
itshar
dertor
eadcod
ethant
owrite
it
```