# Multi-variable Linear Regression

지금까지의 사례로는 학습데이터가 하나만 경우들만은 다루었다. 하지만 실질적으로 Linear Regression을 적용하고자 하면 수 많은 경우의 학습데이터를 가질 때를 대비해야 한다. 
![http://cfile9.uf.tistory.com/image/27288F465795B17D32B975](http://cfile9.uf.tistory.com/image/27288F465795B17D32B975)
> 다음의 그림과 같이 학습 데이터가 많은 경우 작성이 길어진다.

따라서 이러한 Multi-variable 을 다룰 때는 `Matrix` 를 사용하여 손쉽게 표현할 수 있다.

![http://cfile21.uf.tistory.com/image/27318B465795B17F2B98F0](http://cfile21.uf.tistory.com/image/27318B465795B17F2B98F0) ![http://cfile23.uf.tistory.com/image/27044E3F5795B1802B0AD5](http://cfile23.uf.tistory.com/image/27044E3F5795B1802B0AD5)

일반적으로 행렬을 지칭할 때는 대문자를 쓰기 때문에, 그리고 행렬 계산 상의 편의 상 X 행렬이 앞으로 가기 때문에 Hypothesis 표기를 `H(X) = XW` 로 작성하는 것이 좋다.<br> ...내용추가...