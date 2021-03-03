# import math
# from decimal import *
#
#
# def maximumExpectedMoney(noOfTradesAvailable, maximumTradesAllowed, p, x, y):
#     p = [int(round(pi * 100, 0)) for pi in p]
#     x = [int(round(pi * 100, 0)) for pi in x]
#     y = [int(round(pi * 100, 0)) for pi in y]
#     money = []
#     for i in range(noOfTradesAvailable):
#         first = (p[i] * x[i])
#         prop = 100 - p[i]
#         second = (prop * y[i])
#         third = first - second
#         if third > 0:
#             money.append(third)
#     money.sort(reverse=True)
#     suma = sum(money[:maximumTradesAllowed])
#     return "%.2f" % (suma / 10000)
#
#
# def main():
#     # This part may require participants to fill in as well.
#     noOfTradesAvailable, maximumTradesAllowed = list(map(int, input().split()))
#     p = list(map(float, input().split()))
#     x = list(map(float, input().split()))
#     y = list(map(float, input().split()))
#
#     # Participants may update the following function parameters
#
#     answer = maximumExpectedMoney(noOfTradesAvailable, maximumTradesAllowed, p, x, y)
#     print(answer)
#
#
# if __name__ == '__main__':
#     main()

def maximumExpectedMoney(noOfTradesAvailable, maximumTradesAllowed, p, x, y):
    money = []
    for i in range(noOfTradesAvailable):
        if (p[i] * x[i]) - ((1 - p[i]) * y[i]) > 0:
            money.append((p[i] * x[i]) - ((1 - p[i]) * y[i]))
    money.sort(reverse=True)
    return "%.2f" % round(sum(money[:maximumTradesAllowed]), 2)


def main():
    # This part may require participants to fill in as well.
    noOfTradesAvailable, maximumTradesAllowed = list(map(int, input().split()))
    p = list(map(float, input().split()))
    x = list(map(float, input().split()))
    y = list(map(float, input().split()))

    # Participants may update the following function parameters

    answer = maximumExpectedMoney(noOfTradesAvailable, maximumTradesAllowed, p, x, y)
    print(answer)


if __name__ == '__main__':
    main()
