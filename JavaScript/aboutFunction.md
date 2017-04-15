# Function Declration(함수선언) vs Function Expressions(함수표현)

함수는 독립적으로 분리된 로직으로서 프로그램 수준에서 미리 정의되어 있거나 사용자정의에 의해 만들어진 실행단위를 일컫는 말이다. 함수는  `Function` 키워드를 통해 정의될 수 있다.

자바스크립트의 함수선언과 함수표현에 대해 설명하기 앞서 알아야 할 사실은, 자바스크립트의 함수는 `객체` 라는 점이다.<br>정확히는 `First-Class-Object` 이다. First class object(1급 객체)의 특징에 대해 간단히 설명하자면 다음과 같다. 

- 변수(Variable) 에 담을 수 있다
- 다른 함수에 인자(Parameter) 로 전달할 수 있다 
- 반환값(Return value) 으로 전달할 수 있다.

자바스크립트의 함수는 객체이고, 그 중에서도 1급 객체이므로 해당 조건들을 모두 충족한다. 또한 동시에 1급 함수이기도 한데, 따라서 자바스크립트의 함수는 1급객체의 조건과 함께 다음의 추가적인 조건도 가지고 있다.

- 런타임(Runtime) 생성이 가능하다
- 익명(Anonymous) 으로 생성이 가능하다

그 외 가지는 자바스크립트 함수의 특징으로는 

- 함수 내에 또 다른 함수를 정의할 수 있다(내부함수)
- Hoisting

등이 있다.



자바스크립트에서 함수를 작성하는 방식에는 크게 두 가지 특징이 있다.



## 함수 선언(Function Declration)

> 함수 선언은 `Function Statement` 라고도 하며, 말 그대로 **함수 문장** 이라는 뜻이다. 우리가 처음 자바스크립트의 함수를 배울 때 일반적으로 쓰는 형식이다. 이는 **실행 가능한 코드블럭이 아니며,** 함수의 정의를 나타내는 문장으로 해석된다. 따라서 코드 해석에 따른 수행결과가 존재하지 않는다.

 `Statement` 라는 개념을 잘 알아둬야 한다. 함수 선언문이 Statement란 말은, 코드 블럭 자체는 실행 가능한 코드가 아니라는 사실이다. 즉 해당 코드블럭을 콘솔에서 실행해도 아무런 결과도 return되지 않는다. <br>그러한 이유로 함수 선언 블럭을 **class와 동일한 개념**으로 이해해도 무방하다.

```javascript
// Function Declrations
function foo(){
  console.log("hello");
}
```

