# Question 3 - Profit Model for John


John has recently started stock trading. He has predicted share prices for a particular company, over the next N days. John wants to analyze this data to build a model which will predict the best day to buy and sell the shares to achieve a specific profit. If there are multiple approaches of buying and selling shares to achieve this profit, John would like to know which of these will achieve the profit the earliest.

## Input format
The first line contains two integers N and D, where N is the number of days for which he is predicting the share values and D is the number of different profits he would like to achieve.

The next line contains N space separated integers, where N is the value of the share on the i+1th day.

The next D lines contain a single integer D , where D is the profit that needs to be made.

## Constraints
- Only 1 share can be bought.
- Short selling is not allowed.
- 1 ≤ N ≤ 100000
- 1 ≤ D ≤ 10
- 1 ≤ N , D ≤ 1000000

## Output format
Print in the same line two space separated integers - the day on which the share was bought and the day on which the share was sold. The buy and sell days for different profits should be separated by , . If it is not possible to achieve the desirable profit, print -1.

## Examples
### Example 1
#### Input
```
6 2
3 1 2 1 4 5
3
2
```

#### Output
```
4 5,3 5
```

i.e. To achieve a profit of 3, John can either buy on day 2 or day 4 and sell on day 5 or he can buy on day 3 and sell on day 6. The approach which takes the minimum number of days is where he buys on day 4 and sells on day 5. So, the answer is 4 5. To achieve a profit of 2, John can either buy on day 1 and sell on day 6 or he can buy on day 3 and sell on day 5. The approach which happens earliest is where John buys on day 3 and sells on day 5.

### Example 2
#### Input
```
6 2
3 6 9 8 2 4
5
2
```


#### Output
```
1 4,2 4
```

i.e. To achieve a profit of 5, John can buy on day 1 when the price is 3 and sell on day 4 when the price is 8 for a profit of 5. To achieve a profit of 2, he has two options, buy on day 2 and sell on day 4 or buy on day 5 and sell on day 6. The approach which happens earliest is where John buys on day 2 and sells on day 4.