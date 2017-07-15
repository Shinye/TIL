# Tensorflow Basic #2


## 텐서플로우의 자료형
텐서플로우는 뉴럴네트워크에 최적화 되어있는 개발 프레임워크이기 때문에, 실행방식이 일반 프로그래밍 방식과 상이한 면이 있다.

### 상수형(Constant)
상수형은 말 그대로 데이터를 저장하는 데이터형이다. 정의되는 구조는 다음과 같다.

```
tf.constant(value, dtype=None, shape=None, name='Const', verify_shape=False)
```
- value : 상수의 값
- dtype : 상수의 데이터형. tf.float32와 같이 실수,정수등의 데이타 타입을 정의
-c[shape](https://github.com/Shinye/TIL/blob/master/MachineLearning/tensorflow_basic1.md#텐서란) : 행렬의 차원을 정의한다. shape=[3,3]으로 정의해주면, 이 상수는 3x3 행렬을 저장하게 된다.
- name : name은 이 상수의 이름을 정의한다

예제를 하나 작성해 보았다.
![https://drive.google.com/uc?id=0B3Or0Wv2t1xwdUhIT05zS2FGMTA](https://drive.google.com/uc?id=0B3Or0Wv2t1xwdUhIT05zS2FGMTA)
일반적인 프로그래밍의 경우를 생각해본다면 d의 값이 print가 되어야 하지만 프린트 되고 있지 않고 있다.<br>이를 이해하기 위해선 그래프와 세션의 개념에 대해 알아야 한다.
<br>


### 그래프와 세션
위의 `d = a*b+c` 연산은 계산을 수행하는 것이 아닌 a*b+c 그래프를 정의하는 것이다.<br>
![http://cfile8.uf.tistory.com/image/221D7F45584AB42A1F0F4F](http://cfile8.uf.tistory.com/image/221D7F45584AB42A1F0F4F)

값을 출력하기 위해서는 이 그래프에 a,b,c의 값을 넣어주어 실행해야 한다.<br>이를 위해 `세션(session)` 을 생성하여 그래프를 생성한다. 세션은 그래프를 인자로 받아 실행해 결과 값을 return해주는 일종의 Runner이다.
세션 생성 API는 `tf.Session()` 으로 작성하면 된다.

세션을 생성해 그래프를 실행하면 다음과 같이 결과 값이 출력된다.
![https://drive.google.com/uc?id=0B3Or0Wv2t1xwdk1JS2t4OTNsYlk](https://drive.google.com/uc?id=0B3Or0Wv2t1xwdk1JS2t4OTNsYlk)


### Placeholder
학습을 위한 데이터를 담는 그릇

`y = 2*x` 라는 함수의 그래프를 실행할 때, 입력 값으로는 [1,2,3,4,5], 출력은 [2,4,6,8,10] 을 기대한다고 했을 때 다음과 같은 그래프가 그려진다.

![http://cfile21.uf.tistory.com/image/270C9F45584AB42D296501](http://cfile21.uf.tistory.com/image/270C9F45584AB42D296501)

플레이스홀더는 위의 그래프에서 x, 즉 입력값(학습용 데이터)을 저장하는 일종의 버킷이다.<br>정의하는 방법은 다음과 같다.<br>

```
tf.placeholder(dtype, shape, name)
```

- dtype : placeholder에 저장되는 데이터 형. tf.float32와 같이 실수,정수등의 데이타 타입을 정의
- [shape](https://github.com/Shinye/TIL/blob/master/MachineLearning/tensorflow_basic1.md#텐서란) : 행렬의 차원을 정의한다. shape=[3,3]으로 정의해주면, 이 상수는 3x3 행렬을 저장하게 된다.
- name : 이 placeholder의 이름

placeholder에 데이터를 넣는 방법을 `feeding` 이라고 한다.<br>

```
import tensorflow as tf

input_data = [1,2,3,4,5]
x = tf.placeholder(dtype=tf.float32)
y = x * 2

sess = tf.Session()
result = sess.run(y,feed_dict={x:input_data})

print result
```

`sess.run(y,feed_dict={x:input_data})` 와 같이 세션을 통해서 그래프를 실행할 때, `feed_dict` 변수를 이용해서 플레이스홀더 x에, `input_data`의 데이터들을 피드하면, 세션에 의해서 그래프가 실행되면서 x는 `feed_dict`에 의해서 정해진 피드 데이타 [1,2,3,4,5]를 하나씩 읽어서 실행한다.


### 변수형 (Variable)
Linear regression의 경우 `y = W*x+b` 라는 학습용 가설을 기반으로 가진다.<br>x가 입력데이터(placeholder)였다면, W와 b는 학습을 통해 구해야 하는 값이다. 이를 `변수(variable)` 이라 한다.<br> 

```
tf.Variable.__init__(initial_value=None, trainable=True, collections=None, 
validate_shape=True, caching_device=None, name=None, variable_def=None, 
dtype=None, expected_shape=None, import_scope=None)

tf.Variable(initial_value, dtype)
```


텐서플로우에서 변수형은 그래프를 실행하기 전에 `초기화` 해주어야 한다.<br> 초기화 해주는 방법은 `tf.global_variables_initializer()` 를 사용하는 것이다. 구현해보면 다음과 같다.ㄴ

```
import tensorflow as tf

input_data = [1,2,3,4,5]
x = tf.placeholder(dtype=tf.float32)
W = tf.Variable([2],dtype=tf.float32)
y = W*x

sess = tf.Session()
init = tf.global_variables_initializer()
sess.run(init)
result = sess.run(y,feed_dict={x:input_data})

print result
```


모델을 그래프로 정의하고, 세션을 만들어서 그래프를 실행하고, 세션이 실행될때 그래프에 동적으로 값을 넣어가면서 (피딩) 실행한 다는 기본 개념을 잘 이해해야, 텐서플로우 프로그래밍을 제대로 시작할 수 있다.



### 참고URL
[텐서플로우-#1 자료형의 이해](http://bcho.tistory.com/1150)
> 이 글의 모든 그림들은 조대협님 블로그(위의 링크)에서 퍼왔습니다.