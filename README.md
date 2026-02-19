# Algorithm Study Repository
<img src="https://isocpp.org/assets/images/cpp_logo.png" width="100px" alt="OpenGL">

<br/>

## 📌 Project Overview
C++ 기반 알고리즘 학습을 목적으로 주요 알고리즘 유형의 개념 정리와 구현 예제를 정리한 개인 학습 레포지토리입니다.

『이것이 취업을 위한 코딩 테스트다(나동빈)』와 백준 온라인 저지 알고리즘 분류 문제를 참고하여 학습했습니다. 

(학습 진행에 따라 지속적으로 업데이트됩니다.)

<br/>

## 🗂️ Study Scope
```
- Greedy Algorithms
- Implementation (Brute Force & Simulation)
- Graph Traversal (DFS / BFS)
- Sorting Algorithms
- Binary Search
- Dynamic Programming
- Shortest Path Algorithms
- Graph Algorithms
```

<br/>

## 📚 Study Notes
### 1. Greedy Algorithms
그리디 알고리즘은 **'지금 당장 가장 좋은 선택'을 반복적으로 수행하여 전체 문제의 최적해를 찾는 알고리즘**으로, 순간의 최선이 최종적인 최적해를 가져올 것이라고 가정하고 문제를 해결한다. 동전 거스름돈 문제처럼 가장 큰 단위부터 거스르거나, 각 단계에서 가장 이득이 되는 선택을 하는 방식이 대표적이며, **단순하고 빠르지만 항상 최적의 결과를 보장하지는 않는다**는 특징이 있다.

<br/>

### 2. Implementation (Brute Force & Simulation)
구현은 **머릿속에 있는 알고리즘을 소스코드로 바꾸는 과정**이다. 대표적으로 완전탐색과 시뮬레이션 유형이 있다.

완전탐색(Brute-Force)은 **문제의 모든 가능한 경우의 수를 빠짐없이 시도하여 정답을 찾는 방법**이다. 구현이 비교적 간단하고 정확한 답을 보장하지만, 경우의 수가 많아지면 계산 시간이 기하급수적으로 늘어나는 단점이 있어 입력 크기가 작은 문제에 주로 사용된다.

시뮬레이션은 **문제 상황이나 규칙을 단계별로 재현하고 결과를 예측하는 알고리즘**으로, 문제의 조건에 따라 순차적으로 동작을 구현해야 한다. 게임 캐릭터를 이동시키거나 특정 규칙에 따라 배열을 조작하는 방식이 대표적이다. 


<br/>

### 3. Graph Traversal (DFS / BFS)
DFS(깊이 우선 탐색)와 BFS(너비 우선 탐색)는 그래프나 트리 구조에서 **모든 노드를 탐색하는 알고리즘**이다. 

DFS는 **한 경로를 끝까지 파고드는 방식**으로, 주로 스택 자료구조 혹은 재귀 함수를 사용한다.

BFS는 **시작점에서 가까운 노드부터 단계별로 넓게 탐색하는 방식**으로, 주로 큐 자료구조를 사용한다.

<br/>

### 4. Sorting Algorithms
<a href="https://zodang.tistory.com/23">정렬 알고리즘</a>이란 **데이터를 특정 기준에 따라 효율적으로 순서대로 나열하는 방법**을 의미한다. 대표적인 종류로는 버블 정렬, 선택 정렬, 삽입 정렬, 병합 정렬, 퀵 정렬 등이 있으며, 데이터의 양과 특성에 따라 적합한 알고리즘을 선택하는 것이 중요하다.

<br/>

### 5. Binary Search
<a href="https://zodang.tistory.com/24">이진 탐색(Binary Search)</a>은 정렬된 배열의 중앙값을 목표값과 비교하여, **탐색 범위를 절반씩 줄여나가며 원하는 데이터를 찾는 알고리즘**이다. 데이터가 정렬되어 있어야만 사용할 수 있으며, 검색 속도가 매우 빠르다는 장점이 있다.
<br/>
