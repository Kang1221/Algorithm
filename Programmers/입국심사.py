def solution(n, times):
    left = 1  # 최소 시간
    right = max(times) * n  # 최대 시간
    answer = right  # 정답 초기화

    while left <= right:
        mid = (left + right) // 2
        
        # mid 시간 동안 각 심사관이 몇 명 처리할 수 있는지
        total = sum(mid // time for time in times)

        if total >= n:
            # 이 시간에 n명 이상 심사 가능 → 가능한 정답 후보, 더 줄여보기
            answer = mid
            right = mid - 1
        else:
            # 이 시간엔 n명 못 처리함 → 시간 늘려야 함
            left = mid + 1

    return answer
