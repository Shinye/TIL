# JSON



### 구조

[ default ]

```javascript
// 예시 1
var foo1 = {
  "propertyName" : "value",
  "methodName1" : function(){console.log("hi!")},
  "arrayName" : ["a","b","c","d"]
};
```



**key값이 있는 배열**은 다음과 같이 작성한다.

```javascript
// 예시2
var foo2 = {
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



