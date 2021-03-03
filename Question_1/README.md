# Question 1 - Profit Maximization

Emilia, a quantitative researcher, predicts how the closing share price of a stock moves over time.

She wants to find the maximum possible profit of a stock over a given period of time, using only one buy and one sell operation according to a given sequence of predicted share prices.

## Constraints
- Short selling is not allowed.
- All of the predicted share prices are positive integers.

## Input format

The first integer input is the number of predicted days.

The subsequent integer input is a sequence of positive integers. The element at position i refers to the predicted share price of a given stock on the ith day.

## Output format
An integer which is the maximum possible profit with only one buy and one sell operation.

## Examples
### Example 1
#### Input
```
14 5 1 6 3 2 5 6 1 3 6 2 5 5 10
```
Number of predicted days = 14
Sequence of predicted share prices = [5,1,6,3,2,5,6,1,3,6,2,5,5,10]

#### Output
```
9
```
i.e. Buy the stock on day 1 for $1 and sell the stock on the last day at $10.


### Example 2
#### Input
```
8 100 10 12 5 6 14 5 6
```
Number of predicted days = 8
A sequence of predicted share prices = [100, 10, 12, 5, 6, 14, 5, 6]
#### Output
```
9
```
i.e. Buy the stock on day 3 for $5 and sell the stock on day 5 at $14.
