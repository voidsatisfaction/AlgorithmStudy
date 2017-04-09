#Greedy Algorithm
그리디 알고리즘이란? : 저번주에 함  
##언제 그리디 알고리즘을 써야 하는가
###그리디 알고리즘의 요소

1. Optimal structure
2. Greedy-choice property

1.은 DP와 같음. 2.는 DP와 다른 점이다. DP에서는 어떤 subproblem을 풀어야 할 지 선택할 때 subproblem의 결과에 의존하게 된다. 예를들어 계단오르기 문제에서  
f(i) = max(f(i-2) + point(i), f(i-3) + point(i-1) + point(i))  
f(i)를 구하기 위해 f(i-2)를 이용할지, f(i-3)를 이용할지 선택해야 한다. 하지만 이 선택은 f(i-2)와 f(i-3)의 결과를 이미 알고 있는 상태에서만 가능하다. 그러므로 우리가 보통 DP알고리즘을 설계할 때에는 처음부터 모든 subproblem을 풀어나가는 bottom-up방식을 택하게 된다.  
반면 그리디 알고리즘은 subproblem의 결과에 관계없이 현재 상태에서 최적인 선택을 취한다. 예를들어 계단오르기 알고리즘에서 f(i)를 구할 때 그 이전의 point가 최대가 되도록 선택하는 것이다. 하지만 이 알고리즘은 올바른 답을 내지 않는다. 왜냐하면 greedy-choice property를 만족하지 않기 때문이다. Greedy-choice property란 greedy choice가 항상 최적의 해를 가져오는 성질이다.  

직관적으로는 볼록함수의 극점을 찾는 문제를 생각할 수 있다. 볼록함수는 국소적 해가 전역적 해와 같으므로 gradient descent를 이용해 최적해를 구할 수 있다.  
또 다른 예로는 다익스트라 알고리즘이 있다. 다익스트라알고리즘은 매 순간 subproblem의 해와 관계없이 cost가 최소인 경로만을 선택한다.  
  
(DP)0-1 knapsack problem vs (DP, Greedy)Fractional knapsack problem
