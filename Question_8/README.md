# Question 8 - Counting Change
James has recently started working in a currency exchange office at the airport. As many people are buying different types of currencies before they go on holiday, he ends up working with various types of coins. James would like to find all possible ways of making change for a desired amount using different coins. 

For example, if James has 3 different types of coins, and the value of each is given as 15, 31 and 9, an amount of 63 can be made in two ways: {9, 9, 15, 15, 15} and {9, 9, 9, 9, 9, 9, 9}.

Create a countNumberOfWays function which returns an integer denoting the number of possible ways to give change.

## Input format

The first line:
- n: an integer, is the desired amount.
- m: an integer, is the number of different coin types.

The second line:
- coins: space-separated distinct integers describing the respective values of each coin.

## Output format
An integer denoting the number of possible ways to make change for the desired amount.

## Examples
### Example 1
#### Input
```
12 4
2 3 4 5
```

Output
```
10
```

i.e. There are 10 ways to change n = 12 using coins with values 2, 3, 4 and 5.

1. {2, 2, 2, 2, 2, 2}
2. {2, 2, 2, 2, 4}
3. {2, 2, 2, 3, 3}
4. {2, 2, 4, 4}
5. {2, 2, 5, 3}
6. {2, 3, 3, 4}
7. {3, 3, 3, 3}
8. {2, 5, 5}
9. {3, 4, 5}
10. {4, 4, 4}

Thus, we print 10 as our answer.

### Example 2
#### Input
```
206 4
2 20 9 30
```

Output
```
214
```