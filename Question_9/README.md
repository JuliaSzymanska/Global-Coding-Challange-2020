# Question 9 - Unauthorized Transactions
It is important that banks recognize unauthorized transactions in order to protect their clients. Leon has recently started working at a large credit card company where his role is to investigate fraudulent credit card transactions. He is attempting to sort transactions, depending on their fraud probability, into separate boxes.

Let t = 2 mean that Leon has 2 types of transactions and 2 different boxes, both labelled from 0 to t-1. The current organization of the transactions in each box can be shown using a matrix M (size t x t). Consider M = [[8, 3], [3, 9]]:

|       | Type 0 | Type 1 |
| ----- | ------ | ------ |
| Box 0 | 8      | 3      |
| Box 1 | 3      | 9      |

In this table, we can see in box 0 there are 8 transactions of type 0 and 3 transactions of type 1. In box 1, there are 3 transactions of type 0 and 9 transactions of type 1. Leon is able to switch, in a single operation, two transactions in different boxes. He can switch a type 0 transaction from Box 1 with a type 1 transaction from Box 0. As shown below.

|       | Type 0 | Type 1 |
| ----- | ------ | ------ |
| Box 0 | 9      | 2      |
| Box 1 | 2      | 10     |


He can continue doing this until he has all transactions of type 0 in box 0 and all transactions of type 1 in box 1. The sorted boxes are reflected in the Matrix table below. There can be multiple different ways of sorting the transactions.

|       | Type 0 | Type 1 |
| ----- | ------ | ------ |
| Box 0 | 11     | 0      |
| Box 1 | 0      | 12     |


These switching operations need to fulfil the following condition in order for the transactions to be sorted:

- Every box has only transactions of the same type. Two transactions of the same type cannot be located in two different boxes.

## Input format
The first line contains an integer n, the number of unsorted problems. Attempt to sort n different unsorted problems, each in the form of a matrix M.

Each of the next n sets contains:
- Integer t represents the number of boxes (rows) and transaction types (columns).
- The next t lines contains integers, separated using a space, for row M[i].

## Constraints

- A box is a two dimensional array of integers, illustrating the number of transactions of each type found in each box.
- 1 ≤ n ≤10
- 1 ≤ t ≤ 100.
- 0 ≤ M[box][Transaction type] ≤ 100000

## Output format
For each unsorted problem, print the string “Possible” if Leon can sort the transactions in the given matrix. Else, print the string “Impossible”. These strings should be separated by ``` ,``` when answering each unsorted problem.

## Examples
### Example 1
#### Input
```
2
3
2 4 0
3 0 1
1 0 0
2
1 4
5 4
```

#### Output

```
Possible,Impossible
```

#### Explanation
We perform the following n = 2 unsorted problems.

The table below shows one way for which the first unsorted problem can be solved. Thus, we print “Possible”.

|       | Type 0 | Type 1 | Type 2 |
| ----- | ------ | ------ | ------ |
| Box 0 | 6      | 0      | 0      |
| Box 1 | 0      | 4      | 0      |
| Box 2 | 0      | 0      | 1      |


The table below shows the matrix for the second unsorted problem:

|       | Type 0 | Type 1 |
| ----- | ------ | ------ |
| Box 0 | 1      | 4      |
| Box 1 | 5      | 4      |
 
No matter how many times we attempt to switch transactions of type 0 and 1, we will never end up with box 0 only containing type 0 transactions and box 1 only containing type 1 transactions. Thus, we print "Impossible".