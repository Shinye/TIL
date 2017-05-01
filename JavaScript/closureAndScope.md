# 유효범위와 클로져



## 유효범위 (Scope)

변수의 유효범위란 다른 프로그래밍 언어에서도 알 수 있듯, 프로그램에서 어떤 변수가 정의되어 있는 영역을 말한다.

`전역변수`는 코드 전체에 걸쳐 모든 곳에서 유효한 것이고, `지역변수`는 어떤 **함수** 안에서 선언된 변수로 오직 해당 함수 몸체 안에서만 정의된다. (함수의 매개변수로 받아오는 변수도 지역변수이다 물론!)

자바, C++과 같은 프로그래밍 언어에서는 '블록단위' 에 따라 지역변수의 유효범위가 결정되었다. 해당 블록`{}` 안에 선언된 지역변수는 블럭을 벗어난 곳에서는 보이지 않는다. <br>하지만 자바스크립트는 블록 단위 개념의 유효범위가 없고, 대신 `함수 단위`의 유효범위가 존재한다. 따라서 함수 안에 정의된 지역변수는 해당 변수가 정의된 함수 안에서 보이는 것 뿐만 아니라, 그 함수 안에 중첩 된 함수 안에서도 유효하다.

함수 유효범위는 어떤 함수 안에서 선언된 모든 변수는 그 함수 전체에 걸쳐 유효하다는 의미이다. <br>흥미롭게도, 이는 변수가 미처 선언되기 전에도 유효하다는 뜻이기도 하다. (이를 [호이스팅](https://github.com/Shinye/TIL/blob/master/JavaScript/aboutFunction.md#호이스팅hoisting)이라고 한다.) 자바스크립트 코드는 함수 안에 있는 모든 변수를 함수 맨 꼭대기로 '끌어올린' 것처럼 동작한다. 하지만 할당문 (= "something") 까지 끌어올리진 않는다.

```javascript
var scope = "global";
function f(){
  console.log(scope); // "global" 아닌 undefined 출력. 아래에 지역변수로 선언 및 할당된 scope가 할당문
  // 을 제외하고 호이스팅 되었기 때문에 선언은 되었지만 할당값은 없는 undefined가 출력
  scope = "local"; // 이제 scope변수가 초기화되고 제대로 된 값이 있다.
  console.log(scope); // local출력
}
```



 다음 코드에서 변수 i, j, k는 다른 위치에서 선언되지만, 모두 같은 유효범위를 갖는다. 다시 말해, 세 변수는 모두 함수의 몸체 안에 정의되어 있다.

```javascript
function test(o){
  var i = 0; // i는 함수 전체에 걸쳐 정의된다.
  
  if (typeof o == "object"){
    var j = 0; // j는 if문 블록 뿐만 아니라, 함수 전체에 걸쳐 정의된다.
  
    for(var k=0; k<10; k++){ // k는 반복문 외에도 함수 전체에 걸쳐 정의된다.
      console.log(k); // 0~9 출력
    }
    
    console.log(k); // k는 여전히 정의되어 있다. 10 출력
  }
  console.log("j : "+j); // j는 정의되어 있고, if문을 거치지 않았다면 초기화 되지 않아 undefined일 것.
}
```



다음의 추가적인 예시로, 자바스크립트는 지역변수의 유효범위가 블록 기준이 아닌 `함수` 기준임을 다시 한 번 알 수 있다.

![https://68.media.tumblr.com/1311bfd36e06920278e3e7e145720396/tumblr_op682wHWlk1w8w3y8o2_1280.png](https://68.media.tumblr.com/1311bfd36e06920278e3e7e145720396/tumblr_op682wHWlk1w8w3y8o2_1280.png)

![https://68.media.tumblr.com/7cbf499ec3942843cedc7aa9d5a24841/tumblr_op682wHWlk1w8w3y8o3_1280.png](https://68.media.tumblr.com/7cbf499ec3942843cedc7aa9d5a24841/tumblr_op682wHWlk1w8w3y8o3_1280.png)

첫 번째, 두 번째 스크린샷에서 변수 i는 if문 안에서 선언 되어 있다. C++, JAVA와 같은 경우라면 console.log(j) 부분에 Reference Error가 나야 할 것이다.

하지만 자바스크립트이기에!! <br>첫 번째 스크린샷의 경우(if문을 통과하지 못함) j는 정의는 되었지만 초기화(값 할당)는 되지 않았다는 뜻의 undefined가 뜬다.<br>두 번째 스크린샷의 경우(if문을 통과함) j의 값이 할당된 그대로 콘솔에 1이 출력된다.

![https://68.media.tumblr.com/d58eba930f60f5f202189495cadb49da/tumblr_op682wHWlk1w8w3y8o1_1280.png](https://68.media.tumblr.com/d58eba930f60f5f202189495cadb49da/tumblr_op682wHWlk1w8w3y8o1_1280.png)

반면 함수 안에 정의된 변수 j는 `함수단위 유효범위`에 의해 함수 외부에서 j를 부를 시 j가 defined되지 않았다는 Reference Error가 뜬다. (물론 클로져의 기능을 추가 활용한다면 외부에서 함수 내부에 선언된 지역변수를 부를 수 있다. 추후에 다시 클로져에 대해 설명하겠다.)



전역변수와 어떤 함수 내부의 지역변수가 같은 이름을 갖는 경우, 함수 내부의 지역변수를 우선시 한다. 지역 변수 혹은 함수 매개변수를 전역변수와 같은 이름으로 선언하면, 전역변수는 감춰진다.

```javascript
var scope = "global";
function checkScope(){
  var scope = "local";
  return scope;
}
checkScope(); // "local"
```



이와 같은 특성에 따라, 다음과 같은 특수한 경우도 볼 수 있다.

![https://68.media.tumblr.com/d71103800486ea8a552acbe9578ebd99/tumblr_op64ss7CS41w8w3y8o1_1280.png](https://68.media.tumblr.com/d71103800486ea8a552acbe9578ebd99/tumblr_op64ss7CS41w8w3y8o1_1280.png)

전역변수로 scope2가 선언 및 값이 할당되어 있지만, 함수 foo() 안에도 역시 scope2가 선언 및 값 할당 되어 있다. 따라서 전역변수, 지역변수 중복 선언된 변수인 scope2는 둘 중 기존에 선언한 전역변수가 감춰진다. 자바스크립트의 [호이스팅](https://github.com/Shinye/TIL/blob/master/JavaScript/aboutFunction.md#호이스팅hoisting) 성질에 따라, 지역변수 scope2는, `console.log(scope2)` 가 작성된 줄에서는 아직 값 할당이 안된 상태이므로 결과값으로 undefined가 뜬다.

이와 같은 이유로 기존의 블록유효범위를 가진 언어들(C++, JAVA)에서 지역변수를 선언할 때, 일반적으로 그 지역변수를 사용하는 코드와 최대한 가까운 곳에서 선언을 권장한다. 반면 자바스크립트의 지역변수는 함수의 최상단에 변수를 선언 하는 것이 권장된다는 의견도 있다.



### var에 대하여

자바스크립트에서 변수를 선언할 때 꼭 `var`을 써야하는 것은 아니다. var을 쓰지 않고도  변수 선언을 할 수 있다. 다만 권장하지 않을 뿐이다…!

var 키워드는 **해당 변수의 Scope(유효범위)를 설정하는 역할**을 한다고 볼 수 있다. 함수 내에서 변수를 선언할 때, `var` 를 변수 앞에 덧붙이지 않으면 함수의 지역변수가 아닌 전역변수같은 역할을 하는 것이 되어버린다. (정확하게는 전역객체에 등록되는 전역변수가 되는 셈이라고 하는데…)

이러한 선언의 단점은 크게 두 가지가 있다.

- 함수 안에 작성한 변수는 지역변수로써의 역할을 의도한 것일텐데, 실상은 전역변수가 되어버리므로 필요한 경우 외에도 항시 메모리를 차지하고 있다.
- var 없는 변수가 할당되는 것은 런타임 과정에서 일어나는 일이므로, 함수 안에 var없는 변수가 선언되었다면 해당 변수는 함수 호출이 되기 전 (함수 객체 생성 전) global scope에 등록되지 않는다.

```javascript
var x = 1;
function foo(){
  y = 2;
  return x+y;
}

//Case 1
console.log(x+y); // Reference Error - y is not defined

//Case 2
console.log(foo()); // 3
console.log(x+y); // 3
```



## 클로져

외부함수 안에 선언된 내부함수는 외부함수의 지역변수에 접근할 수 있다. 또한, 외부함수가 return에 의해 종료된 이후에도, 내부함수가 외부함수의 지역변수의 접근할 수 있다는 개념이 바로 `클로져` 이다.

클로져의 대표적인 예시는 다음과 같다.

```javascript
function outer(){
  var test = "hello world!";
  return function(){
    console.log(test);
  }
}

var inner = outer();
inner(); // "hello world!"
```

