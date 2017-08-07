# 람다(Lambda)

> 람다 개념은 자바스크립트에서 클로저와 깊은 연관이 있으므로 다음의 글들과 함께 봅시다.<br>
> [유효범위, 클로져에 대하여](https://github.com/Shinye/TIL/blob/master/JavaScript/closureAndScope.md) / [자바스크립트의 Arrow function](https://github.com/Shinye/TIL/blob/master/JavaScript/arrowFunction.md)

## 람다 대수
람다대수는 컴퓨터 과학과 수학의 기초를 이루는 함수와 관련된 개념으로, 함수를 단순하게 표현할 수 있도록 하여 '함수의 계산'이라는 개념을 더 깊이 이해할 수 있게 돕는다.<br>다시 말해, 함수를 보다 단순하게 표현하는 방법이다.

람다가 가지는 특징은 다음과 같다.

- 람다 대수는 이름을 가질 필요가 없다. (익명 함수)
- 두 개 이상의 입력이 있는 함수는 최종적으로 1개의 입력만 받는 람다 대수로 단순화 될 수 있다. (커링)

람다 표현식은 크게 세 가지로 구성되어 있다.

- 코드 블록
- 파라미터
- 자유 변수들의 값 (자유 변수는 파라미터 변수도 아니고, 람다 표현식 코드 내부에 선언한 변수도 아닌 것을 말한다.)


## 익명함수

익명함수는 함수를 단순하게 표현하는 것을 목표로 둔 람다대수의 특징을 반영한 함수의 표현 방법이다. 최근 대부분의 언어들에서 익명함수를 지원하고 있다고 한다.(python, java, javascript...) 

각기 다른 언어의 익명함수들이 갖는 공통적인 특징은, 바로 [`일급객체`](https://github.com/Shinye/TIL/blob/master/JavaScript/aboutFunction.md) 라는 것이다.<br>자바스크립트의 함수 역시도 일급객체이며 일급함수의 특징을 가지고 있다. 위의 링크를 보면 자세히 나와있지만, 일급객체의 특징으로는 다음과 같다.

- 변수의 값으로 할당 가능
- 리턴할 수 있음
- 함수의 인자로 사용할 수 있음

위의 특징들을 모두 익명함수로 적용이 가능하다.<br>참고한 [블로그](https://hyunseob.github.io/2016/09/17/lambda-anonymous-function-closure/) 작성자 분의 의견에 의하면 함수가 일급객체이자 일급함수이면 람다라고 부를 수 있다고 보신다고 한다.

최근 자바스크립트 ES6 문법에서는 [Arrow Function](https://github.com/Shinye/TIL/blob/master/JavaScript/arrowFunction.md) 이라는, 익명함수를 간결히 표현하여  보다 람다스러운(..) 방법을 추가하였다.

### 익명함수의 Use-case

- 함수의 콜백
- 클로져
- IIFE

등등..
<br>

## 클로져와의 연관 관계

람다 표현식의 관점에서 보았을 때, `자유 변수` 의 값을 사용하는 코드 블록을 `클로져` 라고 한다.

클로져는 자바스크립트 뿐만 아니라 몇몇 다른 언어들의 함수 역시 가지고 있는 특징이다.<br>또한 클로져는 람다에서 파생된 개념이라고 한다!! <br>

[MDN](https://developer.mozilla.org/ko/docs/Web/JavaScript/Guide/Closures)에서 클로져를 설명하는 페이지를 확인해보면, 첫 단락에 다음과 같이 클로져의 특징이 요약되어 있다.

> 클로저는 독립적인 (자유) 변수 (지역적으로 사용되지만, 둘러싼 범위 안에서 정의된 변수)를 **참조**하는 함수들이다. 다른 말로 하면, 이 함수들은 그들이 생성된 환경을 '기억'한다.

여기서 "독립적인 자유 변수" 라는 말이 지금까지 무엇인지 전혀 이해할 수 없었는데, 후술한 람다식의 특징을 보면 이해가 간다. (이 글을 쓰는 이유이기도 하다...)

다음의 예제를 보자. 다음의 예시 중 6,7번째 줄은 `커링` 개념을 활용하였다.

```javascript
function adder(a) {
  return function(b) {
    return a + b;
  }
}
var add5 = adder(5);
add5(10); // 15
```

![https://drive.google.com/uc?id=0B3Or0Wv2t1xwZTN4Z1ZiQVhzclU](https://drive.google.com/uc?id=0B3Or0Wv2t1xwZTN4Z1ZiQVhzclU)
> add5 함수에는 adder함수가 리턴한 익명함수가 담겨있다.

add5 함수의 입장에서 보면, 자신의 스코프 내에 있는 `b` 라는 변수는 인자를 통해 갖고 있는 것이고 자신의 스코프 내에 갇혀있다. 하지만 `a` 는 어디에서 온 변수이길래 쓰일 수 있는건지 알 수 없다.<br> 이 때 바깥에서 온 변수인 `a`를 `자유 변수(Free variable)` , `b` 를 `묶인 변수(Bound variable)` 라고 한다.

add5 함수는 자유변수 a와 묶인변수 b를 하나씩 사용하고 있다.<br>
람다 표현식을 표현하는 자료구조는 반드시 자유변수의 값(a) 를 저장해야 한다. 이를 가리켜 람다 표현식이 이 값들을 `캡쳐` 했다고 표현한다.(캡쳐 방법은 언어마다 다른 것 같다..!)<br>람다 표현식(여기서는 클로져 함수)은 **자신을 감싸고 있는 유효범위에 속한 변수의 값**을 캡쳐할 수 있다.

람다식은 사용하는 변수의 종류에 따라 두 종류로 나눌 수 있다. 바로 `닫힌 람다식(Closed expression)` 과 `열린 람다식(Open expression)` 이다. (앞서 자바스크립트 함수가 일급객체이자 일급함수이므로 람다식이라고 봐도 무방하다는 논리에 근거한다.)

람다 표현식에서 사용하는 변수들이 모두 묶인 변수일 때 닫힌 람다식이라고 부른다. 그리고 람다 표현식에서 사용하는 변수들 중 하나라도 자유 변수가 있을 때 열린 람다식이라고 부른다.


자, 이제 클로저를 아주 간단하게 설명할 수 있다. <br>클로저는 바로 **열린 람다식을 닫힌 람다식으로 만드는 것**이다. 클로저의 이름이 어떻게 유래되었는지도 예상이 될 것이다. 클로저는 **람다식 내의 모든 자유 변수**를 스코프 내로 가져와 묶는다. 그렇기 때문에 클로저는 만들어진 환경을 기억하는 것처럼 보인다.



### 참고URL
[javascript 기초 - Scope, Scope Chain & arguments](http://insanehong.kr/post/javascript-scope/)<br>[Closure](https://developer.mozilla.org/ko/docs/Web/JavaScript/Guide/Closures)<br>[람다, 익명 함수, 클로저](https://hyunseob.github.io/2016/09/17/lambda-anonymous-function-closure/)<br>[자바스크립트의 스코프와 클로저-TOAST meetup!](http://meetup.toast.com/posts/86)<br>[람다-자유변수에 대해...](https://books.google.co.kr/books?id=z_N8CwAAQBAJ&pg=PT300&lpg=PT300&dq=%EB%9E%8C%EB%8B%A4+%EC%9E%90%EC%9C%A0%EB%B3%80%EC%88%98&source=bl&ots=PnQgWWAoeP&sig=Sdz8dMdZgC96AdnYUf7JGjglgqU&hl=ko&sa=X&ved=0ahUKEwj49MDTtcTVAhWFpZQKHYvjClMQ6AEISTAF#v=onepage&q=%EB%9E%8C%EB%8B%A4%20%EC%9E%90%EC%9C%A0%EB%B3%80%EC%88%98&f=false)
