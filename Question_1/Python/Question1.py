def findMaxProfit(predictedSharePrices):
    maxis = predictedSharePrices[1] - predictedSharePrices[0]
    minis = predictedSharePrices[0]
    for i in predictedSharePrices:
        if i - minis > maxis:
            maxis = i - minis
        elif i < minis:
            minis = i
    return maxis


def main():
    line = input().split()
    predictedSharePrices = list(map(int, line[1:]))

    answer = findMaxProfit(predictedSharePrices)

    print(answer)


if __name__ == '__main__':
    main()
