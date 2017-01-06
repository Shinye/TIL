#Relational Algebra1 (관계대수)

##Relation
릴레이션은 행과 열로 구분되는 테이블이다<br><br>
![릴레이션 설명](https://68.media.tumblr.com/9b22ef08f4a98dd058110aaea7ce4e5e/tumblr_ojcq2joZZI1v80c66o1_540.jpg)

##관계 대수 연산자
관계 대수 연산자에 속하는 대표적인 8가지 특성에 따라 **일반 집합 연산자**와 **순수 관계 연산자**로 분류할 수 있다.<br><br>
![](http://dbscthumb.phinf.naver.net/4515_000_1/20160715112638554_KLWZ2MLCJ.jpg/ka26_96_i1.jpg?type=w530_fst_n&wm=Y)	

- ####일반 집합 연산자<br>
일반 집합 연산자는 **릴레이션이 투플의 집합**이라는 개념을 이용하는데 이는 수학의 집합 관련 연산자를 차용한 것이다.<br>
![일반 집합 연산자](https://68.media.tumblr.com/8a4d64f8d7dd136a5959a242e47b4226/tumblr_ojcqsem4G61v80c66o1_540.png)

 - **카티션 프로덕트 (곱하기)<br>**
 두 릴레이션 R과 S의 카티션 프로덕트(cartesian product)는 R × S로 표현한다. R × S는 릴레이션 R에 속한 각 투플과 릴레이션 S에 속한 각 투플을 모두 연결하여 만들어진 새로운 투플로 결과 릴레이션을 구성한다. <br><br>
 ![](http://dbscthumb.phinf.naver.net/4515_000_1/20160715112704477_PW5AHDTJX.jpg/ka26_101_i1.jpg?type=w530_fst_n&wm=Y)
<br>


- ####순수 관계 연산자 <br>
순수 관계 연산자는 **릴레이션의 구조와 특성**을 이용하는 것이다.<br>
![순수 관계 연산자](https://68.media.tumblr.com/ffbcbcad61e6c88c8343648d668bffab/tumblr_ojcqsrZhzL1v80c66o1_540.png)

 - **조인** <br>
 릴레이션 하나로는 원하는 결과를 얻지 못할 때 두 개의 릴레이션을 조합하여 하나의 결과 릴레이션을 도출하는 것이다. 이 때, 각 릴레이션은 조인 속성을 만족해야 한다. <br> **조인 속성이란?** 두 릴레이션이 공통으로 가지고 있는 attribute이 존재해야 하는 것 -> 두 릴레이션이 관계가 있음을 나타내는 것이다. <br>
조인 연산 결과, 릴레이션은 피연산자 릴레이션에서 조인 속성의 값이 **같은** 투플만 연결하여 만들어진 새로운 투플이다.
 - **디비젼**
 - ....