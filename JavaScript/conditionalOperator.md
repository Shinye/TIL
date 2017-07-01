# 조건부 연산자 ( ?: )

자바스크립트의 유일한 3항 연산자이다. 세 개의 피연산 함수를 취할 수 있으며 if문을 조금 더 간결하게 작성할 수 있다는 장점이 있다.

- 피연산자에는 모든 타입이 올 수 있다.
- 첫 번째 연산자를 `boolean` 값으로 판단한다.
  - 첫 번째 연산자가 **`true`** 일 시, **`두 번째`** 연산자가 판단되고 실행된다.
  - 첫 번째 연산자가 **`false`** 일 시, **`세 번째`** 연산자가 판단되고 실행된다.
  - 두/세 번째 연산자 중 하나만 실행되며, 동시에 실행되는 일은 없다.



예시) 어떤 변수가 정의되어 있는지 여부 확인하기

![https://drive.google.com/uc?id=0B3Or0Wv2t1xwSTJzU1p6eXhZSms](https://drive.google.com/uc?id=0B3Or0Wv2t1xwMzEwZTVPM3AtSVE)

다음의 if문과 동일하다. 조건 연산자를 쓰면 코드의 길이가 확연히 간결해짐을 알 수 있다.

```javascript
var greeting = "hello";
var username;

if(username){
  greeting += username;
} else{
  greeting += "there";
}
```







