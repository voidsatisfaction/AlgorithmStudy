#계산량 분석
재귀적 알고리즘의 계산량은 recurence equation으로 나타낼 수 있다. Recurrence equation은 다음과 같은 꼴의 식을 말한다.  
<img src="./fig/eq1.png" height="60px">

Recurrence equation이 주어졌을 때 T를 구하는 방법에는 다음 세 가지가 있다.

- Substitution method
- Recursion tree
- Mater's method

##Substitution Method
Substitution method는 다음 두 단계로 이루어진다.

1. 해의 형태를 추측한다.
2. 수학적 귀납법으로 해가 맞음을 증명한다.


**Example.**  
T(n) = 2T(n/2) + n이 주어졌을 때,  
T(n) = O(nlog(n))라고 예측한다.  
이는 어떤 상수 c>0에 대해 T(n) <= cnlog(n)임을 의미한다.  
**수학적 귀납법**  
가정 : m < n를 만족하는 모든 m>0에 대해 T(m) <= cmlog(m)이 성립.  
그렇다면 m = n/2일 때도 성립하므로, T(n/2) <= c(n/2)log(n/2).  
T(n) = 2T(n/2) + n <= 2(c(n/2)log(n/2)) + n  
<= cnlog(n/2) + n  
= cnlog(n) - cnlog(2) + n  
= cnlog(n) - cn + n  
<= cnlog(n) (c>1일 때 성립)


##Recursion-tree Method
substitution method는 옳은 추측을 할 수 있을 때만 사용할 수 있다. 해의 형태를 추측하기 어려운 경우에는 recursion-tree method를 사용할 수 있다. Recursion-tree method는 recursion tree를 그려서 해를 구하는 방법이다. Tree의 각각의 노드는 하나의 subproblem을 푸는데 필요한 계산량을 나타낸다. 이 tree의 모든 node의 cost를 더함으로써 원래 문제의 cost를 구할 수 있다.  
**Example.**  
T(n) = 3T(n/4) + O(n^2)이 주어졌을 때 recursion tree를 그려보자.  
T(n) = 3T(n/4) + cn^2으로 놓아도 문제가 없다.  
