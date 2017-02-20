#Hash Table

" 해시테이블 : 해싱을 통한 검색 - key에 의해 key의 value를 찾음 "

해시의 사전적 의미로는 고기, 야채 등을 잘게 썬다는 뜻을 가지고 있다.<br>위의 사전적 의미처럼 컴퓨터공학적 관점에서는 큰 데이터를 작은 크기로 바꾸어 주는 의미로 쓰인다. 그래서 주로 암호학, 보안학 관련해서 사용될 땐 패스워드를 해싱 후 저장하는 방법을 쓰기도 한다.

자료구조적 의미의 해시테이블은 크게 `해시 함수` / `(키와 값을 저장하는) 해시 테이블` 두 가지로 구성된다. <br>여기서 `키`는 `식별자` 라고도 불리우며, 다음과 같은 예시로 이해를 할 수 있겠다.

```
o 전화번호부
키(key) : 이름
값(value) : 전화번호 // 핸드폰 전화번호부 앱에서 이름을 검색하면 전화번호가 나옴

o 사전
키(key) : 단어
값(value) : 단어의 뜻 // 사전 앱에서 단어를 검색하면 단어 뜻이 나옴
```

이처럼 key를 이용하여 `삽입 / 삭제 / 제거` 를 할 수 있는데 이를 `해싱`이라고 부른다.

해시 테이블의 **강점**은 다음과 같다. (영문 인터넷 강의의 설명이 직관적이라 원문으로 우선 붙여봅니다...)

---

**ARRAY** (random access) + **LINKED LIST** (we want to have our DataStructure be able to grow and shrink.)

Hash tables combine the random access ability of an array with the dynamism of a linked list.

THIS MEANS! (assuming we define our hash table well)

- Insertion can start to tend toward 세타(1) // 세타 : 평균
- Deletion can start to tend toward 세타(1)
- Lookup can start to tend toward 세타(1)

----

 위의 설명대로 원소들의 빠른 접근이 가능한 배열의 장점과, 자료구조의 크기 조정이 자유로운 링크드리스트의 장점이 합쳐진 셈이다. 이 합쳐진 장점들을 토대로 해시테이블은 삽입, 삭제, 제거 3가지 연산의 **평균 검색시간**이 `O(1)` 로 상당히 빠르다는 장점을 가질 수 있다. <br>하지만 이는 해시테이블을 잘!!! 설계 했을 때의 이야기이다… :-( 따라서 해시테이블을 성공적으로 설계하는 것이 가장 중요한 부분이다.

해시테이블의 구조는 다음과 같다.

![](https://68.media.tumblr.com/d9f80bc612c47f9fa8c36950d867f393/tumblr_olo6kgfMrh1v80c66o1_540.png)







### 참고 URL

[https://www.youtube.com/watch?v=tjtFkT97Xmc](https://www.youtube.com/watch?v=tjtFkT97Xmc)

[http://core.ewha.ac.kr/publicview/C0101020141210102600802227?vmode=f](http://core.ewha.ac.kr/publicview/C0101020141210102600802227?vmode=f)

