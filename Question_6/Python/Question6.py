import math


def encrypt(words):
    words = words.replace(" ", "")
    row = int(math.floor(math.sqrt(len(words))))
    col = int(math.ceil(math.sqrt(len(words))))
    if row * col < len(words):
        row += 1
    string = []
    k = 0
    i = 0
    while i < row * col - 1:
        if i < len(words):
            string.append(words[i])
        if i == col * (row - 1) + k:
            k += 1
            i = k
            string.append(" ")
        else:
            i += col
    return "".join(string)


def main():
    words = input()
    answer = encrypt(words)
    print(answer)


if __name__ == '__main__':
    main()
