#Hash Table

" 해시테이블 : 해싱을 통한 검색 - key에 의해 key의 value를 찾음 "

해시의 사전적 의미로는 고기, 야채 등을 잘게 썬다는 뜻을 가지고 있다.<br>위의 사전적 의미처럼 컴퓨터공학적 관점에서는 큰 데이터를 작은 크기로 바꾸어 주는 의미로 쓰인다. 그래서 주로 암호학, 보안학 관련해서 사용될 땐 패스워드를 해싱 후 저장하는 방법을 쓰기도 한다.

자료구조적 의미의 해싱기법은 크게 `해시 함수` / `(키와 값을 저장하는) 해시 테이블` 두 가지로 구성된다. <br>여기서 `키`는 `식별자` 라고도 불리우며, 다음과 같은 예시로 이해를 할 수 있겠다.

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

 위의 설명대로 원소들의 빠른 접근이 가능한 배열의 장점과, 자료구조의 크기 조정이 자유로운 링크드리스트의 장점이 합쳐진 셈이다. 이 합쳐진 장점들을 토대로, 해시테이블은 삽입, 삭제, 제거 3가지 연산의 **평균 검색시간**이 `O(1)` 로 상당히 빠르다는 장점을 가질 수 있다. <br>하지만 이는 해시테이블을 잘!!! 설계 했을 때의 이야기이다… :-( 최악의 경우 탐색/삽입/제거 시간은` O(n)`이다.<br>따라서 해시테이블을 성공적으로 설계하는 것이 가장 중요한 부분이다.

해시테이블의 구조는 다음과 같다.

![](https://68.media.tumblr.com/0ee0b584c91cc1839d113e22810619e1/tumblr_olo8apJIRR1v80c66o1_1280.png)



### Collision(충돌)

" 서로 다른 key를 가지고 있는데, 해시함수로부터 리턴된 해시주소가 동일한 상황 "

```
[예시]
크기 365의 1년 365일을 해시테이블이 있다고 가정하자.
한 반의 60명의 학생들의 생일을 각각 테이블에 저장하고자 한다. 60명 학생 모두의 생일이 다르면 해시테이블 안에 값들이 골고루 분포가 되겠지만, 분명 생일이 같은 학생들이 존재한다. 이럴 때 생일이 같은 학생들은 같은 버켓에 값을 넣게 되는데, 이 경우를 '충돌' 이라고 한다.
```

해시테이블의 Bucket 안에는 여러 개의 slot이 있어 충돌이 생겨도 값을 저장할 수 있긴 하지만, slot의 개수는 유한하기 때문에 주어진 slot이 다 차버리면 분명 저장하지 못하는 상황이 온다. 이러한 충돌이 버킷에 할당된 슬롯 수보다 많이 발생하게 되면 버킷에 더 이상 항목을 저장할 수 없게 되는 `오버플로우(overflow)` 가 발생 한다.

*** 동의식별자** :  충돌을 일으킨 서로 다른 식별자 (key1,value1) / (key2,value2)



### Overflow

" key가 모든 슬롯이 꽉 찬 Bucket에 매핑된 경우 "

앞서 충돌에서 설명하였듯 버킷 안의 슬롯이 모두 찼음에도 불구하고 그 버킷에 key가 할당된 경우를 `오버플로우` 가 발생했다고 한다. 만약 버켓당 슬롯 수를 1개로 정해놓았으면 충돌과 오버플로우가 동시에 발생한다.

따라서 좋은 해시함수는 해시테이블에 적절히 데이터들을 분산시켜주는 것임을 알 수 있다.



### 해시함수

해싱기법의 효율성은 해싱함수와 아주 밀접한 관계가 있다. 해시함수는

- 충돌 최소화
- 쉬운 계산

의 조건을 최대한 충족시킬 수 있도록 해야한다.<br> 이상적인 해시함수는 각 버켓 i로 매핑될 확률이 1/m (m == table size)로 같을 경우이다. 이러한 경우를 충족시키면 충돌이 전혀 없는 것이 가능해지고 이를 `완전 해시 함수`라고 부른다.

...하지만 이건 꿈 같은 일이니^_ㅠ 우리는 충돌과 오버플로우를 방지할 여러 해결책들을 알아갈 필요가 있다.

그 전에 해시 함수의 종류를 알아보도록 하자.

...



### Overflow의 처리

1. **Chaining**

   > 보통 자료구조에서의 Chaining은 연결리스트를 뜻한다고 한다.

   - 각 버킷을 연결리스트로 유지 -> `동의식별자` 들을 동일 버켓에 저장.
   - 해시 테이블의 htable[i]는 리스트 헤드
   - 버킷 안의 각각의 노드들은 `slot`을 의미.

   예시 구조는 다음과 같다.

   ![](https://68.media.tumblr.com/5504f94b9681a018c5e26beae64f360e/tumblr_olob6oTTui1v80c66o1_540.png)



2. **Open Addressing (개방 주소법)**

   Open addressing  방식은 index에 대한 충돌 처리에 대해서 Linked List와 같은 추가적인 메모리 공간을 사용하지 않고, hash table array의 빈공간을 사용하는 방법으로, Separate chaining 방식에 비해서 메모리를 덜 사용한다. Open addressing  방식은 크게 세 가지가 존재한다.

   ​







### 참고 URL

[https://www.youtube.com/watch?v=tjtFkT97Xmc](https://www.youtube.com/watch?v=tjtFkT97Xmc)

[http://core.ewha.ac.kr/publicview/C0101020141210102600802227?vmode=f](http://core.ewha.ac.kr/publicview/C0101020141210102600802227?vmode=f)

http://emzei.tistory.com/128

http://1ambda.github.io/algorithm/design-and-analysis-part1-6/

http://eunpyeonghong.tumblr.com/post/152986466964/%ED%95%B4%EC%8B%9C%ED%85%8C%EC%9D%B4%EB%B8%94hash-table

https://en.wikipedia.org/wiki/Open_addressing

http://bcho.tistory.com/1072