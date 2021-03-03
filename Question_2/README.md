# [Question 2 - Profit Maximization - Extended](https://github.com/JuliaSzymanska/Global_Coding_Challange_2020/blob/master/.questions/Global_Coding_Challenge_2.pdf)

Emilia can now use multiple buy and sell operations over a given period of time.

Given a sequence of predicted share prices, she wants to find the maximum possible profit while using the smallest number of trading operations throughout the given time.

## Constraints
- Short selling is not allowed.
- All of the predicted share prices are positive integers.
- You can only execute one buy or one sell operation of a share on a given day.
- Only one share can be bought or sold at a time.
- You are not required to execute a buy or sell operation every day.

## Input format
The first integer input is the number of predicted days.

The subsequent integer input is a sequence of positive integers. The element at position i refers to the predicted share price of a given stock on the ith day.

## Output format
An integer that is the maximum profit using the smallest number of trading operations throughout the given time.

## Examples
### Examples 1
#### Input
```
 14 5 1 6 3 2 5 6 1 3 6 2 5 5 10
```

Number of predicted days = 14
A sequence of predicted share prices = [5,1,6,3,2,5,6,1,3,6,2,5,5,10]

##### Output
```
22
```
i.e. The smallest operation required is 8. Emilia can achieve this by buying at i = 1 when the price is $1 and selling at i = 2 when the price is $6 for a profit of $5. She can then buy at i = 4 when the price is $2 and sell at i = 6 when the price is $6 for a profit of $4. She can then buy at i = 7 when the price is $1 and sell at i = 9 when the price is $6 for a profit of $5. Then buy at i = 10 when the price is $2 and sell at i = 13 when the price is $10 for a profit of $8. If you add up all of the profits from these buy and sell orders (5 + 4 + 5 + 8) the output is 22.

### Examples 2
#### Input
```
8 100 10 12 5 6 14 5 6
```

Number of predicted days = 8
A sequence of predicted share prices = [100, 10, 12, 5, 6, 14, 5, 6]

#### Output
```
12
```
i.e. The smallest operation required is 6. Emilia can achieve this by buying at i = 1 when the price is $10 and selling at i = 2 when the price is $12 for a profit of $2. Then she can buy at i = 3 when the price is $5 and sell at i = 5 when the price is $14 for a profit of $9. Then buy at i = 6 when the price is $5 and sell at i = 7 when the price is $6 for a profit of $1. If you add up all of the profits from these buy and sell orders (2 + 9 + 1) the output is 12.