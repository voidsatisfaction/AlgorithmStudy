# 자료구조의 정의와 종류(연규민)

## 출처 / 참고

- [Data struceture - 위키피디아](https://en.wikipedia.org/wiki/Data_structure)

- [List of data structures - 위키피디아](https://en.wikipedia.org/wiki/List_of_data_structures)

- [자료구조 - 나무위키](https://namu.wiki/w/%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0#fn-1)

- [자료구조 - 생활코딩](https://www.youtube.com/watch?v=bj2F0hTiTtw&list=PLuHgQVnccGMDsWOOn_P0EmAWB8DArS3Fk)

- C로 배우는 쉬운 자료구조

---

## 오늘 배울 내용

1. 자료구조의 정의

2. 자료구조를 공부하는 이유

3. 자료구조의 분류

## 자료구조(Data Structure)란?
- 정의
  - 현실의 사상(事象)을 프로그래밍적으로 **표현**하는 것(생활코딩)
    - 학교의 시스템 / 다이어트 하는 방법? / 지하철 노선도

  - (대량의)데이터를 효율적으로 다루기(**관리**) 위한 방법(생활코딩, 위키피디아)

- 항상 ~ 가 최고다(x) 때와 장소에 따라서 적절한 자료구조가 다름.

- 적절한 자료구조의 선택은 좋은 알고리즘의 원천이다.(반의 명부)

- Quiz : Class는 자료구조일까?

---

## 왜 자료구조를 공부하는가?

- 문제 해결의 How to (알고리즘과 깊은 관계가 있다.)

- 효율적인 How to

- 문제를 어떠한 방식으로 추상화 시킬 것인가? ex)스도쿠, AlienAndHamburgers문제

---

## 자료구조의 분류

![자료구조의 분류](http://cfile27.uf.tistory.com/image/1176FD3B514A556A0CB28D)

- 단순 구조
  - 정수, 실수, 문자, 문자열 등의 **데이터 타입**에 해당하는 자료 구조.

- 선형 구조
  - 자료 간의 연결 관계가 1:1 관계를 가지고 있는 자료 구조.
  - 자료를 구성하는 원소들을 순차적으로 나열시킨 형태
  - 예) 순차 리스트, 연결 리스트, 스택, 큐, 덱 ...

- 비선형 구조
  - 1:다 or 다:다 관계를 가지고 있는 자료 구조.
  - 자료를 구성하는 원소들을 순차적이지 않은 형태로 관리.
  - 예) 트리, 그래프

- 파일 구조
  - 파일에 대한 자료구조

앞으로 우리가 주로 살펴볼 것들은 **선형 구조 / 비선형 구조**

---

## 키워드

- 표현 / 관리

---

## 대표적인 선형 자료구조와 비선형 자료구조의 예 

- 배열(Array)
  
    - 순서대로 번호가 붙은 원소들이 연속적인 형태로 구성된 구조.

    - fetch = O(1) / store = O(n)

`data = [1,2,3,4,5]`

- 연관배열(Associative Array)

    - 배열의 index(integer) 대신 key(string or symbol)

    - map, symbol table, dictionary, hash 라고도 함.


```js
  data = {
    "Pride and Prejudice": "Alice",
    "Wuthering Heights": "Alice",
    "Great Expectations": "John"
  }

  EX)
  data["Greate Expectations"] // "John"
  data["Pride and Prejudice"] // "Alice" 
```

- [리스트](https://namu.wiki/w/%EC%97%B0%EA%B2%B0%20%EB%A6%AC%EC%8A%A4%ED%8A%B8)(List)

    - 순열 이라고도 불리며, 순서를 가지고 일렬로 나열한 원소들의 모임.

    - 종류로는 순차 리스트 / 연결 리스트(단순 연결 리스트 / 이중 연결 리스트 / 원형 연결 리스트) 등이 있다.

    - fetch = O(n) / store = O(1)

![리스트](http://cfile10.uf.tistory.com/image/1834F84B4F17A790121531)

- [스택](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))(Stack)

    - Last In First Out

    - 재귀함수

![스택](https://upload.wikimedia.org/wikipedia/commons/thumb/b/b4/Lifo_stack.png/350px-Lifo_stack.png)

- [큐](https://en.wikipedia.org/wiki/Queue_(abstract_data_type))(Quene)

    - First In First Out

![큐](https://upload.wikimedia.org/wikipedia/commons/thumb/5/52/Data_Queue.svg/300px-Data_Queue.svg.png)

- [트리](https://en.wikipedia.org/wiki/Tree_(data_structure))(Tree)

![트리](https://upload.wikimedia.org/wikipedia/commons/thumb/f/f7/Binary_tree.svg/220px-Binary_tree.svg.png)

---

## C++와 자료구조

[표준 템플릿 라이브러리(STL) - 위키피디아](https://ko.wikipedia.org/wiki/%ED%91%9C%EC%A4%80_%ED%85%9C%ED%94%8C%EB%A6%BF_%EB%9D%BC%EC%9D%B4%EB%B8%8C%EB%9F%AC%EB%A6%AC)

---

## 생각해보자

- 나는 어떠한 자료구조로 스도쿠판을 표현할 것인가?

- 스타크래프트의 유닛은 어떻게 표현된 것일까?

- 구글은 어떻게 유저의 아이디와 비밀번호를 그들의 데이터베이스에서 그렇게 빨리 확인할 수 있었을까?

- 도서 검색사이트는 그 많은 도서중에서 어떻게 빨리 제목을 찾을 수 있을까?

- Google Map어플리케이션은 어떻게 나에게 최단 시간으로 목적지 까지 가는 법을 알려줄까?

---

## 정리

1. 자료구조는 데이터의 **표현**과 **관리**이다.

2. 자료구조에 대한 이해는 효율적인 데이터 활용을 가능하게 해준다.

3. 적절한 자료구조의 선택은 좋은 알고리즘의 기반이 된다.

---

## 다음 발표 준비자는 '구현'에 초점을 맞춰서 발표해주셨으면 좋겠습니다.