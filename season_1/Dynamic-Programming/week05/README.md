


> Written with [StackEdit](https://stackedit.io/).
작성중

#동적계획법(Dynamic Programming)
---
##동적계획법이란

 - 복잡한 문제를 단순한 작은 문제로 나누고, 그 작은문제의 계산값을 저장해두어 다시 계산하지 않고 재활용하는 알고리즘 설계방식. 
 
 - 즉, 분할정복법(divide and conquer) + 값을 기억해둠(memoization)

 - 작은 문제들이 중복될 때 효과
 
 -  "기억하며 풀기"

##구현법

 - 분할정복법
 
	 - <pre><code>function F(x){
		if (F(x)가 간단){
			return F(x)를 계산한 값;
		}else{
			x를 x1,x2로 분할;
			F(x1), F(x2)를 호출;
			return F(x1),F(x2)로 F(x)를 구한값 
		}</code></pre>
 - 동적계획법 => 물론 이 외에도 다양한 구현법이 있다

	 -  <pre><code>function F(x){
		if (F(x)의 값을 안다){
			return 저장되어 있는 F(x);
		}else{
			x를 x1,x2로 분할;
			F(x)를 F(x1), F(x2)로 구하고 저장;
			return 저장된 F(x)
		}</code></pre>

##동적계획법의 사용예(피보나치 수열의 값 구하기)

 - 재귀함수로 구하기 O(1.6^n)
 - 분할정복법을 이용하기 O(n) 
 - 분할정복법을 이용하기2 O(log n)

##동적계획법의 특징
 
 - 정확한 방법을 사용하면 정확한 답을 반드시 구할  수 있음
 - 값을 저장해야 하므로 메모리를 많이 사용함
 - 모든 경우의 수를 보다 빠르게 검토하는 원리이므로 경우에 따라 비효율적임 -> 그리디 알고리즘 

##그리디 알고리즘
 - 매 순간마다 최선의 선택을 하면 결과적으로 최선의 선택이 된다는 알고리즘 설계법
	 - 최단경로 구하기, 거스름돈 구하기 
 - 항상 최선의 선택은 아니기에 사용하는데 주의가 필요
  - 17엔을 거슬러주는데 동전이 1,7,10엔짜리가 있으면 사용할수 없다

---
##자료 출처
 -[일본 위키백과 動的計画法]
 https://ja.wikipedia.org/wiki/%E5%8B%95%E7%9A%84%E8%A8%88%E7%94%BB%E6%B3%95

-[나무위키 동적계획법]
https://namu.wiki/w/%EB%8F%99%EC%A0%81%20%EA%B3%84%ED%9A%8D%EB%B2%95

-[나무위키 메모이제이션]
https://namu.wiki/w/%EB%A9%94%EB%AA%A8%EC%9D%B4%EC%A0%9C%EC%9D%B4%EC%85%98










