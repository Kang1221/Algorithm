def solution(n, costs):
    # 유니온 파인드
    parent = [i for i in range(n)]
    def find(x):
        if parent[x] != x:
            parent[x] = find(parent[x])  # 경로 압축
        return parent[x]

    def union(x, y):
        root_x = find(x)
        root_y = find(y)
        if root_x != root_y:
            parent[root_y] = root_x
            return True
        return False
    
    # 간선 정렬 : 최소 금액
    costs.sort(key=lambda x: x[2])
    
    total_cost = 0
    edges_used = 0
    for a, b, cost in costs:
        if union(a, b):  # 사이클이 없다면 간선 선택
            total_cost += cost
            edges_used += 1
            if edges_used == n - 1:  # MST 완성
                break

    return total_cost
