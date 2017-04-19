# Callback Function

Node.js를 쓰며 가장 많이 접하는 개념이 바로 `callback 함수` 이다.

자바스크립트의 함수는 다른 Array, Number, String 등과 같이 [일급객체](https://github.com/Shinye/TIL/blob/master/JavaScript/aboutFunction.md)(Object 타입)이다. function자체가 객체이므로 변수에 담을수도 있고, 인수로써 다른 함수에 전달할 수도 있고, 함수에 의해 만들어질 수도, 반환(return) 될 수도 있다.

콜백 함수 역시 위의 일급객체의 특성에 의해 가능한 것인데, **콜백 함수는 특정 함수에 매개 변수로서 전달된 함수를 지칭한다.** 그리고 그 호출된 콜백 함수는 이 함수를 전달 받은 함수 안에서 호출되게 된다.



예시로 jQuery의 onClick() 함수를 살펴보자.

```javascript
// 보시면, click 메소드의 인수가 변수가 아니라 함수이죠?
// click 메소드의 인수가 바로 Callback 함수입니다.
$("#btn_1").click(function() {
  alert("Btn 1 Clicked");
});
```

클릭 이벤트가 발생할 시, click함수의 매개변수에 있는 익명함수가 실행되어 'Btn 1 Clicked' 라는 메세지가 담긴 alert가 출력될 것이다. 여기서 이 alert를 발생시키는 익명함수가 콜백함수가 된다.



### 참조 URL

[Node.JS 강좌 06편: Callback Function 개념](https://velopert.com/255)<br>[콜백(callback) 함수](https://opentutorials.org/course/2136/11861)

