# def calculateMinimumSession(numOfBankers, numOfParticipants, bankersPreferences, participantsPreferences):
#     participant = [0] * numOfParticipants
#     bankers = [0] * numOfBankers
#     minimum = 0
#     for i in range(len(participantsPreferences)):
#         for j in range(len(participantsPreferences[i])):
#             bankers[participantsPreferences[i][j] - 1] += 1
#             if bankers[participantsPreferences[i][j] - 1] > minimum:
#                 minimum = bankers[participantsPreferences[i][j] - 1]
#             if not (i + 1) in bankersPreferences[participantsPreferences[i][j] - 1]:
#                 participant[i] += 1
#                 if participant[i] > minimum:
#                     minimum = participant[i]
#     for i in range(len(bankersPreferences)):
#         for j in range(len(bankersPreferences[i])):
#             participant[bankersPreferences[i][j] - 1] += 1
#             if participant[bankersPreferences[i][j] - 1] > minimum:
#                 minimum = participant[bankersPreferences[i][j] - 1]
#             if not (i + 1) in participantsPreferences[bankersPreferences[i][j] - 1]:
#                 bankers[i] += 1
#                 if bankers[i] > minimum:
#                     minimum = bankers[i]
#     return minimum


def calculateMinimumSession(numOfBankers, numOfParticipants, bankersPreferences, participantsPreferences):
    participant = [0] * numOfParticipants
    bankers = [0] * numOfBankers
    minimum = 0
    for i in range(numOfParticipants):
        for j in range(len(participantsPreferences[i])):
            bankers[participantsPreferences[i][j] - 1] += 1
            participant[i] += 1
            if bankers[participantsPreferences[i][j] - 1] > minimum:
                minimum = bankers[participantsPreferences[i][j] - 1]
            if participant[i] > minimum:
                minimum = participant[i]
    for i in range(numOfBankers):
        for j in range(len(bankersPreferences[i])):
            if not (i + 1) in participantsPreferences[bankersPreferences[i][j] - 1]:
                bankers[i] += 1
                if bankers[i] > minimum:
                    minimum = bankers[i]
                participant[bankersPreferences[i][j] - 1] += 1
                if participant[bankersPreferences[i][j] - 1] > minimum:
                    minimum = participant[bankersPreferences[i][j] - 1]
    return minimum


def main():
    firstLine = input().split(" ")
    secondLine = input().split(" ")
    numOfBankers = int(firstLine[0])
    numOfParticipants = int(secondLine[0])
    bankersPreferences = firstLine[1].split(",")
    participantsPreferences = secondLine[1].split(",")

    bankersPreferencesListOfList = parsePreferences(bankersPreferences)
    participantsPreferencesListOfList = parsePreferences(participantsPreferences)

    answer = calculateMinimumSession(
        numOfBankers,
        numOfParticipants,
        bankersPreferencesListOfList,
        participantsPreferencesListOfList
    )
    print(answer)


def parsePreferences(preferences):
    preferenceListOfList = []
    for index in range(0, len(preferences)):
        preferenceArr = preferences[index].split("&")
        preferenceListOfList.append([int(p) for p in preferenceArr])
    return preferenceListOfList


if __name__ == '__main__':
    main()
