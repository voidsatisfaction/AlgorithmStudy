#Greedy Algorithm
그리디 알고리즘이란? : 저번주에 함  
##언제 그리디 알고리즘을 써야 하는가
###그리디 알고리즘의 요소

1. Optimal structure
2. Greedy-choice property

1.은 DP와 같음. 2.는 DP와 다른 점이다. DP에서는 어떤 subproblem을 풀어야 할 지 선택할 때 subproblem의 결과에 의존하게 된다. 예를들어 계단오르기 문제에서  
f(i) = max(f(i-2) + point(i), f(i-3) + point(i-1) + point(i))  
f(i)를 구하기 위해 f(i-2)를 이용할지, f(i-3)를 이용할지 선택해야 한다. 하지만 이 선택은 f(i-2)와 f(i-3)의 결과를 이미 알고 있는 상태에서만 가능하다. 그러므로 우리가 보통 DP알고리즘을 설계할 때에는 처음부터 모든 subproblem을 풀어나가는 bottom-up방식을 택하게 된다.
