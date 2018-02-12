# Singleton Pattern

## 싱글톤 패턴이란?

> Ensure a class only has one instance, and provide a global point of access to it.<br>오로지 하나의 인스턴스만 갖도록 한다. / 어디서든 이 인스턴스에 접근하도록 한다.

### 싱글톤의 사전적 정의

하나씩 일어나는 것; 단독 개체; 1개인 것; 단생아(單生兒).

-----

일반적으로 자바스크립트에서 객체를 만들 때, 하나의 생성자 (`new` 키워드 사용) 로 여러 객체를 만들 수 있습니다. 하지만 싱글톤은 필요에 의해 **단 하나**의 객체만을 만들 때 사용됩니다.

### 1. 객체 리터럴

자바스크립트에서 흔히 볼 수 있는 대표적인 싱글톤 패턴은 `객체 리터럴` 을 통해 객체를 생성하는 방법이 될 수 있겠습니다.

```javascript
const baseball = {
  infielder: 5,
  outfielder: 3,
  pitcher: 1
}
```

위의 예시를 통해 baseball이라는 하나뿐인 객체가 생성되는 것을 알 수 있습니다.<br>하지만 객체지향 프로그래밍은 `불필요한 정보는 숨기고 중요한 정보만을 표현함으로써 프로그램을 간단히 만드는 것 (캡슐화)` 라는 중요한 특징을 가지고 있습니다. 이러한 특징에 위의 예시는 다소 맞지 않기 때문에 (모든 속성이 다 공개되어있기 때문), 조금 더 객체지향적인 싱글톤을 만들어 보겠습니다.



### 2. IIFE 활용 

불필요한 속성들을 숨길 수 있으며 단 하나의 객체를 생성할 수 있는 방법이 자바스크립트에 있을까요? <br>`IIFE (즉시 실행 함수)` 는 일관되게 하나의 객체를 반환할 수 있으므로 (자바스크립트의 함수는 [일급객체](https://bestalign.github.io/2015/10/18/first-class-object/) 이므로 객체를 반환할 수 있다) 충분히 싱글톤의 자격 조건이 될 수 있습니다. 다음의 예시를 확인해봅시다.

```javascript
const singletonFunc = (function() {
  let instance;
  const a = 'hello';
  function initiate() {
    return {
      a: a,
      b: function() {
        alert(a);
      }
    };
  }
  return {
    getInstance: function() {
      if (!instance) {
        instance = initiate();
      }
      return instance;
    }
  }
})();
const first = singletonFunc.getInstance();
const second = singletonFunc.getInstance();
console.log(first === second); // true;
```

마지막 줄의 로그 결과를 통해 `singletonFunc` 이 일관된 객체를 반환함을 알 수 있습니다.<br>(위의 코드는 자바스크립트에서 [클로져](https://github.com/Shinye/TIL/blob/master/JavaScript/closureAndScope.md) 의 개념과 밀접한데, 이에 대한 개념을 한번쯤 다시 복습해봐도 좋을 것 같습니다.)



### 왜 싱글톤 패턴이 필요할까요?

일반적으로 프로그램을 시작할 때 초기값 설정 등 네임스페이스 설정에 효과적이라고 합니다. (잘 모르겠어요 왜 좋을까요?...ㅠㅠ)<br>함께 고민해볼까요? (1)

### 싱글톤 패턴의 한계

1. 전역변수의 남용이 나쁘듯 전역적인 접근점을 제공하는 싱글톤 패턴의 남용은 충돌의 가능성을 내포하고 있습니다.
2. 코드 재사용을 통한 효율성이 적어집니다.



### 지그재그와 싱글톤 패턴 🤔

함께 고민해볼까요? (2)