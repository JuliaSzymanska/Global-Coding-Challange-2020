# Question 4 - Risk Trading

Whenever a company trades securities, there are various risks involved with the trade. Risk analysis is done for each trade in order to make the maximum profit from that trade. Each available trade can have the following properties:
- Probability that the trade will make a profit (p).
- Probability that the trade will make a loss (1-p).
- Potential profit of the trade (x).
- Potential loss of the trade (y).

Find and print the maximum expected amount of money the company can make by performing at most m of the n trades, given the values of m, n, x, y and p.

## Input format
The first line contains two space-separated integers denoting the respective values n (the number of trades available) and m (the maximum number of trades allowed).

The second line contains p space-separated floating-point numbers describing the respective values of pi, where each pidenotes the probability that the ith transaction will result in a profit.

The third line contains x space-separated floating-point numbers describing the respective values of xi, where each xi denotes the potential profit of the ith transaction.

The fourth line contains y space-separated floating-point numbers describing the respective values of yi, where each yi denotes the potential loss of the ith transaction.

## Constraints
- 1 ≤ n, m ≤ 100000
- 0 ≤ x, y ≤ 100
- 0 ≤ p ≤ 1

All x, y and p are floating-point numbers scaled to exactly two decimal places (i.e 2.45 format).

## Output format
Print the maximum expected amount of money that can be made by performing at most m of the n available trades. Scale your answer to exactly 2 decimal places.

## Examples
### Example 1
#### Input
```
4 2
0.50 0.50 0.50 0.50
4.00 1.00 2.00 3.00
4.00 0.50 1.00 1.00
```

#### Output
```
1.50 
```
i.e. There are n = 4 transactions available and we can perform at most m = 2 of them. We also know the probability that each transaction results in a profit is 0.5. If the third and the fourth transactions are performed, the expected amount of money made from these transactions is: (0.5 * 2.0) - ((1 - 0.5) * 1.0) + (0.5 * 3.0) - ((1 - 0.5) * 1.0) = 1.5. Since this is greater than all of the other possibilities we could calculate, 1.50 is our answer.

### Example 2
#### Input
```
2 2
0.90 0.50
1.00 0.50
100.00 0.40
```

#### Output
```
0.05
```
i.e. There are n = 2 transactions available and we can perform at most m = 2 of them. We know that the probability the first transaction is profitable is 0.9 and for the second transaction this is 0.5. If the second transaction is performed, the expected amount of money made from this transaction is: (0.5 * 0.5) - ((1 - 0.5) * 0.4) = 0.05. Since this is greater than all of the other possibilities we could calculate, we print 0.05 as our answer.