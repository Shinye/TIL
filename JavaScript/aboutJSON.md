# All about JSON

전에 면접에서 JSON을 왜 쓰는지(왜 JSON이여야만 하는지), MySQL과 같은 데이터베이스와 차이점은 무엇인지 에 대한 질문을 들었었는데 깊게 생각해본 적이 없어서 (일단 둘이 비교대상이 된다는 것 부터가 당황스러웠다.) 제대로 된 대답을 하지 못했던 기억이 나서 다시 정리해본다.

<br>

## JSON이란?

> JSON: **J**ava**S**cript **O**bject **N**otation.
>
> **JSON (JavaScript Object Notation) is a lightweight format that is used for data interchanging.** It is based on a subset of JavaScript language (the way objects are built in JavaScript). As [stated in the MDN](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/JSON), some JavaScript is not JSON, and some JSON is not JavaScript.

JSON 자체가 JavaScript의 Object Notation(객체 표기법) 이라는 뜻을 가지고 있다. <br> 특징을 더 설명해보자면,

- Well organized data(Human readable) / Easy to access - 데이터가 읽고 이해하기 쉽게 구조화되어있다. / 접근 api도 좋음
- 웹에서의 경량(light-weight)의 `데이터 교환 방식` 으로 각광받고 있다.
- 한마디로, JSON은 그저 `데이터 형식` 이라고 생각하면 편하다.
- JSON은 자바스크립트에서 객체를 표현하기 위해 사용되는 문법이기도 하며
- JSON은 JavaScript의 subset (부분집합)으로, JavaScript가 꼭 JSON인건 아니다

<br>

앞서 JSON을 `데이터 형식` 이라고 보면 된다고 했는데<br>실제로 서버와 클라이언트 사이에서 데이터를 주고받으며 통신을 할 때 데이터 형식을 구분할 수 있는 코드가 있다.

![https://68.media.tumblr.com/1edee7d40491579f013a2d1a07988a6e/tumblr_owiecnuaI41v80c66o1_1280.png](https://68.media.tumblr.com/1edee7d40491579f013a2d1a07988a6e/tumblr_owiecnuaI41v80c66o1_1280.png)



### MySQL과 JSON

사실 나는 둘은 비교대상이 애초에 아니라고 여기지만..굳이 기록을 해보자면 <br>MySQL에서 쿼리문을 통해 추출한 데이터들을<br> JSON이라는 데이터 형식을 통해 구조화하여 <br>보다 사용자가 읽고 접근하기 쉽게 만들어 서버->클라이언트 로 전달

하는 과정이라고 보면 되지 않을까 싶다.<br>MySQL은 당연히 데이터를 '저장' 하고 '관리' 하기 편리하게 만든 것이고, JSON은 DB에서 추출한 데이터를 유저가 이용하고 읽기 쉽게 구조화한 데이터 형식인 것이다. 둘은 엄연히 다르다!



### XML과 JSON

> It is lightweight when **compared **to its rival XML. Thats all.
>
> When we say something is lightweight or heavy, we are basically comparing that thing with something else - in this case, XML. 
>
> XML is more verbose as compared to JSON. 
>
> To understand why JSON is lightweight, consider the representation of a person in XML and it's JSON equivalent

```xml
<!-- XML -->
<person>
      <first-name>John</first-name>
      <last-name>Carter</last-name>
</person>
```

```json
// JSON
{
      "firstname":"John",
      "lastname":"Carter"
}
```

둘 다 데이터를 구조화하여 나타내는 `데이터 형식` 이라는 공통점을 가지고 있지만, XML보다 JSON이 각광받는 이유는 위에 적은 각각의 문법으로도 설명이 가능하다. XML은 JSON에 비해 다소 장황한 부분이 있다.

[여기의 링크](https://www.quora.com/What-is-the-reason-for-Json-to-be-lightweight) 를 보면 JSON의 특성 중 '경량화' 의 부분은 'XML과의 비교'에서 우위를 점하는 것이라고 볼 수 있다고 한다.





### Ajax와 JSONP



### 구조

[ default ]

```javascript
// 예시 1
{
  "propertyName" : "value",
  "methodName1" : function(){console.log("hi!")},
  "arrayName" : ["a","b","c","d"]
};
```



**key값이 있는 배열**은 다음과 같이 작성한다.

```javascript
// 예시2
{
  array1 : [
    {"propertyName1" : "value1", "propertyName2":"value2"},
    {"propertyName1" : "value3", "propertyName2":"value4"},
    {"propertyName1" : "value5", "propertyName2":"value6"}
  ],
  array2 : [
    {"propertyName1" : "value7", "propertyName2":"value8"},
    {"propertyName1" : "value9", "propertyName2":"value10"},
    {"propertyName1" : "value11", "methodName2":function(){console.log("hello!")}}
  ]
};
```



**JSON에 접근하는 법**

```javascript
// 예시1 기준
foo1.propertyName1; // value
foo1.methodName1(); // hi!
foo1.arrayName[2]; // c

// 예시2 기준
foo2.array1[1].propertyName2; // value4
foo2.array2[2].propertyName1 // value11
foo2.array2[2].methodName2(); // hello!
```



### JSON.parse vs JSON.stringify

- `JSON.stringify()`: js객체를 JSON형식의 문자열로 변환. 이를 이용해 js객체를 브라우저->다른 앱으로 전송가능.
- `JSON.parse()`: JSON객체를 브라우저가 사용가능한 js객체로 변환.



