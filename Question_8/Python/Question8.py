# Participants may update the following function parameters
def countNumberOfWays(numOfUnits, numOfCoinTypes, coins):
    table = [0] * (numOfUnits + 1)
    table[0] = 1
    for i in range(numOfCoinTypes):
        for j in range(coins[i], numOfUnits + 1):
            table[j] += table[j - coins[i]]
    return table[numOfUnits]


def main():
    firstLine = input().split(" ")
    secondLine = input().split(" ")

    numOfUnits = int(firstLine[0])
    numOfCoinTypes = int(firstLine[1])
    coins = list(map(int, secondLine))

    # Participants may update the following function parameters
    answer = countNumberOfWays(numOfUnits, numOfCoinTypes, coins)

    # Please do not remove the below line.
    print(answer)
    # Do not print anything after this line


if __name__ == '__main__':
    main()
