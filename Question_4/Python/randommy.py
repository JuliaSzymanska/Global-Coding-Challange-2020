import random


def main():
    string = []
    string.append(str(1000))
    string.append(" ")
    string.append(str(20))
    string.append('\n')
    for i in range(1000):
        string.append(str(round(random.random(), 2)))
        string.append(' ')
    string = string[:-1]
    string.append('\n')
    for i in range(1000):
        string.append(str(round(random.uniform(1, 100), 2)))
        string.append(' ')
    string = string[:-1]
    string.append('\n')
    for i in range(1000):
        string.append(str(round(random.uniform(1, 100), 2)))
        string.append(' ')
    string = string[:-1]
    # print("".join(string))
    f = open("wygen2.txt", "a")
    f.write("".join(string))
    f.close()

if __name__ == '__main__':
    main()