![https://drive.google.com/uc?id=0B3Or0Wv2t1xweC1ZTjg2elZycHM](https://drive.google.com/uc?id=0B3Or0Wv2t1xweC1ZTjg2elZycHM)

다음의 결과와 같이 아무런 실행 결과도 나타나지 않음을 알 수 있다.



## 함수 표현 (Function Expression)

> 함수 표현은 Function Literal이다. 이는 실행 가능한 코드로 해석되어지거나, 변수나 데이터구조에 할당이 가능함을 뜻한다. 즉, 실행 가능한 코드로 해석되어짐과 동시에, 실행의 결과로써 코드실행에 따른 결과값을 가지거나, 특정 변수에 할당된 값으로 존재한다. 

함수표현은 즉시 실행이 가능하거나, 다른 변수나 데이터구조에 할당될 수 있는 코드블럭으로써 존재하는 함수를 의미한다.<br>함수표현 형식의 함수에는 크게 세 가지가 있다.

```javascript
// 1. Anonymous Function Expression(익명함수) - 변수나 데이터구조에 할당
var foo = function(){
	console.log("hello");
};

// 2. Named Function Expression - 변수나 데이터구조에 할당
var foo = function AFunc(){
  console.log("hello");
};

// 3. Self Invoking Function Expression - 실행 가능한 코드로 해석되어짐
(function foo(){ // 익명함수도 OK
  console.log("hello");
})();
```

**부가설명**

1. 실행시켜보면 다음과 같다.

   ![https://drive.google.com/uc?id=0B3Or0Wv2t1xwbjB1Y3JJbHprWTg](https://drive.google.com/uc?id=0B3Or0Wv2t1xwbjB1Y3JJbHprWTg)

   일반적으로 프로그래밍 언어에서 ` ();` 를 사용하면 실행구문이 되어버린다고 한다. 따라서 익명함수가 할당된 변수 뒤에 ()를 붙이면 그 함수가 실행된 결과 값이 출력된다.

2. Named Function Expression의 경우 조금 특이하다. 우리가 흔히 알고 있는 Function Expression과는 달리 변수 foo에 이름(AFunc) 있는 함수를 할당하고 있다. 하지만 이 함수에는 한가지 특징이 있는데, 바로 해당 함수의 이름(AFunc)는 이 함수 밖에선 사용할 수 없다는 사실이다. 따라서 재귀호출을 위한 경우가 아니면 딱히 쓸모가 없다.

   ```javascript
   var foo = function AFunc(){
     console.log("hello world");
   };

   AFunc(); // Syntax Error
   ```

   ​

3. Self Invoking Function Expression

   자기호출함수를 이용하여 콘솔에서 실행해보면 곧장 실행결과를 출력할 수 있다.

   ![https://drive.google.com/uc?id=0B3Or0Wv2t1xwOFN0UzdwR2VURUU](https://drive.google.com/uc?id=0B3Or0Wv2t1xwOFN0UzdwR2VURUU)





이렇게 함수 표현과 함수 선언 방식을 보았는데, 방식 면에서만 볼 때는 이 특징들을 나누는게 큰 의미가 없어보인다.<br>하지만 자바스크립트에서 아주 중요한 개념 중 하나인  `호이스팅(Hoisting)` 개념을 생각한다면 이 두 특징의 차이가 두드러지게 보인다.



# 호이스팅(Hoisting)

> 인터프리터가 자바스크립트 코드를 해석할 때 Global 영역에 있는 코드블럭을 최상의 Scope로 끌어올리는 것. 

`호이스팅` 의 사전적 의미로는 끌어올리다 라는 뜻을 가지고 있다. 자바스크립트의 개념에서도 호이스팅은 말 그대로 끌어 올리는것이다.

즉, Global 영역에 선언된 변수 또는 함수는 자바스크립트 엔진이 가장 먼저 해석하게 되고 해당 Scope의 최상단에 호이스팅 한다. 단, 할당( `=` 연산자를 사용한 ) 구문은 런타임 과정에서 이루어지기 때문에 hoisting되지 않는다.

다시 말하자면, 자바스크립트의 인터프린터가 코드를 해석하며 코드 작성 순서에 상관 없이 Global 영역에 '선언'된 함수나 변수를  먼저 수집하여 해당 scope의 전역객체의 속성으로 등록시켜준다는 것이다. 

이 호이스팅에서 가장 중요하게 여겨야 할 것은, `Statement` (선언) 구문은 호이스팅이 가능하지만 `=` 연산자를 사용한 할당 구문은 호이스팅 되지 않는다는 점이다. 따라서 위에서 살펴본 함수 형식의 차이가 중요하다는 것이다.

```javascript
// 예제1 : 함수선언에서의 호이스팅
foo();
function foo(){
  console.log("hello world");
}
> hello world

// 예제2 : 함수표현에서의 호이스팅
foo();
var foo = function(){
  console.log("hello world")
};
> Syntax Error
```

![https://drive.google.com/uc?id=0B3Or0Wv2t1xwUUJIcHEwSnNuMlU](https://drive.google.com/uc?id=0B3Or0Wv2t1xwUUJIcHEwSnNuMlU)

예제1의 함수선언의 경우 함수선언 코드블럭이 호이스팅 되어 scope의 최상단으로 간다. 따라서 첫째줄의 foo(); 가 무리 없이 실행될 수 있었다. 하지만 예제2의 경우 함수표현 코드블럭은 변수 foo에 할당되었으므로 호이스팅이 일어나지 않는다. 따라서 에러가 난다.



### 호이스팅 예제

```javascript
// Question 1
function foo(){
    function bar() {
        console.log('hello');
    }

    return bar();

    function bar() {
        console.log('world');
    }
}
foo();
> world

// Question 2
function foo(){
    var bar= function() {
        console.log('hello');
    };
    return bar();
    var bar = function() {
         console.log('world');
    };
}
foo();
> hello
```

![https://drive.google.com/uc?id=0B3Or0Wv2t1xwekt4MEE3Nkk4UFE](https://drive.google.com/uc?id=0B3Or0Wv2t1xwekt4MEE3Nkk4UFE)







