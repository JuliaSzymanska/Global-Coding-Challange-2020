def organizingContainers(container):
    rows = [0] * len(container)
    cols = [0] * len(container)
    for i in range(len(container)):
        for j in range(len(container)):
            rows[i] += container[i][j]
            cols[j] += container[i][j]
    if sorted(rows) == sorted(cols):
        return "Possible"
    return "Impossible"


if __name__ == "__main__":
    q = int(input().strip())
    answer = ""
    for a0 in range(q):
        n = int(input().strip())
        container = []
        for container_i in range(n):
            container_t = [int(container_temp) for container_temp in input().strip().split(' ')]
            container.append(container_t)
        result = organizingContainers(container)
        if (answer == ""):
            answer = str(result)
        else:
            answer = answer + "," + str(result)
    # Do not remove below line
    print(answer)
    # Do not print anything after this line
