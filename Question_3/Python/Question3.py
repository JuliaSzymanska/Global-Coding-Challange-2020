def find_min_days(prices, profit):
    string = []
    for k in profit:
        buyDate = -1
        sellDate = -1
        for i in enumerate(prices):
            if sellDate <= i[0] + 1 and sellDate != -1:
                break
            if (k + i[1]) in prices[(i[0] + 1):]:
                index = prices[(i[0] + 1):].index(k + i[1]) + i[0] + 1
                if buyDate != -1 and sellDate != -1:
                    if index + 1 < sellDate or (index + 1 == sellDate and i[0] + 1 > buyDate):
                        buyDate = i[0] + 1
                        sellDate = index + 1
                else:
                    buyDate = i[0] + 1
                    sellDate = index + 1
        if buyDate == -1 and sellDate == -1:
            string.append("-1")
        else:
            string.append(str(buyDate) + " " + str(sellDate))
        string.append(",")
    return "".join(string[:-1])


n, d = map(int, input().split())
prices = list(map(int, input().split()))
profit = list()
for i in range(d):
    profit.append(int(input().strip()))
answer = find_min_days(prices, profit)
print(answer)
