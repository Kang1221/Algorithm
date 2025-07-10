def solution(n, wires):
    def dfs(node, visited, graph):
        visited[node] = True
        count = 1
        for neighbor in graph[node]:
            if not visited[neighbor]:
                count += dfs(neighbor, visited, graph)
        return count

    answer = n
    for i in range(n-1):
        graph = [[] for _ in range(n + 1)] # 노드별 연결된 노드
        for j in range(len(wires)):
            if i == j:
                continue
            a, b = wires[j]
            graph[a].append(b)
            graph[b].append(a)

        visited = [False] * (n + 1)
        count = dfs(1, visited, graph)
        answer = min(answer, abs(n - count - count))

    return answer
