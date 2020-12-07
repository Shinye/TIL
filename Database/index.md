# MySQL index 관련 이모저모





인덱스는 B+tree 자료구조로 이루어져 있다.

https://zorba91.tistory.com/293

![img](https://blog.kakaocdn.net/dn/Cbs9b/btqBVf7DVW2/8JOOKlHiwkoTsqbvbTt7R1/img.png)



## 성능 향상을 위한 SQL 작성법

https://d2.naver.com/helloworld/1155



### 인덱스 스캔을 이용한 SQL flow

다음과 같은 SQL로 테이블 & 인덱스 설정

```sql
CREATE TABLE tbl  
(a INT NOT NULL,
b STRING,  
c BIGINT);

CREATE INDEX idx ON tbl  
(a, b);

INSERT INTO tbl VALUES  
(1, 'ZZZ', 123456),
(4, 'BBB', 123456789),
(1, 'AAA', 123'),
…
(이하 생략)
```

![sql3](https://d2.naver.com/content/images/2015/06/helloworld-1155-3.png)

```sql
SELECT * FROM tbl  
WHERE a > 1 AND a < 5  
AND b < 'K'  
AND c > 10000  
ORDER BY b;  
```

위와 같은 SELECT 질의에서 WHERE 절에 있는 검색 조건은 다음과 같이 3가지로 나눌 수 있다.

- Key Range: 인덱스 스캔 범위로 활용하는 조건이다 (a > 1 AND a < 5).
  - 여기서 Range조건이란?
    - 범위 조건은 값의 비교 조건, 즉 **크다, 작다, 크거나 같다, 작거나 같다, 같다**와 같은 비교문으로 기술한다. 
      - =(같다) 도 range조건이라 볼 수 있다. 당연한 얘기지만... 왠지 >,< 이런것만 범위조건일것만 같았음.
- Key Filter: Key Range에 **포함할 수 없지만** 인덱스 키로 처리 가능한 조건이다(b < 'K').
- Data Filter: 인덱스를 사용할 수 없는 조건이다. 테이블에서 레코드를 읽어야만 처리 가능한 조건이다(c > 10000).



### 복합인덱스 (Multi-column index)

- 두 개 이상의 칼럼을 묶어서 인덱스를 만들 때는 칼럼의 순서가 매우 중요하다. 이런 인덱스를 다중 칼럼 인덱스(Multi-Column Index) 또는 복합 인덱스라고 한다. 
- 복합 인덱스에서는 WHERE 절에 **인덱스 키의 첫 번째 칼럼을 사용해야 인덱스 스캔을 수행한다**. 
- 인덱스가 여러 칼럼으로 조합되어 있을 때 칼럼 가운데 한 가지 칼럼만 사용해도 무방하다고 알려져 있는데, 잘못 알려진 것이라고 할 수 있다. 
  - 첫 번째 칼럼이 없는 상태에서는 두 번째 칼럼이 정렬된 상태라고 할 수 없기 때문에 범위를 정의할 수 없다. 
- 따라서 **반드시 첫 번째 칼럼이 조건에 있어야 하며**
- **🔥 첫 번째 이후의 칼럼은 조건에 없어도 상관없다.** (이 사실이 너무너무x100 궁금했다. 고민 해결!)



### 인덱스 활용 최적화

- B+-Tree는 특성상 어떤 리프 페이지에 접근하든 거의 동일한 비용이 든다.
-  B+-Tree를 사용할 때 가장 큰 비용이 드는 부분은 Key Range의 시작부터 끝까지 인덱스 리프 노드를 따라 진행하는 스캔과 여기에 대응하는 테이블 데이터의 스캔이다.



### LIMIT 최적화

IN 절을 사용한 질의에도 LIMIT 최적화를 적용할 수 있다. 

- 인덱스 칼럼이 IN 절에 사용되면 Key Range를 IN 절에 사용된 개수만큼 생성하고, 
- 각 Key Range에 대해 인덱스 스캔을 수행한다. 
- 다만, 아래 질의처럼 LIMIT 절에 결과 개수가 명시되면 3번의 인덱스 스캔에 대해 각각 3건의 결과만 구하고 인덱스 스캔을 중단한다. 
  - 즉, 각 인덱스 스캔에 대해서 LIMIT 최적화가 적용되는 것이다.
  - 그렇군요 대박사건;;🤓

```sql
SELECT * FROM tbl  
WHERE a IN (2, 4, 5)  
AND b < 'K'  
ORDER BY b  
LIMIT 3;  
```



### 그 외 이런저런 팁

- 단일 인덱스 여러 개보다 다중 칼럼 인덱스의 생성을 고려한다.
- 업데이트가 빈번하지 않은 칼럼으로 인덱스를 구성한다.
- JOIN 시 자주 사용하는 칼럼은 인덱스로 등록한다.
- 되도록 동등 비교(=)를 사용한다.
- WHERE 절에서 자주 사용하는 칼럼에는 인덱스 추가를 고려한다.
- 인덱스를 많이 생성하는 것은 INSERT/UPDATE/DELETE의 성능 저하의 원인이 될 수 있다.
- 인덱스 스캔이 테이블 순차 스캔보다 항상 빠르지는 않다. 보통 선택도(selectivity)가 5~10% 이내인 경우에 인덱스 스캔이 우수하다.

