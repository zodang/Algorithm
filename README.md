## 그리디
그리디 알고리즘은 **'지금 당장 가장 좋은 선택'을 반복적으로 수행하여 전체 문제의 최적해를 찾는 알고리즘**으로, 순간의 최선이 최종적인 최적해를 가져올 것이라고 가정하고 문제를 해결한다. 동전 거스름돈 문제처럼 가장 큰 단위부터 거스르거나, 각 단계에서 가장 이득이 되는 선택을 하는 방식이 대표적이며, **단순하고 빠르지만 항상 최적의 결과를 보장하지는 않는다**는 특징이 있다.

<br/>

| 출처 | 문제 | 소스코드 |
| --- | --- | --- |
| 이코테 | p.311 모험가길드 | [C++](이코테/그리디/모험가길드.cpp) |
| | p.312 곱하기혹은더하기 | [C++](이코테/그리디/곱하기혹은더하기.cpp) |
| | <a href="https://www.acmicpc.net/problem/1439">p.313 문자열뒤집기</a> | [C++](이코테/그리디/문자열뒤집기.cpp) |
| | p.314 만들수없는금액 | [C++](이코테/그리디/만들수없는금액.cpp) |
| | p.315 볼링공고르기 | [C++](이코테/그리디/볼링공고르기.cpp) |
| 백준 | <a href="https://www.acmicpc.net/problem/1931">1931 - 회의실배정</a> | [C++](백준/그리디/1931-회의실배정) |
| | <a href="https://www.acmicpc.net/problem/2839">2839 - 설탕배달</a> | [C++](백준/그리디/2389-설탕배달) |
| | <a href="https://www.acmicpc.net/problem/11047">11047 - 동전0</a> | [C++](백준/그리디/11047-동전0) |
| | <a href="https://www.acmicpc.net/problem/11399">11399 - ATM</a> | [C++](백준/그리디/11399-ATM) |

<br/>

## 구현
구현은 **머릿속에 있는 알고리즘을 소스코드로 바꾸는 과정**이다. 대표적으로 완전탐색과 시뮬레이션 유형이 있다.

완전탐색(Brute-Force)은 **문제의 모든 가능한 경우의 수를 빠짐없이 시도하여 정답을 찾는 방법**이다. 구현이 비교적 간단하고 정확한 답을 보장하지만, 경우의 수가 많아지면 계산 시간이 기하급수적으로 늘어나는 단점이 있어 입력 크기가 작은 문제에 주로 사용된다.

시뮬레이션은 **문제 상황이나 규칙을 단계별로 재현하고 결과를 예측하는 알고리즘**으로, 문제의 조건에 따라 순차적으로 동작을 구현해야 한다. 게임 캐릭터를 이동시키거나 특정 규칙에 따라 배열을 조작하는 방식이 대표적이다. 

<br/>

| 출처 | 문제 | 소스코드 |
| --- | --- | --- |
| 이코테 | <a href="https://www.acmicpc.net/problem/18406">p.321 럭키스트레이트</a> | [C++](이코테/구현/럭키스트레이트.cpp) |
| | p.322 문자열재정렬 | [C++](이코테/구현/문자열재정렬.cpp) |
| | <a href="https://school.programmers.co.kr/learn/courses/30/lessons/60057">p.323 문자열 압축</a> | [C++](이코테/구현/문자열압축.cpp) |
| | <a href="https://school.programmers.co.kr/learn/courses/30/lessons/60059">p.325 자물쇠와열쇠</a> | [C++](이코테/구현/자물쇠와열쇠.cpp) |
| | <a href="https://www.acmicpc.net/problem/3190">p.327 뱀</a> | [C++](이코테/구현/뱀.cpp) |
| | <a href="https://school.programmers.co.kr/learn/courses/30/lessons/60061">p.329 기둥과보설치</a> | [C++](이코테/구현/기둥과보설치.cpp) |
| | <a href="https://www.acmicpc.net/problem/15686">p.332 치킨배달 </a> | [C++](이코테/구현/치킨배달.cpp) |
| 백준 | <a href="https://www.acmicpc.net/problem/1018">1018 - 체스판다시칠하기</a> | [C++](백준/구현/1018-체스판다시칠하기) |

<br/>

## DFS/BFS
DFS(깊이 우선 탐색)와 BFS(너비 우선 탐색)는 그래프나 트리 구조에서 **모든 노드를 탐색하는 알고리즘**이다. 

DFS는 **한 경로를 끝까지 파고드는 방식**으로, 주로 스택 자료구조 혹은 재귀 함수를 사용한다.

BFS는 **시작점에서 가까운 노드부터 단계별로 넓게 탐색하는 방식**으로, 주로 큐 자료구조를 사용한다.

<br/>

| 출처 | 문제 | 소스코드 |
| --- | --- | --- |
| 이코테 | <a href="https://www.acmicpc.net/problem/18352">p.339 특정거리의도시찾기</a> | [C++](이코테/DFS&BFS/특정거리의도시찾기.cpp) |
|  | <a href="https://www.acmicpc.net/problem/14502">p.341 연구소</a> | [C++](이코테/DFS&BFS/연구소.cpp) |
|  | <a href="https://www.acmicpc.net/problem/18405">p.344 경쟁적전염</a> | [C++](이코테/DFS&BFS/경쟁적전염.cpp) |
|  | <a href="https://school.programmers.co.kr/learn/courses/30/lessons/60058">p.346 괄호변환</a> | [C++](이코테/DFS&BFS/괄호변환.cpp) |
|  | <a href="https://www.acmicpc.net/problem/14888">p.349 연산자끼워넣기</a> | [C++](이코테/DFS&BFS/연산자끼워넣기.cpp) |
| 백준 | <a href="https://www.acmicpc.net/problem/2606">2606 - 바이러스</a> | [C++](백준/DFS&BFS/2606-바이러스.cpp) |

<br/>

## 정렬 알고리즘
<a href="https://zodang.tistory.com/23">정렬 알고리즘</a>이란 **데이터를 특정 기준에 따라 효율적으로 순서대로 나열하는 방법**을 의미한다. 대표적인 종류로는 버블 정렬, 선택 정렬, 삽입 정렬, 병합 정렬, 퀵 정렬 등이 있으며, 데이터의 양과 특성에 따라 적합한 알고리즘을 선택하는 것이 중요하다.

<br/>

| 출처 | 문제 | 소스코드 |
| --- | --- | --- |
| 이코테 | <a href="https://www.acmicpc.net/problem/10825">p.359 국영수</a> | [C++](이코테/정렬/국영수.cpp) |
|  | <a href="https://www.acmicpc.net/problem/18310">p.360 안테나</a> | [C++](이코테/정렬/안테나.cpp) |
