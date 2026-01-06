## 그리디
그리디 알고리즘은 **'지금 당장 가장 좋은 선택'을 반복적으로 수행하여 전체 문제의 최적해를 찾는 알고리즘**으로, 순간의 최선이 최종적인 최적해를 가져올 것이라고 가정하고 문제를 해결한다. 동전 거스름돈 문제처럼 가장 큰 단위부터 거스르거나, 각 단계에서 가장 이득이 되는 선택을 하는 방식이 대표적이며, **단순하고 빠르지만 항상 최적의 결과를 보장하지는 않는다**는 특징이 있다.

<br/>

| 출처 | 문제 | 소스코드 |
| --- | --- | --- |
| 이코테 | p.311 모험가길드 | [C++](https://github.com/zodang/Algorithm/blob/main/%EC%9D%B4%EC%BD%94%ED%85%8C/%EA%B7%B8%EB%A6%AC%EB%94%94/%EB%AA%A8%ED%97%98%EA%B0%80%EA%B8%B8%EB%93%9C.cpp) |
| | p.312 곱하기혹은더하기 | [C++](https://github.com/zodang/Algorithm/blob/main/%EC%9D%B4%EC%BD%94%ED%85%8C/%EA%B7%B8%EB%A6%AC%EB%94%94/%EA%B3%B1%ED%95%98%EA%B8%B0%ED%98%B9%EC%9D%80%EB%8D%94%ED%95%98%EA%B8%B0.cpp) |
| | <a href="https://www.acmicpc.net/problem/1439" target="_blank" rel="noreferrer">p.313 문자열뒤집기</a> | [C++](https://github.com/zodang/Algorithm/blob/main/%EC%9D%B4%EC%BD%94%ED%85%8C/%EA%B7%B8%EB%A6%AC%EB%94%94/%EB%AC%B8%EC%9E%90%EC%97%B4%EB%92%A4%EC%A7%91%EA%B8%B0.cpp) |
| | p.314 만들수없는금액 | [C++](https://github.com/zodang/Algorithm/blob/main/%EC%9D%B4%EC%BD%94%ED%85%8C/%EA%B7%B8%EB%A6%AC%EB%94%94/%EB%A7%8C%EB%93%A4%EC%88%98%EC%97%86%EB%8A%94%EA%B8%88%EC%95%A1.cpp) |
| | p.315 볼링공고르기 | [C++](https://github.com/zodang/Algorithm/blob/main/%EC%9D%B4%EC%BD%94%ED%85%8C/%EA%B7%B8%EB%A6%AC%EB%94%94/%EB%B3%BC%EB%A7%81%EA%B3%B5%EA%B3%A0%EB%A5%B4%EA%B8%B0.cpp) |
| 백준 | <a href="https://www.acmicpc.net/problem/1931" target="_blank" rel="noreferrer">1931 - 회의실배정</a> | [C++](https://github.com/zodang/Algorithm/blob/main/%EB%B0%B1%EC%A4%80/%EA%B7%B8%EB%A6%AC%EB%94%94/1931-%ED%9A%8C%EC%9D%98%EC%8B%A4%EB%B0%B0%EC%A0%95) |
| | <a href="https://www.acmicpc.net/problem/2839" target="_blank" rel="noreferrer">2839 - 설탕배달</a> | [C++](https://github.com/zodang/Algorithm/blob/main/%EB%B0%B1%EC%A4%80/%EA%B7%B8%EB%A6%AC%EB%94%94/2389-%EC%84%A4%ED%83%95%EB%B0%B0%EB%8B%AC) |
| | <a href="https://www.acmicpc.net/problem/11047" target="_blank" rel="noreferrer">11047 - 동전0</a> | [C++](https://github.com/zodang/Algorithm/blob/main/%EB%B0%B1%EC%A4%80/%EA%B7%B8%EB%A6%AC%EB%94%94/11047-%EB%8F%99%EC%A0%840) |
| | <a href="https://www.acmicpc.net/problem/11399" target="_blank" rel="noreferrer">11399 - ATM</a> | [C++](https://github.com/zodang/Algorithm/blob/main/%EB%B0%B1%EC%A4%80/%EA%B7%B8%EB%A6%AC%EB%94%94/11399-ATM) |

<br/>

## 구현
구현은 **머릿속에 있는 알고리즘을 소스코드로 바꾸는 과정**이다. 대표적으로 완전탐색과 시뮬레이션 유형이 있다.

완전탐색(Brute-Force)은 **문제의 모든 가능한 경우의 수를 빠짐없이 시도하여 정답을 찾는 방법**이다. 구현이 비교적 간단하고 정확한 답을 보장하지만, 경우의 수가 많아지면 계산 시간이 기하급수적으로 늘어나는 단점이 있어 입력 크기가 작은 문제에 주로 사용된다.

시뮬레이션은 **문제 상황이나 규칙을 단계별로 재현하고 결과를 예측하는 알고리즘**으로, 문제의 조건에 따라 순차적으로 동작을 구현해야 한다. 게임 캐릭터를 이동시키거나 특정 규칙에 따라 배열을 조작하는 방식이 대표적이다. 

<br/>

| 출처 | 문제 | 소스코드 |
| --- | --- | --- |
| 이코테 | <a href="https://www.acmicpc.net/problem/18406" target="_blank" rel="noreferrer">p.321 럭키스트레이트</a> | [C++](https://github.com/zodang/Algorithm/blob/main/%EC%9D%B4%EC%BD%94%ED%85%8C/%EA%B5%AC%ED%98%84/%EB%9F%AD%ED%82%A4%EC%8A%A4%ED%8A%B8%EB%A0%88%EC%9D%B4%ED%8A%B8.cpp) |
| | p.322 문자열재정렬 | [C++](https://github.com/zodang/Algorithm/blob/main/%EC%9D%B4%EC%BD%94%ED%85%8C/%EA%B5%AC%ED%98%84/%EB%AC%B8%EC%9E%90%EC%97%B4%EC%9E%AC%EC%A0%95%EB%A0%AC.cpp) |
| | <a href="https://school.programmers.co.kr/learn/courses/30/lessons/60057" target="_blank" rel="noreferrer">p.323 문자열 압축</a> | [C++](https://github.com/zodang/Algorithm/blob/main/%EC%9D%B4%EC%BD%94%ED%85%8C/%EA%B5%AC%ED%98%84/%EB%AC%B8%EC%9E%90%EC%97%B4%EC%95%95%EC%B6%95.cpp) |
| | <a href="https://school.programmers.co.kr/learn/courses/30/lessons/60059" target="_blank" rel="noreferrer">p.325 자물쇠와열쇠</a> | [C++](https://github.com/zodang/Algorithm/tree/main/%EC%9D%B4%EC%BD%94%ED%85%8C/%EA%B5%AC%ED%98%84) |

