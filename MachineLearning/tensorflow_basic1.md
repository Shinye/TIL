# Tensorflow Basic #1

> [모두를 위한 딥러닝](https://www.youtube.com/watch?v=BS6O0zOGX4E&list=PLlMkM4tgfjnLSOjrEJN31gZATbcj_MpUm) 강좌를 듣고 배운 내용을 기반으로 기록합니다.

<br>

## 머신러닝이란?

- 기존 프로그래밍의 한계에 대한 대안으로 시작 됨
- 데이터를 주고 그것을 컴퓨터가 학습하도록 하게 하자는 것이 핵심 아이디어. ex) 스팸메일 자동필터링, 자동주행운전 ...



### 컴퓨터의 데이터 학습 방법

데이터를 학습하는 방법에 따라 `Supervised learning / Unsupervised learning` 으로 나뉨

- Supervised Learning

  머신러닝 방법 중에서 가장 흔히 쓰이는 방법으로써, 학습에 사용되는 데이터에 결과가 정해져 있는 경우(Training data set)를 통한 학습을 하는 것이다. (Learning w/ labeled examples)

  ex) cat : (다수의 고양이 사진들) / dog : (다수의 강아지 사진들) ...

  ![https://68.media.tumblr.com/e919e8ab53b3843c23f877714d83ea4d/tumblr_ot31hbslLr1v80c66o2_1280.png](https://68.media.tumblr.com/e919e8ab53b3843c23f877714d83ea4d/tumblr_ot31hbslLr1v80c66o2_1280.png)

  <br>조금 더 일반적으로 쓰이는 경우에 대해 이야기하자면 다음과 같이 표현할 수 있다.<br>

  ![https://68.media.tumblr.com/d3f1cc79a61f1ab153276944a6b5a4a7/tumblr_ot31hbslLr1v80c66o1_1280.png](https://68.media.tumblr.com/d3f1cc79a61f1ab153276944a6b5a4a7/tumblr_ot31hbslLr1v80c66o1_1280.png)

  ​

  또 다른 예로, 아래와 같이 지역,평수,층수에 따른 가격 데이터가 있다고 하자

  ![http://cfile27.uf.tistory.com/image/213D4D40544F9C3326A70A](http://cfile27.uf.tistory.com/image/213D4D40544F9C3326A70A)

  가격은 앞의 3개 조건에 따라 변화하는 결과인데, 이 지역,평수,층수와 같은 조건을 `Feature` 또는 `Attribute` 라고 하며, 이 Feature에 따라 결정되는 값을 `Targeted value(목적값)` 이라고 한다.


- Unsupervised learning 

  일일이 데이터에 label을 줄 수 없는 경우.<br>ex) 구글 뉴스 그루핑, 단어 클러스터링 : 유사한 소재를 그루핑하는 것. 사전에 데이터를 주어 미리 레이블링 하기 어렵다.



### Supervised Learning 의 종류

1. Regression<br>
   ex) 공부한 시간을 기반으로 점수(0점~100점)를 예측하는 것

2. Binary classification<br>
   ex) 공부한 시간을 기반으로 Pass/NotPass 여부를 예측하는 것

3. Multi-label classification<br>
   ex) 공부한 시간을 기반으로 Letter Grade(A,B,C,D,F) 를 예측하는 것

<br>

## Tensorflow에 대하여

### 텐서플로우란?

![https://camo.githubusercontent.com/4ee55154486232ec9edd8f1a3bad4c4a146f6cfe/68747470733a2f2f7777772e74656e736f72666c6f772e6f72672f696d616765732f74656e736f72735f666c6f77696e672e676966](https://camo.githubusercontent.com/4ee55154486232ec9edd8f1a3bad4c4a146f6cfe/68747470733a2f2f7777772e74656e736f72666c6f772e6f72672f696d616765732f74656e736f72735f666c6f77696e672e676966)

> 텐서플로우는 그래프라고 하는 자료구조(Data Structure)처럼 동작한다는 것을 알려주는 그림이다.

텐서플로우(TensorFlow)는 기계 학습과 딥러닝을 위해 구글에서 만든 오픈소스 라이브러리이다. 데이터 플로우 그래프(Data Flow Graph) 방식을 사용하여 연산을 수행한다.

텐서플로우는 크게 두 가지로 구성되어 있다.

- 노드 : 주로 수학적인 연산 (Mathematical operations), 데이터 입/출력, 그리고 데이터의 읽기/저장 등의 작업을 수행한다.
- 엣지 : 데이터를 담고 있다. 정확히는 노드들 간의 데이터의 흐름을 나타내며, 동적 사이즈의 다차원 배열(tensor)을 실어나른다. 여기서 `tensorflow` 라는 용어가 생성된 것이다. (Multidimensional data arrays(tensors) communicated between nodes.)

<br>

### 텐서란?

Tensor란 학습 데이터가 저장되는 다차원 배열을 뜻한다.<br>
텐서를 이야기 할 때 일반적으로 `Ranks` , `Shapes` , `Types` 를 이야기한다. 

**1.  Rank : "몇차원 Array인가?"**

| Rank(차원) | Math Entity | Python ex                                |
| -------- | ----------- | ---------------------------------------- |
| 0        | Scalar      | S = 123                                  |
| 1        | Vector      | V = [1,2,3]                              |
| 2        | Matrix      | M = [[1,2,3], [4,5,6], [7,8,9]]          |
| 3        | 3 - Tensor  | T = [ [ [2], [4],[6] ], [ [1], [3], [5]], ... ] |
| N        | N - Tensor  | ...                                      |



**2. Shapes : "각각의 Array에 원소가 몇 개씩 들어있는가?"**

| Rank | Shape        | Dimension Number |
| ---- | ------------ | ---------------- |
| 0    | []           | 0-D              |
| 1    | [D0]         | 1-D              |
| 2    | [D0, D1]     | 2-D              |
| 3    | [D0, D1, D2] | 3-D              |

<br>

### 텐서플로우의 특징

- 데이터 플로우 그래프를 통한 풍부한 표현력
- 코드 수정 없이 CPU/GPU 모드로 동작
- 아이디어 테스트에서 서비스 단계까지 이용 가능
- 계산 구조와 목표 함수만 정의하면 자동으로 미분 계산을 처리
- Python/C++를 지원하며, [SWIG](http://www.swig.org/)를 통해 다양한 언어 지원 가능



### 텐서플로우의 핵심 매커니즘

텐서플로우는 크게 다음의 세 가지 구조로 나뉘어 실행된다.

1. 그래프를 Build한다 : Build graph using TensorFlow operations
2. 그래프를 실행한다 : Feed data and run graph(operation)
3. 연산 수행 결과 값을 return한다 : Update variables in the graph and return values



### 참고 URL

[텐서플로우 시작하기]([https://gist.github.com/haje01/202ac276bace4b25dd3f](https://gist.github.com/haje01/202ac276bace4b25dd3f))<br>[맨땅에 해딩 머신러닝 #1](http://bcho.tistory.com/966)

