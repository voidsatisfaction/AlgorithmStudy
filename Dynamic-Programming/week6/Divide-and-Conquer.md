#Divide and Conquer
많은 알고리즘은 재귀적으로 나타내어진다. 하나의 problem이 주어질 때, 호출된 함수는 한번에 그 문제를 해결하기 보다는 자기 자신을 반복해서 호출해 원래 문제보다 작은 규모의 문제를 풀게 한다. 이 작은 문제들의 해를 조합해 원래 문제의 해를 구해낼 수 있다. 이를 divide-and-conquer approach라고 한다.  

- Divide : 주어진 문제를 몇 개의 부분문제로 나눈다.  
- Conquer : 부분 문제를 푼다. 부분 문제의 크기가 충분히 작으면 직접 계산해 해를 구한다.  
- Combine : 부분 문제들의 해를 조합해 원래 문제의 해를 구한다.

###Merge Sort
- Divide : n개의 요소를 가진 배열을 n/2개의 요소를 가진 두 개의 배열로 나눈다.
- Conquer : 두 개의 배열을 'merge sort'로 정렬한다.
- Combine : 정렬된 두 배열을 합쳐 정렬된 새로운 배열을 만든다.  

###Recurrence Equation
재귀적 알고리즘은 recurrence equation으로 계산량을 표현할 수 있다. (재귀적 알고리즘이란, 재귀함수를 이용한다는 것이 아니라 recursive하다는 것)  
Recurrence equation은 다음과 같은 형식을 가진다.  
<img src="./fig/eq1.png" width="400px" height="60px">
