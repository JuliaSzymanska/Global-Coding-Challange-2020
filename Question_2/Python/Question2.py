def findMaxProfit(numOfPredictedTimes, predictedSharePrices):
    predicted = {i[0]: i[1] for i in enumerate(predictedSharePrices)}
    result = 0
    k = 0
    for i in range(numOfPredictedTimes - 1):
        if predictedSharePrices[i + 1] - predictedSharePrices[i] > 0:
            result += predictedSharePrices[i + 1] - predictedSharePrices[i]
    return result


def main():
    line = input().split()
    numOfPredictedTimes = int(line[0])
    predictedSharePrices = list(map(int, line[1:]))
    answer = findMaxProfit(numOfPredictedTimes, predictedSharePrices)
    print(answer)


if __name__ == '__main__':
    main()
