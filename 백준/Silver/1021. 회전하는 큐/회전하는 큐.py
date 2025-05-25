from collections import deque

# 입력 받기
n, m = map(int, input().split())
# 1부터 N까지의 수로 초기화된 deque 생성
queue = deque(range(1, n + 1))
# 뽑아내려고 하는 수의 위치를 리스트로 받기
targets = list(map(int, input().split()))

count = 0  # 연산 횟수 초기화

for target in targets:
    while True:
        # 현재 큐의 첫 번째 원소가 우리가 찾고자 하는 원소인 경우
        if queue[0] == target:
            queue.popleft()  # 원소를 뽑아냄
            break  # 다음 타겟으로 넘어감
        else:
            # 타겟의 인덱스를 찾음
            index = queue.index(target)
            # 큐의 길이의 절반과 비교하여 왼쪽으로 회전할지 오른쪽으로 회전할지 결정
            if index <= len(queue) // 2:
                queue.rotate(-1)  # 왼쪽으로 한 칸 회전
            else:
                queue.rotate(1)   # 오른쪽으로 한 칸 회전
            count += 1  # 연산 횟수 증가

print(count)  # 최종 연산 횟수 출력
