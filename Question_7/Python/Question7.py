def findSuspiciousUserId(questionAndAnswerListOfList):
    string = [""] * (max(max(x) for x in questionAndAnswerListOfList) + 1)
    for i in range(len(questionAndAnswerListOfList)):
        for value in questionAndAnswerListOfList[i + 1:]:
            if questionAndAnswerListOfList[i][0] in value and value[0] in questionAndAnswerListOfList[i]:
                string[value[0]] = str(value[0]) + ","
                string[questionAndAnswerListOfList[i][0]] = str(questionAndAnswerListOfList[i][0]) + ","
    actual = 0
    previous = -1
    while previous < actual:
        previous = actual
        for ints in questionAndAnswerListOfList:
            if not string[ints[0]]:
                i = 0
                for j in ints[1:]:
                    if string[j]:
                        i += 1
                        if i == 2:
                            string[ints[0]] = str(ints[0]) + ","
                            actual += 1
                            break
    return ("".join(string))[:-1]


def main():
    firstLine = input().split(" ")
    secondLine = input()

    # Sample input:
    # 3
    # 1 2,2 1,3 1 2

    numOfQuestions = int(firstLine[0])
    questionAndAnswers = secondLine.split(",")
    questionAndAnswerListOfList = parseQuestionAndAnswer(questionAndAnswers)

    # Participants may update the following function parameters
    answer = findSuspiciousUserId(questionAndAnswerListOfList)

    # Please do not remove the below line.
    print(answer)
    # Do not print anything after this line


def parseQuestionAndAnswer(questionAndAnswers):
    questionAndAnswerListOfList = []
    for index in range(0, len(questionAndAnswers)):
        questionAndAnswerList = questionAndAnswers[index].split(" ")
        questionAndAnswerListOfList.append([int(x) for x in questionAndAnswerList])
    return questionAndAnswerListOfList


if __name__ == '__main__':
    main()
